#ifndef __WOLVERINE_H__
#define __WOLVERINE_H__

#define R_HPVOLL        0x0 
#define R_HPVOLR        0x1 
#define R_SPKVOLL       0x2 
#define R_SPKVOLR       0x3 
#define R_DACVOLL       0x4 
#define R_DACVOLR       0x5 
#define R_ADCVOLL       0x6 
#define R_ADCVOLR       0x7 
#define R_INVOLL        0x8 
#define R_INVOLR        0x9 
#define R_VUCTL         0x0A
#define R_INMODE        0x0B
#define R_INSELL        0x0C
#define R_INSELR        0x0D
#define R_ALC0          0x0E
#define R_ALC1          0x0F
#define R_ALC2          0x10
#define R_ALC3          0x11
#define R_NGATE         0x12
#define R_AIC1          0x13
#define R_AIC2          0x14
#define R_AIC3          0x15
#define R_CNVRTR0       0x16
#define R_ADCSR         0x17
#define R_CNVRTR1       0x18
#define R_DACSR         0x19
#define R_PWRM1         0x1A
#define R_PWRM2         0x1B
#define R_CTL           0x1C
#define R_THERMTS       0x1D
#define R_THERMSPKR1    0x1E
#define R_CONFIG0       0x1F
#define R_CONFIG1       0x20
#define R_GAINCTL       0x21
#define R_COP1          0x22
#define R_COP2          0x23
#define R_DMICCTL       0x24
#define R_CLECTL        0x25
#define R_MUGAIN        0x26
#define R_COMPTH        0x27
#define R_CMPRAT        0x28
#define R_CATKTCL       0x29
#define R_CATKTCH       0x2A
#define R_CRELTCL       0x2B
#define R_CRELTCH       0x2C
#define R_LIMTH         0x2D
#define R_LIMTGT        0x2E
#define R_LATKTCL       0x2F
#define R_LATKTCH       0x30
#define R_LRELTCL       0x31
#define R_LRELTCH       0x32
#define R_EXPTH         0x33
#define R_EXPRAT        0x34
#define R_XATKTCL       0x35
#define R_XATKTCH       0x36
#define R_XRELTCL       0x37
#define R_XRELTCH       0x38
#define R_FXCTL         0x39
#define R_DACCRWRL      0x3A
#define R_DACCRWRM      0x3B
#define R_DACCRWRH      0x3C
#define R_DACCRRDL      0x3D
#define R_DACCRRDM      0x3E
#define R_DACCRRDH      0x3F
#define R_DACCRADDR     0x40
#define R_DCOFSEL       0x41
#define R_PWM0          0x42
#define R_PWM1          0x43
#define R_PWM2          0x44
#define R_PWM3          0x45
#define R_PLLCTL1       0x46
#define R_PLLCTL2       0x47
#define R_PLLCTL3       0x48
#define R_PLLCTL4       0x49
#define R_PLLCTL5       0x4A
#define R_PLLCTL6       0x4B
#define R_PLLCTL7       0x4C
#define R_PLLCTL8       0x4D
#define R_PLLCTL9       0x4E
#define R_PLLCTLA       0x4F
#define R_PLLCTLB       0x50
#define R_PLLCTLC       0x51
#define R_PLLCTLD       0x52
#define R_PLLCTLE       0x53
#define R_PLLCTLF       0x54
#define R_PLLCTL10      0x55
#define R_PLLCTL11      0x56
#define R_PLLCTL12      0x57
#define R_PLLCTL13      0x58
#define R_PLLCTL14      0x59
#define R_PLLCTL15      0x5A
#define R_PLLCTL16      0x5B
#define R_PLLCTL17      0x5C
#define R_PLLCTL18      0x5D
#define R_PLLCTL19      0x5E
#define R_PLLCTL1A      0x5F
#define R_PLLCTL1B      0x60
#define R_PLLCTL1C      0x61
#define R_PLLCTL1D      0x62
#define R_PLLCTL1E      0x63
#define R_PLLCTL1F      0x64
#define R_PLLCTL20      0x65
#define R_PLLCTL21      0x66
#define R_PLLCTL22      0x67
#define R_DTEST0        0x68
#define R_DTEST1        0x69
#define R_ATEST0        0x6A
#define R_ATEST1        0x6B
#define R_ATEST2        0x6C
#define R_ATEST3        0x6D
#define R_ATEST4        0x6E
#define R_ATEST5        0x6F
#define R_ATEST6        0x70
#define R_ATEST7        0x71
#define R_ATEST8        0x72
#define R_ATEST9        0x73
#define R_ATEST10       0x74
#define R_ATEST11       0x75
#define R_ATEST12       0x76
#define R_TIMEBASE      0x77
#define R_MFG0          0x78
#define R_MFG1          0x79
#define R_MFG2          0x7A
#define R_MFG3          0x7B
#define R_DEVADR        0x7C
#define R_DEVIDL        0x7D
#define R_DEVIDH        0x7E
#define R_REVID         0x7F
#define R_RESET         0x80
#define R_THERMSPKR2    0x88
#define R_COP3          0x89
#define R_DACCRSTAT     0x8A
#define R_HPDETSTAT     0x8B
#define R_ADCALCSTAT    0x8C
#define R_SDSTAT        0x8D
#define R_PLLCTL0       0x8E
#define R_BISTCTL       0x90
#define R_BISTSTAT1     0x91
#define R_BISTSTAT2     0x92
#define R_BISTSTAT3     0x93
#define R_BISTSTAT4     0x94
#define R_BISTSTAT5     0x95
#define R_ATEST13       0xA0
#define R_ATEST14       0xA1
#define R_ATEST15       0xA2


/* Helpers */
#define RM(m,b) ((m)<<(b))
#define RV(v,b) ((v)<<(b))


/****************************
 *      R_HPVOLL (0x0)      *
 ****************************/

/* Field Offsets */
#define FB_HPVOLL                            0                                  

/* Field Masks */
#define FM_HPVOLL                            0X7F                               

/* Field Values */
#define FV_HPVOLL_P6DB                       0x7F                               
#define FV_HPVOLL_N88PT5DB                   0x1                                
#define FV_HPVOLL_MUTE                       0x0                                

/* Register Default */
#define RD_HPVOLL                            0x0                                

/* Register Masks */
#define RM_HPVOLL                            RM(FM_HPVOLL, FB_HPVOLL)           

/* Register Values */
#define RV_HPVOLL_P6DB                       RV(FV_HPVOLL_P6DB, FB_HPVOLL)      
#define RV_HPVOLL_N88PT5DB                   RV(FV_HPVOLL_N88PT5DB, FB_HPVOLL)  
#define RV_HPVOLL_MUTE                       RV(FV_HPVOLL_MUTE, FB_HPVOLL)      


/****************************
 *      R_HPVOLR (0x1)      *
 ****************************/

/* Field Offsets */
#define FB_HPVOLR                            0                                  

/* Field Masks */
#define FM_HPVOLR                            0X7F                               

/* Field Values */
#define FV_HPVOLR_P6DB                       0x7F                               
#define FV_HPVOLR_N88PT5DB                   0x1                                
#define FV_HPVOLR_MUTE                       0x0                                

/* Register Default */
#define RD_HPVOLR                            0x0                                

/* Register Masks */
#define RM_HPVOLR                            RM(FM_HPVOLR, FB_HPVOLR)           

/* Register Values */
#define RV_HPVOLR_P6DB                       RV(FV_HPVOLR_P6DB, FB_HPVOLR)      
#define RV_HPVOLR_N88PT5DB                   RV(FV_HPVOLR_N88PT5DB, FB_HPVOLR)  
#define RV_HPVOLR_MUTE                       RV(FV_HPVOLR_MUTE, FB_HPVOLR)      


/*****************************
 *      R_SPKVOLL (0x2)      *
 *****************************/

/* Field Offsets */
#define FB_SPKVOLL                           0                                  

/* Field Masks */
#define FM_SPKVOLL                           0X7F                               

/* Field Values */
#define FV_SPKVOLL_P12DB                     0x7F                               
#define FV_SPKVOLL_N77PT25DB                 0x8                                
#define FV_SPKVOLL_MUTE                      0x0                                

/* Register Default */
#define RD_SPKVOLL                           0x0                                

/* Register Masks */
#define RM_SPKVOLL                           RM(FM_SPKVOLL, FB_SPKVOLL)         

/* Register Values */
#define RV_SPKVOLL_P12DB                     RV(FV_SPKVOLL_P12DB, FB_SPKVOLL)   
#define RV_SPKVOLL_N77PT25DB                 RV(FV_SPKVOLL_N77PT25DB, FB_SPKVOLL)
#define RV_SPKVOLL_MUTE                      RV(FV_SPKVOLL_MUTE, FB_SPKVOLL)    


/*****************************
 *      R_SPKVOLR (0x3)      *
 *****************************/

/* Field Offsets */
#define FB_SPKVOLR                           0                                  

/* Field Masks */
#define FM_SPKVOLR                           0X7F                               

/* Field Values */
#define FV_SPKVOLR_P12DB                     0x7F                               
#define FV_SPKVOLR_N77PT25DB                 0x8                                
#define FV_SPKVOLR_MUTE                      0x0                                

/* Register Default */
#define RD_SPKVOLR                           0x0                                

/* Register Masks */
#define RM_SPKVOLR                           RM(FM_SPKVOLR, FB_SPKVOLR)         

/* Register Values */
#define RV_SPKVOLR_P12DB                     RV(FV_SPKVOLR_P12DB, FB_SPKVOLR)   
#define RV_SPKVOLR_N77PT25DB                 RV(FV_SPKVOLR_N77PT25DB, FB_SPKVOLR)
#define RV_SPKVOLR_MUTE                      RV(FV_SPKVOLR_MUTE, FB_SPKVOLR)    


/*****************************
 *      R_DACVOLL (0x4)      *
 *****************************/

/* Field Offsets */
#define FB_DACVOLL                           0                                  

/* Field Masks */
#define FM_DACVOLL                           0XFF                               

/* Field Values */
#define FV_DACVOLL_0DB                       0xFF                               
#define FV_DACVOLL_N95PT625DB                0x1                                
#define FV_DACVOLL_MUTE                      0x0                                

/* Register Default */
#define RD_DACVOLL                           0xFF                               

/* Register Masks */
#define RM_DACVOLL                           RM(FM_DACVOLL, FB_DACVOLL)         

/* Register Values */
#define RV_DACVOLL_0DB                       RV(FV_DACVOLL_0DB, FB_DACVOLL)     
#define RV_DACVOLL_N95PT625DB                RV(FV_DACVOLL_N95PT625DB, FB_DACVOLL)
#define RV_DACVOLL_MUTE                      RV(FV_DACVOLL_MUTE, FB_DACVOLL)    


/*****************************
 *      R_DACVOLR (0x5)      *
 *****************************/

/* Field Offsets */
#define FB_DACVOLR                           0                                  

/* Field Masks */
#define FM_DACVOLR                           0XFF                               

/* Field Values */
#define FV_DACVOLR_0DB                       0xFF                               
#define FV_DACVOLR_N95PT625DB                0x1                                
#define FV_DACVOLR_MUTE                      0x0                                

/* Register Default */
#define RD_DACVOLR                           0xFF                               

/* Register Masks */
#define RM_DACVOLR                           RM(FM_DACVOLR, FB_DACVOLR)         

/* Register Values */
#define RV_DACVOLR_0DB                       RV(FV_DACVOLR_0DB, FB_DACVOLR)     
#define RV_DACVOLR_N95PT625DB                RV(FV_DACVOLR_N95PT625DB, FB_DACVOLR)
#define RV_DACVOLR_MUTE                      RV(FV_DACVOLR_MUTE, FB_DACVOLR)    


/*****************************
 *      R_ADCVOLL (0x6)      *
 *****************************/

/* Field Offsets */
#define FB_ADCVOLL                           0                                  

/* Field Masks */
#define FM_ADCVOLL                           0XFF                               

/* Field Values */
#define FV_ADCVOLL_P24DB                     0xFF                               
#define FV_ADCVOLL_N71PT25DB                 0x1                                
#define FV_ADCVOLL_MUTE                      0x0                                

/* Register Default */
#define RD_ADCVOLL                           0xBF                               

/* Register Masks */
#define RM_ADCVOLL                           RM(FM_ADCVOLL, FB_ADCVOLL)         

/* Register Values */
#define RV_ADCVOLL_P24DB                     RV(FV_ADCVOLL_P24DB, FB_ADCVOLL)   
#define RV_ADCVOLL_N71PT25DB                 RV(FV_ADCVOLL_N71PT25DB, FB_ADCVOLL)
#define RV_ADCVOLL_MUTE                      RV(FV_ADCVOLL_MUTE, FB_ADCVOLL)    


/*****************************
 *      R_ADCVOLR (0x7)      *
 *****************************/

/* Field Offsets */
#define FB_ADCVOLR                           0                                  

/* Field Masks */
#define FM_ADCVOLR                           0XFF                               

/* Field Values */
#define FV_ADCVOLR_P24DB                     0xFF                               
#define FV_ADCVOLR_N71PT25DB                 0x1                                
#define FV_ADCVOLR_MUTE                      0x0                                

/* Register Default */
#define RD_ADCVOLR                           0xBF                               

/* Register Masks */
#define RM_ADCVOLR                           RM(FM_ADCVOLR, FB_ADCVOLR)         

/* Register Values */
#define RV_ADCVOLR_P24DB                     RV(FV_ADCVOLR_P24DB, FB_ADCVOLR)   
#define RV_ADCVOLR_N71PT25DB                 RV(FV_ADCVOLR_N71PT25DB, FB_ADCVOLR)
#define RV_ADCVOLR_MUTE                      RV(FV_ADCVOLR_MUTE, FB_ADCVOLR)    


/****************************
 *      R_INVOLL (0x8)      *
 ****************************/

/* Field Offsets */
#define FB_INVOLL_INMUTEL                    7                                  
#define FB_INVOLL_IZCL                       6                                  
#define FB_INVOLL                            0                                  

/* Field Masks */
#define FM_INVOLL_INMUTEL                    0X1                                
#define FM_INVOLL_IZCL                       0X1                                
#define FM_INVOLL                            0X3F                               

/* Field Values */
#define FV_INVOLL_INMUTEL_ENABLE             0x1                                
#define FV_INVOLL_INMUTEL_DISABLE            0x0                                
#define FV_INVOLL_IZCL_ENABLE                0x1                                
#define FV_INVOLL_IZCL_DISABLE               0x0                                
#define FV_INVOLL_P30DB                      0x3F                               
#define FV_INVOLL_N17PT25DB                  0x0                                

/* Register Default */
#define RD_INVOLL                            0x0                                

/* Register Masks */
#define RM_INVOLL_INMUTEL                    RM(FM_INVOLL_INMUTEL, FB_INVOLL_INMUTEL)
#define RM_INVOLL_IZCL                       RM(FM_INVOLL_IZCL, FB_INVOLL_IZCL) 
#define RM_INVOLL                            RM(FM_INVOLL, FB_INVOLL)           

/* Register Values */
#define RV_INVOLL_INMUTEL_ENABLE             RV(FV_INVOLL_INMUTEL_ENABLE, FB_INVOLL_INMUTEL)
#define RV_INVOLL_INMUTEL_DISABLE            RV(FV_INVOLL_INMUTEL_DISABLE, FB_INVOLL_INMUTEL)
#define RV_INVOLL_IZCL_ENABLE                RV(FV_INVOLL_IZCL_ENABLE, FB_INVOLL_IZCL)
#define RV_INVOLL_IZCL_DISABLE               RV(FV_INVOLL_IZCL_DISABLE, FB_INVOLL_IZCL)
#define RV_INVOLL_P30DB                      RV(FV_INVOLL_P30DB, FB_INVOLL)     
#define RV_INVOLL_N17PT25DB                  RV(FV_INVOLL_N17PT25DB, FB_INVOLL) 


/****************************
 *      R_INVOLR (0x9)      *
 ****************************/

/* Field Offsets */
#define FB_INVOLR_INMUTER                    7                                  
#define FB_INVOLR_IZCR                       6                                  
#define FB_INVOLR                            0                                  

/* Field Masks */
#define FM_INVOLR_INMUTER                    0X1                                
#define FM_INVOLR_IZCR                       0X1                                
#define FM_INVOLR                            0X3F                               

/* Field Values */
#define FV_INVOLR_INMUTER_ENABLE             0x1                                
#define FV_INVOLR_INMUTER_DISABLE            0x0                                
#define FV_INVOLR_IZCR_ENABLE                0x1                                
#define FV_INVOLR_IZCR_DISABLE               0x0                                
#define FV_INVOLR_P30DB                      0x3F                               
#define FV_INVOLR_N17PT25DB                  0x0                                

/* Register Default */
#define RD_INVOLR                            0x0                                

/* Register Masks */
#define RM_INVOLR_INMUTER                    RM(FM_INVOLR_INMUTER, FB_INVOLR_INMUTER)
#define RM_INVOLR_IZCR                       RM(FM_INVOLR_IZCR, FB_INVOLR_IZCR) 
#define RM_INVOLR                            RM(FM_INVOLR, FB_INVOLR)           

/* Register Values */
#define RV_INVOLR_INMUTER_ENABLE             RV(FV_INVOLR_INMUTER_ENABLE, FB_INVOLR_INMUTER)
#define RV_INVOLR_INMUTER_DISABLE            RV(FV_INVOLR_INMUTER_DISABLE, FB_INVOLR_INMUTER)
#define RV_INVOLR_IZCR_ENABLE                RV(FV_INVOLR_IZCR_ENABLE, FB_INVOLR_IZCR)
#define RV_INVOLR_IZCR_DISABLE               RV(FV_INVOLR_IZCR_DISABLE, FB_INVOLR_IZCR)
#define RV_INVOLR_P30DB                      RV(FV_INVOLR_P30DB, FB_INVOLR)     
#define RV_INVOLR_N17PT25DB                  RV(FV_INVOLR_N17PT25DB, FB_INVOLR) 


/****************************
 *      R_VUCTL (0x0A)      *
 ****************************/

/* Field Offsets */
#define FB_VUCTL_ADCFADE                     7                                  
#define FB_VUCTL_DACFADE                     6                                  
#define FB_VUCTL_INVOLU                      4                                  
#define FB_VUCTL_ADCVOLU                     3                                  
#define FB_VUCTL_DACVOLU                     2                                  
#define FB_VUCTL_SPKVOLU                     1                                  
#define FB_VUCTL_HPVOLU                      0                                  

/* Field Masks */
#define FM_VUCTL_ADCFADE                     0X1                                
#define FM_VUCTL_DACFADE                     0X1                                
#define FM_VUCTL_INVOLU                      0X1                                
#define FM_VUCTL_ADCVOLU                     0X1                                
#define FM_VUCTL_DACVOLU                     0X1                                
#define FM_VUCTL_SPKVOLU                     0X1                                
#define FM_VUCTL_HPVOLU                      0X1                                

/* Field Values */
#define FV_VUCTL_ADCFADE_ENABLE              0x1                                
#define FV_VUCTL_ADCFADE_DISABLE             0x0                                
#define FV_VUCTL_DACFADE_ENABLE              0x1                                
#define FV_VUCTL_DACFADE_DISABLE             0x0                                
#define FV_VUCTL_INVOLU_ENABLE               0x1                                
#define FV_VUCTL_INVOLU_DISABLE              0x0                                
#define FV_VUCTL_ADCVOLU_ENABLE              0x1                                
#define FV_VUCTL_ADCVOLU_DISABLE             0x0                                
#define FV_VUCTL_DACVOLU_ENABLE              0x1                                
#define FV_VUCTL_DACVOLU_DISABLE             0x0                                
#define FV_VUCTL_SPKVOLU_ENABLE              0x1                                
#define FV_VUCTL_SPKVOLU_DISABLE             0x0                                
#define FV_VUCTL_HPVOLU_ENABLE               0x1                                
#define FV_VUCTL_HPVOLU_DISABLE              0x0                                

/* Register Default */
#define RD_VUCTL                             0x1                                

/* Register Masks */
#define RM_VUCTL_ADCFADE                     RM(FM_VUCTL_ADCFADE, FB_VUCTL_ADCFADE)
#define RM_VUCTL_DACFADE                     RM(FM_VUCTL_DACFADE, FB_VUCTL_DACFADE)
#define RM_VUCTL_INVOLU                      RM(FM_VUCTL_INVOLU, FB_VUCTL_INVOLU)
#define RM_VUCTL_ADCVOLU                     RM(FM_VUCTL_ADCVOLU, FB_VUCTL_ADCVOLU)
#define RM_VUCTL_DACVOLU                     RM(FM_VUCTL_DACVOLU, FB_VUCTL_DACVOLU)
#define RM_VUCTL_SPKVOLU                     RM(FM_VUCTL_SPKVOLU, FB_VUCTL_SPKVOLU)
#define RM_VUCTL_HPVOLU                      RM(FM_VUCTL_HPVOLU, FB_VUCTL_HPVOLU)

/* Register Values */
#define RV_VUCTL_ADCFADE_ENABLE              RV(FV_VUCTL_ADCFADE_ENABLE, FB_VUCTL_ADCFADE)
#define RV_VUCTL_ADCFADE_DISABLE             RV(FV_VUCTL_ADCFADE_DISABLE, FB_VUCTL_ADCFADE)
#define RV_VUCTL_DACFADE_ENABLE              RV(FV_VUCTL_DACFADE_ENABLE, FB_VUCTL_DACFADE)
#define RV_VUCTL_DACFADE_DISABLE             RV(FV_VUCTL_DACFADE_DISABLE, FB_VUCTL_DACFADE)
#define RV_VUCTL_INVOLU_ENABLE               RV(FV_VUCTL_INVOLU_ENABLE, FB_VUCTL_INVOLU)
#define RV_VUCTL_INVOLU_DISABLE              RV(FV_VUCTL_INVOLU_DISABLE, FB_VUCTL_INVOLU)
#define RV_VUCTL_ADCVOLU_ENABLE              RV(FV_VUCTL_ADCVOLU_ENABLE, FB_VUCTL_ADCVOLU)
#define RV_VUCTL_ADCVOLU_DISABLE             RV(FV_VUCTL_ADCVOLU_DISABLE, FB_VUCTL_ADCVOLU)
#define RV_VUCTL_DACVOLU_ENABLE              RV(FV_VUCTL_DACVOLU_ENABLE, FB_VUCTL_DACVOLU)
#define RV_VUCTL_DACVOLU_DISABLE             RV(FV_VUCTL_DACVOLU_DISABLE, FB_VUCTL_DACVOLU)
#define RV_VUCTL_SPKVOLU_ENABLE              RV(FV_VUCTL_SPKVOLU_ENABLE, FB_VUCTL_SPKVOLU)
#define RV_VUCTL_SPKVOLU_DISABLE             RV(FV_VUCTL_SPKVOLU_DISABLE, FB_VUCTL_SPKVOLU)
#define RV_VUCTL_HPVOLU_ENABLE               RV(FV_VUCTL_HPVOLU_ENABLE, FB_VUCTL_HPVOLU)
#define RV_VUCTL_HPVOLU_DISABLE              RV(FV_VUCTL_HPVOLU_DISABLE, FB_VUCTL_HPVOLU)


/*****************************
 *      R_INMODE (0x0B)      *
 *****************************/

/* Field Offsets */
#define FB_INMODE_DS                         0                                  

/* Field Masks */
#define FM_INMODE_DS                         0X1                                

/* Field Values */
#define FV_INMODE_DS_LRIN1                   0x0                                
#define FV_INMODE_DS_LRIN2                   0x1                                

/* Register Default */
#define RD_INMODE                            0x0                                

/* Register Masks */
#define RM_INMODE_DS                         RM(FM_INMODE_DS, FB_INMODE_DS)     

/* Register Values */
#define RV_INMODE_DS_LRIN1                   RV(FV_INMODE_DS_LRIN1, FB_INMODE_DS)
#define RV_INMODE_DS_LRIN2                   RV(FV_INMODE_DS_LRIN2, FB_INMODE_DS)


