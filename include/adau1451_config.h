#ifndef ADAU1451_CONFIG_H
#define ADAU1451_CONFIG_H


extern "C"
{
#include "ADAU1451_IC_1_PARAM.h"
}



/* Volume Setting */
#define ADAU1451_VOLUME_ADDR                         MOD_VOLUMECONTROL_SETVOLUME_DCINPALG145X2VALUE_ADDR
#define ADAU1451_UPDATE_VOLUME_LEN                   (6)

#endif
