#include <string.h>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "Dsp1451.h"


using namespace std;

CDsp1451::CDsp1451()
{
    //ctor
    mbIsDspReady = false;
    mRaspI2CObj.SetAddress(DEVICE_ADDR_IC_2);
    mRaspI2CObj.Init();
    if (mRaspI2CObj.GetErrorCode() != 0)
    {
        cout << "DSP device init error!" << endl;
    }
    else
    {
        cout << "DSP device init ok." << endl;
        mbIsDspReady = true;
    }

}

CDsp1451::~CDsp1451()
{
    //dtor
}

void CDsp1451::Load()  
{
    if (!mbIsDspReady) 
    {
        cout << "DSP device is not ready!" << endl;
        return;
    }
    InitSection1();
    InitSection2();
    InitSection3();
    InitSection4();
    InitSection5();
    InitSection6();
    InitSection7();
    InitSection8();
    InitSection9();

}

void CDsp1451::WriteRegister(unsigned int regAddr, unsigned int size, unsigned char* pData)
{
    if (!mbIsDspReady) 
    {
        cout << "DSP device is not ready!" << endl;
        return;
    }
    unsigned char buffer[2+ADAU1451_REGISTER_LEN];
    buffer[0]=(regAddr>>8);
    buffer[1]=(regAddr&0xff);
    memcpy(&buffer[2], pData, size);
    mRaspI2CObj.Write(size+2, &buffer[0]);

}

void CDsp1451::InitSection1()
{
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOFT_RESET_IC_2_ADDR, REG_SOFT_RESET_IC_2_BYTE, R0_SOFT_RESET_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOFT_RESET_IC_2_ADDR, REG_SOFT_RESET_IC_2_BYTE, R1_SOFT_RESET_IC_2_Default );
}

void CDsp1451::InitSection2()
{
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_HIBERNATE_IC_2_ADDR, REG_HIBERNATE_IC_2_BYTE, R3_HIBERNATE_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_HIBERNATE_IC_2_ADDR, REG_HIBERNATE_IC_2_BYTE, R4_HIBERNATE_IC_2_Default );
}

void CDsp1451::InitSection3()
{
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_KILL_CORE_IC_2_ADDR, REG_KILL_CORE_IC_2_BYTE, R6_KILL_CORE_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_KILL_CORE_IC_2_ADDR, REG_KILL_CORE_IC_2_BYTE, R7_KILL_CORE_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_PLL_ENABLE_IC_2_ADDR, REG_PLL_ENABLE_IC_2_BYTE, R8_PLL_ENABLE_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_PLL_CTRL0_IC_2_ADDR, REG_PLL_CTRL0_IC_2_BYTE, R9_PLL_CTRL0_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_PLL_CTRL1_IC_2_ADDR, REG_PLL_CTRL1_IC_2_BYTE, R10_PLL_CTRL1_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_PLL_CLK_SRC_IC_2_ADDR, REG_PLL_CLK_SRC_IC_2_BYTE, R11_PLL_CLK_SRC_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_MCLK_OUT_IC_2_ADDR, REG_MCLK_OUT_IC_2_BYTE, R12_MCLK_OUT_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_PLL_ENABLE_IC_2_ADDR, REG_PLL_ENABLE_IC_2_BYTE, R13_PLL_ENABLE_IC_2_Default );
}