/*****************************
 *      R_INSELL (0x0C)      *
 *****************************/

/* Field Offsets */
#define FB_INSELL                            6                                  
#define FB_INSELL_MICBSTL                    4                                  

/* Field Masks */
#define FM_INSELL                            0X3                                
#define FM_INSELL_MICBSTL                    0X3                                

/* Field Values */
#define FV_INSELL_IN1                        0x0                                
#define FV_INSELL_IN2                        0x1                                
#define FV_INSELL_IN3                        0x2                                
#define FV_INSELL_D2S                        0x3                                
#define FV_INSELL_MICBSTL_OFF                0x0                                
#define FV_INSELL_MICBSTL_10DB               0x1                                
#define FV_INSELL_MICBSTL_20DB               0x2                                
#define FV_INSELL_MICBSTL_30DB               0x3                                

/* Register Default */
#define RD_INSELL                            0x0                                

/* Register Masks */
#define RM_INSELL                            RM(FM_INSELL, FB_INSELL)           
#define RM_INSELL_MICBSTL                    RM(FM_INSELL_MICBSTL, FB_INSELL_MICBSTL)

/* Register Values */
#define RV_INSELL_IN1                        RV(FV_INSELL_IN1, FB_INSELL)       
#define RV_INSELL_IN2                        RV(FV_INSELL_IN2, FB_INSELL)       
#define RV_INSELL_IN3                        RV(FV_INSELL_IN3, FB_INSELL)       
#define RV_INSELL_D2S                        RV(FV_INSELL_D2S, FB_INSELL)       
#define RV_INSELL_MICBSTL_OFF                RV(FV_INSELL_MICBSTL_OFF, FB_INSELL_MICBSTL)
#define RV_INSELL_MICBSTL_10DB               RV(FV_INSELL_MICBSTL_10DB, FB_INSELL_MICBSTL)
#define RV_INSELL_MICBSTL_20DB               RV(FV_INSELL_MICBSTL_20DB, FB_INSELL_MICBSTL)
#define RV_INSELL_MICBSTL_30DB               RV(FV_INSELL_MICBSTL_30DB, FB_INSELL_MICBSTL)


/*****************************
 *      R_INSELR (0x0D)      *
 *****************************/

/* Field Offsets */
#define FB_INSELR                            6                                  
#define FB_INSELR_MICBSTR                    4                                  

/* Field Masks */
#define FM_INSELR                            0X3                                
#define FM_INSELR_MICBSTR                    0X3                                

/* Field Values */
#define FV_INSELR_IN1                        0x0                                
#define FV_INSELR_IN2                        0x1                                
#define FV_INSELR_IN3                        0x2                                
#define FV_INSELR_D2S                        0x3                                
#define FV_INSELR_MICBSTR_OFF                0x0                                
#define FV_INSELR_MICBSTR_10DB               0x1                                
#define FV_INSELR_MICBSTR_20DB               0x2                                
#define FV_INSELR_MICBSTR_30DB               0x3                                

/* Register Default */
#define RD_INSELR                            0x0                                

/* Register Masks */
#define RM_INSELR                            RM(FM_INSELR, FB_INSELR)           
#define RM_INSELR_MICBSTR                    RM(FM_INSELR_MICBSTR, FB_INSELR_MICBSTR)

/* Register Values */
#define RV_INSELR_IN1                        RV(FV_INSELR_IN1, FB_INSELR)       
#define RV_INSELR_IN2                        RV(FV_INSELR_IN2, FB_INSELR)       
#define RV_INSELR_IN3                        RV(FV_INSELR_IN3, FB_INSELR)       
#define RV_INSELR_D2S                        RV(FV_INSELR_D2S, FB_INSELR)       
#define RV_INSELR_MICBSTR_OFF                RV(FV_INSELR_MICBSTR_OFF, FB_INSELR_MICBSTR)
#define RV_INSELR_MICBSTR_10DB               RV(FV_INSELR_MICBSTR_10DB, FB_INSELR_MICBSTR)
#define RV_INSELR_MICBSTR_20DB               RV(FV_INSELR_MICBSTR_20DB, FB_INSELR_MICBSTR)
#define RV_INSELR_MICBSTR_30DB               RV(FV_INSELR_MICBSTR_30DB, FB_INSELR_MICBSTR)


/***************************
 *      R_ALC0 (0x0E)      *
 ***************************/

/* Field Offsets */
#define FB_ALC0_ALCMODE                      2                                  
#define FB_ALC0_ALCSEL                       0                                  

/* Field Masks */
#define FM_ALC0_ALCMODE                      0X1                                
#define FM_ALC0_ALCSEL                       0X3                                

/* Field Values */
#define FV_ALC0_ALCMODE_ALC                  0x0                                
#define FV_ALC0_ALCMODE_LIMITER              0x1                                
#define FV_ALC0_ALCSEL_OFF                   0x0                                
#define FV_ALC0_ALCSEL_RIGHT                 0x1                                
#define FV_ALC0_ALCSEL_LEFT                  0x2                                
#define FV_ALC0_ALCSEL_STEREO                0x3                                

/* Register Default */
#define RD_ALC0                              0x0                                

/* Register Masks */
#define RM_ALC0_ALCMODE                      RM(FM_ALC0_ALCMODE, FB_ALC0_ALCMODE)
#define RM_ALC0_ALCSEL                       RM(FM_ALC0_ALCSEL, FB_ALC0_ALCSEL) 

/* Register Values */
#define RV_ALC0_ALCMODE_ALC                  RV(FV_ALC0_ALCMODE_ALC, FB_ALC0_ALCMODE)
#define RV_ALC0_ALCMODE_LIMITER              RV(FV_ALC0_ALCMODE_LIMITER, FB_ALC0_ALCMODE)
#define RV_ALC0_ALCSEL_OFF                   RV(FV_ALC0_ALCSEL_OFF, FB_ALC0_ALCSEL)
#define RV_ALC0_ALCSEL_RIGHT                 RV(FV_ALC0_ALCSEL_RIGHT, FB_ALC0_ALCSEL)
#define RV_ALC0_ALCSEL_LEFT                  RV(FV_ALC0_ALCSEL_LEFT, FB_ALC0_ALCSEL)
#define RV_ALC0_ALCSEL_STEREO                RV(FV_ALC0_ALCSEL_STEREO, FB_ALC0_ALCSEL)


/***************************
 *      R_ALC1 (0x0F)      *
 ***************************/

/* Field Offsets */
#define FB_ALC1_MAXGAIN                      4                                  
#define FB_ALC1_ALCL                         0                                  

/* Field Masks */
#define FM_ALC1_MAXGAIN                      0X7                                
#define FM_ALC1_ALCL                         0XF                                

/* Field Values */
#define FV_ALC1_MAXGAIN_P30DB                0x7F                               
#define FV_ALC1_MAXGAIN_N12DB                0x0                                
#define FV_ALC1_ALCL_N6DBFS                  0xF                                
#define FV_ALC1_ALCL_N28PT5DBFS              0x0                                

/* Register Default */
#define RD_ALC1                              0x0                                

/* Register Masks */
#define RM_ALC1_MAXGAIN                      RM(FM_ALC1_MAXGAIN, FB_ALC1_MAXGAIN)
#define RM_ALC1_ALCL                         RM(FM_ALC1_ALCL, FB_ALC1_ALCL)     

/* Register Values */
#define RV_ALC1_MAXGAIN_P30DB                RV(FV_ALC1_MAXGAIN_P30DB, FB_ALC1_MAXGAIN)
#define RV_ALC1_MAXGAIN_N12DB                RV(FV_ALC1_MAXGAIN_N12DB, FB_ALC1_MAXGAIN)
#define RV_ALC1_ALCL_N6DBFS                  RV(FV_ALC1_ALCL_N6DBFS, FB_ALC1_ALCL)
#define RV_ALC1_ALCL_N28PT5DBFS              RV(FV_ALC1_ALCL_N28PT5DBFS, FB_ALC1_ALCL)


/***************************
 *      R_ALC2 (0x10)      *
 ***************************/

/* Field Offsets */
#define FB_ALC2_MINGAIN                      4                                  
#define FB_ALC2_HLD                          0                                  

/* Field Masks */
#define FM_ALC2_MINGAIN                      0X7                                
#define FM_ALC2_HLD                          0XF                                

/* Field Values */
#define FV_ALC2_MINGAIN_P24PT75DB            0x7                                
#define FV_ALC2_MINGAIN_N17PT25DB            0x0                                
#define FV_ALC2_HLD_0MS                      0x0                                
#define FV_ALC2_HLD_2PT67MS                  0x1                                
#define FV_ALC2_HLD_43PT691MS                0xF                                

/* Register Default */
#define RD_ALC2                              0x0                                

/* Register Masks */
#define RM_ALC2_MINGAIN                      RM(FM_ALC2_MINGAIN, FB_ALC2_MINGAIN)
#define RM_ALC2_HLD                          RM(FM_ALC2_HLD, FB_ALC2_HLD)       

/* Register Values */
#define RV_ALC2_MINGAIN_P24PT75DB            RV(FV_ALC2_MINGAIN_P24PT75DB, FB_ALC2_MINGAIN)
#define RV_ALC2_MINGAIN_N17PT25DB            RV(FV_ALC2_MINGAIN_N17PT25DB, FB_ALC2_MINGAIN)
#define RV_ALC2_HLD_0MS                      RV(FV_ALC2_HLD_0MS, FB_ALC2_HLD)   
#define RV_ALC2_HLD_2PT67MS                  RV(FV_ALC2_HLD_2PT67MS, FB_ALC2_HLD)
#define RV_ALC2_HLD_43PT691MS                RV(FV_ALC2_HLD_43PT691MS, FB_ALC2_HLD)


/***************************
 *      R_ALC3 (0x11)      *
 ***************************/

/* Field Offsets */
#define FB_ALC3_DCY                          4                                  
#define FB_ALC3_ATK                          0                                  

/* Field Masks */
#define FM_ALC3_DCY                          0XF                                
#define FM_ALC3_ATK                          0XF                                

/* Field Values */
#define FV_ALC3_DCY_21PT33MS                 0x0                                
#define FV_ALC3_DCY_42PT67MS                 0x1                                
#define FV_ALC3_DCY_21PT85S                  0xA                                
#define FV_ALC3_ATK_5PT33MS                  0x0                                
#define FV_ALC3_ATK_10PT67MS                 0x1                                
#define FV_ALC3_ATK_5PT46S                   0xA                                

/* Register Default */
#define RD_ALC3                              0x3                                

/* Register Masks */
#define RM_ALC3_DCY                          RM(FM_ALC3_DCY, FB_ALC3_DCY)       
#define RM_ALC3_ATK                          RM(FM_ALC3_ATK, FB_ALC3_ATK)       

/* Register Values */
#define RV_ALC3_DCY_21PT33MS                 RV(FV_ALC3_DCY_21PT33MS, FB_ALC3_DCY)
#define RV_ALC3_DCY_42PT67MS                 RV(FV_ALC3_DCY_42PT67MS, FB_ALC3_DCY)
#define RV_ALC3_DCY_21PT85S                  RV(FV_ALC3_DCY_21PT85S, FB_ALC3_DCY)
#define RV_ALC3_ATK_5PT33MS                  RV(FV_ALC3_ATK_5PT33MS, FB_ALC3_ATK)
#define RV_ALC3_ATK_10PT67MS                 RV(FV_ALC3_ATK_10PT67MS, FB_ALC3_ATK)
#define RV_ALC3_ATK_5PT46S                   RV(FV_ALC3_ATK_5PT46S, FB_ALC3_ATK)


/****************************
 *      R_NGATE (0x12)      *
 ****************************/

/* Field Offsets */
#define FB_NGATE_NGTH                        3                                  
#define FB_NGATE_NGG                         1                                  
#define FB_NGATE                             0                                  

/* Field Masks */
#define FM_NGATE_NGTH                        0X1F                               
#define FM_NGATE_NGG                         0X3                                
#define FM_NGATE                             0X1                                

/* Field Values */
#define FV_NGATE_NGTH_N30DBFS                0x1                                
#define FV_NGATE_NGTH_N76PT5DBFS             0x0                                
#define FV_NGATE_NGG_MUTE_ADC                0x1                                
#define FV_NGATE_NGG_CONSTANT                0x0                                
#define FV_NGATE_ENABLE                      0x1                                
#define FV_NGATE_DISABLE                     0x0                                

/* Register Default */
#define RD_NGATE                             0x0                                

/* Register Masks */
#define RM_NGATE_NGTH                        RM(FM_NGATE_NGTH, FB_NGATE_NGTH)   
#define RM_NGATE_NGG                         RM(FM_NGATE_NGG, FB_NGATE_NGG)     
#define RM_NGATE                             RM(FM_NGATE, FB_NGATE)             

/* Register Values */
#define RV_NGATE_NGTH_N30DBFS                RV(FV_NGATE_NGTH_N30DBFS, FB_NGATE_NGTH)
#define RV_NGATE_NGTH_N76PT5DBFS             RV(FV_NGATE_NGTH_N76PT5DBFS, FB_NGATE_NGTH)
#define RV_NGATE_NGG_MUTE_ADC                RV(FV_NGATE_NGG_MUTE_ADC, FB_NGATE_NGG)
#define RV_NGATE_NGG_CONSTANT                RV(FV_NGATE_NGG_CONSTANT, FB_NGATE_NGG)
#define RV_NGATE_ENABLE                      RV(FV_NGATE_ENABLE, FB_NGATE)      
#define RV_NGATE_DISABLE                     RV(FV_NGATE_DISABLE, FB_NGATE)     


/***************************
 *      R_AIC1 (0x13)      *
 ***************************/

/* Field Offsets */
#define FB_AIC1_BCLKINV                      6                                  
#define FB_AIC1_MS                           5                                  
#define FB_AIC1LRP                           4                                  
#define FB_AIC1_WL                           2                                  
#define FB_AIC1_FORMAT                       0                                  

/* Field Masks */
#define FM_AIC1_BCLKINV                      0X1                                
#define FM_AIC1_MS                           0X1                                
#define FM_AIC1LRP                           0X1                                
#define FM_AIC1_WL                           0X3                                
#define FM_AIC1_FORMAT                       0X3                                

/* Field Values */
#define FV_AIC1_BCLKINV_ENABLE               0x1                                
#define FV_AIC1_BCLKINV_DISABLE              0x0                                
#define FV_AIC1_MS_MASTER                    0x1                                
#define FV_AIC1_MS_SLAVE                     0x0                                
#define FV_AIC1LRP_INVERT                    0x1                                
#define FV_AIC1LRP_NORMAL                    0x0                                
#define FV_AIC1_WL_16                        0x0                                
#define FV_AIC1_WL_20                        0x1                                
#define FV_AIC1_WL_24                        0x2                                
#define FV_AIC1_WL_32                        0x3                                
#define FV_AIC1_FORMAT_RIGHT                 0x0                                
#define FV_AIC1_FORMAT_LEFT                  0x1                                
#define FV_AIC1_FORMAT_I2S                   0x2                                

/* Register Default */
#define RD_AIC1                              0x0                                

/* Register Masks */
#define RM_AIC1_BCLKINV                      RM(FM_AIC1_BCLKINV, FB_AIC1_BCLKINV)
#define RM_AIC1_MS                           RM(FM_AIC1_MS, FB_AIC1_MS)         
#define RM_AIC1LRP                           RM(FM_AIC1LRP, FB_AIC1LRP)         
#define RM_AIC1_WL                           RM(FM_AIC1_WL, FB_AIC1_WL)         
#define RM_AIC1_FORMAT                       RM(FM_AIC1_FORMAT, FB_AIC1_FORMAT) 

/* Register Values */
#define RV_AIC1_BCLKINV_ENABLE               RV(FV_AIC1_BCLKINV_ENABLE, FB_AIC1_BCLKINV)
#define RV_AIC1_BCLKINV_DISABLE              RV(FV_AIC1_BCLKINV_DISABLE, FB_AIC1_BCLKINV)
#define RV_AIC1_MS_MASTER                    RV(FV_AIC1_MS_MASTER, FB_AIC1_MS)  
#define RV_AIC1_MS_SLAVE                     RV(FV_AIC1_MS_SLAVE, FB_AIC1_MS)   
#define RV_AIC1LRP_INVERT                    RV(FV_AIC1LRP_INVERT, FB_AIC1LRP)  
#define RV_AIC1LRP_NORMAL                    RV(FV_AIC1LRP_NORMAL, FB_AIC1LRP)  
#define RV_AIC1_WL_16                        RV(FV_AIC1_WL_16, FB_AIC1_WL)      
#define RV_AIC1_WL_20                        RV(FV_AIC1_WL_20, FB_AIC1_WL)      
#define RV_AIC1_WL_24                        RV(FV_AIC1_WL_24, FB_AIC1_WL)      
#define RV_AIC1_WL_32                        RV(FV_AIC1_WL_32, FB_AIC1_WL)      
#define RV_AIC1_FORMAT_RIGHT                 RV(FV_AIC1_FORMAT_RIGHT, FB_AIC1_FORMAT)
#define RV_AIC1_FORMAT_LEFT                  RV(FV_AIC1_FORMAT_LEFT, FB_AIC1_FORMAT)
#define RV_AIC1_FORMAT_I2S                   RV(FV_AIC1_FORMAT_I2S, FB_AIC1_FORMAT)


/***************************
 *      R_AIC2 (0x14)      *
 ***************************/

/* Field Offsets */
#define FB_AIC2_DACDSEL                      6                                  
#define FB_AIC2_ADCDSEL                      4                                  
#define FB_AIC2_TRI                          3                                  
#define FB_AIC2_BLRCM                        0                                  

/* Field Masks */
#define FM_AIC2_DACDSEL                      0X3                                
#define FM_AIC2_ADCDSEL                      0X3                                
#define FM_AIC2_TRI                          0X1                                
#define FM_AIC2_BLRCM                        0X7                                

/* Field Values */
#define FV_AIC2_BLRCM_DAC_BCLK_LRCLK_SHARED  0x3                                

/* Register Default */
#define RD_AIC2                              0x0                                

/* Register Masks */
#define RM_AIC2_DACDSEL                      RM(FM_AIC2_DACDSEL, FB_AIC2_DACDSEL)
#define RM_AIC2_ADCDSEL                      RM(FM_AIC2_ADCDSEL, FB_AIC2_ADCDSEL)
#define RM_AIC2_TRI                          RM(FM_AIC2_TRI, FB_AIC2_TRI)       
#define RM_AIC2_BLRCM                        RM(FM_AIC2_BLRCM, FB_AIC2_BLRCM)   

/* Register Values */
#define RV_AIC2_BLRCM_DAC_BCLK_LRCLK_SHARED  RV(FV_AIC2_BLRCM_DAC_BCLK_LRCLK_SHARED, FB_AIC2_BLRCM)


/***************************
 *      R_AIC3 (0x15)      *
 ***************************/

/* Field Offsets */
#define FB_AIC3_ADOPDD                       5                                  
#define FB_AIC3_ALRPDD                       4                                  
#define FB_AIC3_ABCPDD                       3                                  
#define FB_AIC3_DDIPDD                       2                                  
#define FB_AIC3_DLRPDD                       1                                  
#define FB_AIC3_DBCPDD                       0                                  

/* Field Masks */
#define FM_AIC3_ADOPDD                       0X1                                
#define FM_AIC3_ALRPDD                       0X1                                
#define FM_AIC3_ABCPDD                       0X1                                
#define FM_AIC3_DDIPDD                       0X1                                
#define FM_AIC3_DLRPDD                       0X1                                
#define FM_AIC3_DBCPDD                       0X1                                

/* Field Values */
#define FV_AIC3_ADOPDD_DISABLE               0x1                                
#define FV_AIC3_ADOPDD_ENABLE                0x0                                
#define FV_AIC3_ALRPDD_DISABLE               0x1                                
#define FV_AIC3_ALRPDD_ENABLE                0x0                                
#define FV_AIC3_ABCPDD_DISABLE               0x1                                
#define FV_AIC3_ABCPDD_ENABLE                0x0                                
#define FV_AIC3_DDIPDD_DISABLE               0x1                                
#define FV_AIC3_DDIPDD_ENABLE                0x0                                
#define FV_AIC3_DLRPDD_DISABLE               0x1                                
#define FV_AIC3_DLRPDD_ENABLE                0x0                                
#define FV_AIC3_DBCPDD_DISABLE               0x1                                
#define FV_AIC3_DBCPDD_ENABLE                0x0                                

/* Register Default */
#define RD_AIC3                              0x0                                

/* Register Masks */
#define RM_AIC3_ADOPDD                       RM(FM_AIC3_ADOPDD, FB_AIC3_ADOPDD) 
#define RM_AIC3_ALRPDD                       RM(FM_AIC3_ALRPDD, FB_AIC3_ALRPDD) 
#define RM_AIC3_ABCPDD                       RM(FM_AIC3_ABCPDD, FB_AIC3_ABCPDD) 
#define RM_AIC3_DDIPDD                       RM(FM_AIC3_DDIPDD, FB_AIC3_DDIPDD) 
#define RM_AIC3_DLRPDD                       RM(FM_AIC3_DLRPDD, FB_AIC3_DLRPDD) 
#define RM_AIC3_DBCPDD                       RM(FM_AIC3_DBCPDD, FB_AIC3_DBCPDD) 

/* Register Values */
#define RV_AIC3_ADOPDD_DISABLE               RV(FV_AIC3_ADOPDD_DISABLE, FB_AIC3_ADOPDD)
#define RV_AIC3_ADOPDD_ENABLE                RV(FV_AIC3_ADOPDD_ENABLE, FB_AIC3_ADOPDD)
#define RV_AIC3_ALRPDD_DISABLE               RV(FV_AIC3_ALRPDD_DISABLE, FB_AIC3_ALRPDD)
#define RV_AIC3_ALRPDD_ENABLE                RV(FV_AIC3_ALRPDD_ENABLE, FB_AIC3_ALRPDD)
#define RV_AIC3_ABCPDD_DISABLE               RV(FV_AIC3_ABCPDD_DISABLE, FB_AIC3_ABCPDD)
#define RV_AIC3_ABCPDD_ENABLE                RV(FV_AIC3_ABCPDD_ENABLE, FB_AIC3_ABCPDD)
#define RV_AIC3_DDIPDD_DISABLE               RV(FV_AIC3_DDIPDD_DISABLE, FB_AIC3_DDIPDD)
#define RV_AIC3_DDIPDD_ENABLE                RV(FV_AIC3_DDIPDD_ENABLE, FB_AIC3_DDIPDD)
#define RV_AIC3_DLRPDD_DISABLE               RV(FV_AIC3_DLRPDD_DISABLE, FB_AIC3_DLRPDD)
#define RV_AIC3_DLRPDD_ENABLE                RV(FV_AIC3_DLRPDD_ENABLE, FB_AIC3_DLRPDD)
#define RV_AIC3_DBCPDD_DISABLE               RV(FV_AIC3_DBCPDD_DISABLE, FB_AIC3_DBCPDD)
#define RV_AIC3_DBCPDD_ENABLE                RV(FV_AIC3_DBCPDD_ENABLE, FB_AIC3_DBCPDD)


/******************************
 *      R_CNVRTR0 (0x16)      *
 ******************************/

/* Field Offsets */
#define FB_CNVRTR0_ADCPOLR                   7                                  
#define FB_CNVRTR0_ADCPOLL                   6                                  
#define FB_CNVRTR0_AMONOMIX                  4                                  
#define FB_CNVRTR0_ADCMU                     3                                  
#define FB_CNVRTR0_HPOR                      2                                  
#define FB_CNVRTR0_ADCHPDR                   1                                  
#define FB_CNVRTR0_ADCHPDL                   0                                  

