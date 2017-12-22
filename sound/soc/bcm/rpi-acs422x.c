/*
 * ASoC Driver for ACS422wv  
 *
 * Author:	Steven W. Eckhoff <steven.eckhoff.opensource@gmail.com>	
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 */

#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/kernel.h>
#include <linux/clk.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/gpio.h>
#include <linux/slab.h>
#include <linux/delay.h>

#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/soc.h>
#include <sound/jack.h>

#include "../codecs/acs422x.h"

#define DEBUG_ACS
#ifdef DEBUG_ACS
#define debug(str, ...) printk(KERN_INFO "%s(): " str "\n", __func__, ##__VA_ARGS__)
#else
#define debug(str, ...) 
#endif

struct snd_rpi_acs422x_priv {
	int gpio_hp;
	int gpio_hp_active_low;
	struct snd_kcontrol *headphone_kctl;
	int gpio_mic;
	int gpio_mic_active_low;
	struct snd_kcontrol *analog_mic_kctl;
	//struct snd_kcontrol *line_in_kctl;
	struct snd_soc_codec *codec;
};

static struct snd_soc_jack hp_jack;
static struct snd_soc_jack_pin hp_jack_pins[] = {
	{
		.pin = "Headphone Jack",
		.mask = SND_JACK_HEADPHONE,
		.invert = false,
	},
};
static struct snd_soc_jack_gpio hp_jack_gpio = {
	.name = "Headphone Detect",
	.report = SND_JACK_HEADPHONE,
	.debounce_time = 150,
	.invert = 0,
};

static struct snd_soc_jack mic_jack;
static struct snd_soc_jack_pin mic_jack_pins[] = {
	{
		.pin = "Analog Mic",
		.mask = SND_JACK_MICROPHONE,
		.invert = false,
	},
};
static struct snd_soc_jack_gpio mic_jack_gpio = {
	.name = "Mic Detect",
	.report = SND_JACK_MICROPHONE,
	.debounce_time = 150,
	.invert = 0,
};

static int hp_jack_status_check(void *cb_data)
{
	struct snd_rpi_acs422x_priv *data = 
			(struct snd_rpi_acs422x_priv *)cb_data; 
	int ret, hp_status;
	
	hp_status = gpio_get_value(data->gpio_hp) ? 1 : 0;
	hp_status = (hp_status << 1) | data->gpio_hp_active_low;
	switch (hp_status) {
	case 0:
		ret = 0;
		break;
	case 1: /* Enable */
		ret = hp_jack_gpio.report;
		break;
	case 2: /* Enable */
		ret = hp_jack_gpio.report;
		break;
	case 3:
		ret = 0;	
		break;
	}

	if (ret == hp_jack_gpio.report) {
		if (snd_soc_dapm_disable_pin(&data->codec->component.dapm, 
				"Speaker") < 0)
			dev_warn(data->codec->dev, 
					"Failed to disable Speaker");
	} else {
		if (snd_soc_dapm_enable_pin(&data->codec->component.dapm, 
				"Speaker") < 0)
			dev_warn(data->codec->dev, 
					"Failed to enable Speaker");
	}

	return ret;
}

static int mic_jack_status_check(void *cb_data)
{
	struct snd_rpi_acs422x_priv *data = 
			(struct snd_rpi_acs422x_priv *)cb_data; 
	int ret, mic_status;

	mic_status = gpio_get_value(data->gpio_mic) ? 1 : 0;
	mic_status = (mic_status << 1) | data->gpio_mic_active_low;
	switch (mic_status) {
	case 0:
		ret = 0;
		break;
	case 1: /* Enable */
		ret = mic_jack_gpio.report;
		break;
	case 2: /* Enable */
		ret = mic_jack_gpio.report;
		break;
	case 3:
		ret = 0;	
		break;
	}

	if (ret == mic_jack_gpio.report) {
		/* Analog Mic */
		if (snd_soc_update_bits(data->codec, R_INSELL, 
				RM_INSELL, RV_INSELL_IN1) < 0)
			dev_err(data->codec->dev, "Failed to select analog mic");
		if (snd_soc_update_bits(data->codec, R_INSELR, 
				RM_INSELR, RV_INSELR_IN1) < 0)
			dev_err(data->codec->dev, "Failed to select analog mic");
	} else {
		/* Digital Mic */
		if (snd_soc_update_bits(data->codec, R_INSELL, 
				RM_INSELL, RV_INSELL_IN3) < 0)
			dev_err(data->codec->dev, "Failed to select digital mic");
		if (snd_soc_update_bits(data->codec, R_INSELR, 
				RM_INSELR, RV_INSELR_IN3) < 0)
			dev_err(data->codec->dev, "Failed to select digital mic");
	}

	return ret;
}
	
