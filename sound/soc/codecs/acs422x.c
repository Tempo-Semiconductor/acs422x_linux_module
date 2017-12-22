/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 */

#include <linux/moduleparam.h>
#include <linux/module.h> 
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/pm.h>
#include <linux/i2c.h>
#include <linux/slab.h>
#include <linux/regmap.h>
#include <linux/regulator/consumer.h>
#include <linux/spi/spi.h>
#include <linux/of_device.h>
#include <linux/mutex.h>
#include <linux/clk.h>
#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/soc.h>
#include <sound/initval.h>
#include <sound/tlv.h>
#include <linux/firmware.h>

#include "acs422x.h"

#define DEBUG_TSCS
#ifdef DEBUG_TSCS
#define debug(str, ...) printk(KERN_WARNING "%s(): " str "\n", __func__, ##__VA_ARGS__)
#else
#define debug(str, ...) 
#endif

struct acs422x_priv {
	struct regmap *regmap;
	struct clk *mclk;
	int mclk_src_freq;
	bool mclk_src_is_xtal;
	int bclk_ratio;
	int samplerate;
	struct snd_soc_codec *codec;

	struct mutex lock;
};

static bool acs422x_volatile(struct device *dev, unsigned int reg)
{	
	switch (reg) {
	case R_PLLCTL0:
	case R_DACCRSTAT:
	case R_DACCRADDR:
	case R_DACCRRDL:
	case R_DACCRRDM:
	case R_DACCRRDH:
		return true;
	default:
		return false;
	};
}

static bool acs422x_writable(struct device *dev, unsigned int reg)
{	
	switch (reg) {
	case R_PLLCTL0:
	case R_DEVIDH:
	case R_DEVIDL:
	case R_REVID:
	case R_DEVADR:
		return false;
	default:
		return true;
	};
}

static bool acs422x_precious(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case R_DACCRWRL:
	case R_DACCRWRM:
	case R_DACCRWRH:	
	case R_DACCRRDL:
	case R_DACCRRDM:
	case R_DACCRRDH:
		return true;
	default:
		return false;
	};
}

static const struct regmap_config acs422x_regmap = {
	.reg_bits = 8,
	.val_bits = 8,

        .writeable_reg = acs422x_writable,
	.volatile_reg = acs422x_volatile,
	.precious_reg = acs422x_precious,
	.max_register = R_ATEST15,

	.cache_type = REGCACHE_RBTREE,
};

static struct reg_default r_inits[] = {
	{ .reg = R_ADCSR,   .def = RV_ADCSR_ABCM_64 }, 
	{ .reg = R_DACSR,   .def = RV_DACSR_DBCM_64 },
	{ .reg = R_AIC2,    .def = RV_AIC2_BLRCM_DAC_BCLK_LRCLK_SHARED }, 
};

static int load_dac_coefficient_ram(struct snd_soc_codec *codec)
{
	const struct firmware *fw = NULL;
	int ret;
	int i, j;

	ret = request_firmware_direct(&fw, "acs422x_daccram.dfw", codec->dev);
	if (0 != ret) {
		dev_err(codec->dev, "Failed to load effects data");
		return ret;
	}

	if (fw->size % 3 != 0) {
		dev_err(codec->dev, "Malformed effects file");
		return -EINVAL;
	}

	ret = snd_soc_write(codec, R_DACCRADDR, 0x00);
	if (ret < 0) {
		dev_err(codec->dev, "Failed to clear DACCRADDR");
		return ret;
	}

	for (i = 0; i < fw->size; i += 3) {
		for (j = 0; j < 3; j++) { // Effects FW in big endian
			ret = snd_soc_write(codec, R_DACCRWRL + j, 
					fw->data[i + 2 - j]);
			if (ret < 0) {
				dev_err(codec->dev, 
						"Failed to write coefficient");
				return ret;
			}
		}
		do {
			udelay(10);
			ret = snd_soc_read(codec, R_DACCRSTAT); 
			if (ret < 0) {
				dev_err(codec->dev, "Failed to read DACCSTAT");
				return ret;
			}
		} while ((ret & RM_DACCRSTAT_DACCR_BUSY));
	}

	return 0;
}

static bool plls_locked(struct snd_soc_codec *codec)
{
	int reg, count;
	bool ret = false;

	for (count = 0; count < 10; count++) {
		reg = snd_soc_read(codec, R_PLLCTL0); 	
		if (reg < 0) {
			dev_err(codec->dev, "Failed to read PLL lock status");
			break;
		} else if (reg > 0) {
			ret = true;	
			break;
		}
		mdelay(1);
	}
	
	return ret;
}


/* D2S Input Select */
static const char *d2s_input_select_text[] = {
  "LRIN1", "LRIN2"
};

static const struct soc_enum d2s_input_select_enum =
SOC_ENUM_SINGLE(R_INMODE, 0, ARRAY_SIZE(d2s_input_select_text), 
		d2s_input_select_text);

static const struct snd_kcontrol_new d2s_input_mux =
SOC_DAPM_ENUM("D2S_IN_MUX", d2s_input_select_enum);