void CDsp1451::InitSection4()
{
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_POWER_ENABLE0_IC_2_ADDR, REG_POWER_ENABLE0_IC_2_BYTE, R15_POWER_ENABLE0_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_POWER_ENABLE1_IC_2_ADDR, REG_POWER_ENABLE1_IC_2_BYTE, R16_POWER_ENABLE1_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_ASRC_MUTE_IC_2_ADDR, REG_ASRC_MUTE_IC_2_BYTE, R17_ASRC_MUTE_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_DMIC_CTRL0_IC_2_ADDR, REG_DMIC_CTRL0_IC_2_BYTE, R18_DMIC_CTRL0_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_ASRC_INPUT0_IC_2_ADDR, REG_ASRC_INPUT0_IC_2_BYTE, R19_ASRC_INPUT0_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_ASRC_INPUT2_IC_2_ADDR, REG_ASRC_INPUT2_IC_2_BYTE, R20_ASRC_INPUT2_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_ASRC_OUT_RATE0_IC_2_ADDR, REG_ASRC_OUT_RATE0_IC_2_BYTE, R21_ASRC_OUT_RATE0_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_ASRC_OUT_RATE2_IC_2_ADDR, REG_ASRC_OUT_RATE2_IC_2_BYTE, R22_ASRC_OUT_RATE2_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE0_IC_2_ADDR, REG_SOUT_SOURCE0_IC_2_BYTE, R23_SOUT_SOURCE0_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE1_IC_2_ADDR, REG_SOUT_SOURCE1_IC_2_BYTE, R24_SOUT_SOURCE1_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE2_IC_2_ADDR, REG_SOUT_SOURCE2_IC_2_BYTE, R25_SOUT_SOURCE2_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE3_IC_2_ADDR, REG_SOUT_SOURCE3_IC_2_BYTE, R26_SOUT_SOURCE3_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE4_IC_2_ADDR, REG_SOUT_SOURCE4_IC_2_BYTE, R27_SOUT_SOURCE4_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE5_IC_2_ADDR, REG_SOUT_SOURCE5_IC_2_BYTE, R28_SOUT_SOURCE5_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE6_IC_2_ADDR, REG_SOUT_SOURCE6_IC_2_BYTE, R29_SOUT_SOURCE6_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE7_IC_2_ADDR, REG_SOUT_SOURCE7_IC_2_BYTE, R30_SOUT_SOURCE7_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE8_IC_2_ADDR, REG_SOUT_SOURCE8_IC_2_BYTE, R31_SOUT_SOURCE8_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE9_IC_2_ADDR, REG_SOUT_SOURCE9_IC_2_BYTE, R32_SOUT_SOURCE9_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE10_IC_2_ADDR, REG_SOUT_SOURCE10_IC_2_BYTE, R33_SOUT_SOURCE10_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE11_IC_2_ADDR, REG_SOUT_SOURCE11_IC_2_BYTE, R34_SOUT_SOURCE11_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE12_IC_2_ADDR, REG_SOUT_SOURCE12_IC_2_BYTE, R35_SOUT_SOURCE12_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE13_IC_2_ADDR, REG_SOUT_SOURCE13_IC_2_BYTE, R36_SOUT_SOURCE13_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE14_IC_2_ADDR, REG_SOUT_SOURCE14_IC_2_BYTE, R37_SOUT_SOURCE14_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE15_IC_2_ADDR, REG_SOUT_SOURCE15_IC_2_BYTE, R38_SOUT_SOURCE15_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE16_IC_2_ADDR, REG_SOUT_SOURCE16_IC_2_BYTE, R39_SOUT_SOURCE16_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE17_IC_2_ADDR, REG_SOUT_SOURCE17_IC_2_BYTE, R40_SOUT_SOURCE17_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE18_IC_2_ADDR, REG_SOUT_SOURCE18_IC_2_BYTE, R41_SOUT_SOURCE18_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE19_IC_2_ADDR, REG_SOUT_SOURCE19_IC_2_BYTE, R42_SOUT_SOURCE19_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE20_IC_2_ADDR, REG_SOUT_SOURCE20_IC_2_BYTE, R43_SOUT_SOURCE20_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE21_IC_2_ADDR, REG_SOUT_SOURCE21_IC_2_BYTE, R44_SOUT_SOURCE21_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE22_IC_2_ADDR, REG_SOUT_SOURCE22_IC_2_BYTE, R45_SOUT_SOURCE22_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SOUT_SOURCE23_IC_2_ADDR, REG_SOUT_SOURCE23_IC_2_BYTE, R46_SOUT_SOURCE23_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SERIAL_BYTE_1_0_IC_2_ADDR, REG_SERIAL_BYTE_1_0_IC_2_BYTE, R47_SERIAL_BYTE_1_0_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SERIAL_BYTE_2_0_IC_2_ADDR, REG_SERIAL_BYTE_2_0_IC_2_BYTE, R48_SERIAL_BYTE_2_0_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SERIAL_BYTE_3_0_IC_2_ADDR, REG_SERIAL_BYTE_3_0_IC_2_BYTE, R49_SERIAL_BYTE_3_0_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SERIAL_BYTE_4_0_IC_2_ADDR, REG_SERIAL_BYTE_4_0_IC_2_BYTE, R50_SERIAL_BYTE_4_0_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SERIAL_BYTE_5_0_IC_2_ADDR, REG_SERIAL_BYTE_5_0_IC_2_BYTE, R51_SERIAL_BYTE_5_0_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SERIAL_BYTE_6_0_IC_2_ADDR, REG_SERIAL_BYTE_6_0_IC_2_BYTE, R52_SERIAL_BYTE_6_0_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SERIAL_BYTE_7_0_IC_2_ADDR, REG_SERIAL_BYTE_7_0_IC_2_BYTE, R53_SERIAL_BYTE_7_0_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_SPDIF_RESTART_IC_2_ADDR, REG_SPDIF_RESTART_IC_2_BYTE, R54_SPDIF_RESTART_IC_2_Default );
}

