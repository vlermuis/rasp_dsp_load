#ifndef DSP1761_H
#define DSP1761_H
#include "RaspI2C.h"
#include "adau1761_config.h"
#include "Dsp.h"


//typedef unsigned char ADI_REG_TYPE;
#define ADI_REG_TYPE  static unsigned char

#include "ADAU1761_IC_1.h"


//#define DSP1451_ADDR                    (0x70)
//#define DEVICE_ADDR_IC_2                (0x70)
#define ADAU1451_REGISTER_LEN           (4)
#define PROGRAM_RAM_PAGE_SIZE           (4)
#define PARA_RAM_PAGE_SIZE              (4)
#define DM1_PAGE_SIZE                   (4)


///* SOFT_RESET  - Registers (IC 2) */
//#define REG_SOFT_RESET_IC_2_ADDR                  0xF890
//#define REG_SOFT_RESET_IC_2_BYTE                  2
//#define REG_SOFT_RESET_IC_2_VALUE                 0x1


#define DSP_PLL_CLOCK_DISABLE                   (0)
#define DSP_PLL_CLOCK_ENABLE                    (1)



#define SIGMA_WRITE_REGISTER_BLOCK(dev_address, reg_addr, data_len, pdata) \
    WriteRegister(reg_addr, data_len, (unsigned char*)pdata);

#define MAX_VOLUME      (90)
#define MIN_VOLUME      (0)

class CDsp1761 : public CDsp
{
    public:
        CDsp1761();
        ~CDsp1761();
        void Load();
        void SetVolume(unsigned int volume);

    protected:

    private:
        void InitSection1();
        void InitSection2();
        void InitSection3();
        void InitSection4();
        void InitSection5();
        void WriteRegister(unsigned int regAddr, unsigned int size, unsigned char* pData);

        CRaspI2C mRaspI2CObj;
        bool mbIsDspReady;
};

#endif // DSP1761_H