/* Left Input Capture Switch */
static const char *left_input_select_text[] = {
  "LIN1", "LIN2", "LIN3", "LD2S"
};

static const struct soc_enum left_input_select_enum = 
SOC_ENUM_SINGLE(R_INSELL, 6, ARRAY_SIZE(left_input_select_text), 
		left_input_select_text);

static const struct snd_kcontrol_new left_input_select = 
SOC_DAPM_ENUM("LEFT_INPUT_SELECT_ENUM", left_input_select_enum);

/* Right Input Capture Switch */
static const char *right_input_select_text[] = {
  "RIN1", "RIN2", "RIN3", "RD2S"
};

static const struct soc_enum right_input_select_enum = 
SOC_ENUM_SINGLE(R_INSELR, 6, ARRAY_SIZE(right_input_select_text), 
		right_input_select_text);

static const struct snd_kcontrol_new right_input_select = 
SOC_DAPM_ENUM("RIGHT_INPUT_SELECT_ENUM", right_input_select_enum);


static int dapm_vref_event(struct snd_soc_dapm_widget *w,
			 struct snd_kcontrol *kcontrol, int event)
{
	mdelay(100);
	return 0;
}

static int dapm_micb_event(struct snd_soc_dapm_widget *w,
			 struct snd_kcontrol *kcontrol, int event)
{
	mdelay(5);
	return 0;
}

static const struct snd_soc_dapm_widget acs422x_dapm_widgets[] = {
	
	SND_SOC_DAPM_SUPPLY_S("VREF", 1, R_PWRM2, 0, 0, dapm_vref_event, 
			SND_SOC_DAPM_POST_PMU|SND_SOC_DAPM_PRE_PMD),

	/* Headphone */
	SND_SOC_DAPM_DAC("HiFi HP Left", "HiFi Playback", R_PWRM2, 6, 0),
	SND_SOC_DAPM_DAC("HiFi HP Right", "HiFi Playback", R_PWRM2, 5, 0),
	SND_SOC_DAPM_OUTPUT("HP_L"),
	SND_SOC_DAPM_OUTPUT("HP_R"),

	/* Speaker */
	SND_SOC_DAPM_DAC("HiFi SPK Left", "HiFi Playback", R_PWRM2, 4, 0),
	SND_SOC_DAPM_DAC("HiFi SPK Right", "HiFi Playback", R_PWRM2, 3, 0),
	SND_SOC_DAPM_OUTPUT("SPK_L"),
	SND_SOC_DAPM_OUTPUT("SPK_R"),

	/* Capture */
	SND_SOC_DAPM_PGA("ANA_IN_PGAL", R_PWRM1, 5, 0, NULL, 0),
	SND_SOC_DAPM_PGA("ANA_IN_PGAR", R_PWRM1, 4, 0, NULL, 0),
	SND_SOC_DAPM_PGA("BSTL", R_PWRM1, 7, 0, NULL, 0),
	SND_SOC_DAPM_PGA("BSTR", R_PWRM1, 6, 0, NULL, 0),
	SND_SOC_DAPM_PGA("ADC Mute", R_CNVRTR0, 3, true, NULL, 0),
	SND_SOC_DAPM_ADC("ADCL", "HiFi Capture", R_PWRM1, 3, 0),
	SND_SOC_DAPM_ADC("ADCR", "HiFi Capture", R_PWRM1, 2, 0),

	/* Capture Input */
        SND_SOC_DAPM_MUX("Left Input Capture Switch", R_PWRM2, 
			2, 0, &left_input_select),
        SND_SOC_DAPM_MUX("Right Input Capture Switch", R_PWRM2, 
			1, 0, &right_input_select),

	/* Digital Mic */
        SND_SOC_DAPM_PGA("DMIC Enable", R_DMICCTL, 7, 0, NULL, 0), 
        SND_SOC_DAPM_INPUT("DMIC_L"),
        SND_SOC_DAPM_INPUT("DMIC_R"),

	/* Analog Mic */
	SND_SOC_DAPM_SUPPLY_S("MICB", 2, R_PWRM1, 1, 0, dapm_micb_event, 
			SND_SOC_DAPM_POST_PMU|SND_SOC_DAPM_PRE_PMD),
	SND_SOC_DAPM_INPUT("AMIC1_L"),
	SND_SOC_DAPM_INPUT("AMIC1_R"),
	SND_SOC_DAPM_INPUT("AMIC2_L"),
	SND_SOC_DAPM_INPUT("AMIC2_R"),
	SND_SOC_DAPM_INPUT("AMIC3_L"),
	SND_SOC_DAPM_INPUT("AMIC3_R"),

	/* Line In */
	SND_SOC_DAPM_INPUT("LIN1_L"),
	SND_SOC_DAPM_INPUT("LIN1_R"),
	SND_SOC_DAPM_INPUT("LIN2_L"),
	SND_SOC_DAPM_INPUT("LIN2_R"),
	SND_SOC_DAPM_INPUT("LIN3_L"),
	SND_SOC_DAPM_INPUT("LIN3_R"),
};

