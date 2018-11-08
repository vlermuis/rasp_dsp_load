#ifndef ADAU1451_CONFIG_H
#define ADAU1451_CONFIG_H


#include "ADAU1451_IC_1_PARAM.h"
#include "ADAU1451_IC_1_REG.h"



/* Volume Setting */
#define ADAU1451_VOLUME_ADDR                         MOD_VOLUMECONTROL_SETVOLUME_DCINPALG145X2VALUE_ADDR
#define ADAU1451_UPDATE_VOLUME_LEN                   (6)

#define REG_ADDR_PLL_CLOCK                      REG_PLL_ENABLE_IC_2_ADDR
#define DATA_PLL_CLOCK_ENABLE                   (0x0001)
#define DATA_PLL_CLOCK_DISABLE                  (0x0000)
#define PLL_CLOCK_CTRL_LEN                      (4)
#endif