/* Field Masks */
#define FM_CNVRTR0_ADCPOLR                   0X1                                
#define FM_CNVRTR0_ADCPOLL                   0X1                                
#define FM_CNVRTR0_AMONOMIX                  0X3                                
#define FM_CNVRTR0_ADCMU                     0X1                                
#define FM_CNVRTR0_HPOR                      0X1                                
#define FM_CNVRTR0_ADCHPDR                   0X1                                
#define FM_CNVRTR0_ADCHPDL                   0X1                                

/* Field Values */
#define FV_CNVRTR0_ADCPOLR_INVERT            0x1                                
#define FV_CNVRTR0_ADCPOLR_NORMAL            0x0                                
#define FV_CNVRTR0_ADCPOLL_INVERT            0x1                                
#define FV_CNVRTR0_ADCPOLL_NORMAL            0x0                                
#define FV_CNVRTR0_ADCMU_ENABLE              0x1                                
#define FV_CNVRTR0_ADCMU_DISABLE             0x0                                
#define FV_CNVRTR0_ADCHPDR_ENABLE            0x1                                
#define FV_CNVRTR0_ADCHPDR_DISABLE           0x0                                
#define FV_CNVRTR0_ADCHPDL_ENABLE            0x1                                
#define FV_CNVRTR0_ADCHPDL_DISABLE           0x0                                

/* Register Default */
#define RD_CNVRTR0                           0x0                                

/* Register Masks */
#define RM_CNVRTR0_ADCPOLR                   RM(FM_CNVRTR0_ADCPOLR, FB_CNVRTR0_ADCPOLR)
#define RM_CNVRTR0_ADCPOLL                   RM(FM_CNVRTR0_ADCPOLL, FB_CNVRTR0_ADCPOLL)
#define RM_CNVRTR0_AMONOMIX                  RM(FM_CNVRTR0_AMONOMIX, FB_CNVRTR0_AMONOMIX)
#define RM_CNVRTR0_ADCMU                     RM(FM_CNVRTR0_ADCMU, FB_CNVRTR0_ADCMU)
#define RM_CNVRTR0_HPOR                      RM(FM_CNVRTR0_HPOR, FB_CNVRTR0_HPOR)
#define RM_CNVRTR0_ADCHPDR                   RM(FM_CNVRTR0_ADCHPDR, FB_CNVRTR0_ADCHPDR)
#define RM_CNVRTR0_ADCHPDL                   RM(FM_CNVRTR0_ADCHPDL, FB_CNVRTR0_ADCHPDL)

/* Register Values */
#define RV_CNVRTR0_ADCPOLR_INVERT            RV(FV_CNVRTR0_ADCPOLR_INVERT, FB_CNVRTR0_ADCPOLR)
#define RV_CNVRTR0_ADCPOLR_NORMAL            RV(FV_CNVRTR0_ADCPOLR_NORMAL, FB_CNVRTR0_ADCPOLR)
#define RV_CNVRTR0_ADCPOLL_INVERT            RV(FV_CNVRTR0_ADCPOLL_INVERT, FB_CNVRTR0_ADCPOLL)
#define RV_CNVRTR0_ADCPOLL_NORMAL            RV(FV_CNVRTR0_ADCPOLL_NORMAL, FB_CNVRTR0_ADCPOLL)
#define RV_CNVRTR0_ADCMU_ENABLE              RV(FV_CNVRTR0_ADCMU_ENABLE, FB_CNVRTR0_ADCMU)
#define RV_CNVRTR0_ADCMU_DISABLE             RV(FV_CNVRTR0_ADCMU_DISABLE, FB_CNVRTR0_ADCMU)
#define RV_CNVRTR0_ADCHPDR_ENABLE            RV(FV_CNVRTR0_ADCHPDR_ENABLE, FB_CNVRTR0_ADCHPDR)
#define RV_CNVRTR0_ADCHPDR_DISABLE           RV(FV_CNVRTR0_ADCHPDR_DISABLE, FB_CNVRTR0_ADCHPDR)
#define RV_CNVRTR0_ADCHPDL_ENABLE            RV(FV_CNVRTR0_ADCHPDL_ENABLE, FB_CNVRTR0_ADCHPDL)
#define RV_CNVRTR0_ADCHPDL_DISABLE           RV(FV_CNVRTR0_ADCHPDL_DISABLE, FB_CNVRTR0_ADCHPDL)


/****************************
 *      R_ADCSR (0x17)      *
 ****************************/

/* Field Offsets */
#define FB_ADCSR_ABCM                        6                                  
#define FB_ADCSR_ABR                         3                                  
#define FB_ADCSR_ABM                         0                                  

/* Field Masks */
#define FM_ADCSR_ABCM                        0X3                                
#define FM_ADCSR_ABR                         0X3                                
#define FM_ADCSR_ABM                         0X7                                

/* Field Values */
#define FV_ADCSR_ABCM_AUTO                   0x0                                
#define FV_ADCSR_ABCM_32                     0x1                                
#define FV_ADCSR_ABCM_40                     0x2                                
#define FV_ADCSR_ABCM_64                     0x3                                
#define FV_ADCSR_ABR_32                      0x0                                
#define FV_ADCSR_ABR_44_1                    0x1                                
#define FV_ADCSR_ABR_48                      0x2                                
#define FV_ADCSR_ABM_PT25                    0x0                                
#define FV_ADCSR_ABM_PT5                     0x1                                
#define FV_ADCSR_ABM_1                       0x2                                
#define FV_ADCSR_ABM_2                       0x3                                

/* Register Default */
#define RD_ADCSR                             0x0                                

/* Register Masks */
#define RM_ADCSR_ABCM                        RM(FM_ADCSR_ABCM, FB_ADCSR_ABCM)   
#define RM_ADCSR_ABR                         RM(FM_ADCSR_ABR, FB_ADCSR_ABR)     
#define RM_ADCSR_ABM                         RM(FM_ADCSR_ABM, FB_ADCSR_ABM)     

/* Register Values */
#define RV_ADCSR_ABCM_AUTO                   RV(FV_ADCSR_ABCM_AUTO, FB_ADCSR_ABCM)
#define RV_ADCSR_ABCM_32                     RV(FV_ADCSR_ABCM_32, FB_ADCSR_ABCM)
#define RV_ADCSR_ABCM_40                     RV(FV_ADCSR_ABCM_40, FB_ADCSR_ABCM)
#define RV_ADCSR_ABCM_64                     RV(FV_ADCSR_ABCM_64, FB_ADCSR_ABCM)
#define RV_ADCSR_ABR_32                      RV(FV_ADCSR_ABR_32, FB_ADCSR_ABR)  
#define RV_ADCSR_ABR_44_1                    RV(FV_ADCSR_ABR_44_1, FB_ADCSR_ABR)
#define RV_ADCSR_ABR_48                      RV(FV_ADCSR_ABR_48, FB_ADCSR_ABR)  
#define RV_ADCSR_ABR_                        RV(FV_ADCSR_ABR_, FB_ADCSR_ABR)    
#define RV_ADCSR_ABM_PT25                    RV(FV_ADCSR_ABM_PT25, FB_ADCSR_ABM)
#define RV_ADCSR_ABM_PT5                     RV(FV_ADCSR_ABM_PT5, FB_ADCSR_ABM) 
#define RV_ADCSR_ABM_1                       RV(FV_ADCSR_ABM_1, FB_ADCSR_ABM)   
#define RV_ADCSR_ABM_2                       RV(FV_ADCSR_ABM_2, FB_ADCSR_ABM)   


/******************************
 *      R_CNVRTR1 (0x18)      *
 ******************************/

/* Field Offsets */
#define FB_CNVRTR1_DACPOLR                   7                                  
#define FB_CNVRTR1_DACPOLL                   6                                  
#define FB_CNVRTR1_DMONOMIX                  4                                  
#define FB_CNVRTR1_DACMU                     3                                  
#define FB_CNVRTR1_DEEMPH                    2                                  

/* Field Masks */
#define FM_CNVRTR1_DACPOLR                   0X1                                
#define FM_CNVRTR1_DACPOLL                   0X1                                
#define FM_CNVRTR1_DMONOMIX                  0X3                                
#define FM_CNVRTR1_DACMU                     0X1                                
#define FM_CNVRTR1_DEEMPH                    0X1                                

/* Field Values */
#define FV_CNVRTR1_DACPOLR_INVERT            0x1                                
#define FV_CNVRTR1_DACPOLR_NORMAL            0x0                                
#define FV_CNVRTR1_DACPOLL_INVERT            0x1                                
#define FV_CNVRTR1_DACPOLL_NORMAL            0x0                                
#define FV_CNVRTR1_DMONOMIX_ENABLE           0x1                                
#define FV_CNVRTR1_DMONOMIX_DISABLE          0x0                                
#define FV_CNVRTR1_DACMU_ENABLE              0x1                                
#define FV_CNVRTR1_DACMU_DISABLE             0x0                                

/* Register Default */
#define RD_CNVRTR1                           0x0                                

/* Register Masks */
#define RM_CNVRTR1_DACPOLR                   RM(FM_CNVRTR1_DACPOLR, FB_CNVRTR1_DACPOLR)
#define RM_CNVRTR1_DACPOLL                   RM(FM_CNVRTR1_DACPOLL, FB_CNVRTR1_DACPOLL)
#define RM_CNVRTR1_DMONOMIX                  RM(FM_CNVRTR1_DMONOMIX, FB_CNVRTR1_DMONOMIX)
#define RM_CNVRTR1_DACMU                     RM(FM_CNVRTR1_DACMU, FB_CNVRTR1_DACMU)
#define RM_CNVRTR1_DEEMPH                    RM(FM_CNVRTR1_DEEMPH, FB_CNVRTR1_DEEMPH)

/* Register Values */
#define RV_CNVRTR1_DACPOLR_INVERT            RV(FV_CNVRTR1_DACPOLR_INVERT, FB_CNVRTR1_DACPOLR)
#define RV_CNVRTR1_DACPOLR_NORMAL            RV(FV_CNVRTR1_DACPOLR_NORMAL, FB_CNVRTR1_DACPOLR)
#define RV_CNVRTR1_DACPOLL_INVERT            RV(FV_CNVRTR1_DACPOLL_INVERT, FB_CNVRTR1_DACPOLL)
#define RV_CNVRTR1_DACPOLL_NORMAL            RV(FV_CNVRTR1_DACPOLL_NORMAL, FB_CNVRTR1_DACPOLL)
#define RV_CNVRTR1_DMONOMIX_ENABLE           RV(FV_CNVRTR1_DMONOMIX_ENABLE, FB_CNVRTR1_DMONOMIX)
#define RV_CNVRTR1_DMONOMIX_DISABLE          RV(FV_CNVRTR1_DMONOMIX_DISABLE, FB_CNVRTR1_DMONOMIX)
#define RV_CNVRTR1_DACMU_ENABLE              RV(FV_CNVRTR1_DACMU_ENABLE, FB_CNVRTR1_DACMU)
#define RV_CNVRTR1_DACMU_DISABLE             RV(FV_CNVRTR1_DACMU_DISABLE, FB_CNVRTR1_DACMU)


/****************************
 *      R_DACSR (0x19)      *
 ****************************/

/* Field Offsets */
#define FB_DACSR_DBCM                        6                                  
#define FB_DACSR_DBR                         3                                  
#define FB_DACSR_DBM                         0                                  

/* Field Masks */
#define FM_DACSR_DBCM                        0X3                                
#define FM_DACSR_DBR                         0X3                                
#define FM_DACSR_DBM                         0X7                                

/* Field Values */
#define FV_DACSR_DBCM_AUTO                   0x0                                
#define FV_DACSR_DBCM_32                     0x1                                
#define FV_DACSR_DBCM_40                     0x2                                
#define FV_DACSR_DBCM_64                     0x3                                
#define FV_DACSR_DBR_32                      0x0                                
#define FV_DACSR_DBR_44_1                    0x1                                
#define FV_DACSR_DBR_48                      0x2                                
#define FV_DACSR_DBM_PT25                    0x0                                
#define FV_DACSR_DBM_PT5                     0x1                                
#define FV_DACSR_DBM_1                       0x2                                
#define FV_DACSR_DBM_2                       0x3                                

/* Register Default */
#define RD_DACSR                             0x0                                

/* Register Masks */
#define RM_DACSR_DBCM                        RM(FM_DACSR_DBCM, FB_DACSR_DBCM)   
#define RM_DACSR_DBR                         RM(FM_DACSR_DBR, FB_DACSR_DBR)     
#define RM_DACSR_DBM                         RM(FM_DACSR_DBM, FB_DACSR_DBM)     

/* Register Values */
#define RV_DACSR_DBCM_AUTO                   RV(FV_DACSR_DBCM_AUTO, FB_DACSR_DBCM)
#define RV_DACSR_DBCM_32                     RV(FV_DACSR_DBCM_32, FB_DACSR_DBCM)
#define RV_DACSR_DBCM_40                     RV(FV_DACSR_DBCM_40, FB_DACSR_DBCM)
#define RV_DACSR_DBCM_64                     RV(FV_DACSR_DBCM_64, FB_DACSR_DBCM)
#define RV_DACSR_DBR_32                      RV(FV_DACSR_DBR_32, FB_DACSR_DBR)  
#define RV_DACSR_DBR_44_1                    RV(FV_DACSR_DBR_44_1, FB_DACSR_DBR)
#define RV_DACSR_DBR_48                      RV(FV_DACSR_DBR_48, FB_DACSR_DBR)  
#define RV_DACSR_DBR_                        RV(FV_DACSR_DBR_, FB_DACSR_DBR)    
#define RV_DACSR_DBM_PT25                    RV(FV_DACSR_DBM_PT25, FB_DACSR_DBM)
#define RV_DACSR_DBM_PT5                     RV(FV_DACSR_DBM_PT5, FB_DACSR_DBM) 
#define RV_DACSR_DBM_1                       RV(FV_DACSR_DBM_1, FB_DACSR_DBM)   
#define RV_DACSR_DBM_2                       RV(FV_DACSR_DBM_2, FB_DACSR_DBM)   


/****************************
 *      R_PWRM1 (0x1A)      *
 ****************************/

/* Field Offsets */
#define FB_PWRM1_BSTL                        7                                  
#define FB_PWRM1_BSTR                        6                                  
#define FB_PWRM1_PGAL                        5                                  
#define FB_PWRM1_PGAR                        4                                  
#define FB_PWRM1_ADCL                        3                                  
#define FB_PWRM1_ADCR                        2                                  
#define FB_PWRM1_MICB                        1                                  
#define FB_PWRM1_DIGENB                      0                                  

/* Field Masks */
#define FM_PWRM1_BSTL                        0X1                                
#define FM_PWRM1_BSTR                        0X1                                
#define FM_PWRM1_PGAL                        0X1                                
#define FM_PWRM1_PGAR                        0X1                                
#define FM_PWRM1_ADCL                        0X1                                
#define FM_PWRM1_ADCR                        0X1                                
#define FM_PWRM1_MICB                        0X1                                
#define FM_PWRM1_DIGENB                      0X1                                

/* Field Values */
#define FV_PWRM1_BSTL_ENABLE                 0x1                                
#define FV_PWRM1_BSTL_DISABLE                0x0                                
#define FV_PWRM1_BSTR_ENABLE                 0x1                                
#define FV_PWRM1_BSTR_DISABLE                0x0                                
#define FV_PWRM1_PGAL_ENABLE                 0x1                                
#define FV_PWRM1_PGAL_DISABLE                0x0                                
#define FV_PWRM1_PGAR_ENABLE                 0x1                                
#define FV_PWRM1_PGAR_DISABLE                0x0                                
#define FV_PWRM1_ADCL_ENABLE                 0x1                                
#define FV_PWRM1_ADCL_DISABLE                0x0                                
#define FV_PWRM1_ADCR_ENABLE                 0x1                                
#define FV_PWRM1_ADCR_DISABLE                0x0                                
#define FV_PWRM1_MICB_ENABLE                 0x1                                
#define FV_PWRM1_MICB_DISABLE                0x0                                
#define FV_PWRM1_DIGENB_DISABLE              0x1                                
#define FV_PWRM1_DIGENB_ENABLE               0x0                                

/* Register Default */
#define RD_PWRM1                             0x0                                

/* Register Masks */
#define RM_PWRM1_BSTL                        RM(FM_PWRM1_BSTL, FB_PWRM1_BSTL)   
#define RM_PWRM1_BSTR                        RM(FM_PWRM1_BSTR, FB_PWRM1_BSTR)   
#define RM_PWRM1_PGAL                        RM(FM_PWRM1_PGAL, FB_PWRM1_PGAL)   
#define RM_PWRM1_PGAR                        RM(FM_PWRM1_PGAR, FB_PWRM1_PGAR)   
#define RM_PWRM1_ADCL                        RM(FM_PWRM1_ADCL, FB_PWRM1_ADCL)   
#define RM_PWRM1_ADCR                        RM(FM_PWRM1_ADCR, FB_PWRM1_ADCR)   
#define RM_PWRM1_MICB                        RM(FM_PWRM1_MICB, FB_PWRM1_MICB)   
#define RM_PWRM1_DIGENB                      RM(FM_PWRM1_DIGENB, FB_PWRM1_DIGENB)

/* Register Values */
#define RV_PWRM1_BSTL_ENABLE                 RV(FV_PWRM1_BSTL_ENABLE, FB_PWRM1_BSTL)
#define RV_PWRM1_BSTL_DISABLE                RV(FV_PWRM1_BSTL_DISABLE, FB_PWRM1_BSTL)
#define RV_PWRM1_BSTR_ENABLE                 RV(FV_PWRM1_BSTR_ENABLE, FB_PWRM1_BSTR)
#define RV_PWRM1_BSTR_DISABLE                RV(FV_PWRM1_BSTR_DISABLE, FB_PWRM1_BSTR)
#define RV_PWRM1_PGAL_ENABLE                 RV(FV_PWRM1_PGAL_ENABLE, FB_PWRM1_PGAL)
#define RV_PWRM1_PGAL_DISABLE                RV(FV_PWRM1_PGAL_DISABLE, FB_PWRM1_PGAL)
#define RV_PWRM1_PGAR_ENABLE                 RV(FV_PWRM1_PGAR_ENABLE, FB_PWRM1_PGAR)
#define RV_PWRM1_PGAR_DISABLE                RV(FV_PWRM1_PGAR_DISABLE, FB_PWRM1_PGAR)
#define RV_PWRM1_ADCL_ENABLE                 RV(FV_PWRM1_ADCL_ENABLE, FB_PWRM1_ADCL)
#define RV_PWRM1_ADCL_DISABLE                RV(FV_PWRM1_ADCL_DISABLE, FB_PWRM1_ADCL)
#define RV_PWRM1_ADCR_ENABLE                 RV(FV_PWRM1_ADCR_ENABLE, FB_PWRM1_ADCR)
#define RV_PWRM1_ADCR_DISABLE                RV(FV_PWRM1_ADCR_DISABLE, FB_PWRM1_ADCR)
#define RV_PWRM1_MICB_ENABLE                 RV(FV_PWRM1_MICB_ENABLE, FB_PWRM1_MICB)
#define RV_PWRM1_MICB_DISABLE                RV(FV_PWRM1_MICB_DISABLE, FB_PWRM1_MICB)
#define RV_PWRM1_DIGENB_DISABLE              RV(FV_PWRM1_DIGENB_DISABLE, FB_PWRM1_DIGENB)
#define RV_PWRM1_DIGENB_ENABLE               RV(FV_PWRM1_DIGENB_ENABLE, FB_PWRM1_DIGENB)


/****************************
 *      R_PWRM2 (0x1B)      *
 ****************************/

/* Field Offsets */
#define FB_PWRM2_D2S                         7                                  
#define FB_PWRM2_HPL                         6                                  
#define FB_PWRM2_HPR                         5                                  
#define FB_PWRM2_SPKL                        4                                  
#define FB_PWRM2_SPKR                        3                                  
#define FB_PWRM2_INSELL                      2                                  
#define FB_PWRM2_INSELR                      1                                  
#define FB_PWRM2_VREF                        0                                  

/* Field Masks */
#define FM_PWRM2_D2S                         0X1                                
#define FM_PWRM2_HPL                         0X1                                
#define FM_PWRM2_HPR                         0X1                                
#define FM_PWRM2_SPKL                        0X1                                
#define FM_PWRM2_SPKR                        0X1                                
#define FM_PWRM2_INSELL                      0X1                                
#define FM_PWRM2_INSELR                      0X1                                
#define FM_PWRM2_VREF                        0X1                                

/* Field Values */
#define FV_PWRM2_D2S_ENABLE                  0x1                                
#define FV_PWRM2_D2S_DISABLE                 0x0                                
#define FV_PWRM2_HPL_ENABLE                  0x1                                
#define FV_PWRM2_HPL_DISABLE                 0x0                                
#define FV_PWRM2_HPR_ENABLE                  0x1                                
#define FV_PWRM2_HPR_DISABLE                 0x0                                
#define FV_PWRM2_SPKL_ENABLE                 0x1                                
#define FV_PWRM2_SPKL_DISABLE                0x0                                
#define FV_PWRM2_SPKR_ENABLE                 0x1                                
#define FV_PWRM2_SPKR_DISABLE                0x0                                
#define FV_PWRM2_INSELL_ENABLE               0x1                                
#define FV_PWRM2_INSELL_DISABLE              0x0                                
#define FV_PWRM2_INSELR_ENABLE               0x1                                
#define FV_PWRM2_INSELR_DISABLE              0x0                                
#define FV_PWRM2_VREF_ENABLE                 0x1                                
#define FV_PWRM2_VREF_DISABLE                0x0                                

/* Register Default */
#define RD_PWRM2                             0x0                                

/* Register Masks */
#define RM_PWRM2_D2S                         RM(FM_PWRM2_D2S, FB_PWRM2_D2S)     
#define RM_PWRM2_HPL                         RM(FM_PWRM2_HPL, FB_PWRM2_HPL)     
#define RM_PWRM2_HPR                         RM(FM_PWRM2_HPR, FB_PWRM2_HPR)     
#define RM_PWRM2_SPKL                        RM(FM_PWRM2_SPKL, FB_PWRM2_SPKL)   
#define RM_PWRM2_SPKR                        RM(FM_PWRM2_SPKR, FB_PWRM2_SPKR)   
#define RM_PWRM2_INSELL                      RM(FM_PWRM2_INSELL, FB_PWRM2_INSELL)
#define RM_PWRM2_INSELR                      RM(FM_PWRM2_INSELR, FB_PWRM2_INSELR)
#define RM_PWRM2_VREF                        RM(FM_PWRM2_VREF, FB_PWRM2_VREF)   

/* Register Values */
#define RV_PWRM2_D2S_ENABLE                  RV(FV_PWRM2_D2S_ENABLE, FB_PWRM2_D2S)
#define RV_PWRM2_D2S_DISABLE                 RV(FV_PWRM2_D2S_DISABLE, FB_PWRM2_D2S)
#define RV_PWRM2_HPL_ENABLE                  RV(FV_PWRM2_HPL_ENABLE, FB_PWRM2_HPL)
#define RV_PWRM2_HPL_DISABLE                 RV(FV_PWRM2_HPL_DISABLE, FB_PWRM2_HPL)
#define RV_PWRM2_HPR_ENABLE                  RV(FV_PWRM2_HPR_ENABLE, FB_PWRM2_HPR)
#define RV_PWRM2_HPR_DISABLE                 RV(FV_PWRM2_HPR_DISABLE, FB_PWRM2_HPR)
#define RV_PWRM2_SPKL_ENABLE                 RV(FV_PWRM2_SPKL_ENABLE, FB_PWRM2_SPKL)
#define RV_PWRM2_SPKL_DISABLE                RV(FV_PWRM2_SPKL_DISABLE, FB_PWRM2_SPKL)
#define RV_PWRM2_SPKR_ENABLE                 RV(FV_PWRM2_SPKR_ENABLE, FB_PWRM2_SPKR)
#define RV_PWRM2_SPKR_DISABLE                RV(FV_PWRM2_SPKR_DISABLE, FB_PWRM2_SPKR)
#define RV_PWRM2_INSELL_ENABLE               RV(FV_PWRM2_INSELL_ENABLE, FB_PWRM2_INSELL)
#define RV_PWRM2_INSELL_DISABLE              RV(FV_PWRM2_INSELL_DISABLE, FB_PWRM2_INSELL)
#define RV_PWRM2_INSELR_ENABLE               RV(FV_PWRM2_INSELR_ENABLE, FB_PWRM2_INSELR)
#define RV_PWRM2_INSELR_DISABLE              RV(FV_PWRM2_INSELR_DISABLE, FB_PWRM2_INSELR)
#define RV_PWRM2_VREF_ENABLE                 RV(FV_PWRM2_VREF_ENABLE, FB_PWRM2_VREF)
#define RV_PWRM2_VREF_DISABLE                RV(FV_PWRM2_VREF_DISABLE, FB_PWRM2_VREF)