static const struct snd_soc_dapm_route acs422x_intercon[] = {
	/* Headphone Path */
	{"HiFi HP Left", NULL, "VREF"},
	{"HiFi HP Right", NULL, "VREF"},
	{"HP_L", NULL, "HiFi HP Left"},
	{"HP_R", NULL, "HiFi HP Right"},

	/* Speaker Path */
	{"HiFi SPK Left", NULL, "VREF"},
	{"HiFi SPK Right", NULL, "VREF"},
	{"SPK_L", NULL, "HiFi SPK Left"},
	{"SPK_R", NULL, "HiFi SPK Right"},

	/* Digital Mic Path */
	{"DMIC Enable", NULL, "DMIC_L"},
	{"DMIC Enable", NULL, "DMIC_R"},
	{"Left Input Capture Switch", "LIN3", "DMIC Enable"},
	{"Right Input Capture Switch", "RIN3", "DMIC Enable"},

	/* Input Select Path */
	{"Left Input Capture Switch", NULL, "VREF"},
	{"Right Input Capture Switch", NULL, "VREF"},

	/* Analog Mic Path */
	{"MICB", NULL, "VREF"},
	{"AMIC1_L", NULL, "MICB"},
	{"AMIC1_R", NULL, "MICB"},
	{"AMIC2_L", NULL, "MICB"},
	{"AMIC2_R", NULL, "MICB"},
	{"AMIC3_L", NULL, "MICB"},
	{"AMIC3_R", NULL, "MICB"},
	{"Left Input Capture Switch", "LIN1", "AMIC1_L"},
	{"Right Input Capture Switch", "RIN1", "AMIC1_R"},
	{"Left Input Capture Switch", "LIN2", "AMIC2_L"},
	{"Right Input Capture Swtich", "RIN2", "AMIC2_R"},
	{"Left Input Capture Swtich", "LIN3", "AMIC3_L"},
	{"Right Input Capture Swtich", "RIN3", "AMIC3_R"},

	/* Line In Path */
	{"Left Input Capture Switch", "LIN1", "LIN1_L"},
	{"Right Input Capture Switch", "RIN1", "LIN1_R"},
	{"Left Input Capture Switch", "LIN2", "LIN2_L"},
	{"Right Input Capture Switch", "RIN2", "LIN2_R"},
	{"Left Input Capture Switch", "LIN3", "LIN3_L"},
	{"Right Input Capture Switch", "RIN3", "LIN3_R"},

	/* Input Path */
	{"ANA_IN_PGAL", NULL, "Left Input Capture Switch"},
	{"ANA_IN_PGAR", NULL, "Right Input Capture Switch"},
	{"BSTL", NULL, "ANA_IN_PGAL"},
	{"BSTR", NULL, "ANA_IN_PGAR"},
	{"ADC Mute", NULL, "BSTL"},
	{"ADC Mute", NULL, "BSTR"},
	{"ADCL", NULL, "ADC Mute"},
	{"ADCR", NULL, "ADC Mute"},
};

/*******
 * GEN *
 *******/

static const char *switch_text[] = {"OFF", "ON"};

/***********
 * Volumes *
 ***********/

static DECLARE_TLV_DB_SCALE(hpvol, -8850, 75, 0);
static DECLARE_TLV_DB_SCALE(spkvol, -7725, 75, 0);
static DECLARE_TLV_DB_SCALE(dacvol, -9563, 38, 0);
static DECLARE_TLV_DB_SCALE(adcvol, -7125, 38, 0);
static DECLARE_TLV_DB_SCALE(invol, -1725, 75, 0);

/*********
 * INSEL *
 *********/

static DECLARE_TLV_DB_SCALE(mic_boost_tlv, 0, 1000, 0);

/*******
 * ALC *
 *******/
static const DECLARE_TLV_DB_SCALE(alc_max_gain, -1200, 600, 0);

static const DECLARE_TLV_DB_SCALE(alc_target, -2850, 150, 0);

static const DECLARE_TLV_DB_SCALE(alc_min_gain, -1725, 600, 0);

static const char *alc_mode_text[] = {"ALC Mode", "Limiter Mode"};

static const char *alc_sel_text[] = 
		{"ALC Off", "Right Only", "Left Only", "Stereo"};

static const char *alc_hold_time_text[] = 
		{"0.0ms",    "2.67ms",   "5.34ms",  "10.68ms", 
                 "21.36ms",  "42.72ms",  "85.44ms", "170.88ms", 
                 "341.76ms", "683.52ms", "1.37s",   "2.73s",
                 "5.47s",    "10.9s",    "21.9s",   "43.7s"};

static const char *alc_decay_time_text[] = 
		{"21.33ms",  "42.66ms",  "85.32ms", "170.64ms",
                 "341.28ms", "682.56ms", "1.37s",   "2.73s",
                 "5.46s",    "10.9s",    "21.85s",  "21.85s", 
                 "21.85s",   "21.85s",   "21.85s",  "21.85s"}; 

static const char *alc_attack_time_text[] = 
		{"5.33ms",  "10.66ms",  "21.32ms",  "42.64ms",
                 "85.28ms", "170.56ms", "341.12ms", "682.24ms",
                 "1.36s",   "2.73s",    "5.46s",    "5.46s",
                 "5.46s",   "5.46s",    "5.46s",    "5.46s"};