void CDsp1451::InitSection5()
{
    unsigned char buffer[PROGRAM_RAM_PAGE_SIZE+2];
    int RegAddr;
    const unsigned char * bufferPtr;
    bufferPtr=Program_Data_IC_2;
    RegAddr = PROGRAM_ADDR_IC_2;
    for(RegAddr=PROGRAM_ADDR_IC_2;RegAddr<(PROGRAM_ADDR_IC_2 + (PROGRAM_SIZE_IC_2/PROGRAM_RAM_PAGE_SIZE));RegAddr++)
    {
        buffer[0]=(RegAddr>>8);
        buffer[1]=(RegAddr&0xff);
        memcpy(&buffer[2], bufferPtr, PROGRAM_RAM_PAGE_SIZE);
        mRaspI2CObj.Write(PROGRAM_RAM_PAGE_SIZE + 2, &buffer[0]);
        bufferPtr+=PROGRAM_RAM_PAGE_SIZE;
    }

}

void CDsp1451::InitSection6()
{
    unsigned char buffer[PARA_RAM_PAGE_SIZE+2];
    int RegAddr;
    const unsigned char * bufferPtr;
    bufferPtr=Param_Data_IC_2;
    RegAddr = PARAM_ADDR_IC_2;
    for(RegAddr=PARAM_ADDR_IC_2;RegAddr<(PARAM_ADDR_IC_2 + (PARAM_SIZE_IC_2/PARA_RAM_PAGE_SIZE));RegAddr++)
    {
        buffer[0]=(RegAddr>>8);
        buffer[1]=(RegAddr&0xff);
        memcpy(&buffer[2], bufferPtr, PARA_RAM_PAGE_SIZE);
        mRaspI2CObj.Write(PARA_RAM_PAGE_SIZE + 2, &buffer[0]);
        bufferPtr+=PARA_RAM_PAGE_SIZE;
    }

}