/**************************
 *      R_CTL (0x1C)      *
 **************************/

/* Field Offsets */
#define FB_CTL_HPSWEN                        7                                  
#define FB_CTL_HPSWPOL                       6                                  
#define FB_CTL_EQ2SW                         4                                  
#define FB_CTL_EQ1SW                         2                                  
#define FB_CTL_TSDEN                         1                                  
#define FB_CTL_TOEN                          0                                  

/* Field Masks */
#define FM_CTL_HPSWEN                        0X1                                
#define FM_CTL_HPSWPOL                       0X1                                
#define FM_CTL_EQ2SW                         0X3                                
#define FM_CTL_EQ1SW                         0X3                                
#define FM_CTL_TSDEN                         0X1                                
#define FM_CTL_TOEN                          0X1                                

/* Field Values */
#define FV_CTL_HPSWEN_ENABLE                 0x1                                
#define FV_CTL_HPSWEN_DISABLE                0x0                                
#define FV_CTL_HPSWPOL_HP                    0x0                                
#define FV_CTL_HPSWPOL_SPK                   0x1                                
#define FV_CTL_EQ2SW_DISABLED                0x0                                
#define FV_CTL_EQ2SW_HP                      0x1                                
#define FV_CTL_EQ2SW_SPK                     0x2                                
#define FV_CTL_EQ2SW_HP_SPK                  0x3                                
#define FV_CTL_EQ1SW_DISABLED                0x0                                
#define FV_CTL_EQ1SW_HP                      0x1                                
#define FV_CTL_EQ1SW_SPK                     0x2                                
#define FV_CTL_EQ1SW_HP_SPK                  0x3                                
#define FV_CTL_TSDEN_ENABLE                  0x1                                
#define FV_CTL_TSDEN_DISABLE                 0x0                                
#define FV_CTL_TOEN_ENABLE                   0x1                                
#define FV_CTL_TOEN_DISABLE                  0x0                                

/* Register Default */
#define RD_CTL                               0x0                                

/* Register Masks */
#define RM_CTL_HPSWEN                        RM(FM_CTL_HPSWEN, FB_CTL_HPSWEN)   
#define RM_CTL_HPSWPOL                       RM(FM_CTL_HPSWPOL, FB_CTL_HPSWPOL) 
#define RM_CTL_EQ2SW                         RM(FM_CTL_EQ2SW, FB_CTL_EQ2SW)     
#define RM_CTL_EQ1SW                         RM(FM_CTL_EQ1SW, FB_CTL_EQ1SW)     
#define RM_CTL_TSDEN                         RM(FM_CTL_TSDEN, FB_CTL_TSDEN)     
#define RM_CTL_TOEN                          RM(FM_CTL_TOEN, FB_CTL_TOEN)       

/* Register Values */
#define RV_CTL_HPSWEN_ENABLE                 RV(FV_CTL_HPSWEN_ENABLE, FB_CTL_HPSWEN)
#define RV_CTL_HPSWEN_DISABLE                RV(FV_CTL_HPSWEN_DISABLE, FB_CTL_HPSWEN)
#define RV_CTL_HPSWPOL_HP                    RV(FV_CTL_HPSWPOL_HP, FB_CTL_HPSWPOL)
#define RV_CTL_HPSWPOL_SPK                   RV(FV_CTL_HPSWPOL_SPK, FB_CTL_HPSWPOL)
#define RV_CTL_EQ2SW_DISABLED                RV(FV_CTL_EQ2SW_DISABLED, FB_CTL_EQ2SW)
#define RV_CTL_EQ2SW_HP                      RV(FV_CTL_EQ2SW_HP, FB_CTL_EQ2SW)  
#define RV_CTL_EQ2SW_SPK                     RV(FV_CTL_EQ2SW_SPK, FB_CTL_EQ2SW) 
#define RV_CTL_EQ2SW_HP_SPK                  RV(FV_CTL_EQ2SW_HP_SPK, FB_CTL_EQ2SW)
#define RV_CTL_EQ1SW_DISABLED                RV(FV_CTL_EQ1SW_DISABLED, FB_CTL_EQ1SW)
#define RV_CTL_EQ1SW_HP                      RV(FV_CTL_EQ1SW_HP, FB_CTL_EQ1SW)  
#define RV_CTL_EQ1SW_SPK                     RV(FV_CTL_EQ1SW_SPK, FB_CTL_EQ1SW) 
#define RV_CTL_EQ1SW_HP_SPK                  RV(FV_CTL_EQ1SW_HP_SPK, FB_CTL_EQ1SW)
#define RV_CTL_TSDEN_ENABLE                  RV(FV_CTL_TSDEN_ENABLE, FB_CTL_TSDEN)
#define RV_CTL_TSDEN_DISABLE                 RV(FV_CTL_TSDEN_DISABLE, FB_CTL_TSDEN)
#define RV_CTL_TOEN_ENABLE                   RV(FV_CTL_TOEN_ENABLE, FB_CTL_TOEN)
#define RV_CTL_TOEN_DISABLE                  RV(FV_CTL_TOEN_DISABLE, FB_CTL_TOEN)


/******************************
 *      R_THERMTS (0x1D)      *
 ******************************/

/* Field Offsets */
#define FB_THERMTS_TRIPHIGHSTAT              7                                  
#define FB_THERMTS_TRIPLOWSTAT               6                                  
#define FB_THERMTS_TRIPSPLIT                 4                                  
#define FB_THERMTS_TRIPSHIFT                 2                                  
#define FB_THERMTS_POLL                      0                                  

/* Field Masks */
#define FM_THERMTS_TRIPHIGHSTAT              0X1                                
#define FM_THERMTS_TRIPLOWSTAT               0X1                                
#define FM_THERMTS_TRIPSPLIT                 0X3                                
#define FM_THERMTS_TRIPSHIFT                 0X3                                
#define FM_THERMTS_POLL                      0X3                                

/* Field Values */
#define FV_THERMTS_TRIPSPLIT_15C             0x0                                
#define FV_THERMTS_TRIPSPLIT_30C             0x1                                
#define FV_THERMTS_TRIPSPLIT_45C             0x2                                
#define FV_THERMTS_TRIPSPLIT_60C             0x3                                
#define FV_THERMTS_TRIPSHIFT_110C            0x0                                
#define FV_THERMTS_TRIPSHIFT_125C            0x1                                
#define FV_THERMTS_TRIPSHIFT_140C            0x2                                
#define FV_THERMTS_TRIPSHIFT_155             0x3                                
#define FV_THERMTS_POLL_4MS                  0x0                                
#define FV_THERMTS_POLL_8MS                  0x1                                
#define FV_THERMTS_POLL_16MS                 0x2                                
#define FV_THERMTS_POLL_32MS                 0x3                                

/* Register Default */
#define RD_THERMTS                           0x0                                

/* Register Masks */
#define RM_THERMTS_TRIPHIGHSTAT              RM(FM_THERMTS_TRIPHIGHSTAT, FB_THERMTS_TRIPHIGHSTAT)
#define RM_THERMTS_TRIPLOWSTAT               RM(FM_THERMTS_TRIPLOWSTAT, FB_THERMTS_TRIPLOWSTAT)
#define RM_THERMTS_TRIPSPLIT                 RM(FM_THERMTS_TRIPSPLIT, FB_THERMTS_TRIPSPLIT)
#define RM_THERMTS_TRIPSHIFT                 RM(FM_THERMTS_TRIPSHIFT, FB_THERMTS_TRIPSHIFT)
#define RM_THERMTS_POLL                      RM(FM_THERMTS_POLL, FB_THERMTS_POLL)

/* Register Values */
#define RV_THERMTS_TRIPSPLIT_15C             RV(FV_THERMTS_TRIPSPLIT_15C, FB_THERMTS_TRIPSPLIT)
#define RV_THERMTS_TRIPSPLIT_30C             RV(FV_THERMTS_TRIPSPLIT_30C, FB_THERMTS_TRIPSPLIT)
#define RV_THERMTS_TRIPSPLIT_45C             RV(FV_THERMTS_TRIPSPLIT_45C, FB_THERMTS_TRIPSPLIT)
#define RV_THERMTS_TRIPSPLIT_60C             RV(FV_THERMTS_TRIPSPLIT_60C, FB_THERMTS_TRIPSPLIT)
#define RV_THERMTS_TRIPSHIFT_110C            RV(FV_THERMTS_TRIPSHIFT_110C, FB_THERMTS_TRIPSHIFT)
#define RV_THERMTS_TRIPSHIFT_125C            RV(FV_THERMTS_TRIPSHIFT_125C, FB_THERMTS_TRIPSHIFT)
#define RV_THERMTS_TRIPSHIFT_140C            RV(FV_THERMTS_TRIPSHIFT_140C, FB_THERMTS_TRIPSHIFT)
#define RV_THERMTS_TRIPSHIFT_155             RV(FV_THERMTS_TRIPSHIFT_155, FB_THERMTS_TRIPSHIFT)
#define RV_THERMTS_POLL_4MS                  RV(FV_THERMTS_POLL_4MS, FB_THERMTS_POLL)
#define RV_THERMTS_POLL_8MS                  RV(FV_THERMTS_POLL_8MS, FB_THERMTS_POLL)
#define RV_THERMTS_POLL_16MS                 RV(FV_THERMTS_POLL_16MS, FB_THERMTS_POLL)
#define RV_THERMTS_POLL_32MS                 RV(FV_THERMTS_POLL_32MS, FB_THERMTS_POLL)


/*********************************
 *      R_THERMSPKR1 (0x1E)      *
 *********************************/

/* Field Offsets */
#define FB_THERMSPKR1_FORCEPWD               7                                  
#define FB_THERMSPKR1_INSTCUTMODE            6                                  
#define FB_THERMSPKR1_INCRATIO               4                                  
#define FB_THERMSPKR1_INCSTEP                2                                  
#define FB_THERMSPKR1_DECSTEP                0                                  

/* Field Masks */
#define FM_THERMSPKR1_FORCEPWD               0X1                                
#define FM_THERMSPKR1_INSTCUTMODE            0X1                                
#define FM_THERMSPKR1_INCRATIO               0X3                                
#define FM_THERMSPKR1_INCSTEP                0X3                                
#define FM_THERMSPKR1_DECSTEP                0X3                                

/* Field Values */

/* Register Default */
#define RD_THERMSPKR1                        0x1                                

/* Register Masks */
#define RM_THERMSPKR1_FORCEPWD               RM(FM_THERMSPKR1_FORCEPWD, FB_THERMSPKR1_FORCEPWD)
#define RM_THERMSPKR1_INSTCUTMODE            RM(FM_THERMSPKR1_INSTCUTMODE, FB_THERMSPKR1_INSTCUTMODE)
#define RM_THERMSPKR1_INCRATIO               RM(FM_THERMSPKR1_INCRATIO, FB_THERMSPKR1_INCRATIO)
#define RM_THERMSPKR1_INCSTEP                RM(FM_THERMSPKR1_INCSTEP, FB_THERMSPKR1_INCSTEP)
#define RM_THERMSPKR1_DECSTEP                RM(FM_THERMSPKR1_DECSTEP, FB_THERMSPKR1_DECSTEP)

/* Register Values */


/******************************
 *      R_CONFIG0 (0x1F)      *
 ******************************/

/* Field Offsets */
#define FB_CONFIG0_ASDM                      6                                  
#define FB_CONFIG0_DSDM                      4                                  
#define FB_CONFIG0_DC_BYPASS                 1                                  
#define FB_CONFIG0_SD_FORCE_ON               0                                  

/* Field Masks */
#define FM_CONFIG0_ASDM                      0X3                                
#define FM_CONFIG0_DSDM                      0X3                                
#define FM_CONFIG0_DC_BYPASS                 0X1                                
#define FM_CONFIG0_SD_FORCE_ON               0X1                                

/* Field Values */
#define FV_CONFIG0_ASDM_HALF                 0x1                                
#define FV_CONFIG0_ASDM_FULL                 0x2                                
#define FV_CONFIG0_ASDM_AUTO                 0x3                                
#define FV_CONFIG0_DSDM_HALF                 0x1                                
#define FV_CONFIG0_DSDM_FULL                 0x2                                
#define FV_CONFIG0_DSDM_AUTO                 0x3                                
#define FV_CONFIG0_DC_BYPASS_ENABLE          0x1                                
#define FV_CONFIG0_DC_BYPASS_DISABLE         0x0                                
#define FV_CONFIG0_SD_FORCE_ON_ENABLE        0x1                                
#define FV_CONFIG0_SD_FORCE_ON_DISABLE       0x0                                

/* Register Default */
#define RD_CONFIG0                           0x2                                

/* Register Masks */
#define RM_CONFIG0_ASDM                      RM(FM_CONFIG0_ASDM, FB_CONFIG0_ASDM)
#define RM_CONFIG0_DSDM                      RM(FM_CONFIG0_DSDM, FB_CONFIG0_DSDM)
#define RM_CONFIG0_DC_BYPASS                 RM(FM_CONFIG0_DC_BYPASS, FB_CONFIG0_DC_BYPASS)
#define RM_CONFIG0_SD_FORCE_ON               RM(FM_CONFIG0_SD_FORCE_ON, FB_CONFIG0_SD_FORCE_ON)

/* Register Values */
#define RV_CONFIG0_ASDM_HALF                 RV(FV_CONFIG0_ASDM_HALF, FB_CONFIG0_ASDM)
#define RV_CONFIG0_ASDM_FULL                 RV(FV_CONFIG0_ASDM_FULL, FB_CONFIG0_ASDM)
#define RV_CONFIG0_ASDM_AUTO                 RV(FV_CONFIG0_ASDM_AUTO, FB_CONFIG0_ASDM)
#define RV_CONFIG0_DSDM_HALF                 RV(FV_CONFIG0_DSDM_HALF, FB_CONFIG0_DSDM)
#define RV_CONFIG0_DSDM_FULL                 RV(FV_CONFIG0_DSDM_FULL, FB_CONFIG0_DSDM)
#define RV_CONFIG0_DSDM_AUTO                 RV(FV_CONFIG0_DSDM_AUTO, FB_CONFIG0_DSDM)
#define RV_CONFIG0_DC_BYPASS_ENABLE          RV(FV_CONFIG0_DC_BYPASS_ENABLE, FB_CONFIG0_DC_BYPASS)
#define RV_CONFIG0_DC_BYPASS_DISABLE         RV(FV_CONFIG0_DC_BYPASS_DISABLE, FB_CONFIG0_DC_BYPASS)
#define RV_CONFIG0_SD_FORCE_ON_ENABLE        RV(FV_CONFIG0_SD_FORCE_ON_ENABLE, FB_CONFIG0_SD_FORCE_ON)
#define RV_CONFIG0_SD_FORCE_ON_DISABLE       RV(FV_CONFIG0_SD_FORCE_ON_DISABLE, FB_CONFIG0_SD_FORCE_ON)


/******************************
 *      R_CONFIG1 (0x20)      *
 ******************************/

/* Field Offsets */
#define FB_CONFIG1_EQ2_EN                    7                                  
#define FB_CONFIG1_EQ2_BE                    4                                  
#define FB_CONFIG1_EQ1_EN                    3                                  
#define FB_CONFIG1_EQ1_BE                    0                                  

/* Field Masks */
#define FM_CONFIG1_EQ2_EN                    0X1                                
#define FM_CONFIG1_EQ2_BE                    0X7                                
#define FM_CONFIG1_EQ1_EN                    0X1                                
#define FM_CONFIG1_EQ1_BE                    0X7                                

/* Field Values */
#define FV_CONFIG1_EQ2_EN_ENABLE             0x1                                
#define FV_CONFIG1_EQ2_EN_DISABLE            0x0                                
#define FV_CONFIG1_EQ2_BE_PRE                0x0                                
#define FV_CONFIG1_EQ2_BE_PRE_EQ_0           0x1                                
#define FV_CONFIG1_EQ2_BE_PRE_EQ0_1          0x2                                
#define FV_CONFIG1_EQ2_BE_PRE_EQ0_2          0x3                                
#define FV_CONFIG1_EQ2_BE_PRE_EQ0_3          0x4                                
#define FV_CONFIG1_EQ2_BE_PRE_EQ0_4          0x5                                
#define FV_CONFIG1_EQ2_BE_PRE_EQ0_5          0x6                                
#define FV_CONFIG1_EQ1_EN_ENABLE             0x1                                
#define FV_CONFIG1_EQ1_EN_DISABLE            0x0                                
#define FV_CONFIG1_EQ1_BE_PRE                0x0                                
#define FV_CONFIG1_EQ1_BE_PRE_EQ_0           0x1                                
#define FV_CONFIG1_EQ1_BE_PRE_EQ0_1          0x2                                
#define FV_CONFIG1_EQ1_BE_PRE_EQ0_2          0x3                                
#define FV_CONFIG1_EQ1_BE_PRE_EQ0_3          0x4                                
#define FV_CONFIG1_EQ1_BE_PRE_EQ0_4          0x5                                
#define FV_CONFIG1_EQ1_BE_PRE_EQ0_5          0x6                                

/* Register Default */
#define RD_CONFIG1                           0x0                                

/* Register Masks */
#define RM_CONFIG1_EQ2_EN                    RM(FM_CONFIG1_EQ2_EN, FB_CONFIG1_EQ2_EN)
#define RM_CONFIG1_EQ2_BE                    RM(FM_CONFIG1_EQ2_BE, FB_CONFIG1_EQ2_BE)
#define RM_CONFIG1_EQ1_EN                    RM(FM_CONFIG1_EQ1_EN, FB_CONFIG1_EQ1_EN)
#define RM_CONFIG1_EQ1_BE                    RM(FM_CONFIG1_EQ1_BE, FB_CONFIG1_EQ1_BE)

/* Register Values */
#define RV_CONFIG1_EQ2_EN_ENABLE             RV(FV_CONFIG1_EQ2_EN_ENABLE, FB_CONFIG1_EQ2_EN)
#define RV_CONFIG1_EQ2_EN_DISABLE            RV(FV_CONFIG1_EQ2_EN_DISABLE, FB_CONFIG1_EQ2_EN)
#define RV_CONFIG1_EQ2_BE_PRE                RV(FV_CONFIG1_EQ2_BE_PRE, FB_CONFIG1_EQ2_BE)
#define RV_CONFIG1_EQ2_BE_PRE_EQ_0           RV(FV_CONFIG1_EQ2_BE_PRE_EQ_0, FB_CONFIG1_EQ2_BE)
#define RV_CONFIG1_EQ2_BE_PRE_EQ0_1          RV(FV_CONFIG1_EQ2_BE_PRE_EQ0_1, FB_CONFIG1_EQ2_BE)
#define RV_CONFIG1_EQ2_BE_PRE_EQ0_2          RV(FV_CONFIG1_EQ2_BE_PRE_EQ0_2, FB_CONFIG1_EQ2_BE)
#define RV_CONFIG1_EQ2_BE_PRE_EQ0_3          RV(FV_CONFIG1_EQ2_BE_PRE_EQ0_3, FB_CONFIG1_EQ2_BE)
#define RV_CONFIG1_EQ2_BE_PRE_EQ0_4          RV(FV_CONFIG1_EQ2_BE_PRE_EQ0_4, FB_CONFIG1_EQ2_BE)
#define RV_CONFIG1_EQ2_BE_PRE_EQ0_5          RV(FV_CONFIG1_EQ2_BE_PRE_EQ0_5, FB_CONFIG1_EQ2_BE)
#define RV_CONFIG1_EQ1_EN_ENABLE             RV(FV_CONFIG1_EQ1_EN_ENABLE, FB_CONFIG1_EQ1_EN)
#define RV_CONFIG1_EQ1_EN_DISABLE            RV(FV_CONFIG1_EQ1_EN_DISABLE, FB_CONFIG1_EQ1_EN)
#define RV_CONFIG1_EQ1_BE_PRE                RV(FV_CONFIG1_EQ1_BE_PRE, FB_CONFIG1_EQ1_BE)
#define RV_CONFIG1_EQ1_BE_PRE_EQ_0           RV(FV_CONFIG1_EQ1_BE_PRE_EQ_0, FB_CONFIG1_EQ1_BE)
#define RV_CONFIG1_EQ1_BE_PRE_EQ0_1          RV(FV_CONFIG1_EQ1_BE_PRE_EQ0_1, FB_CONFIG1_EQ1_BE)
#define RV_CONFIG1_EQ1_BE_PRE_EQ0_2          RV(FV_CONFIG1_EQ1_BE_PRE_EQ0_2, FB_CONFIG1_EQ1_BE)
#define RV_CONFIG1_EQ1_BE_PRE_EQ0_3          RV(FV_CONFIG1_EQ1_BE_PRE_EQ0_3, FB_CONFIG1_EQ1_BE)
#define RV_CONFIG1_EQ1_BE_PRE_EQ0_4          RV(FV_CONFIG1_EQ1_BE_PRE_EQ0_4, FB_CONFIG1_EQ1_BE)
#define RV_CONFIG1_EQ1_BE_PRE_EQ0_5          RV(FV_CONFIG1_EQ1_BE_PRE_EQ0_5, FB_CONFIG1_EQ1_BE)


/******************************
 *      R_GAINCTL (0x21)      *
 ******************************/

/* Field Offsets */
#define FB_GAINCTL_ZERODET_FLAG              7                                  
#define FB_GAINCTL_ZERODETLEN                4                                  
#define FB_GAINCTL_AUTO_MUTE                 2                                  

/* Field Masks */
#define FM_GAINCTL_ZERODET_FLAG              0X1                                
#define FM_GAINCTL_ZERODETLEN                0X3                                
#define FM_GAINCTL_AUTO_MUTE                 0X1                                

/* Field Values */
#define FV_GAINCTL_ZERODETLEN_512            0x0                                
#define FV_GAINCTL_ZERODETLEN_1024           0x1                                
#define FV_GAINCTL_ZERODETLEN_2048           0x2                                
#define FV_GAINCTL_ZERODETLEN_4096           0x3                                
#define FV_GAINCTL_AUTO_MUTE_ENABLE          0x1                                
#define FV_GAINCTL_AUTO_MUTE_DISABLE         0x0                                

/* Register Default */
#define RD_GAINCTL                           0x0                                

/* Register Masks */
#define RM_GAINCTL_ZERODET_FLAG              RM(FM_GAINCTL_ZERODET_FLAG, FB_GAINCTL_ZERODET_FLAG)
#define RM_GAINCTL_ZERODETLEN                RM(FM_GAINCTL_ZERODETLEN, FB_GAINCTL_ZERODETLEN)
#define RM_GAINCTL_AUTO_MUTE                 RM(FM_GAINCTL_AUTO_MUTE, FB_GAINCTL_AUTO_MUTE)