static const struct soc_enum alc_enums[] = {
        SOC_ENUM_SINGLE(R_ALC0, 2, ARRAY_SIZE(alc_mode_text), 
			alc_mode_text), 
        SOC_ENUM_SINGLE(R_ALC0, 0, ARRAY_SIZE(alc_sel_text), 
			alc_sel_text),
        SOC_ENUM_SINGLE(R_ALC2, 0, ARRAY_SIZE(alc_hold_time_text), 
			alc_hold_time_text),
        SOC_ENUM_SINGLE(R_ALC3, 4, ARRAY_SIZE(alc_decay_time_text), 
			alc_decay_time_text),
        SOC_ENUM_SINGLE(R_ALC3, 0, ARRAY_SIZE(alc_attack_time_text), 
			alc_attack_time_text),
};

/*********
 * NGATE *
 *********/
static const DECLARE_TLV_DB_SCALE(ngth_tlv, -7650, 150, 0);

static const char *ngg_text[] = {"Constant", "Mute"};

static const struct soc_enum ngate_enums[] = {
	SOC_ENUM_SINGLE(R_NGATE, 0, ARRAY_SIZE(switch_text), switch_text),
        SOC_ENUM_SINGLE(R_NGATE, 1, ARRAY_SIZE(ngg_text), ngg_text),
};

/************
 * CONTROLS *
 ************/
static const struct snd_kcontrol_new acs422x_snd_controls[] = {
        /* Volumes */
        SOC_DOUBLE_R_TLV("HP Playback Volume", R_HPVOLR, R_HPVOLL, 
			0, 0x7F, 0, hpvol), 
        SOC_DOUBLE_R_TLV("SPK Playback Volume", R_SPKVOLR, R_SPKVOLL, 
			0, 0x7F, 0, spkvol),
        SOC_DOUBLE_R_TLV("Master Playback Volume", R_DACVOLR, R_DACVOLL, 
			0, 0xFF, 0, dacvol),
        SOC_DOUBLE_R_TLV("ADC Capture Volume", R_ADCVOLR, R_ADCVOLL, 
			0, 0xFF, 0, adcvol),
        SOC_DOUBLE_R_TLV("Input Capture Volume", R_INVOLR, R_INVOLL, 
			0, 0x3F, 0, invol),

        /* INSEL */
	SOC_DOUBLE_R_TLV("Mic Boost Capture Volume", R_INSELL, R_INSELR, 
			4, 3, 0, mic_boost_tlv),

        /* ALC */
        SOC_ENUM("ALC Capture Volume", alc_enums[0]), 
        SOC_ENUM("ALC_SEL Capture Volume", alc_enums[1]),
        SOC_SINGLE_TLV("ALC Max Gain Capture Volume", R_ALC1, 
			4, 7, 0, alc_max_gain),
        SOC_SINGLE_TLV("ALC Target Capture Volume", R_ALC1, 
			0, 15, 0, alc_target),
        SOC_SINGLE_TLV("ALC Min Gain Capture Volume", R_ALC2, 
			4, 7, 0, alc_min_gain),
        SOC_ENUM("ALC Hold Time Capture Volume", alc_enums[2]),
        SOC_ENUM("ALC Decay Time Capture Volume", alc_enums[3]),
        SOC_ENUM("ALC Attack Time Capture Volume", alc_enums[4]),

        /* NGATE */
	SOC_SINGLE_TLV("NGTH Capture Volume", R_NGATE, 3, 31, 0, ngth_tlv),
        SOC_ENUM("NGG Capture Volume", ngate_enums[1]),
	SOC_ENUM("NGATE Capture Volume", ngate_enums[0]),
};

#define ACS422WV_RATES SNDRV_PCM_RATE_8000_96000

#define ACS422WV_FORMATS (SNDRV_PCM_FMTBIT_S16_LE | SNDRV_PCM_FMTBIT_S20_3LE \
	| SNDRV_PCM_FMTBIT_S24_LE | SNDRV_PCM_FMTBIT_S32_LE)

static int setup_sample_format(struct snd_soc_codec *codec, 
		snd_pcm_format_t format)
{
	unsigned int width;
	int ret;

	switch (format) {
	case SNDRV_PCM_FORMAT_S16_LE:
		width = RV_AIC1_WL_16;
		break;
	case SNDRV_PCM_FORMAT_S20_3LE:
		width = RV_AIC1_WL_20;
		break;
	case SNDRV_PCM_FORMAT_S24_LE:
		width = RV_AIC1_WL_24;
		break;
	case SNDRV_PCM_FORMAT_S32_LE:
		width = RV_AIC1_WL_32;
		break;
	default:
		dev_err(codec->dev, "%s(): Unsupported format width", __func__);
		return -EINVAL;
	}
	ret = snd_soc_update_bits(codec, R_AIC1, RM_AIC1_WL, width);
	if (ret < 0) {
		dev_err(codec->dev, "Failed to set sample width");
		return ret;
	}
	
	return 0;
}

