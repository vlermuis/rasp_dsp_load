#include <iostream>
#include "Dsp.h"

using namespace std;
CDsp::CDsp()
{
    //ctor
}

CDsp::~CDsp()
{
    //dtor
}
void CDsp::Load()
{
    cout << "CDsp::Load()" << endl;
}
void CDsp::SetVolume(unsigned int volume)
{
    cout << "CDsp::SetVolume()" << endl;
}
void CDsp::Sleep(unsigned int mode)
{
    cout << "CDsp::Sleep()" << endl;
}
/**
 * Convert DSP float raw data to float number
 *
 * @param      data: float data with DSP format
 *             fmt_num: Numeric nubmer of DSP format
 *             fmt_frac: Fraction nubmer of DSP format
 *
 * @return     starnard float number
 * 
 * @Example, 
 * Numerical Format: (fmt_num).(fmt_frac)
 *  Range: -16.0 to (+16.0 - 1 LSB)
 *  0000 1000  0000 0000  0000 0000  0000 0000 =  -16.0 
 *  0000 1110  0000 0000  0000 0000  0000 0000 =  -4.0 
 *  0000 1111  1000 0000  0000 0000  0000 0000 =  -1.0 
 *  0000 1111  1110 0000  0000 0000  0000 0000 =  -0.25 
 *  0000 1111  1111 1111  1111 1111  1111 1111 =  (1 LSB below 0.0) 
 *  0000 0000  0000 0000  0000 0000  0000 0000 =  0.0 
 *  0000 0000  0010 0000  0000 0000  0000 0000 =  0.25 
 *  0000 0000  1000 0000  0000 0000  0000 0000 =  1.0 (0 dB full scale)
 *  0000 0010  0000 0000  0000 0000  0000 0000 =  4.0 
 *  0000 0111  1111 1111  1111 1111  1111 1111 =  (16.0 - 1 LSB)
 */
float CDsp::DataToFloat(unsigned int data, unsigned char fmt_num, unsigned char fmt_frac)
{ 
    unsigned char sign_bit= fmt_num + fmt_frac - 1;
    unsigned int sign_value= UINT32_GET_BIT(data, sign_bit);
    unsigned int value_uint= UINT32_GET_BIT_RANGE(data, sign_bit-1, fmt_frac);
    float value_float= 0.0;
    if(sign_value==0)
    {   //positive number
        value_float= (float)value_uint;
    }
    else
    {   //negative number
        unsigned int value_max= 2<<(fmt_num-2);  //2^fmt_num
        value_float= -(float)(value_max-value_uint);
    }
    float f= 1;
    for(int i=fmt_frac-1 ; i>=0 ; i--)
    {
        f/= 2;
        if(UINT32_GET_BIT_RANGE(data, i, i)) {
            value_float+= f;
        }
    }
    return value_float;
}