/* Register Values */
#define RV_GAINCTL_ZERODETLEN_512            RV(FV_GAINCTL_ZERODETLEN_512, FB_GAINCTL_ZERODETLEN)
#define RV_GAINCTL_ZERODETLEN_1024           RV(FV_GAINCTL_ZERODETLEN_1024, FB_GAINCTL_ZERODETLEN)
#define RV_GAINCTL_ZERODETLEN_2048           RV(FV_GAINCTL_ZERODETLEN_2048, FB_GAINCTL_ZERODETLEN)
#define RV_GAINCTL_ZERODETLEN_4096           RV(FV_GAINCTL_ZERODETLEN_4096, FB_GAINCTL_ZERODETLEN)
#define RV_GAINCTL_AUTO_MUTE_ENABLE          RV(FV_GAINCTL_AUTO_MUTE_ENABLE, FB_GAINCTL_AUTO_MUTE)
#define RV_GAINCTL_AUTO_MUTE_DISABLE         RV(FV_GAINCTL_AUTO_MUTE_DISABLE, FB_GAINCTL_AUTO_MUTE)


/***************************
 *      R_COP1 (0x22)      *
 ***************************/

/* Field Offsets */
#define FB_COP1_COPATTEN                     7                                  
#define FB_COP1_COPGAIN                      6                                  
#define FB_COP1_HDELTAEN                     5                                  
#define FB_COP1_COPTARGET                    0                                  

/* Field Masks */
#define FM_COP1_COPATTEN                     0X1                                
#define FM_COP1_COPGAIN                      0X1                                
#define FM_COP1_HDELTAEN                     0X1                                
#define FM_COP1_COPTARGET                    0X1F                               

/* Field Values */
#define FV_COP1_COPATTEN_ENABLE              0x1                                
#define FV_COP1_COPATTEN_DISABLE             0x0                                
#define FV_COP1_COPGAIN_ENABLE               0x1                                
#define FV_COP1_COPGAIN_DISABLE              0x0                                
#define FV_COP1_HDELTAEN_ENABLE              0x1                                
#define FV_COP1_HDELTAEN_DISABLE             0x0                                

/* Register Default */
#define RD_COP1                              0x1                                

/* Register Masks */
#define RM_COP1_COPATTEN                     RM(FM_COP1_COPATTEN, FB_COP1_COPATTEN)
#define RM_COP1_COPGAIN                      RM(FM_COP1_COPGAIN, FB_COP1_COPGAIN)
#define RM_COP1_HDELTAEN                     RM(FM_COP1_HDELTAEN, FB_COP1_HDELTAEN)
#define RM_COP1_COPTARGET                    RM(FM_COP1_COPTARGET, FB_COP1_COPTARGET)

/* Register Values */
#define RV_COP1_COPATTEN_ENABLE              RV(FV_COP1_COPATTEN_ENABLE, FB_COP1_COPATTEN)
#define RV_COP1_COPATTEN_DISABLE             RV(FV_COP1_COPATTEN_DISABLE, FB_COP1_COPATTEN)
#define RV_COP1_COPGAIN_ENABLE               RV(FV_COP1_COPGAIN_ENABLE, FB_COP1_COPGAIN)
#define RV_COP1_COPGAIN_DISABLE              RV(FV_COP1_COPGAIN_DISABLE, FB_COP1_COPGAIN)
#define RV_COP1_HDELTAEN_ENABLE              RV(FV_COP1_HDELTAEN_ENABLE, FB_COP1_HDELTAEN)
#define RV_COP1_HDELTAEN_DISABLE             RV(FV_COP1_HDELTAEN_DISABLE, FB_COP1_HDELTAEN)


/***************************
 *      R_COP2 (0x23)      *
 ***************************/

/* Field Offsets */
#define FB_COP2_HDCOMPMODE                   6                                  
#define FB_COP2_AVGLENGTH                    2                                  
#define FB_COP2_MONRATE                      0                                  

/* Field Masks */
#define FM_COP2_HDCOMPMODE                   0X1                                
#define FM_COP2_AVGLENGTH                    0XF                                
#define FM_COP2_MONRATE                      0X3                                

/* Field Values */
#define FV_COP2_HDCOMPMODE_AVG               0x0                                
#define FV_COP2_HDCOMPMODE_LAST              0x1                                
#define FV_COP2_AVGLENGTH_1                  0x0                                
#define FV_COP2_AVGLENGTH_2                  0x1                                
#define FV_COP2_AVGLENGTH_4                  0x2                                
#define FV_COP2_AVGLENGTH_8                  0x3                                
#define FV_COP2_AVGLENGTH_16                 0x4                                
#define FV_COP2_AVGLENGTH_32                 0x5                                
#define FV_COP2_AVGLENGTH_64                 0x6                                
#define FV_COP2_AVGLENGTH_128                0x7                                
#define FV_COP2_AVGLENGTH_256                0x8                                
#define FV_COP2_AVGLENGTH_512                0x9                                
#define FV_COP2_MONRATE_PT25MS               0x0                                
#define FV_COP2_MONRATE_PT5MS                0x1                                
#define FV_COP2_MONRATE_1MS                  0x2                                
#define FV_COP2_MONRATE_2MS                  0x3                                

/* Register Default */
#define RD_COP2                              0x0                                

/* Register Masks */
#define RM_COP2_HDCOMPMODE                   RM(FM_COP2_HDCOMPMODE, FB_COP2_HDCOMPMODE)
#define RM_COP2_AVGLENGTH                    RM(FM_COP2_AVGLENGTH, FB_COP2_AVGLENGTH)
#define RM_COP2_MONRATE                      RM(FM_COP2_MONRATE, FB_COP2_MONRATE)

/* Register Values */
#define RV_COP2_HDCOMPMODE_AVG               RV(FV_COP2_HDCOMPMODE_AVG, FB_COP2_HDCOMPMODE)
#define RV_COP2_HDCOMPMODE_LAST              RV(FV_COP2_HDCOMPMODE_LAST, FB_COP2_HDCOMPMODE)
#define RV_COP2_AVGLENGTH_1                  RV(FV_COP2_AVGLENGTH_1, FB_COP2_AVGLENGTH)
#define RV_COP2_AVGLENGTH_2                  RV(FV_COP2_AVGLENGTH_2, FB_COP2_AVGLENGTH)
#define RV_COP2_AVGLENGTH_4                  RV(FV_COP2_AVGLENGTH_4, FB_COP2_AVGLENGTH)
#define RV_COP2_AVGLENGTH_8                  RV(FV_COP2_AVGLENGTH_8, FB_COP2_AVGLENGTH)
#define RV_COP2_AVGLENGTH_16                 RV(FV_COP2_AVGLENGTH_16, FB_COP2_AVGLENGTH)
#define RV_COP2_AVGLENGTH_32                 RV(FV_COP2_AVGLENGTH_32, FB_COP2_AVGLENGTH)
#define RV_COP2_AVGLENGTH_64                 RV(FV_COP2_AVGLENGTH_64, FB_COP2_AVGLENGTH)
#define RV_COP2_AVGLENGTH_128                RV(FV_COP2_AVGLENGTH_128, FB_COP2_AVGLENGTH)
#define RV_COP2_AVGLENGTH_256                RV(FV_COP2_AVGLENGTH_256, FB_COP2_AVGLENGTH)
#define RV_COP2_AVGLENGTH_512                RV(FV_COP2_AVGLENGTH_512, FB_COP2_AVGLENGTH)
#define RV_COP2_MONRATE_PT25MS               RV(FV_COP2_MONRATE_PT25MS, FB_COP2_MONRATE)
#define RV_COP2_MONRATE_PT5MS                RV(FV_COP2_MONRATE_PT5MS, FB_COP2_MONRATE)
#define RV_COP2_MONRATE_1MS                  RV(FV_COP2_MONRATE_1MS, FB_COP2_MONRATE)
#define RV_COP2_MONRATE_2MS                  RV(FV_COP2_MONRATE_2MS, FB_COP2_MONRATE)


/******************************
 *      R_DMICCTL (0x24)      *
 ******************************/

/* Field Offsets */
#define FB_DMICCTL_DMICEN                    7                                  
#define FB_DMICCTL_DMONO                     4                                  
#define FB_DMICCTL_DMPHADJ                   2                                  
#define FB_DMICCTL_DMRATE                    0                                  

/* Field Masks */
#define FM_DMICCTL_DMICEN                    0X1                                
#define FM_DMICCTL_DMONO                     0X1                                
#define FM_DMICCTL_DMPHADJ                   0X3                                
#define FM_DMICCTL_DMRATE                    0X3                                

/* Field Values */
#define FV_DMICCTL_DMICEN_ENABLE             0x1                                
#define FV_DMICCTL_DMICEN_DISABLE            0x0                                
#define FV_DMICCTL_DMONO_STEREO              0x0                                
#define FV_DMICCTL_DMONO_MONO                0x1                                

/* Register Default */
#define RD_DMICCTL                           0x0                                

/* Register Masks */
#define RM_DMICCTL_DMICEN                    RM(FM_DMICCTL_DMICEN, FB_DMICCTL_DMICEN)
#define RM_DMICCTL_DMONO                     RM(FM_DMICCTL_DMONO, FB_DMICCTL_DMONO)
#define RM_DMICCTL_DMPHADJ                   RM(FM_DMICCTL_DMPHADJ, FB_DMICCTL_DMPHADJ)
#define RM_DMICCTL_DMRATE                    RM(FM_DMICCTL_DMRATE, FB_DMICCTL_DMRATE)

/* Register Values */
#define RV_DMICCTL_DMICEN_ENABLE             RV(FV_DMICCTL_DMICEN_ENABLE, FB_DMICCTL_DMICEN)
#define RV_DMICCTL_DMICEN_DISABLE            RV(FV_DMICCTL_DMICEN_DISABLE, FB_DMICCTL_DMICEN)
#define RV_DMICCTL_DMONO_STEREO              RV(FV_DMICCTL_DMONO_STEREO, FB_DMICCTL_DMONO)
#define RV_DMICCTL_DMONO_MONO                RV(FV_DMICCTL_DMONO_MONO, FB_DMICCTL_DMONO)


/*****************************
 *      R_CLECTL (0x25)      *
 *****************************/

/* Field Offsets */
#define FB_CLECTLLVL_MODE                    4                                  
#define FB_CLECTL_WINDOWSEL                  3                                  
#define FB_CLECTL_EXP_EN                     2                                  
#define FB_CLECTLLIMIT_EN                    1                                  
#define FB_CLECTL_COMP_EN                    0                                  

/* Field Masks */
#define FM_CLECTLLVL_MODE                    0X1                                
#define FM_CLECTL_WINDOWSEL                  0X1                                
#define FM_CLECTL_EXP_EN                     0X1                                
#define FM_CLECTLLIMIT_EN                    0X1                                
#define FM_CLECTL_COMP_EN                    0X1                                

/* Field Values */
#define FV_CLECTLLVL_MODE_AVG                0x0                                
#define FV_CLECTLLVL_MODE_PEAK               0x1                                
#define FV_CLECTL_WINDOWSEL_512              0x0                                
#define FV_CLECTL_WINDOWSEL_64               0x1                                
#define FV_CLECTL_EXP_EN_ENABLE              0x1                                
#define FV_CLECTL_EXP_EN_DISABLE             0x0                                
#define FV_CLECTLLIMIT_EN_ENABLE             0x1                                
#define FV_CLECTLLIMIT_EN_DISABLE            0x0                                
#define FV_CLECTL_COMP_EN_ENABLE             0x1                                
#define FV_CLECTL_COMP_EN_DISABLE            0x0                                

/* Register Default */
#define RD_CLECTL                            0x0                                

/* Register Masks */
#define RM_CLECTLLVL_MODE                    RM(FM_CLECTLLVL_MODE, FB_CLECTLLVL_MODE)
#define RM_CLECTL_WINDOWSEL                  RM(FM_CLECTL_WINDOWSEL, FB_CLECTL_WINDOWSEL)
#define RM_CLECTL_EXP_EN                     RM(FM_CLECTL_EXP_EN, FB_CLECTL_EXP_EN)
#define RM_CLECTLLIMIT_EN                    RM(FM_CLECTLLIMIT_EN, FB_CLECTLLIMIT_EN)
#define RM_CLECTL_COMP_EN                    RM(FM_CLECTL_COMP_EN, FB_CLECTL_COMP_EN)

/* Register Values */
#define RV_CLECTLLVL_MODE_AVG                RV(FV_CLECTLLVL_MODE_AVG, FB_CLECTLLVL_MODE)
#define RV_CLECTLLVL_MODE_PEAK               RV(FV_CLECTLLVL_MODE_PEAK, FB_CLECTLLVL_MODE)
#define RV_CLECTL_WINDOWSEL_512              RV(FV_CLECTL_WINDOWSEL_512, FB_CLECTL_WINDOWSEL)
#define RV_CLECTL_WINDOWSEL_64               RV(FV_CLECTL_WINDOWSEL_64, FB_CLECTL_WINDOWSEL)
#define RV_CLECTL_EXP_EN_ENABLE              RV(FV_CLECTL_EXP_EN_ENABLE, FB_CLECTL_EXP_EN)
#define RV_CLECTL_EXP_EN_DISABLE             RV(FV_CLECTL_EXP_EN_DISABLE, FB_CLECTL_EXP_EN)
#define RV_CLECTLLIMIT_EN_ENABLE             RV(FV_CLECTLLIMIT_EN_ENABLE, FB_CLECTLLIMIT_EN)
#define RV_CLECTLLIMIT_EN_DISABLE            RV(FV_CLECTLLIMIT_EN_DISABLE, FB_CLECTLLIMIT_EN)
#define RV_CLECTL_COMP_EN_ENABLE             RV(FV_CLECTL_COMP_EN_ENABLE, FB_CLECTL_COMP_EN)
#define RV_CLECTL_COMP_EN_DISABLE            RV(FV_CLECTL_COMP_EN_DISABLE, FB_CLECTL_COMP_EN)


/*****************************
 *      R_MUGAIN (0x26)      *
 *****************************/

/* Field Offsets */
#define FB_MUGAIN_CLEMUG                     0                                  

/* Field Masks */
#define FM_MUGAIN_CLEMUG                     0X1F                               

/* Field Values */
#define FV_MUGAIN_CLEMUG_46PT5DB             0x1F                               
#define FV_MUGAIN_CLEMUG_0DB                 0x0                                

/* Register Default */
#define RD_MUGAIN                            0x0                                

/* Register Masks */
#define RM_MUGAIN_CLEMUG                     RM(FM_MUGAIN_CLEMUG, FB_MUGAIN_CLEMUG)

/* Register Values */
#define RV_MUGAIN_CLEMUG_46PT5DB             RV(FV_MUGAIN_CLEMUG_46PT5DB, FB_MUGAIN_CLEMUG)
#define RV_MUGAIN_CLEMUG_0DB                 RV(FV_MUGAIN_CLEMUG_0DB, FB_MUGAIN_CLEMUG)


/*****************************
 *      R_COMPTH (0x27)      *
 *****************************/

/* Field Offsets */
#define FB_COMPTH                            0                                  

/* Field Masks */
#define FM_COMPTH                            0XFF                               

/* Field Values */
#define FV_COMPTH_0DB                        0xFF                               
#define FV_COMPTH_N95PT625DB                 0x0                                

/* Register Default */
#define RD_COMPTH                            0x0                                

/* Register Masks */
#define RM_COMPTH                            RM(FM_COMPTH, FB_COMPTH)           

/* Register Values */
#define RV_COMPTH_0DB                        RV(FV_COMPTH_0DB, FB_COMPTH)       
#define RV_COMPTH_N95PT625DB                 RV(FV_COMPTH_N95PT625DB, FB_COMPTH)


/*****************************
 *      R_CMPRAT (0x28)      *
 *****************************/

/* Field Offsets */
#define FB_CMPRAT                            0                                  

/* Field Masks */
#define FM_CMPRAT                            0X1F                               

/* Field Values */

/* Register Default */
#define RD_CMPRAT                            0x0                                

/* Register Masks */
#define RM_CMPRAT                            RM(FM_CMPRAT, FB_CMPRAT)           

/* Register Values */


/******************************
 *      R_CATKTCL (0x29)      *
 ******************************/

/* Field Offsets */
#define FB_CATKTCL                           0                                  

/* Field Masks */
#define FM_CATKTCL                           0XFF                               

/* Field Values */

/* Register Default */
#define RD_CATKTCL                           0x0                                

/* Register Masks */
#define RM_CATKTCL                           RM(FM_CATKTCL, FB_CATKTCL)         

/* Register Values */


/******************************
 *      R_CATKTCH (0x2A)      *
 ******************************/

/* Field Offsets */
#define FB_CATKTCH                           0                                  

/* Field Masks */
#define FM_CATKTCH                           0XFF                               

/* Field Values */

/* Register Default */
#define RD_CATKTCH                           0x0                                

/* Register Masks */
#define RM_CATKTCH                           RM(FM_CATKTCH, FB_CATKTCH)         

/* Register Values */


/******************************
 *      R_CRELTCL (0x2B)      *
 ******************************/

/* Field Offsets */
#define FB_CRELTCL                           0                                  

/* Field Masks */
#define FM_CRELTCL                           0XFF                               

/* Field Values */

/* Register Default */
#define RD_CRELTCL                           0x0                                

/* Register Masks */
#define RM_CRELTCL                           RM(FM_CRELTCL, FB_CRELTCL)         

/* Register Values */


/******************************
 *      R_CRELTCH (0x2C)      *
 ******************************/

/* Field Offsets */
#define FB_CRELTCH                           0                                  

/* Field Masks */
#define FM_CRELTCH                           0XFF                               

/* Field Values */

/* Register Default */
#define RD_CRELTCH                           0x0                                

/* Register Masks */
#define RM_CRELTCH                           RM(FM_CRELTCH, FB_CRELTCH)         

/* Register Values */


/****************************
 *      R_LIMTH (0x2D)      *
 ****************************/

/* Field Offsets */
#define FB_LIMTH                             0                                  

/* Field Masks */
#define FM_LIMTH                             0XFF                               

/* Field Values */
#define FV_LIMTH_0DB                         0xFF                               
#define FV_LIMTH_N95PT625DB                  0x0                                

/* Register Default */
#define RD_LIMTH                             0x0                                

/* Register Masks */
#define RM_LIMTH                             RM(FM_LIMTH, FB_LIMTH)             

/* Register Values */
#define RV_LIMTH_0DB                         RV(FV_LIMTH_0DB, FB_LIMTH)         
#define RV_LIMTH_N95PT625DB                  RV(FV_LIMTH_N95PT625DB, FB_LIMTH)  


/*****************************
 *      R_LIMTGT (0x2E)      *
 *****************************/

/* Field Offsets */
#define FB_LIMTGT                            0                                  

/* Field Masks */
#define FM_LIMTGT                            0XFF                               

/* Field Values */
#define FV_LIMTGT_0DB                        0xFF                               
#define FV_LIMTGT_N95PT625DB                 0x0                                

/* Register Default */
#define RD_LIMTGT                            0x0                                

/* Register Masks */
#define RM_LIMTGT                            RM(FM_LIMTGT, FB_LIMTGT)           

/* Register Values */
#define RV_LIMTGT_0DB                        RV(FV_LIMTGT_0DB, FB_LIMTGT)       
#define RV_LIMTGT_N95PT625DB                 RV(FV_LIMTGT_N95PT625DB, FB_LIMTGT)


/******************************
 *      R_LATKTCL (0x2F)      *
 ******************************/

/* Field Offsets */
#define FB_LATKTCL                           0                                  

/* Field Masks */
#define FM_LATKTCL                           0XFF                               

/* Field Values */

/* Register Default */
#define RD_LATKTCL                           0x0                                

/* Register Masks */
#define RM_LATKTCL                           RM(FM_LATKTCL, FB_LATKTCL)         

/* Register Values */


/******************************
 *      R_LATKTCH (0x30)      *
 ******************************/

/* Field Offsets */
#define FB_LATKTCH                           0                                  

/* Field Masks */
#define FM_LATKTCH                           0XFF                               

/* Field Values */

/* Register Default */
#define RD_LATKTCH                           0x0                                

/* Register Masks */
#define RM_LATKTCH                           RM(FM_LATKTCH, FB_LATKTCH)         

/* Register Values */


/******************************
 *      R_LRELTCL (0x31)      *
 ******************************/

/* Field Offsets */
#define FB_LRELTCL                           0                                  

/* Field Masks */
#define FM_LRELTCL                           0XFF                               

/* Field Values */

/* Register Default */
#define RD_LRELTCL                           0x0                                

/* Register Masks */
#define RM_LRELTCL                           RM(FM_LRELTCL, FB_LRELTCL)         

/* Register Values */


/******************************
 *      R_LRELTCH (0x32)      *
 ******************************/

/* Field Offsets */
#define FB_LRELTCH                           0                                  

/* Field Masks */
#define FM_LRELTCH                           0XFF                               

/* Field Values */

/* Register Default */
#define RD_LRELTCH                           0x0                                

/* Register Masks */
#define RM_LRELTCH                           RM(FM_LRELTCH, FB_LRELTCH)         

/* Register Values */


/****************************
 *      R_EXPTH (0x33)      *
 ****************************/

/* Field Offsets */
#define FB_EXPTH                             0                                  

/* Field Masks */
#define FM_EXPTH                             0XFF                               

/* Field Values */
#define FV_EXPTH_0DB                         0xFF                               
#define FV_EXPTH_N95PT625DB                  0x0                                

/* Register Default */
#define RD_EXPTH                             0x0                                

/* Register Masks */
#define RM_EXPTH                             RM(FM_EXPTH, FB_EXPTH)             

/* Register Values */
#define RV_EXPTH_0DB                         RV(FV_EXPTH_0DB, FB_EXPTH)         
#define RV_EXPTH_N95PT625DB                  RV(FV_EXPTH_N95PT625DB, FB_EXPTH)  


/*****************************
 *      R_EXPRAT (0x34)      *
 *****************************/

/* Field Offsets */
#define FB_EXPRAT                            0                                  

/* Field Masks */
#define FM_EXPRAT                            0X1F                               

/* Field Values */

/* Register Default */
#define RD_EXPRAT                            0x0                                

/* Register Masks */
#define RM_EXPRAT                            RM(FM_EXPRAT, FB_EXPRAT)           

/* Register Values */


/******************************
 *      R_XATKTCL (0x35)      *
 ******************************/

/* Field Offsets */
#define FB_XATKTCL                           0                                  

/* Field Masks */
#define FM_XATKTCL                           0XFF                               

/* Field Values */

/* Register Default */
#define RD_XATKTCL                           0x0                                

/* Register Masks */
#define RM_XATKTCL                           RM(FM_XATKTCL, FB_XATKTCL)         

/* Register Values */


/******************************
 *      R_XATKTCH (0x36)      *
 ******************************/

/* Field Offsets */
#define FB_XATKTCH                           0                                  

/* Field Masks */
#define FM_XATKTCH                           0XFF                               

/* Field Values */

/* Register Default */
#define RD_XATKTCH                           0x0                                

/* Register Masks */
#define RM_XATKTCH                           RM(FM_XATKTCH, FB_XATKTCH)         

/* Register Values */


/******************************
 *      R_XRELTCL (0x37)      *
 ******************************/

/* Field Offsets */
#define FB_XRELTCL                           0                                  

/* Field Masks */
#define FM_XRELTCL                           0XFF                               

/* Field Values */

/* Register Default */
#define RD_XRELTCL                           0x0                                

/* Register Masks */
#define RM_XRELTCL                           RM(FM_XRELTCL, FB_XRELTCL)         

/* Register Values */


/******************************
 *      R_XRELTCH (0x38)      *
 ******************************/

/* Field Offsets */
#define FB_XRELTCH                           0                                  

/* Field Masks */
#define FM_XRELTCH                           0XFF                               

/* Field Values */

/* Register Default */
#define RD_XRELTCH                           0x0                                

/* Register Masks */
#define RM_XRELTCH                           RM(FM_XRELTCH, FB_XRELTCH)         

/* Register Values */


/****************************
 *      R_FXCTL (0x39)      *
 ****************************/