static int setup_sample_rate(struct snd_soc_codec *codec, unsigned int rate)
{
	struct acs422x_priv *data = snd_soc_codec_get_drvdata(codec);
	unsigned int br, bm;
	int ret;

	switch (rate) {
	case 8000:
		br = RV_DACSR_DBR_32;
		bm = RV_DACSR_DBM_PT25;
		break;
	case 16000:
		br = RV_DACSR_DBR_32;
		bm = RV_DACSR_DBM_PT5;
		break;
	case 24000:
		br = RV_DACSR_DBR_48;
		bm = RV_DACSR_DBM_PT5;
		break;
	case 32000:
		br = RV_DACSR_DBR_32;
		bm = RV_DACSR_DBM_1;
		break;
	case 48000:
		br = RV_DACSR_DBR_48;
		bm = RV_DACSR_DBM_1;
		break;
	case 96000:
		br = RV_DACSR_DBR_48;
		bm = RV_DACSR_DBM_2;
		break;
	case 11025:
		br = RV_DACSR_DBR_44_1;
		bm = RV_DACSR_DBM_PT25;
		break;
	case 22050:
		br = RV_DACSR_DBR_44_1;
		bm = RV_DACSR_DBM_PT5;
		break;
	case 44100:
		br = RV_DACSR_DBR_44_1;
		bm = RV_DACSR_DBM_1;
		break;
	case 88200:
		br = RV_DACSR_DBR_44_1;
		bm = RV_DACSR_DBM_2;
		break;
	default:
		dev_err(codec->dev, "%s(): Unsupported sample rate", __func__);
		return -EINVAL;
		break;
	}

	ret = snd_soc_update_bits(
		codec, 
		R_DACSR, 
		RM_DACSR_DBR|RM_DACSR_DBM, 
		br|bm);
	if (ret < 0) {
		dev_err (codec->dev, "Failed to update register: %d", ret);
		return ret;
	}
	ret = snd_soc_update_bits(
		codec, 
		R_ADCSR, 
		RM_ADCSR_ABR|RM_ADCSR_ABM, 
		br|bm);
	if (ret < 0) {
		dev_err (codec->dev, "Failed to update register: %d", ret);
		return ret;
	}

	data->samplerate = rate;

	mdelay(100);

	return 0;
}

struct reg_setting {
	char addr;
	char val;
};

#define PLL_REG_SETTINGS_COUNT 9
struct pll_ctl {
	int input_freq;
	struct reg_setting settings[PLL_REG_SETTINGS_COUNT];
};

static const struct pll_ctl pll_ctls[] = {
	{
		.input_freq = 25000000,
		.settings = {
			{ 0x58, 0x32 },
			{ 0x59, 0x09 },
			{ 0x5A, 0x10 },
			{ 0x5B, 0x32 },
			{ 0x5C, 0x60 },
			{ 0x5D, 0x03 },
			{ 0x5E, 0x1A },
			{ 0x60, 0x02 },
			{ 0x77, 0x61 },
		},
	},
};

static const struct pll_ctl *get_pll_ctl(int input_freq)
{
	int i;
	const struct pll_ctl *pll_ctl = NULL;

	for (i = 0; i < ARRAY_SIZE(pll_ctls); ++i)
		if (input_freq == pll_ctls[i].input_freq) {
			pll_ctl = &pll_ctls[i];
			break;
		}

	return pll_ctl;
}

static int 
sample_rate_to_pll_freq_out(struct snd_soc_codec *codec, int sample_rate)
{
	switch (sample_rate) {
	case 11025:
	case 22050:
	case 44100:
	case 88200:
		return 112896000;
	case 8000:
	case 16000:
	case 32000:
	case 48000:
	case 96000:
		return 122880000;
	default:
		dev_err(codec->dev, "Unsupported sample rate");
		return -EINVAL;
	}
}


static int set_pll_ctl_from_input_freq(struct snd_soc_codec *codec, 
		const int input_freq)
{
	int ret, i;
	const struct pll_ctl *pll_ctl;

	pll_ctl = get_pll_ctl(input_freq);
	if (NULL == pll_ctl) {
		dev_err(codec->dev, "No PLL input entry for %d", input_freq);
		return -EINVAL;
	}

	for (i = 0; i < PLL_REG_SETTINGS_COUNT; ++i) {
		ret = snd_soc_write(codec, pll_ctl->settings[i].addr, 
			pll_ctl->settings[i].val); 
		if (ret < 0) {
			dev_err(codec->dev, "Failed to set pll ctl: %d", ret);
			return ret;
		}
	}

	return 0;
}

static int configure_clocks(struct snd_soc_codec *codec)
{
	struct acs422x_priv *data = snd_soc_codec_get_drvdata(codec);
	int ret;

	ret = clk_prepare_enable(data->mclk);
	if (ret < 0) {
		dev_err(codec->dev, "Failed to enable mclk: %d", ret);
		return ret;
	}

	ret = set_pll_ctl_from_input_freq(codec, data->mclk_src_freq);
	if (ret < 0) {
		dev_err(codec->dev, "Failed to setup PLL input");
		return ret;
	}

	return 0;
}