void CDsp1451::InitSection7()
{
    unsigned char buffer[DM1_PAGE_SIZE+2];
    int RegAddr;
    const unsigned char * bufferPtr;
    bufferPtr=DM1_DATA_Data_IC_2;
    RegAddr = DM1_DATA_ADDR_IC_2;
    for(RegAddr=DM1_DATA_ADDR_IC_2;RegAddr<(DM1_DATA_ADDR_IC_2 + (DM1_DATA_SIZE_IC_2/DM1_PAGE_SIZE));RegAddr++)
    {
        buffer[0]=(RegAddr>>8);
        buffer[1]=(RegAddr&0xff);
        memcpy(&buffer[2], bufferPtr, PARA_RAM_PAGE_SIZE);
        mRaspI2CObj.Write(DM1_PAGE_SIZE + 2, &buffer[0]);
        bufferPtr+=DM1_PAGE_SIZE;
    }

}

void CDsp1451::InitSection8()
{
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_KILL_CORE_IC_2_ADDR, REG_KILL_CORE_IC_2_BYTE, R58_KILL_CORE_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_START_ADDRESS_IC_2_ADDR, REG_START_ADDRESS_IC_2_BYTE, R59_START_ADDRESS_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_START_PULSE_IC_2_ADDR, REG_START_PULSE_IC_2_BYTE, R60_START_PULSE_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_START_CORE_IC_2_ADDR, REG_START_CORE_IC_2_BYTE, R61_START_CORE_IC_2_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_START_CORE_IC_2_ADDR, REG_START_CORE_IC_2_BYTE, R62_START_CORE_IC_2_Default );
}

void CDsp1451::InitSection9()
{
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_2, REG_HIBERNATE_IC_2_ADDR, REG_HIBERNATE_IC_2_BYTE, R64_HIBERNATE_IC_2_Default );
}


void CDsp1451::SetVolume(unsigned int volume)
{
    cout << "CDsp1451::SetVolume()" << endl;
    if (!mbIsDspReady) 
    {
        cout << "DSP device is not ready!" << endl;
        return;
    }
    unsigned char vol_iic[ADAU1451_UPDATE_VOLUME_LEN] = {0,0,0,0,0,0}; /* write DSP register */
    int reg_addr= ADAU1451_VOLUME_ADDR;
    
    if(volume > MAX_VOLUME)
    {
        volume = MAX_VOLUME;
//        ASSERT(0);
    }
    else if(volume < MIN_VOLUME)
    {
        volume = MIN_VOLUME;
//        ASSERT(0);
    }

    vol_iic[0] = reg_addr >> 8;
    vol_iic[1] = reg_addr & 0x00FF;
    vol_iic[2] = 0;
    vol_iic[3] = 0;
    vol_iic[4] = 0;
    vol_iic[5] = volume;

    mRaspI2CObj.Write(ADAU1451_UPDATE_VOLUME_LEN, &vol_iic[0]);
}

void CDsp1451::Sleep(unsigned int mode)
{
    cout << "CDsp1451::Sleep()" << endl;
    switch(mode)
    {
        case DSP_PLL_CLOCK_DISABLE:
        {
            unsigned char buffer[4];
            buffer[0] = (REG_ADDR_PLL_CLOCK >> 8);
            buffer[1] = (REG_ADDR_PLL_CLOCK & 0xff);
            buffer[2] = DATA_PLL_CLOCK_DISABLE >> 8;
            buffer[3] = DATA_PLL_CLOCK_DISABLE & 0xff;
            mRaspI2CObj.Write(PLL_CLOCK_CTRL_LEN, &buffer[0]);
            mbIsDspReady = false;
            break;
        }
        case DSP_PLL_CLOCK_ENABLE:
        {
            unsigned char buffer[4];
            buffer[0] = (REG_ADDR_PLL_CLOCK >> 8);
            buffer[1] = (REG_ADDR_PLL_CLOCK & 0xff);
            buffer[2] = DATA_PLL_CLOCK_ENABLE >> 8;
            buffer[3] = DATA_PLL_CLOCK_ENABLE & 0xff;
            mRaspI2CObj.Write(PLL_CLOCK_CTRL_LEN, &buffer[0]);
            mbIsDspReady = true;
            break;
        }
        default:
      		cout << "Unknown DSP sleep mode!" << endl;
            break;
    }
}