/* Field Offsets */
#define FB_FXCTL_3DEN                        4                                  
#define FB_FXCTL_TEEN                        3                                  
#define FB_FXCTL_TNLFBYPASS                  2                                  
#define FB_FXCTL_BEEN                        1                                  
#define FB_FXCTL_BNLFBYPASS                  0                                  

/* Field Masks */
#define FM_FXCTL_3DEN                        0X1                                
#define FM_FXCTL_TEEN                        0X1                                
#define FM_FXCTL_TNLFBYPASS                  0X1                                
#define FM_FXCTL_BEEN                        0X1                                
#define FM_FXCTL_BNLFBYPASS                  0X1                                

/* Field Values */
#define FV_FXCTL_3DEN_ENABLE                 0x1                                
#define FV_FXCTL_3DEN_DISABLE                0x0                                
#define FV_FXCTL_TEEN_ENABLE                 0x1                                
#define FV_FXCTL_TEEN_DISABLE                0x0                                
#define FV_FXCTL_TNLFBYPASS_ENABLE           0x1                                
#define FV_FXCTL_TNLFBYPASS_DISABLE          0x0                                
#define FV_FXCTL_BEEN_ENABLE                 0x1                                
#define FV_FXCTL_BEEN_DISABLE                0x0                                
#define FV_FXCTL_BNLFBYPASS_ENABLE           0x1                                
#define FV_FXCTL_BNLFBYPASS_DISABLE          0x0                                

/* Register Default */
#define RD_FXCTL                             0x0                                

/* Register Masks */
#define RM_FXCTL_3DEN                        RM(FM_FXCTL_3DEN, FB_FXCTL_3DEN)   
#define RM_FXCTL_TEEN                        RM(FM_FXCTL_TEEN, FB_FXCTL_TEEN)   
#define RM_FXCTL_TNLFBYPASS                  RM(FM_FXCTL_TNLFBYPASS, FB_FXCTL_TNLFBYPASS)
#define RM_FXCTL_BEEN                        RM(FM_FXCTL_BEEN, FB_FXCTL_BEEN)   
#define RM_FXCTL_BNLFBYPASS                  RM(FM_FXCTL_BNLFBYPASS, FB_FXCTL_BNLFBYPASS)

/* Register Values */
#define RV_FXCTL_3DEN_ENABLE                 RV(FV_FXCTL_3DEN_ENABLE, FB_FXCTL_3DEN)
#define RV_FXCTL_3DEN_DISABLE                RV(FV_FXCTL_3DEN_DISABLE, FB_FXCTL_3DEN)
#define RV_FXCTL_TEEN_ENABLE                 RV(FV_FXCTL_TEEN_ENABLE, FB_FXCTL_TEEN)
#define RV_FXCTL_TEEN_DISABLE                RV(FV_FXCTL_TEEN_DISABLE, FB_FXCTL_TEEN)
#define RV_FXCTL_TNLFBYPASS_ENABLE           RV(FV_FXCTL_TNLFBYPASS_ENABLE, FB_FXCTL_TNLFBYPASS)
#define RV_FXCTL_TNLFBYPASS_DISABLE          RV(FV_FXCTL_TNLFBYPASS_DISABLE, FB_FXCTL_TNLFBYPASS)
#define RV_FXCTL_BEEN_ENABLE                 RV(FV_FXCTL_BEEN_ENABLE, FB_FXCTL_BEEN)
#define RV_FXCTL_BEEN_DISABLE                RV(FV_FXCTL_BEEN_DISABLE, FB_FXCTL_BEEN)
#define RV_FXCTL_BNLFBYPASS_ENABLE           RV(FV_FXCTL_BNLFBYPASS_ENABLE, FB_FXCTL_BNLFBYPASS)
#define RV_FXCTL_BNLFBYPASS_DISABLE          RV(FV_FXCTL_BNLFBYPASS_DISABLE, FB_FXCTL_BNLFBYPASS)


/*******************************
 *      R_DACCRWRL (0x3A)      *
 *******************************/

/* Field Offsets */
#define FB_DACCRWRL_DACCRWDL                 0                                  

/* Field Masks */
#define FM_DACCRWRL_DACCRWDL                 0XFF                               

/* Field Values */

/* Register Default */
#define RD_DACCRWRL                          0x0                                

/* Register Masks */
#define RM_DACCRWRL_DACCRWDL                 RM(FM_DACCRWRL_DACCRWDL, FB_DACCRWRL_DACCRWDL)

/* Register Values */


/*******************************
 *      R_DACCRWRM (0x3B)      *
 *******************************/

/* Field Offsets */
#define FB_DACCRWRM_DACCRWDM                 0                                  

/* Field Masks */
#define FM_DACCRWRM_DACCRWDM                 0XFF                               

/* Field Values */

/* Register Default */
#define RD_DACCRWRM                          0x0                                

/* Register Masks */
#define RM_DACCRWRM_DACCRWDM                 RM(FM_DACCRWRM_DACCRWDM, FB_DACCRWRM_DACCRWDM)

/* Register Values */


/*******************************
 *      R_DACCRWRH (0x3C)      *
 *******************************/

/* Field Offsets */
#define FB_DACCRWRH_DACCRWDH                 0                                  

/* Field Masks */
#define FM_DACCRWRH_DACCRWDH                 0XFF                               

/* Field Values */

/* Register Default */
#define RD_DACCRWRH                          0x0                                

/* Register Masks */
#define RM_DACCRWRH_DACCRWDH                 RM(FM_DACCRWRH_DACCRWDH, FB_DACCRWRH_DACCRWDH)

/* Register Values */


/*******************************
 *      R_DACCRRDL (0x3D)      *
 *******************************/

/* Field Offsets */
#define FB_DACCRRDL                          0                                  

/* Field Masks */
#define FM_DACCRRDL                          0XFF                               

/* Field Values */

/* Register Default */
#define RD_DACCRRDL                          0x0                                

/* Register Masks */
#define RM_DACCRRDL                          RM(FM_DACCRRDL, FB_DACCRRDL)       

/* Register Values */


/*******************************
 *      R_DACCRRDM (0x3E)      *
 *******************************/

/* Field Offsets */
#define FB_DACCRRDM                          0                                  

/* Field Masks */
#define FM_DACCRRDM                          0XFF                               

/* Field Values */

/* Register Default */
#define RD_DACCRRDM                          0x0                                

/* Register Masks */
#define RM_DACCRRDM                          RM(FM_DACCRRDM, FB_DACCRRDM)       

/* Register Values */


/*******************************
 *      R_DACCRRDH (0x3F)      *
 *******************************/

/* Field Offsets */
#define FB_DACCRRDH                          0                                  

/* Field Masks */
#define FM_DACCRRDH                          0XFF                               

/* Field Values */

/* Register Default */
#define RD_DACCRRDH                          0x0                                

/* Register Masks */
#define RM_DACCRRDH                          RM(FM_DACCRRDH, FB_DACCRRDH)       

/* Register Values */


/********************************
 *      R_DACCRADDR (0x40)      *
 ********************************/

/* Field Offsets */
#define FB_DACCRADDR                         0                                  

/* Field Masks */
#define FM_DACCRADDR                         0XFF                               

/* Field Values */

/* Register Default */
#define RD_DACCRADDR                         0x0                                

/* Register Masks */
#define RM_DACCRADDR                         RM(FM_DACCRADDR, FB_DACCRADDR)     

/* Register Values */


/******************************
 *      R_DCOFSEL (0x41)      *
 ******************************/

/* Field Offsets */
#define FB_DCOFSEL_DC_COEF_SEL               0                                  

/* Field Masks */
#define FM_DCOFSEL_DC_COEF_SEL               0X7                                

/* Field Values */
#define FV_DCOFSEL_DC_COEF_SEL_2_N8          0x0                                
#define FV_DCOFSEL_DC_COEF_SEL_2_N9          0x1                                
#define FV_DCOFSEL_DC_COEF_SEL_2_N10         0x2                                
#define FV_DCOFSEL_DC_COEF_SEL_2_N11         0x3                                
#define FV_DCOFSEL_DC_COEF_SEL_2_N12         0x4                                
#define FV_DCOFSEL_DC_COEF_SEL_2_N13         0x5                                
#define FV_DCOFSEL_DC_COEF_SEL_2_N14         0x6                                
#define FV_DCOFSEL_DC_COEF_SEL_2_N15         0x7                                

/* Register Default */
#define RD_DCOFSEL                           0x0                                

/* Register Masks */
#define RM_DCOFSEL_DC_COEF_SEL               RM(FM_DCOFSEL_DC_COEF_SEL, FB_DCOFSEL_DC_COEF_SEL)

/* Register Values */
#define RV_DCOFSEL_DC_COEF_SEL_2_N8          RV(FV_DCOFSEL_DC_COEF_SEL_2_N8, FB_DCOFSEL_DC_COEF_SEL)
#define RV_DCOFSEL_DC_COEF_SEL_2_N9          RV(FV_DCOFSEL_DC_COEF_SEL_2_N9, FB_DCOFSEL_DC_COEF_SEL)
#define RV_DCOFSEL_DC_COEF_SEL_2_N10         RV(FV_DCOFSEL_DC_COEF_SEL_2_N10, FB_DCOFSEL_DC_COEF_SEL)
#define RV_DCOFSEL_DC_COEF_SEL_2_N11         RV(FV_DCOFSEL_DC_COEF_SEL_2_N11, FB_DCOFSEL_DC_COEF_SEL)
#define RV_DCOFSEL_DC_COEF_SEL_2_N12         RV(FV_DCOFSEL_DC_COEF_SEL_2_N12, FB_DCOFSEL_DC_COEF_SEL)
#define RV_DCOFSEL_DC_COEF_SEL_2_N13         RV(FV_DCOFSEL_DC_COEF_SEL_2_N13, FB_DCOFSEL_DC_COEF_SEL)
#define RV_DCOFSEL_DC_COEF_SEL_2_N14         RV(FV_DCOFSEL_DC_COEF_SEL_2_N14, FB_DCOFSEL_DC_COEF_SEL)
#define RV_DCOFSEL_DC_COEF_SEL_2_N15         RV(FV_DCOFSEL_DC_COEF_SEL_2_N15, FB_DCOFSEL_DC_COEF_SEL)


/***************************
 *      R_PWM0 (0x42)      *
 ***************************/

/* Field Offsets */
#define FB_PWM0_SCTO                         6                                  
#define FB_PWM0_UVLO                         5                                  
#define FB_PWM0ROUNDUP                       4                                  
#define FB_PWM0_BFCLR                        3                                  
#define FB_PWM0_FOURTHORDER                  2                                  
#define FB_PWM0_ADD3_SEL                     1                                  
#define FB_PWM0_QUANTIZER_SEL                0                                  

/* Field Masks */
#define FM_PWM0_SCTO                         0X3                                
#define FM_PWM0_UVLO                         0X1                                
#define FM_PWM0ROUNDUP                       0X1                                
#define FM_PWM0_BFCLR                        0X1                                
#define FM_PWM0_FOURTHORDER                  0X1                                
#define FM_PWM0_ADD3_SEL                     0X1                                
#define FM_PWM0_QUANTIZER_SEL                0X1                                

/* Field Values */
#define FV_PWM0_SCTO_10US                    0x0                                
#define FV_PWM0_SCTO_100US                   0x1                                
#define FV_PWM0_SCTO_500US                   0x2                                
#define FV_PWM0_SCTO_100MS                   0x3                                
#define FV_PWM0_UVLO_ENABLE                  0x1                                
#define FV_PWM0_UVLO_DISABLE                 0x0                                
#define FV_PWM0_BFCLR_DISABLE                0x1                                
#define FV_PWM0_BFCLR_ENABLE                 0x0                                
#define FV_PWM0_FOURTHORDER_BINARY           0x0                                
#define FV_PWM0_FOURTHORDER_TERNARY          0x1                                

/* Register Default */
#define RD_PWM0                              0x3                                

/* Register Masks */
#define RM_PWM0_SCTO                         RM(FM_PWM0_SCTO, FB_PWM0_SCTO)     
#define RM_PWM0_UVLO                         RM(FM_PWM0_UVLO, FB_PWM0_UVLO)     
#define RM_PWM0ROUNDUP                       RM(FM_PWM0ROUNDUP, FB_PWM0ROUNDUP) 
#define RM_PWM0_BFCLR                        RM(FM_PWM0_BFCLR, FB_PWM0_BFCLR)   
#define RM_PWM0_FOURTHORDER                  RM(FM_PWM0_FOURTHORDER, FB_PWM0_FOURTHORDER)
#define RM_PWM0_ADD3_SEL                     RM(FM_PWM0_ADD3_SEL, FB_PWM0_ADD3_SEL)
#define RM_PWM0_QUANTIZER_SEL                RM(FM_PWM0_QUANTIZER_SEL, FB_PWM0_QUANTIZER_SEL)

/* Register Values */
#define RV_PWM0_SCTO_10US                    RV(FV_PWM0_SCTO_10US, FB_PWM0_SCTO)
#define RV_PWM0_SCTO_100US                   RV(FV_PWM0_SCTO_100US, FB_PWM0_SCTO)
#define RV_PWM0_SCTO_500US                   RV(FV_PWM0_SCTO_500US, FB_PWM0_SCTO)
#define RV_PWM0_SCTO_100MS                   RV(FV_PWM0_SCTO_100MS, FB_PWM0_SCTO)
#define RV_PWM0_UVLO_ENABLE                  RV(FV_PWM0_UVLO_ENABLE, FB_PWM0_UVLO)
#define RV_PWM0_UVLO_DISABLE                 RV(FV_PWM0_UVLO_DISABLE, FB_PWM0_UVLO)
#define RV_PWM0_BFCLR_DISABLE                RV(FV_PWM0_BFCLR_DISABLE, FB_PWM0_BFCLR)
#define RV_PWM0_BFCLR_ENABLE                 RV(FV_PWM0_BFCLR_ENABLE, FB_PWM0_BFCLR)
#define RV_PWM0_FOURTHORDER_BINARY           RV(FV_PWM0_FOURTHORDER_BINARY, FB_PWM0_FOURTHORDER)
#define RV_PWM0_FOURTHORDER_TERNARY          RV(FV_PWM0_FOURTHORDER_TERNARY, FB_PWM0_FOURTHORDER)


/***************************
 *      R_PWM1 (0x43)      *
 ***************************/

/* Field Offsets */
#define FB_PWM1_DITHPOS                      2                                  
#define FB_PWM1_DITHRANGE                    1                                  
#define FB_PWM1_DITHCLR                      0                                  

/* Field Masks */
#define FM_PWM1_DITHPOS                      0X1F                               
#define FM_PWM1_DITHRANGE                    0X1                                
#define FM_PWM1_DITHCLR                      0X1                                

/* Field Values */
#define FV_PWM1_DITHPOS_FULL                 0x0                                
#define FV_PWM1_DITHPOS_HALF                 0x1                                
#define FV_PWM1_DITHPOS_QUARTER              0x2                                
#define FV_PWM1_DITHPOS_8TH                  0x3                                
#define FV_PWM1_DITHPOS_16TH                 0x4                                

/* Register Default */
#define RD_PWM1                              0x0                                

/* Register Masks */
#define RM_PWM1_DITHPOS                      RM(FM_PWM1_DITHPOS, FB_PWM1_DITHPOS)
#define RM_PWM1_DITHRANGE                    RM(FM_PWM1_DITHRANGE, FB_PWM1_DITHRANGE)
#define RM_PWM1_DITHCLR                      RM(FM_PWM1_DITHCLR, FB_PWM1_DITHCLR)

/* Register Values */
#define RV_PWM1_DITHPOS_FULL                 RV(FV_PWM1_DITHPOS_FULL, FB_PWM1_DITHPOS)
#define RV_PWM1_DITHPOS_HALF                 RV(FV_PWM1_DITHPOS_HALF, FB_PWM1_DITHPOS)
#define RV_PWM1_DITHPOS_QUARTER              RV(FV_PWM1_DITHPOS_QUARTER, FB_PWM1_DITHPOS)
#define RV_PWM1_DITHPOS_8TH                  RV(FV_PWM1_DITHPOS_8TH, FB_PWM1_DITHPOS)
#define RV_PWM1_DITHPOS_16TH                 RV(FV_PWM1_DITHPOS_16TH, FB_PWM1_DITHPOS)


/***************************
 *      R_PWM2 (0x44)      *
 ***************************/

/* Field Offsets */
#define FB_PWM2_DVALUE                       2                                  
#define FB_PWM2_PWM_OUTMODE                  0                                  

/* Field Masks */
#define FM_PWM2_DVALUE                       0X3F                               
#define FM_PWM2_PWM_OUTMODE                  0X1                                

/* Field Values */

/* Register Default */
#define RD_PWM2                              0x18                               

/* Register Masks */
#define RM_PWM2_DVALUE                       RM(FM_PWM2_DVALUE, FB_PWM2_DVALUE) 
#define RM_PWM2_PWM_OUTMODE                  RM(FM_PWM2_PWM_OUTMODE, FB_PWM2_PWM_OUTMODE)

/* Register Values */


/***************************
 *      R_PWM3 (0x45)      *
 ***************************/

/* Field Offsets */
#define FB_PWM3_OUTCTRL                      6                                  
#define FB_PWM3_CVALUE                       0                                  

/* Field Masks */
#define FM_PWM3_OUTCTRL                      0X3                                
#define FM_PWM3_CVALUE                       0X3F                               

/* Field Values */
#define FV_PWM3_OUTCTRL_NORMAL               0x0                                
#define FV_PWM3_OUTCTRL_SWAP                 0x1                                
#define FV_PWM3_OUTCTRL_CHAN0_L              0x2                                
#define FV_PWM3_OUTCTRL_CHAN1_R              0x3                                

/* Register Default */
#define RD_PWM3                              0x0                                

/* Register Masks */
#define RM_PWM3_OUTCTRL                      RM(FM_PWM3_OUTCTRL, FB_PWM3_OUTCTRL)
#define RM_PWM3_CVALUE                       RM(FM_PWM3_CVALUE, FB_PWM3_CVALUE) 

/* Register Values */
#define RV_PWM3_OUTCTRL_NORMAL               RV(FV_PWM3_OUTCTRL_NORMAL, FB_PWM3_OUTCTRL)
#define RV_PWM3_OUTCTRL_SWAP                 RV(FV_PWM3_OUTCTRL_SWAP, FB_PWM3_OUTCTRL)
#define RV_PWM3_OUTCTRL_CHAN0_L              RV(FV_PWM3_OUTCTRL_CHAN0_L, FB_PWM3_OUTCTRL)
#define RV_PWM3_OUTCTRL_CHAN1_R              RV(FV_PWM3_OUTCTRL_CHAN1_R, FB_PWM3_OUTCTRL)


/******************************
 *      R_PLLCTL1 (0x46)      *
 ******************************/

/* Field Offsets */
#define FB_PLLCTL1REFDIV_PLLSS               0                                  

/* Field Masks */
#define FM_PLLCTL1REFDIV_PLLSS               0XFF                               

/* Field Values */

/* Register Default */
#define RD_PLLCTL1                           0x19                               

/* Register Masks */
#define RM_PLLCTL1REFDIV_PLLSS               RM(FM_PLLCTL1REFDIV_PLLSS, FB_PLLCTL1REFDIV_PLLSS)

/* Register Values */


/******************************
 *      R_PLLCTL2 (0x47)      *
 ******************************/

/* Field Offsets */
#define FB_PLLCTL2_OUTDIV_PLLSS              0                                  

/* Field Masks */
#define FM_PLLCTL2_OUTDIV_PLLSS              0XFF                               

/* Field Values */

/* Register Default */
#define RD_PLLCTL2                           0x0D                               

/* Register Masks */
#define RM_PLLCTL2_OUTDIV_PLLSS              RM(FM_PLLCTL2_OUTDIV_PLLSS, FB_PLLCTL2_OUTDIV_PLLSS)

/* Register Values */


/******************************
 *      R_PLLCTL3 (0x48)      *
 ******************************/

/* Field Offsets */
#define FB_PLLCTL3_FBDIV_PLLSSL              0                                  

/* Field Masks */
#define FM_PLLCTL3_FBDIV_PLLSSL              0XFF                               

/* Field Values */

/* Register Default */
#define RD_PLLCTL3                           0x70                               

/* Register Masks */
#define RM_PLLCTL3_FBDIV_PLLSSL              RM(FM_PLLCTL3_FBDIV_PLLSSL, FB_PLLCTL3_FBDIV_PLLSSL)

/* Register Values */


/******************************
 *      R_PLLCTL4 (0x49)      *
 ******************************/

/* Field Offsets */
#define FB_PLLCTL4_FBDIV_PLLSSH              0                                  

/* Field Masks */
#define FM_PLLCTL4_FBDIV_PLLSSH              0X7                                

/* Field Values */

/* Register Default */
#define RD_PLLCTL4                           0x0                                

/* Register Masks */
#define RM_PLLCTL4_FBDIV_PLLSSH              RM(FM_PLLCTL4_FBDIV_PLLSSH, FB_PLLCTL4_FBDIV_PLLSSH)

/* Register Values */


/******************************
 *      R_PLLCTL5 (0x4A)      *
 ******************************/

/* Field Offsets */
#define FB_PLLCTL5_MOD_PLLSS                 0                                  

/* Field Masks */
#define FM_PLLCTL5_MOD_PLLSS                 0XFF                               

/* Field Values */

/* Register Default */
#define RD_PLLCTL5                           0x0                                

/* Register Masks */
#define RM_PLLCTL5_MOD_PLLSS                 RM(FM_PLLCTL5_MOD_PLLSS, FB_PLLCTL5_MOD_PLLSS)

/* Register Values */


/******************************
 *      R_PLLCTL6 (0x4B)      *
 ******************************/

/* Field Offsets */
#define FB_PLLCTL6_SPREAD_PLLSSL             0                                  

/* Field Masks */
#define FM_PLLCTL6_SPREAD_PLLSSL             0XFF                               

/* Field Values */

/* Register Default */
#define RD_PLLCTL6                           0x0                                

/* Register Masks */
#define RM_PLLCTL6_SPREAD_PLLSSL             RM(FM_PLLCTL6_SPREAD_PLLSSL, FB_PLLCTL6_SPREAD_PLLSSL)

/* Register Values */


/******************************
 *      R_PLLCTL7 (0x4C)      *
 ******************************/

/* Field Offsets */
#define FB_PLLCTL7_SPREAD_PLLSSH             0                                  

/* Field Masks */
#define FM_PLLCTL7_SPREAD_PLLSSH             0X1F                               

/* Field Values */

/* Register Default */
#define RD_PLLCTL7                           0x0                                

/* Register Masks */
#define RM_PLLCTL7_SPREAD_PLLSSH             RM(FM_PLLCTL7_SPREAD_PLLSSH, FB_PLLCTL7_SPREAD_PLLSSH)

/* Register Values */


/******************************
 *      R_PLLCTL8 (0x4D)      *
 ******************************/

/* Field Offsets */
#define FB_PLLCTL8_CPSS_PLSS                 5                                  
#define FB_PLLCTL8RZ_PLLSS                   3                                  
#define FB_PLLCTL8_CP_PLLSS                  0                                  

/* Field Masks */
#define FM_PLLCTL8_CPSS_PLSS                 0X7                                
#define FM_PLLCTL8RZ_PLLSS                   0X3                                
#define FM_PLLCTL8_CP_PLLSS                  0X7                                

/* Field Values */

/* Register Default */
#define RD_PLLCTL8                           0x1                                

/* Register Masks */
#define RM_PLLCTL8_CPSS_PLSS                 RM(FM_PLLCTL8_CPSS_PLSS, FB_PLLCTL8_CPSS_PLSS)
#define RM_PLLCTL8RZ_PLLSS                   RM(FM_PLLCTL8RZ_PLLSS, FB_PLLCTL8RZ_PLLSS)
#define RM_PLLCTL8_CP_PLLSS                  RM(FM_PLLCTL8_CP_PLLSS, FB_PLLCTL8_CP_PLLSS)