static int power_down_audio_plls(struct snd_soc_codec *codec)
{
	int ret;

	ret = snd_soc_update_bits(
			codec, 
			R_PLLCTL1C, 
			RM_PLLCTL1C_PDB_PLL1|
			RM_PLLCTL1C_PDB_PLL2|
			RM_PLLCTL1C_PDB_PLL3,
			RV_PLLCTL1C_PDB_PLL1_OFF|
			RV_PLLCTL1C_PDB_PLL2_OFF|
			RV_PLLCTL1C_PDB_PLL3_OFF);
	if (ret < 0) {
		dev_err(codec->dev, "Failed to turn PLL off");
		return ret;
	}

	return 0;
}

static int power_up_audio_plls(struct snd_soc_codec *codec)
{
	struct acs422x_priv *data = snd_soc_codec_get_drvdata(codec);
	int freq_out;
	int ret;
	unsigned int mask, val;

	freq_out = sample_rate_to_pll_freq_out(codec, data->samplerate);
	switch (freq_out) {
	case 122880000: // 48k
		mask = RM_PLLCTL1C_PDB_PLL1;
		val = RV_PLLCTL1C_PDB_PLL1_ON; 
		break;
	case 112896000: // 44.1k
		mask = RM_PLLCTL1C_PDB_PLL2;
		val = RV_PLLCTL1C_PDB_PLL2_ON; 
		break;
	default:
		return -EINVAL;
		break;
	}

	ret = snd_soc_update_bits(
		codec, 
		R_PLLCTL1C, 
		mask | RM_PLLCTL1C_PDB_PLL3, // PLL1 and 2 depend on PLL3
		val | RV_PLLCTL1C_PDB_PLL3_ON);
	if (ret < 0) {
		dev_err(codec->dev, "Failed to turn PLL on");
		return ret;
	}

	return 0;
}

static int acs422x_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *params,
			    struct snd_soc_dai *codec_dai)
{
	struct snd_soc_codec *codec = codec_dai->codec;
        int ret;

	ret = setup_sample_format(codec, params_format(params));
	if (ret < 0) {
		dev_err(codec->dev, "Failed to setup sample format");
		return ret;
	}

	ret = setup_sample_rate(codec, params_rate(params));
	if (ret < 0) {
		dev_err(codec->dev, "Failed to setup sample rate");
		return ret;
	}

	return 0;
}

static int acs422x_mute_stream(struct snd_soc_dai *dai, int mute, int stream)
{
	int ret;
	unsigned int reg, mask, val;
	struct snd_soc_codec *codec = dai->codec;

	if (!mute) {
		ret = power_up_audio_plls(codec);
		if (ret < 0) {
			dev_err(codec->dev, "Failed to setup PLLs");
			return ret;
		}

		if (!plls_locked(codec)) {
			dev_err(codec->dev, "Failed to lock plls");
			return -1;
		}
	}

	if (SNDRV_PCM_STREAM_PLAYBACK == stream) {
		reg = R_CNVRTR1;
		mask = RM_CNVRTR1_DACMU;
		if (mute)
			val = RV_CNVRTR1_DACMU_ENABLE;
		else
			val = RV_CNVRTR1_DACMU_DISABLE;
	} else {
		reg = R_CNVRTR0;
		mask = RM_CNVRTR0_ADCMU;
		if (mute)
			val = RV_CNVRTR0_ADCMU_ENABLE;
		else
			val = RV_CNVRTR0_ADCMU_DISABLE;
	}

	if (SNDRV_PCM_STREAM_CAPTURE == stream)
		mdelay(50);

	// DAC mute used by HP and SPK path 
	ret = snd_soc_update_bits(codec, reg, mask, val);
	if (ret < 0) {
		dev_err(codec->dev, "Failed to %s %s",
				mute ? "mute": "unmute",
				stream ? "ADC":"DAC");
		return ret;
	}

	if (mute) {
		ret = power_down_audio_plls(codec);
		if (ret < 0) {
			dev_err(codec->dev, "Failed to power down plls");
			return ret;
		}
	}

	return 0;
}

static int acs422x_set_dai_fmt(struct snd_soc_dai *codec_dai,
		unsigned int fmt)
{
	struct snd_soc_codec *codec = codec_dai->codec;
	int ret;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		ret = snd_soc_update_bits(codec, R_AIC1, RM_AIC1_MS, 
				RV_AIC1_MS_MASTER);
		if (ret < 0) {
			dev_err(codec->dev, "Failed to set codec DAI master");
			return ret;
		}
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		dev_err(codec->dev, "acs422x slave mode not supported");
		return -EINVAL;
		break;
	default:
		dev_err(codec->dev, "Unsupported format");
		return -EINVAL;
	}

	return 0;
}