/* codec/machine specific init */
static int snd_rpi_acs422x_init(struct snd_soc_pcm_runtime *rtd)
{
	int ret;

	debug("");

	ret = snd_soc_dai_set_bclk_ratio(rtd->codec_dai, 64);
	if (ret < 0) {
		dev_err(rtd->codec->dev, "Failed to set codec bclk ratio");
		return ret;
	}

	ret = snd_soc_dai_set_bclk_ratio(rtd->cpu_dai, 64);
	if (ret < 0) {
		dev_err(rtd->codec->dev, "Failed to set the cpu dai bclk ratio");
		return ret;
	}

	return 0;
}

static struct snd_soc_dai_link snd_rpi_acs422x_dai[1] = {
	{
		.name		= "RPi ACS422WV",
		.stream_name	= "RPi ACS422WV HiFi",
		.cpu_dai_name	= "bcm2708-i2s.0",
		.codec_dai_name	= "acs422x-HiFi",
		.platform_name	= "bcm2708-i2s.0",
		.dai_fmt	= SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF |
					SND_SOC_DAIFMT_CBM_CFM,
		.init		= snd_rpi_acs422x_init,
	},
};

/* Widgets */
static const struct snd_soc_dapm_widget rpi_acs422x_dapm_widgets[] = {
	SND_SOC_DAPM_SPK("Speaker", NULL),
	SND_SOC_DAPM_HP("Headphone Jack", NULL),
	SND_SOC_DAPM_MIC("Analog Mic", NULL),
	SND_SOC_DAPM_MIC("Digital Mic", NULL),
	SND_SOC_DAPM_INPUT("Line In"),
};

/* Routes */
static const struct snd_soc_dapm_route rpi_acs422x_intercon[] = {
	{"Headphone Jack", NULL, "HP_L"},
	{"Headphone Jack", NULL, "HP_R"},
	{"Speaker", NULL, "SPK_L"},
	{"Speaker", NULL, "SPK_R"},
	{"DMIC_L", NULL, "Digital Mic"},
	{"DMIC_R", NULL, "Digital Mic"},
	{"AMIC1_L", NULL, "Analog Mic"},
	{"AMIC1_R", NULL, "Analog Mic"},
	{"LIN2_L", NULL, "Line In"},
	{"LIN2_R", NULL, "Line In"},
};

/* audio machine driver */
static struct snd_soc_card snd_rpi_acs422x = {
	.name         = "snd_rpi_acs422x",
	.dai_link     = snd_rpi_acs422x_dai,
	.num_links    = ARRAY_SIZE(snd_rpi_acs422x_dai),

	.dapm_widgets = rpi_acs422x_dapm_widgets,
	.num_dapm_widgets = ARRAY_SIZE(rpi_acs422x_dapm_widgets),
	.dapm_routes = rpi_acs422x_intercon,
	.num_dapm_routes = ARRAY_SIZE(rpi_acs422x_intercon),
        .fully_routed = true,
};