/* Register Values */


/******************************
 *      R_PLLCTL9 (0x4E)      *
 ******************************/

/* Field Offsets */
#define FB_PLLCTL9REFDIV_PLL1                0                                  

/* Field Masks */
#define FM_PLLCTL9REFDIV_PLL1                0XFF                               

/* Field Values */

/* Register Default */
#define RD_PLLCTL9                           0x5                                

/* Register Masks */
#define RM_PLLCTL9REFDIV_PLL1                RM(FM_PLLCTL9REFDIV_PLL1, FB_PLLCTL9REFDIV_PLL1)

/* Register Values */


/******************************
 *      R_PLLCTLA (0x4F)      *
 ******************************/

/* Field Offsets */
#define FB_PLLCTLA_OUTDIV_PLL1               0                                  

/* Field Masks */
#define FM_PLLCTLA_OUTDIV_PLL1               0XFF                               

/* Field Values */

/* Register Default */
#define RD_PLLCTLA                           0x3                                

/* Register Masks */
#define RM_PLLCTLA_OUTDIV_PLL1               RM(FM_PLLCTLA_OUTDIV_PLL1, FB_PLLCTLA_OUTDIV_PLL1)

/* Register Values */


/******************************
 *      R_PLLCTLB (0x50)      *
 ******************************/

/* Field Offsets */
#define FB_PLLCTLB_FBDIV_PLL1L               0                                  

/* Field Masks */
#define FM_PLLCTLB_FBDIV_PLL1L               0XFF                               

/* Field Values */

/* Register Default */
#define RD_PLLCTLB                           0xC4                               

/* Register Masks */
#define RM_PLLCTLB_FBDIV_PLL1L               RM(FM_PLLCTLB_FBDIV_PLL1L, FB_PLLCTLB_FBDIV_PLL1L)

/* Register Values */


/******************************
 *      R_PLLCTLC (0x51)      *
 ******************************/

/* Field Offsets */
#define FB_PLLCTLC_FBDIV_PLL1H               0                                  

/* Field Masks */
#define FM_PLLCTLC_FBDIV_PLL1H               0X7                                

/* Field Values */

/* Register Default */
#define RD_PLLCTLC                           0x0                                

/* Register Masks */
#define RM_PLLCTLC_FBDIV_PLL1H               RM(FM_PLLCTLC_FBDIV_PLL1H, FB_PLLCTLC_FBDIV_PLL1H)

/* Register Values */


/******************************
 *      R_PLLCTLD (0x52)      *
 ******************************/

/* Field Offsets */
#define FB_PLLCTLDRZ_PLL1                    3                                  
#define FB_PLLCTLD_CP_PLL1                   0                                  

/* Field Masks */
#define FM_PLLCTLDRZ_PLL1                    0X3                                
#define FM_PLLCTLD_CP_PLL1                   0X7                                

/* Field Values */

/* Register Default */
#define RD_PLLCTLD                           0x0                                

/* Register Masks */
#define RM_PLLCTLDRZ_PLL1                    RM(FM_PLLCTLDRZ_PLL1, FB_PLLCTLDRZ_PLL1)
#define RM_PLLCTLD_CP_PLL1                   RM(FM_PLLCTLD_CP_PLL1, FB_PLLCTLD_CP_PLL1)

/* Register Values */


/******************************
 *      R_PLLCTLE (0x53)      *
 ******************************/

/* Field Offsets */
#define FB_PLLCTLEREFDIV_PLL2                0                                  

/* Field Masks */
#define FM_PLLCTLEREFDIV_PLL2                0XFF                               

/* Field Values */

/* Register Default */
#define RD_PLLCTLE                           0x3                                

/* Register Masks */
#define RM_PLLCTLEREFDIV_PLL2                RM(FM_PLLCTLEREFDIV_PLL2, FB_PLLCTLEREFDIV_PLL2)

/* Register Values */


/******************************
 *      R_PLLCTLF (0x54)      *
 ******************************/

/* Field Offsets */
#define FB_PLLCTLF_OUTDIV_PLL2               0                                  

/* Field Masks */
#define FM_PLLCTLF_OUTDIV_PLL2               0XFF                               

/* Field Values */

/* Register Default */
#define RD_PLLCTLF                           0x3                                

/* Register Masks */
#define RM_PLLCTLF_OUTDIV_PLL2               RM(FM_PLLCTLF_OUTDIV_PLL2, FB_PLLCTLF_OUTDIV_PLL2)

/* Register Values */


/*******************************
 *      R_PLLCTL10 (0x55)      *
 *******************************/

/* Field Offsets */
#define FB_PLLCTL10_FBDIV_PLL2L              0                                  

/* Field Masks */
#define FM_PLLCTL10_FBDIV_PLL2L              0XFF                               

/* Field Values */

/* Register Default */
#define RD_PLLCTL10                          0x80                               

/* Register Masks */
#define RM_PLLCTL10_FBDIV_PLL2L              RM(FM_PLLCTL10_FBDIV_PLL2L, FB_PLLCTL10_FBDIV_PLL2L)

/* Register Values */


/*******************************
 *      R_PLLCTL11 (0x56)      *
 *******************************/

/* Field Offsets */
#define FB_PLLCTL11_FBDIV_PLL2H              0                                  

/* Field Masks */
#define FM_PLLCTL11_FBDIV_PLL2H              0X7                                

/* Field Values */

/* Register Default */
#define RD_PLLCTL11                          0x0                                

/* Register Masks */
#define RM_PLLCTL11_FBDIV_PLL2H              RM(FM_PLLCTL11_FBDIV_PLL2H, FB_PLLCTL11_FBDIV_PLL2H)

/* Register Values */


/*******************************
 *      R_PLLCTL12 (0x57)      *
 *******************************/

/* Field Offsets */
#define FB_PLLCTL12RZ_PLL2                   3                                  
#define FB_PLLCTL12_CP_PLL2                  0                                  

/* Field Masks */
#define FM_PLLCTL12RZ_PLL2                   0X3                                
#define FM_PLLCTL12_CP_PLL2                  0X7                                

/* Field Values */

/* Register Default */
#define RD_PLLCTL12                          0x0                                

/* Register Masks */
#define RM_PLLCTL12RZ_PLL2                   RM(FM_PLLCTL12RZ_PLL2, FB_PLLCTL12RZ_PLL2)
#define RM_PLLCTL12_CP_PLL2                  RM(FM_PLLCTL12_CP_PLL2, FB_PLLCTL12_CP_PLL2)

/* Register Values */


/*******************************
 *      R_PLLCTL13 (0x58)      *
 *******************************/

/* Field Offsets */
#define FB_PLLCTL13REFDIV_PL3                0                                  

/* Field Masks */
#define FM_PLLCTL13REFDIV_PL3                0XFF                               

/* Field Values */

/* Register Default */
#define RD_PLLCTL13                          0x19                               

/* Register Masks */
#define RM_PLLCTL13REFDIV_PL3                RM(FM_PLLCTL13REFDIV_PL3, FB_PLLCTL13REFDIV_PL3)

/* Register Values */


/*******************************
 *      R_PLLCTL14 (0x59)      *
 *******************************/

/* Field Offsets */
#define FB_PLLCTL14_OUTDIV1_PLL3             0                                  

/* Field Masks */
#define FM_PLLCTL14_OUTDIV1_PLL3             0XFF                               

/* Field Values */

/* Register Default */
#define RD_PLLCTL14                          0x9                                

/* Register Masks */
#define RM_PLLCTL14_OUTDIV1_PLL3             RM(FM_PLLCTL14_OUTDIV1_PLL3, FB_PLLCTL14_OUTDIV1_PLL3)

/* Register Values */


/*******************************
 *      R_PLLCTL15 (0x5A)      *
 *******************************/

/* Field Offsets */
#define FB_PLLCTL15_OUTDIV2_PLL3             0                                  

/* Field Masks */
#define FM_PLLCTL15_OUTDIV2_PLL3             0XFF                               

/* Field Values */

/* Register Default */
#define RD_PLLCTL15                          0x10                               

/* Register Masks */
#define RM_PLLCTL15_OUTDIV2_PLL3             RM(FM_PLLCTL15_OUTDIV2_PLL3, FB_PLLCTL15_OUTDIV2_PLL3)

/* Register Values */


/*******************************
 *      R_PLLCTL16 (0x5B)      *
 *******************************/

/* Field Offsets */
#define FB_PLLCTL16_OUTDIV3_PLL3             0                                  

/* Field Masks */
#define FM_PLLCTL16_OUTDIV3_PLL3             0XFF                               

/* Field Values */

/* Register Default */
#define RD_PLLCTL16                          0x32                               

/* Register Masks */
#define RM_PLLCTL16_OUTDIV3_PLL3             RM(FM_PLLCTL16_OUTDIV3_PLL3, FB_PLLCTL16_OUTDIV3_PLL3)

/* Register Values */


/*******************************
 *      R_PLLCTL17 (0x5C)      *
 *******************************/

/* Field Offsets */
#define FB_PLLCTL17_FBDIV_PLL3L              0                                  

/* Field Masks */
#define FM_PLLCTL17_FBDIV_PLL3L              0XFF                               

/* Field Values */

/* Register Default */
#define RD_PLLCTL17                          0xB0                               

/* Register Masks */
#define RM_PLLCTL17_FBDIV_PLL3L              RM(FM_PLLCTL17_FBDIV_PLL3L, FB_PLLCTL17_FBDIV_PLL3L)

/* Register Values */


/*******************************
 *      R_PLLCTL18 (0x5D)      *
 *******************************/

/* Field Offsets */
#define FB_PLLCTL18_FBDIV_PLL3H              0                                  

/* Field Masks */
#define FM_PLLCTL18_FBDIV_PLL3H              0X7                                

/* Field Values */

/* Register Default */
#define RD_PLLCTL18                          0x0                                

/* Register Masks */
#define RM_PLLCTL18_FBDIV_PLL3H              RM(FM_PLLCTL18_FBDIV_PLL3H, FB_PLLCTL18_FBDIV_PLL3H)

/* Register Values */


/*******************************
 *      R_PLLCTL19 (0x5E)      *
 *******************************/

/* Field Offsets */
#define FB_PLLCTL19RZ_PLL3                   3                                  
#define FB_PLLCTL19_CP_PLL3                  0                                  

/* Field Masks */
#define FM_PLLCTL19RZ_PLL3                   0X3                                
#define FM_PLLCTL19_CP_PLL3                  0X7                                

/* Field Values */

/* Register Default */
#define RD_PLLCTL19                          0x0                                

/* Register Masks */
#define RM_PLLCTL19RZ_PLL3                   RM(FM_PLLCTL19RZ_PLL3, FB_PLLCTL19RZ_PLL3)
#define RM_PLLCTL19_CP_PLL3                  RM(FM_PLLCTL19_CP_PLL3, FB_PLLCTL19_CP_PLL3)

/* Register Values */


/*******************************
 *      R_PLLCTL1A (0x5F)      *
 *******************************/

/* Field Offsets */
#define FB_PLLCTL1A_DIV_22OR24M              0                                  

/* Field Masks */
#define FM_PLLCTL1A_DIV_22OR24M              0XFF                               

/* Field Values */

/* Register Default */
#define RD_PLLCTL1A                          0x0F                               

/* Register Masks */
#define RM_PLLCTL1A_DIV_22OR24M              RM(FM_PLLCTL1A_DIV_22OR24M, FB_PLLCTL1A_DIV_22OR24M)

/* Register Values */


/*******************************
 *      R_PLLCTL1B (0x60)      *
 *******************************/

/* Field Offsets */
#define FB_PLLCTL1B_VCOI_PLL3                6                                  
#define FB_PLLCTL1B_VCOI_PLL2                4                                  
#define FB_PLLCTL1B_VCOI_PLL1                2                                  
#define FB_PLLCTL1B_VCOI_PLLSS               0                                  

/* Field Masks */
#define FM_PLLCTL1B_VCOI_PLL3                0X3                                
#define FM_PLLCTL1B_VCOI_PLL2                0X3                                
#define FM_PLLCTL1B_VCOI_PLL1                0X3                                
#define FM_PLLCTL1B_VCOI_PLLSS               0X3                                

/* Field Values */

/* Register Default */
#define RD_PLLCTL1B                          0x1                                

/* Register Masks */
#define RM_PLLCTL1B_VCOI_PLL3                RM(FM_PLLCTL1B_VCOI_PLL3, FB_PLLCTL1B_VCOI_PLL3)
#define RM_PLLCTL1B_VCOI_PLL2                RM(FM_PLLCTL1B_VCOI_PLL2, FB_PLLCTL1B_VCOI_PLL2)
#define RM_PLLCTL1B_VCOI_PLL1                RM(FM_PLLCTL1B_VCOI_PLL1, FB_PLLCTL1B_VCOI_PLL1)
#define RM_PLLCTL1B_VCOI_PLLSS               RM(FM_PLLCTL1B_VCOI_PLLSS, FB_PLLCTL1B_VCOI_PLLSS)

/* Register Values */


/*******************************
 *      R_PLLCTL1C (0x61)      *
 *******************************/

/* Field Offsets */
#define FB_PLLCTL1C_PDB_PLL3                 3                                  
#define FB_PLLCTL1C_PDB_PLL2                 2                                  
#define FB_PLLCTL1C_PDB_PLL1                 1                                  
#define FB_PLLCTL1C_PDB_PLLSS                0                                  

/* Field Masks */
#define FM_PLLCTL1C_PDB_PLL3                 0X1                                
#define FM_PLLCTL1C_PDB_PLL2                 0X1                                
#define FM_PLLCTL1C_PDB_PLL1                 0X1                                
#define FM_PLLCTL1C_PDB_PLLSS                0X1                                

/* Field Values */
#define FV_PLLCTL1C_PDB_PLL3_ON              0x1                                
#define FV_PLLCTL1C_PDB_PLL3_OFF             0x0                                
#define FV_PLLCTL1C_PDB_PLL2_ON              0x1                                
#define FV_PLLCTL1C_PDB_PLL2_OFF             0x0                                
#define FV_PLLCTL1C_PDB_PLL1_ON              0x1                                
#define FV_PLLCTL1C_PDB_PLL1_OFF             0x0                                
#define FV_PLLCTL1C_PDB_PLLSS_ON             0x1                                
#define FV_PLLCTL1C_PDB_PLLSS_OFF            0x0                                

/* Register Default */
#define RD_PLLCTL1C                          0x0                                

/* Register Masks */
#define RM_PLLCTL1C_PDB_PLL3                 RM(FM_PLLCTL1C_PDB_PLL3, FB_PLLCTL1C_PDB_PLL3)
#define RM_PLLCTL1C_PDB_PLL2                 RM(FM_PLLCTL1C_PDB_PLL2, FB_PLLCTL1C_PDB_PLL2)
#define RM_PLLCTL1C_PDB_PLL1                 RM(FM_PLLCTL1C_PDB_PLL1, FB_PLLCTL1C_PDB_PLL1)
#define RM_PLLCTL1C_PDB_PLLSS                RM(FM_PLLCTL1C_PDB_PLLSS, FB_PLLCTL1C_PDB_PLLSS)

/* Register Values */
#define RV_PLLCTL1C_PDB_PLL3_ON              RV(FV_PLLCTL1C_PDB_PLL3_ON, FB_PLLCTL1C_PDB_PLL3)
#define RV_PLLCTL1C_PDB_PLL3_OFF             RV(FV_PLLCTL1C_PDB_PLL3_OFF, FB_PLLCTL1C_PDB_PLL3)
#define RV_PLLCTL1C_PDB_PLL2_ON              RV(FV_PLLCTL1C_PDB_PLL2_ON, FB_PLLCTL1C_PDB_PLL2)
#define RV_PLLCTL1C_PDB_PLL2_OFF             RV(FV_PLLCTL1C_PDB_PLL2_OFF, FB_PLLCTL1C_PDB_PLL2)
#define RV_PLLCTL1C_PDB_PLL1_ON              RV(FV_PLLCTL1C_PDB_PLL1_ON, FB_PLLCTL1C_PDB_PLL1)
#define RV_PLLCTL1C_PDB_PLL1_OFF             RV(FV_PLLCTL1C_PDB_PLL1_OFF, FB_PLLCTL1C_PDB_PLL1)
#define RV_PLLCTL1C_PDB_PLLSS_ON             RV(FV_PLLCTL1C_PDB_PLLSS_ON, FB_PLLCTL1C_PDB_PLLSS)
#define RV_PLLCTL1C_PDB_PLLSS_OFF            RV(FV_PLLCTL1C_PDB_PLLSS_OFF, FB_PLLCTL1C_PDB_PLLSS)


/*******************************
 *      R_PLLCTL1D (0x62)      *
 *******************************/

/* Field Offsets */
#define FB_PLLCTL1D_SSENB_PLLSS              3                                  
#define FB_PLLCTL1D_XTALHALF                 2                                  
#define FB_PLLCTL1D_22_24M_SEL               0                                  

/* Field Masks */
#define FM_PLLCTL1D_SSENB_PLLSS              0X1                                
#define FM_PLLCTL1D_XTALHALF                 0X1                                
#define FM_PLLCTL1D_22_24M_SEL               0X1                                

/* Field Values */

/* Register Default */
#define RD_PLLCTL1D                          0x0                                

/* Register Masks */
#define RM_PLLCTL1D_SSENB_PLLSS              RM(FM_PLLCTL1D_SSENB_PLLSS, FB_PLLCTL1D_SSENB_PLLSS)
#define RM_PLLCTL1D_XTALHALF                 RM(FM_PLLCTL1D_XTALHALF, FB_PLLCTL1D_XTALHALF)
#define RM_PLLCTL1D_22_24M_SEL               RM(FM_PLLCTL1D_22_24M_SEL, FB_PLLCTL1D_22_24M_SEL)

/* Register Values */


/*******************************
 *      R_PLLCTL1E (0x63)      *
 *******************************/

/* Field Offsets */
#define FB_PLLCTL1E_OUT1SSOE                 6                                  
#define FB_PLLCTL1E_OUT4OE                   5                                  
#define FB_PLLCTL1E_OUT3OE                   4                                  
#define FB_PLLCTL1E_OUT2OE                   3                                  
#define FB_PLLCTL1EREFOE                     2                                  
#define FB_PLLCTL1E_112MOE                   1                                  
#define FB_PLLCTL1E_122MOE                   0                                  

/* Field Masks */
#define FM_PLLCTL1E_OUT1SSOE                 0X1                                
#define FM_PLLCTL1E_OUT4OE                   0X1                                
#define FM_PLLCTL1E_OUT3OE                   0X1                                
#define FM_PLLCTL1E_OUT2OE                   0X1                                
#define FM_PLLCTL1EREFOE                     0X1                                
#define FM_PLLCTL1E_112MOE                   0X1                                
#define FM_PLLCTL1E_122MOE                   0X1                                

/* Field Values */

/* Register Default */
#define RD_PLLCTL1E                          0x0                                

/* Register Masks */
#define RM_PLLCTL1E_OUT1SSOE                 RM(FM_PLLCTL1E_OUT1SSOE, FB_PLLCTL1E_OUT1SSOE)
#define RM_PLLCTL1E_OUT4OE                   RM(FM_PLLCTL1E_OUT4OE, FB_PLLCTL1E_OUT4OE)
#define RM_PLLCTL1E_OUT3OE                   RM(FM_PLLCTL1E_OUT3OE, FB_PLLCTL1E_OUT3OE)
#define RM_PLLCTL1E_OUT2OE                   RM(FM_PLLCTL1E_OUT2OE, FB_PLLCTL1E_OUT2OE)
#define RM_PLLCTL1EREFOE                     RM(FM_PLLCTL1EREFOE, FB_PLLCTL1EREFOE)
#define RM_PLLCTL1E_112MOE                   RM(FM_PLLCTL1E_112MOE, FB_PLLCTL1E_112MOE)
#define RM_PLLCTL1E_122MOE                   RM(FM_PLLCTL1E_122MOE, FB_PLLCTL1E_122MOE)

/* Register Values */


/*******************************
 *      R_PLLCTL1F (0x64)      *
 *******************************/

/* Field Offsets */
#define FB_PLLCTL1F_SLEW_OUT2                4                                  
#define FB_PLLCTL1F_SLEWREFOUT               0                                  

/* Field Masks */
#define FM_PLLCTL1F_SLEW_OUT2                0XF                                
#define FM_PLLCTL1F_SLEWREFOUT               0XF                                

/* Field Values */

/* Register Default */
#define RD_PLLCTL1F                          0x8                                

/* Register Masks */
#define RM_PLLCTL1F_SLEW_OUT2                RM(FM_PLLCTL1F_SLEW_OUT2, FB_PLLCTL1F_SLEW_OUT2)
#define RM_PLLCTL1F_SLEWREFOUT               RM(FM_PLLCTL1F_SLEWREFOUT, FB_PLLCTL1F_SLEWREFOUT)

/* Register Values */


/*******************************
 *      R_PLLCTL20 (0x65)      *
 *******************************/

/* Field Offsets */
#define FB_PLLCTL20_SLEW_OUT4                4                                  
#define FB_PLLCTL20_SLEW_OUT3                0                                  

/* Field Masks */
#define FM_PLLCTL20_SLEW_OUT4                0XF                                
#define FM_PLLCTL20_SLEW_OUT3                0XF                                

/* Field Values */

/* Register Default */
#define RD_PLLCTL20                          0x8                                

/* Register Masks */
#define RM_PLLCTL20_SLEW_OUT4                RM(FM_PLLCTL20_SLEW_OUT4, FB_PLLCTL20_SLEW_OUT4)
#define RM_PLLCTL20_SLEW_OUT3                RM(FM_PLLCTL20_SLEW_OUT3, FB_PLLCTL20_SLEW_OUT3)

/* Register Values */


/*******************************
 *      R_PLLCTL21 (0x66)      *
 *******************************/

/* Field Offsets */
#define FB_PLLCTL21_SLEW_OUT1SS              0                                  

/* Field Masks */
#define FM_PLLCTL21_SLEW_OUT1SS              0XF                                

/* Field Values */

/* Register Default */
#define RD_PLLCTL21                          0x0                                

/* Register Masks */
#define RM_PLLCTL21_SLEW_OUT1SS              RM(FM_PLLCTL21_SLEW_OUT1SS, FB_PLLCTL21_SLEW_OUT1SS)

/* Register Values */


/*******************************
 *      R_PLLCTL22 (0x67)      *
 *******************************/

/* Field Offsets */
#define FB_PLLCTL22_CXTAL                    3                                  
#define FB_PLLCTL22_PLL3_VCO_SEL             2                                  
#define FB_PLLCTL22_PLL2_VCO_SEL             1                                  
#define FB_PLLCTL22_PLL1_VCO_SEL             0                                  

/* Field Masks */
#define FM_PLLCTL22_CXTAL                    0X1F                               
#define FM_PLLCTL22_PLL3_VCO_SEL             0X1                                
#define FM_PLLCTL22_PLL2_VCO_SEL             0X1                                
#define FM_PLLCTL22_PLL1_VCO_SEL             0X1                                

/* Field Values */

/* Register Default */
#define RD_PLLCTL22                          0x0                                

/* Register Masks */
#define RM_PLLCTL22_CXTAL                    RM(FM_PLLCTL22_CXTAL, FB_PLLCTL22_CXTAL)
#define RM_PLLCTL22_PLL3_VCO_SEL             RM(FM_PLLCTL22_PLL3_VCO_SEL, FB_PLLCTL22_PLL3_VCO_SEL)
#define RM_PLLCTL22_PLL2_VCO_SEL             RM(FM_PLLCTL22_PLL2_VCO_SEL, FB_PLLCTL22_PLL2_VCO_SEL)
#define RM_PLLCTL22_PLL1_VCO_SEL             RM(FM_PLLCTL22_PLL1_VCO_SEL, FB_PLLCTL22_PLL1_VCO_SEL)

/* Register Values */