static int acs422x_set_bclk_ratio(struct snd_soc_dai *codec_dai, 
		unsigned int ratio)
{
	struct snd_soc_codec *codec = codec_dai->codec;
	struct acs422x_priv *acs422x = snd_soc_codec_get_drvdata(codec);
	unsigned int dac_val, adc_val;
	int ret;
	
	switch (ratio) {
	case 32:
		dac_val = RV_DACSR_DBCM_32;
		adc_val = RV_ADCSR_ABCM_32;
		break;
	case 40:
		dac_val = RV_DACSR_DBCM_40;
		adc_val = RV_ADCSR_ABCM_40;
		break;
	case 64:
		dac_val = RV_DACSR_DBCM_64;
		adc_val = RV_ADCSR_ABCM_64;
		break;
	default:
		dev_err(codec->dev, "Unsupported bclk ratio");
		return -EINVAL;
		break;
	}

	ret = snd_soc_update_bits(codec, R_DACSR, RM_DACSR_DBCM, dac_val); 
	if (ret < 0) {
		dev_err(codec->dev, "Failed to set DAC BCLK ratio");
		return ret;
	}
	ret = snd_soc_update_bits(codec, R_ADCSR, RM_ADCSR_ABCM, adc_val); 
	if (ret < 0) {
		dev_err(codec->dev, "Failed to set ADC BCLK ratio");
		return ret;
	}

	acs422x->bclk_ratio = ratio;

	return 0;
}

static const struct snd_soc_dai_ops acs422x_dai_ops = {
	.hw_params	= acs422x_hw_params,
	.mute_stream	= acs422x_mute_stream,
	.set_fmt	= acs422x_set_dai_fmt,
	.set_bclk_ratio = acs422x_set_bclk_ratio,
};

static struct snd_soc_dai_driver acs422x_dai = {
	.name = "acs422x-HiFi",
	.playback = {
		.stream_name = "HiFi Playback",
		.channels_min = 2,
		.channels_max = 2,
		.rates = ACS422WV_RATES,
		.formats = ACS422WV_FORMATS,},
	.capture = {
		.stream_name = "HiFi Capture",
		.channels_min = 2,
		.channels_max = 2,
		.rates = ACS422WV_RATES,
		.formats = ACS422WV_FORMATS,},
	.ops = &acs422x_dai_ops,
	.symmetric_rates = 1,
};

static int acs422x_i2c_read(struct i2c_client *i2c, u8 reg, u8 *val)
{
	int ret;

	ret = i2c_smbus_write_byte(i2c, reg);	
	if (ret < 0) {
		dev_err(&i2c->dev, "I2C write failed");
		return ret;
	}

	ret = i2c_smbus_read_byte(i2c);
	if (ret < 0) {
		dev_err(&i2c->dev, "I2C read failed");
		return ret;
	}

	*val = (u8)ret;

	return 0;
}

static int part_is_valid(struct i2c_client *i2c)
{
	int val, ret;
	u8 reg;	

	ret = acs422x_i2c_read(i2c, R_DEVIDH, &reg);	
	if (ret < 0) 
		goto exit;

	val = reg << 8;
	ret = acs422x_i2c_read(i2c, R_DEVIDL, &reg);	
	if (ret < 0) 
		goto exit;
	
	val |= reg;

	switch (val) {
		case 0x2260:
		case 0x2267:
		case 0x2268:
			ret = true;
			break;
		default:
			ret = false;
			break;
	};

	if (ret)
		dev_info(&i2c->dev, "Found part 0x%04x", val);
	else
		dev_err(&i2c->dev, "0x%04x is not a valid part", val);

exit:
	return ret;
}

static int set_data_from_of(struct i2c_client *i2c,
		struct acs422x_priv *data)
{
	struct device_node *np = i2c->dev.of_node;
	const char *mclk_src = NULL;
	int ret;

	ret = of_property_read_string(np, "mclk-src", &mclk_src);
	if (ret) {
		dev_err(&i2c->dev, "mclk-src is needed");
		return ret;
	}

	if (!strncmp(mclk_src, "mclk", 4)) {	
		data->mclk = devm_clk_get(&i2c->dev, NULL);
		if (IS_ERR(data->mclk)) {
			dev_info(&i2c->dev, "mclk not present trying again");
			return -EPROBE_DEFER;
		}
	} else if (!strncmp(mclk_src, "xtal", 4)) {
		data->mclk_src_is_xtal = true;
	} else {
		dev_err(&i2c->dev, "mclk-src %s is unsupported", mclk_src);
		return -EINVAL;
	}

	ret = of_property_read_u32(np, "mclk-src-freq", 
			&data->mclk_src_freq);
	if (ret) {
		dev_err(&i2c->dev, "mclk-src-freq not provided");
		return ret;
	} else {
		if (NULL == get_pll_ctl(data->mclk_src_freq)) {
			dev_err(&i2c->dev, "mclk frequency unsupported");
			return ret; 
		}
	}

	return 0;
}

static int acs422x_probe(struct snd_soc_codec *codec)
{
	struct acs422x_priv *data = snd_soc_codec_get_drvdata(codec);
	int i, ret;

	data->codec = codec;

	ret = configure_clocks(codec);
	if (ret < 0) {
		dev_err(codec->dev, "Failed to configure clocks");
		return ret;
	}

	for (i = 0; i < ARRAY_SIZE(r_inits); ++i) {
		ret = snd_soc_write(codec, r_inits[i].reg, r_inits[i].def); 
		if (ret) {
			dev_err(codec->dev, 
					"Failed to write reg inits to codec");
			return ret;
		}
	}

	/* This could fail if user has not installed fw */
	load_dac_coefficient_ram(codec);

	return  0;
}