static int snd_rpi_acs422x_probe(struct platform_device *pdev)
{
	int ret = 0;
	struct snd_rpi_acs422x_priv *data;
	struct device_node *i2s_node;
	struct snd_soc_dai_link *dai;
	struct device_node *codec_of_node;

	debug("");

	if (NULL == pdev->dev.of_node)
		return -ENODEV;

	data = (struct snd_rpi_acs422x_priv *) devm_kzalloc(&pdev->dev, 
			sizeof(*data), GFP_KERNEL);
	if (NULL == data)
		return -ENOMEM;

	snd_soc_card_set_drvdata(&snd_rpi_acs422x, data);

	snd_rpi_acs422x.dev = &pdev->dev;

	dai = &snd_rpi_acs422x_dai[0];
	i2s_node = of_parse_phandle(pdev->dev.of_node,
			"i2s-controller", 0);

	if (i2s_node) {
		dai->cpu_dai_name = NULL;
		dai->cpu_of_node = i2s_node;
		dai->platform_name = NULL;
		dai->platform_of_node = i2s_node;
	}

	codec_of_node = of_parse_phandle(pdev->dev.of_node,
			"audio-codec", 0);	
	if (codec_of_node)
		dai->codec_of_node = codec_of_node;
	else
		dev_err(&pdev->dev,
				"Failed to get codec_of_node");

	ret = snd_soc_register_card(&snd_rpi_acs422x);
	if (ret) {
		dev_err(&pdev->dev,
			"snd_soc_register_card() failed: %d\n", ret);
		return -EPROBE_DEFER;
	}
	data->codec = (struct snd_soc_codec *) 
		list_first_entry_or_null(&snd_rpi_acs422x.codec_dev_list,
						struct snd_soc_card,
						codec_dev_list);

	/* Headphone Jack */
	data->gpio_hp = of_get_named_gpio_flags(pdev->dev.of_node,
			"hp-gpios", 0, 
			(enum of_gpio_flags *)&data->gpio_hp_active_low);	

	debug("hp gpio active low = %d", data->gpio_hp_active_low);

	if (!gpio_is_valid(data->gpio_hp)) {
		dev_err(&pdev->dev, "Failed to get headphone detect gpio");
		return -EINVAL;
	}

	ret = snd_soc_card_jack_new(&snd_rpi_acs422x, "Headphone Jack",
			SND_JACK_HEADPHONE, &hp_jack,
			hp_jack_pins, 
			ARRAY_SIZE(hp_jack_pins));	
	if (ret < 0) {
		dev_err(&pdev->dev, 
				"Failed to create Headphone Jack (%d)", 
				ret);
		return ret;
	}
	hp_jack_gpio.gpio = data->gpio_hp;
	hp_jack_gpio.data = data;
	hp_jack_gpio.jack_status_check = hp_jack_status_check;
	ret = snd_soc_jack_add_gpios(&hp_jack, 1, &hp_jack_gpio);
	if (ret < 0) {
		dev_err(&pdev->dev, 
				"Failed set GPIOs for Headphone Jack (%d)", 
				ret);
		return ret;
	}

	/* Mic Jack */
	data->gpio_mic = of_get_named_gpio_flags(pdev->dev.of_node,
			"mic-gpios", 0, 
			(enum of_gpio_flags *)&data->gpio_mic_active_low);	

	debug("mic gpio active low = %d", data->gpio_mic_active_low);

	if (!gpio_is_valid(data->gpio_mic)) {
		dev_err(&pdev->dev, "Failed to get mic detect gpio");
		return -EINVAL;
	}

	ret = snd_soc_card_jack_new(&snd_rpi_acs422x, "Mic Jack",
			SND_JACK_HEADPHONE, &mic_jack,
			mic_jack_pins, 
			ARRAY_SIZE(mic_jack_pins));	
	if (ret < 0) {
		dev_err(&pdev->dev, 
				"Failed to create Mic Jack (%d)", 
				ret);
		return ret;
	}
	mic_jack_gpio.gpio = data->gpio_mic;
	mic_jack_gpio.data = data;
	mic_jack_gpio.jack_status_check = mic_jack_status_check;
	ret = snd_soc_jack_add_gpios(&mic_jack, 1, &mic_jack_gpio);
	if (ret < 0) {
		dev_err(&pdev->dev, 
				"Failed set GPIOs for Mic Jack (%d)", 
				ret);
		return ret;
	}

	return ret;
}

static int snd_rpi_acs422x_remove(struct platform_device *pdev)
{
	debug("");

	return snd_soc_unregister_card(&snd_rpi_acs422x);
}

static const struct of_device_id snd_rpi_acs422x_of_match[] = {
	{ .compatible = "rpi-acs,rpi-acs422x", },
	{},
};
MODULE_DEVICE_TABLE(of, snd_rpi_acs422x_of_match);

static struct platform_driver snd_rpi_acs422x_driver = {
	.driver = {
		.name   = "snd-rpi-acs422x",
		.owner  = THIS_MODULE,
		.of_match_table = snd_rpi_acs422x_of_match,
	},
	.probe          = snd_rpi_acs422x_probe,
	.remove         = snd_rpi_acs422x_remove,
};

module_platform_driver(snd_rpi_acs422x_driver);

MODULE_AUTHOR("Tempo Semiconductor: Steven W. Eckhoff <steven.eckhoff.opensource@gmail.com>");
MODULE_DESCRIPTION("ASoC Driver for ACS422wv");
MODULE_LICENSE("GPL v2");