/*****************************
 *      R_DTEST0 (0x68)      *
 *****************************/

/* Field Offsets */
#define FB_DTEST0                            0                                  

/* Field Masks */
#define FM_DTEST0                            0XFF                               

/* Field Values */

/* Register Default */
#define RD_DTEST0                            0x0                                

/* Register Masks */
#define RM_DTEST0                            RM(FM_DTEST0, FB_DTEST0)           

/* Register Values */


/*****************************
 *      R_DTEST1 (0x69)      *
 *****************************/

/* Field Offsets */
#define FB_DTEST1                            0                                  

/* Field Masks */
#define FM_DTEST1                            0XFF                               

/* Field Values */

/* Register Default */
#define RD_DTEST1                            0x0                                

/* Register Masks */
#define RM_DTEST1                            RM(FM_DTEST1, FB_DTEST1)           

/* Register Values */


/*****************************
 *      R_ATEST0 (0x6A)      *
 *****************************/

/* Field Offsets */
#define FB_ATEST0                            0                                  

/* Field Masks */
#define FM_ATEST0                            0XFF                               

/* Field Values */

/* Register Default */
#define RD_ATEST0                            0x0                                

/* Register Masks */
#define RM_ATEST0                            RM(FM_ATEST0, FB_ATEST0)           

/* Register Values */


/*****************************
 *      R_ATEST1 (0x6B)      *
 *****************************/

/* Field Offsets */
#define FB_ATEST1                            0                                  

/* Field Masks */
#define FM_ATEST1                            0XFF                               

/* Field Values */

/* Register Default */
#define RD_ATEST1                            0x0                                

/* Register Masks */
#define RM_ATEST1                            RM(FM_ATEST1, FB_ATEST1)           

/* Register Values */


/*****************************
 *      R_ATEST2 (0x6C)      *
 *****************************/

/* Field Offsets */
#define FB_ATEST2                            0                                  

/* Field Masks */
#define FM_ATEST2                            0XFF                               

/* Field Values */

/* Register Default */
#define RD_ATEST2                            0x0                                

/* Register Masks */
#define RM_ATEST2                            RM(FM_ATEST2, FB_ATEST2)           

/* Register Values */


/*****************************
 *      R_ATEST3 (0x6D)      *
 *****************************/

/* Field Offsets */
#define FB_ATEST3                            0                                  

/* Field Masks */
#define FM_ATEST3                            0XFF                               

/* Field Values */

/* Register Default */
#define RD_ATEST3                            0x0                                

/* Register Masks */
#define RM_ATEST3                            RM(FM_ATEST3, FB_ATEST3)           

/* Register Values */


/*****************************
 *      R_ATEST4 (0x6E)      *
 *****************************/

/* Field Offsets */
#define FB_ATEST4                            0                                  

/* Field Masks */
#define FM_ATEST4                            0XFF                               

/* Field Values */

/* Register Default */
#define RD_ATEST4                            0x0                                

/* Register Masks */
#define RM_ATEST4                            RM(FM_ATEST4, FB_ATEST4)           

/* Register Values */


/*****************************
 *      R_ATEST5 (0x6F)      *
 *****************************/

/* Field Offsets */
#define FB_ATEST5                            0                                  

/* Field Masks */
#define FM_ATEST5                            0XFF                               

/* Field Values */

/* Register Default */
#define RD_ATEST5                            0x0                                

/* Register Masks */
#define RM_ATEST5                            RM(FM_ATEST5, FB_ATEST5)           

/* Register Values */


/*****************************
 *      R_ATEST6 (0x70)      *
 *****************************/

/* Field Offsets */
#define FB_ATEST6                            0                                  

/* Field Masks */
#define FM_ATEST6                            0XFF                               

/* Field Values */

/* Register Default */
#define RD_ATEST6                            0x0                                

/* Register Masks */
#define RM_ATEST6                            RM(FM_ATEST6, FB_ATEST6)           

/* Register Values */


/*****************************
 *      R_ATEST7 (0x71)      *
 *****************************/

/* Field Offsets */
#define FB_ATEST7                            0                                  

/* Field Masks */
#define FM_ATEST7                            0XFF                               

/* Field Values */

/* Register Default */
#define RD_ATEST7                            0x0                                

/* Register Masks */
#define RM_ATEST7                            RM(FM_ATEST7, FB_ATEST7)           

/* Register Values */


/*****************************
 *      R_ATEST8 (0x72)      *
 *****************************/

/* Field Offsets */
#define FB_ATEST8                            0                                  

/* Field Masks */
#define FM_ATEST8                            0XFF                               

/* Field Values */

/* Register Default */
#define RD_ATEST8                            0x0                                

/* Register Masks */
#define RM_ATEST8                            RM(FM_ATEST8, FB_ATEST8)           

/* Register Values */


/*****************************
 *      R_ATEST9 (0x73)      *
 *****************************/

/* Field Offsets */
#define FB_ATEST9                            0                                  

/* Field Masks */
#define FM_ATEST9                            0XFF                               

/* Field Values */

/* Register Default */
#define RD_ATEST9                            0x0                                

/* Register Masks */
#define RM_ATEST9                            RM(FM_ATEST9, FB_ATEST9)           

/* Register Values */


/******************************
 *      R_ATEST10 (0x74)      *
 ******************************/

/* Field Offsets */
#define FB_ATEST10                           0                                  

/* Field Masks */
#define FM_ATEST10                           0XFF                               

/* Field Values */

/* Register Default */
#define RD_ATEST10                           0x0                                

/* Register Masks */
#define RM_ATEST10                           RM(FM_ATEST10, FB_ATEST10)         

/* Register Values */


/******************************
 *      R_ATEST11 (0x75)      *
 ******************************/

/* Field Offsets */
#define FB_ATEST11                           0                                  

/* Field Masks */
#define FM_ATEST11                           0XFF                               

/* Field Values */

/* Register Default */
#define RD_ATEST11                           0x0                                

/* Register Masks */
#define RM_ATEST11                           RM(FM_ATEST11, FB_ATEST11)         

/* Register Values */


/******************************
 *      R_ATEST12 (0x76)      *
 ******************************/

/* Field Offsets */
#define FB_ATEST12                           0                                  

/* Field Masks */
#define FM_ATEST12                           0XFF                               

/* Field Values */

/* Register Default */
#define RD_ATEST12                           0x0                                

/* Register Masks */
#define RM_ATEST12                           RM(FM_ATEST12, FB_ATEST12)         

/* Register Values */


/*******************************
 *      R_TIMEBASE (0x77)      *
 *******************************/

/* Field Offsets */
#define FB_TIMEBASE_DIVIDER                  0                                  

/* Field Masks */
#define FM_TIMEBASE_DIVIDER                  0XFF                               

/* Field Values */

/* Register Default */
#define RD_TIMEBASE                          0x61                               

/* Register Masks */
#define RM_TIMEBASE_DIVIDER                  RM(FM_TIMEBASE_DIVIDER, FB_TIMEBASE_DIVIDER)

/* Register Values */


/***************************
 *      R_MFG0 (0x78)      *
 ***************************/

/* Field Offsets */
#define FB_MFG0_OTPVER                       0                                  

/* Field Masks */
#define FM_MFG0_OTPVER                       0XFF                               

/* Field Values */

/* Register Default */
#define RD_MFG0                              0x0                                

/* Register Masks */
#define RM_MFG0_OTPVER                       RM(FM_MFG0_OTPVER, FB_MFG0_OTPVER) 

/* Register Values */


/***************************
 *      R_MFG1 (0x79)      *
 ***************************/

/* Field Offsets */
#define FB_MFG1_MAPX                         0                                  

/* Field Masks */
#define FM_MFG1_MAPX                         0X3F                               

/* Field Values */

/* Register Default */
#define RD_MFG1                              0x0                                

/* Register Masks */
#define RM_MFG1_MAPX                         RM(FM_MFG1_MAPX, FB_MFG1_MAPX)     

/* Register Values */


/***************************
 *      R_MFG2 (0x7A)      *
 ***************************/

/* Field Offsets */
#define FB_MFG2_MAPY                         0                                  

/* Field Masks */
#define FM_MFG2_MAPY                         0X3F                               

/* Field Values */

/* Register Default */
#define RD_MFG2                              0x0                                

/* Register Masks */
#define RM_MFG2_MAPY                         RM(FM_MFG2_MAPY, FB_MFG2_MAPY)     

/* Register Values */


/***************************
 *      R_MFG3 (0x7B)      *
 ***************************/

/* Field Offsets */
#define FB_MFG3_WAFER                        0                                  

/* Field Masks */
#define FM_MFG3_WAFER                        0X1F                               

/* Field Values */

/* Register Default */
#define RD_MFG3                              0x0                                

/* Register Masks */
#define RM_MFG3_WAFER                        RM(FM_MFG3_WAFER, FB_MFG3_WAFER)   

/* Register Values */


/*****************************
 *      R_DEVADR (0x7C)      *
 *****************************/

/* Field Offsets */
#define FB_DEVADR_ADDR                       1                                  

/* Field Masks */
#define FM_DEVADR_ADDR                       0X7F                               

/* Field Values */

/* Register Default */
#define RD_DEVADR                            0x69                               

/* Register Masks */
#define RM_DEVADR_ADDR                       RM(FM_DEVADR_ADDR, FB_DEVADR_ADDR) 

/* Register Values */


/*****************************
 *      R_DEVIDL (0x7D)      *
 *****************************/

/* Field Offsets */
#define FB_DEVIDL_DIDL                       0                                  

/* Field Masks */
#define FM_DEVIDL_DIDL                       0XFF                               

/* Field Values */

/* Register Default */
#define RD_DEVIDL                            0x1                                

/* Register Masks */
#define RM_DEVIDL_DIDL                       RM(FM_DEVIDL_DIDL, FB_DEVIDL_DIDL) 

/* Register Values */


/*****************************
 *      R_DEVIDH (0x7E)      *
 *****************************/

/* Field Offsets */
#define FB_DEVIDH_DIDH                       0                                  

/* Field Masks */
#define FM_DEVIDH_DIDH                       0XFF                               

/* Field Values */

/* Register Default */
#define RD_DEVIDH                            0x22                               

/* Register Masks */
#define RM_DEVIDH_DIDH                       RM(FM_DEVIDH_DIDH, FB_DEVIDH_DIDH) 

/* Register Values */


/****************************
 *      R_REVID (0x7F)      *
 ****************************/

/* Field Offsets */
#define FB_REVID_MAJ                         4                                  
#define FB_REVID_MNR                         0                                  

/* Field Masks */
#define FM_REVID_MAJ                         0XF                                
#define FM_REVID_MNR                         0XF                                

/* Field Values */

/* Register Default */
#define RD_REVID                             0x1                                

/* Register Masks */
#define RM_REVID_MAJ                         RM(FM_REVID_MAJ, FB_REVID_MAJ)     
#define RM_REVID_MNR                         RM(FM_REVID_MNR, FB_REVID_MNR)     

/* Register Values */


/****************************
 *      R_RESET (0x80)      *
 ****************************/

/* Field Offsets */
#define FB_RESET                             0                                  

/* Field Masks */
#define FM_RESET                             0XFF                               

/* Field Values */
#define FV_RESET_PWR_ON_DEFAULTS             0x85                               

/* Register Default */
#define RD_RESET                             0x0                                

/* Register Masks */
#define RM_RESET                             RM(FM_RESET, FB_RESET)             

/* Register Values */
#define RV_RESET_PWR_ON_DEFAULTS             RV(FV_RESET_PWR_ON_DEFAULTS, FB_RESET)


/*********************************
 *      R_THERMSPKR2 (0x88)      *
 *********************************/

/* Field Offsets */
#define FB_THERMSPKR2_FORCEPWDSTAT           7                                  
#define FB_THERMSPKR2_VOLSTAT                0                                  

/* Field Masks */
#define FM_THERMSPKR2_FORCEPWDSTAT           0X1                                
#define FM_THERMSPKR2_VOLSTAT                0X7F                               

/* Field Values */

/* Register Default */
#define RD_THERMSPKR2                        0x0                                

/* Register Masks */
#define RM_THERMSPKR2_FORCEPWDSTAT           RM(FM_THERMSPKR2_FORCEPWDSTAT, FB_THERMSPKR2_FORCEPWDSTAT)
#define RM_THERMSPKR2_VOLSTAT                RM(FM_THERMSPKR2_VOLSTAT, FB_THERMSPKR2_VOLSTAT)

/* Register Values */


/***************************
 *      R_COP3 (0x89)      *
 ***************************/

/* Field Offsets */
#define FB_COP3_HIGHDELTA                    7                                  
#define FB_COP3_UNDERVOLTAGE                 6                                  
#define FB_COP3_COPADJ                       0                                  

/* Field Masks */
#define FM_COP3_HIGHDELTA                    0X1                                
#define FM_COP3_UNDERVOLTAGE                 0X1                                
#define FM_COP3_COPADJ                       0X3F                               

/* Field Values */

/* Register Default */
#define RD_COP3                              0x0                                

/* Register Masks */
#define RM_COP3_HIGHDELTA                    RM(FM_COP3_HIGHDELTA, FB_COP3_HIGHDELTA)
#define RM_COP3_UNDERVOLTAGE                 RM(FM_COP3_UNDERVOLTAGE, FB_COP3_UNDERVOLTAGE)
#define RM_COP3_COPADJ                       RM(FM_COP3_COPADJ, FB_COP3_COPADJ) 

/* Register Values */


/********************************
 *      R_DACCRSTAT (0x8A)      *
 ********************************/

/* Field Offsets */
#define FB_DACCRSTAT_DACCR_BUSY              7                                  

/* Field Masks */
#define FM_DACCRSTAT_DACCR_BUSY              0X1                                

/* Field Values */

/* Register Default */
#define RD_DACCRSTAT                         0x0                                

/* Register Masks */
#define RM_DACCRSTAT_DACCR_BUSY              RM(FM_DACCRSTAT_DACCR_BUSY, FB_DACCRSTAT_DACCR_BUSY)

/* Register Values */


/********************************
 *      R_HPDETSTAT (0x8B)      *
 ********************************/

/* Field Offsets */
#define FB_HPDETSTAT_HP_DETECT               7                                  

/* Field Masks */
#define FM_HPDETSTAT_HP_DETECT               0X1                                

/* Field Values */

/* Register Default */
#define RD_HPDETSTAT                         0x0                                

/* Register Masks */
#define RM_HPDETSTAT_HP_DETECT               RM(FM_HPDETSTAT_HP_DETECT, FB_HPDETSTAT_HP_DETECT)

/* Register Values */


/*********************************
 *      R_ADCALCSTAT (0x8C)      *
 *********************************/

/* Field Offsets */
#define FB_ADCALCSTAT_PGA_GAIN               0                                  

/* Field Masks */
#define FM_ADCALCSTAT_PGA_GAIN               0X3F                               

/* Field Values */

/* Register Default */
#define RD_ADCALCSTAT                        0x0                                

/* Register Masks */
#define RM_ADCALCSTAT_PGA_GAIN               RM(FM_ADCALCSTAT_PGA_GAIN, FB_ADCALCSTAT_PGA_GAIN)

/* Register Values */


/*****************************
 *      R_SDSTAT (0x8D)      *
 *****************************/

/* Field Offsets */
#define FB_SDSTAT_SD_VALUE                   0                                  

/* Field Masks */
#define FM_SDSTAT_SD_VALUE                   0X1F                               

/* Field Values */

/* Register Default */
#define RD_SDSTAT                            0x0                                

/* Register Masks */
#define RM_SDSTAT_SD_VALUE                   RM(FM_SDSTAT_SD_VALUE, FB_SDSTAT_SD_VALUE)

/* Register Values */


/******************************
 *      R_PLLCTL0 (0x8E)      *
 ******************************/

/* Field Offsets */
#define FB_PLLCTL0_GPOUT                     4                                  
#define FB_PLLCTL0_PLLSSLOCK                 3                                  
#define FB_PLLCTL0_PLL3LOCK                  2                                  
#define FB_PLLCTL0_PLL2LOCK                  1                                  
#define FB_PLLCTL0_PLL1LOCK                  0                                  

/* Field Masks */
#define FM_PLLCTL0_GPOUT                     0XF                                
#define FM_PLLCTL0_PLLSSLOCK                 0X1                                
#define FM_PLLCTL0_PLL3LOCK                  0X1                                
#define FM_PLLCTL0_PLL2LOCK                  0X1                                
#define FM_PLLCTL0_PLL1LOCK                  0X1                                

/* Field Values */

/* Register Default */
#define RD_PLLCTL0                           0x0                                

/* Register Masks */
#define RM_PLLCTL0_GPOUT                     RM(FM_PLLCTL0_GPOUT, FB_PLLCTL0_GPOUT)
#define RM_PLLCTL0_PLLSSLOCK                 RM(FM_PLLCTL0_PLLSSLOCK, FB_PLLCTL0_PLLSSLOCK)
#define RM_PLLCTL0_PLL3LOCK                  RM(FM_PLLCTL0_PLL3LOCK, FB_PLLCTL0_PLL3LOCK)
#define RM_PLLCTL0_PLL2LOCK                  RM(FM_PLLCTL0_PLL2LOCK, FB_PLLCTL0_PLL2LOCK)
#define RM_PLLCTL0_PLL1LOCK                  RM(FM_PLLCTL0_PLL1LOCK, FB_PLLCTL0_PLL1LOCK)

/* Register Values */


/******************************
 *      R_BISTCTL (0x90)      *
 ******************************/

/* Field Offsets */
#define FB_BISTCTLRAM4_SKIP                  7                                  
#define FB_BISTCTLRAM3_SKIP                  6                                  
#define FB_BISTCTLRAM2_SKIP                  5                                  
#define FB_BISTCTLRAM1_SKIP                  4                                  
#define FB_BISTCTL_MODE                      1                                  
#define FB_BISTCTL_GO                        0                                  

/* Field Masks */
#define FM_BISTCTLRAM4_SKIP                  0X1                                
#define FM_BISTCTLRAM3_SKIP                  0X1                                
#define FM_BISTCTLRAM2_SKIP                  0X1                                
#define FM_BISTCTLRAM1_SKIP                  0X1                                
#define FM_BISTCTL_MODE                      0X1                                
#define FM_BISTCTL_GO                        0X1                                

/* Field Values */

/* Register Default */
#define RD_BISTCTL                           0x0                                

/* Register Masks */
#define RM_BISTCTLRAM4_SKIP                  RM(FM_BISTCTLRAM4_SKIP, FB_BISTCTLRAM4_SKIP)
#define RM_BISTCTLRAM3_SKIP                  RM(FM_BISTCTLRAM3_SKIP, FB_BISTCTLRAM3_SKIP)
#define RM_BISTCTLRAM2_SKIP                  RM(FM_BISTCTLRAM2_SKIP, FB_BISTCTLRAM2_SKIP)
#define RM_BISTCTLRAM1_SKIP                  RM(FM_BISTCTLRAM1_SKIP, FB_BISTCTLRAM1_SKIP)
#define RM_BISTCTL_MODE                      RM(FM_BISTCTL_MODE, FB_BISTCTL_MODE)
#define RM_BISTCTL_GO                        RM(FM_BISTCTL_GO, FB_BISTCTL_GO)   

/* Register Values */


/********************************
 *      R_BISTSTAT1 (0x91)      *
 ********************************/

/* Field Offsets */
#define FB_BISTSTAT1_DONE                    7                                  
#define FB_BISTSTAT1_ACTIVE                  6                                  
#define FB_BISTSTAT1_ADDR8                   3                                  
#define FB_BISTSTAT1RAM                      0                                  

/* Field Masks */
#define FM_BISTSTAT1_DONE                    0X1                                
#define FM_BISTSTAT1_ACTIVE                  0X1                                
#define FM_BISTSTAT1_ADDR8                   0X1                                
#define FM_BISTSTAT1RAM                      0X7                                

/* Field Values */

/* Register Default */
#define RD_BISTSTAT1                         0x1                                

/* Register Masks */
#define RM_BISTSTAT1_DONE                    RM(FM_BISTSTAT1_DONE, FB_BISTSTAT1_DONE)
#define RM_BISTSTAT1_ACTIVE                  RM(FM_BISTSTAT1_ACTIVE, FB_BISTSTAT1_ACTIVE)
#define RM_BISTSTAT1_ADDR8                   RM(FM_BISTSTAT1_ADDR8, FB_BISTSTAT1_ADDR8)
#define RM_BISTSTAT1RAM                      RM(FM_BISTSTAT1RAM, FB_BISTSTAT1RAM)

/* Register Values */


/********************************
 *      R_BISTSTAT2 (0x92)      *
 ********************************/

/* Field Offsets */
#define FB_BISTSTAT2_ADDR                    0                                  

/* Field Masks */
#define FM_BISTSTAT2_ADDR                    0XFF                               

/* Field Values */

/* Register Default */
#define RD_BISTSTAT2                         0x0                                

/* Register Masks */
#define RM_BISTSTAT2_ADDR                    RM(FM_BISTSTAT2_ADDR, FB_BISTSTAT2_ADDR)

/* Register Values */


/********************************
 *      R_BISTSTAT3 (0x93)      *
 ********************************/

/* Field Offsets */
#define FB_BISTSTAT3_BITSL                   0                                  

/* Field Masks */
#define FM_BISTSTAT3_BITSL                   0XFF                               

/* Field Values */

/* Register Default */
#define RD_BISTSTAT3                         0x0                                

/* Register Masks */
#define RM_BISTSTAT3_BITSL                   RM(FM_BISTSTAT3_BITSL, FB_BISTSTAT3_BITSL)

/* Register Values */


/********************************
 *      R_BISTSTAT4 (0x94)      *
 ********************************/

/* Field Offsets */
#define FB_BISTSTAT4_BITSM                   0                                  

/* Field Masks */
#define FM_BISTSTAT4_BITSM                   0XFF                               

/* Field Values */

/* Register Default */
#define RD_BISTSTAT4                         0x0                                

/* Register Masks */
#define RM_BISTSTAT4_BITSM                   RM(FM_BISTSTAT4_BITSM, FB_BISTSTAT4_BITSM)

/* Register Values */


/********************************
 *      R_BISTSTAT5 (0x95)      *
 ********************************/

/* Field Offsets */
#define FB_BISTSTAT5_BITSH                   0                                  

/* Field Masks */
#define FM_BISTSTAT5_BITSH                   0XFF                               

/* Field Values */

/* Register Default */
#define RD_BISTSTAT5                         0x0                                

/* Register Masks */
#define RM_BISTSTAT5_BITSH                   RM(FM_BISTSTAT5_BITSH, FB_BISTSTAT5_BITSH)

/* Register Values */


/******************************
 *      R_ATEST13 (0xA0)      *
 ******************************/

/* Field Offsets */
#define FB_ATEST13                           0                                  

/* Field Masks */
#define FM_ATEST13                           0XFF                               

/* Field Values */

/* Register Default */
#define RD_ATEST13                           0x0                                

/* Register Masks */
#define RM_ATEST13                           RM(FM_ATEST13, FB_ATEST13)         

/* Register Values */


/******************************
 *      R_ATEST14 (0xA1)      *
 ******************************/

/* Field Offsets */
#define FB_ATEST14                           0                                  

/* Field Masks */
#define FM_ATEST14                           0XFF                               

/* Field Values */

/* Register Default */
#define RD_ATEST14                           0x0                                

/* Register Masks */
#define RM_ATEST14                           RM(FM_ATEST14, FB_ATEST14)         

/* Register Values */


/******************************
 *      R_ATEST15 (0xA2)      *
 ******************************/

/* Field Offsets */
#define FB_ATEST15                           0                                  

/* Field Masks */
#define FM_ATEST15                           0XFF                               

/* Field Values */

/* Register Default */
#define RD_ATEST15                           0x0                                

/* Register Masks */
#define RM_ATEST15                           RM(FM_ATEST15, FB_ATEST15)         

/* Register Values */

#endif /* __WOLVERINE_H__ */