static int acs422x_remove(struct snd_soc_codec *codec)
{
	return 0;
}
static struct snd_soc_codec_driver soc_codec_dev_acs422x = {
	.probe =	acs422x_probe,
	.remove =	acs422x_remove,
	.component_driver = {
		.dapm_widgets = acs422x_dapm_widgets,
		.num_dapm_widgets = ARRAY_SIZE(acs422x_dapm_widgets),
		.dapm_routes = acs422x_intercon,
		.num_dapm_routes = ARRAY_SIZE(acs422x_intercon),
		.controls =	acs422x_snd_controls,
		.num_controls = ARRAY_SIZE(acs422x_snd_controls),
	},
};

static int acs422x_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct acs422x_priv *data;
	int ret;

	data = (struct acs422x_priv *) devm_kzalloc(&i2c->dev, 
			sizeof(*data), GFP_KERNEL);
	if (NULL == data)
		return -ENOMEM;

	mutex_init(&data->lock);	

	ret = set_data_from_of(i2c, data);
	if (ret < 0) {
		dev_err(&i2c->dev, "Error parsing device tree info");
		return ret;
	}

	/* I2C depends on MCLK  to part */
	ret = clk_prepare_enable(data->mclk);
	if (ret < 0) {
		dev_err(&i2c->dev, "Failed to enable mclk: %d", ret);
		return ret;
	}

	ret = part_is_valid(i2c);	
	if (ret < 0) {
		dev_info(&i2c->dev, "Reading part number failed. Trying again.");
		return -EPROBE_DEFER;
	} else if (false == ret) {
		dev_err(&i2c->dev, "Part is not valid");
		return -ENODEV;
	}

	/* Reset device */
	ret = i2c_smbus_write_byte_data(i2c, R_RESET, RV_RESET_PWR_ON_DEFAULTS);
	if (ret < 0) {
		dev_err(&i2c->dev, "Failed to reset device");
		return ret;
	}
	mdelay(1);

	data->regmap = devm_regmap_init_i2c(i2c, &acs422x_regmap);
	if (IS_ERR(data->regmap)) {
		ret = PTR_ERR(data->regmap);
		dev_err(&i2c->dev, "Failed to allocat regmap: %d\n", ret);
		return ret;
	}

	i2c_set_clientdata(i2c, data);

	ret = snd_soc_register_codec(&i2c->dev, &soc_codec_dev_acs422x, 
			&acs422x_dai, 1);
	if (ret) {
		dev_err(&i2c->dev, "Failed to register codec\n");
		return ret;
	}

	return 0;
}

static int acs422x_i2c_remove(struct i2c_client *client)
{
	snd_soc_unregister_codec(&client->dev);

	return 0;
}

#ifdef CONFIG_PM
static int acs422x_runtime_resume(struct device *dev)
{
	struct acs422x_priv *data = dev_get_drvdata(dev);
	int ret;

	ret = configure_clocks(data->codec);
	if (ret < 0) {
		dev_err(dev, "Failed to reconfigure clocks");
		return ret;
	}

	return 0;
}

static int acs422x_runtime_suspend(struct device *dev)
{
	struct acs422x_priv *data = dev_get_drvdata(dev);

	if (!data->mclk_src_is_xtal)
		clk_disable_unprepare(data->mclk);

	return 0;
}
#endif

static struct dev_pm_ops acs422x_pm = {
	SET_RUNTIME_PM_OPS(acs422x_runtime_suspend, acs422x_runtime_resume, NULL)
};

static const struct i2c_device_id acs422x_i2c_id[] = {
	{ "acs422x", 0 },
	{ }
};
MODULE_DEVICE_TABLE(i2c, acs422x_i2c_id);

static const struct of_device_id acs422x_of_match[] = {
	{ .compatible = "acs,acs422x", },
	{ }
};
MODULE_DEVICE_TABLE(of, acs422x_of_match);

static struct i2c_driver acs422x_i2c_driver = {
	.driver = {
		.name = "acs422x",
		.owner = THIS_MODULE,
		.of_match_table = acs422x_of_match,
		.pm = &acs422x_pm,
	},
	.probe =    acs422x_i2c_probe,
	.remove =   acs422x_i2c_remove,
	.id_table = acs422x_i2c_id,
};

static int __init acs422x_modinit(void)
{
	int ret = 0;

	ret = i2c_add_driver(&acs422x_i2c_driver);
	if (ret < 0) {
		printk(KERN_ERR "Failed to register ACS422wv I2C driver: %d\n",
		       ret);
	}

	return ret;
}
module_init(acs422x_modinit);

static void __exit acs422x_exit(void)
{
	i2c_del_driver(&acs422x_i2c_driver);
}
module_exit(acs422x_exit);

MODULE_AUTHOR("Tempo Semiconductor <steven.eckhoff.opensource@gmail.com");
MODULE_DESCRIPTION("ASoC ACS422wv driver");
MODULE_LICENSE("GPL");
