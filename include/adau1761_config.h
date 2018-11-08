#ifndef ADAU1761_CONFIG_H
#define ADAU1761_CONFIG_H


extern "C"
{
#include "ADAU1761_IC_1_PARAM.h"
#include "ADAU1761_IC_1_REG.h"
}

#define ADAU1761_MAX_TX_BYTES   80

/*Volume control*/
#define ADAU1761_VOLUME_CONTROL_ADDR             MOD_VOLUMECONTROL_VOLUME_DCINPALG7_ADDR//MOD_VOLUMECONTROL_SWVOLUME_ALG0_GAINS200ALG1GAINTARGET_ADDR
#define ADAU1761_UPDATE_VOLUME_LEN               6


/* Enable\Disable DSP PLL clock, when disable PLL clock DSP is in low power consumption mode */
#define REG_ADDR_PLL_CLOCK                      REG_PLL_ENABLE_IC_2_ADDR
#define DATA_PLL_CLOCK_ENABLE                   (0x0001)
#define DATA_PLL_CLOCK_DISABLE                  (0x0000)
#define PLL_CLOCK_CTRL_LEN                      (4)

#endif
