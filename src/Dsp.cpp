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
/**
 * Convert standard float number to DSP float raw data 8.24
 *
 * @param      float_val: float value
 *
 * @return     starnard float number
 * 
 * @example
 *   float_val=16.000000   ==>  return 0x10000000
 *   float_val=1.000000    ==>  return 0x01000000
 *   float_val=0.800000    ==>  return 0x00cccccd
 *   float_val=0.500000    ==>  return 0x00800000
 *   float_val=0.250000    ==>  return 0x00400000
 *   float_val=0.000000    ==>  return 0x00000000
 *   float_val=-16.000000  ==>  return 0xf0000000
 *   float_val=-15.000000  ==>  return 0xf1000000
 *   float_val=-1.000000   ==>  return 0xff000000
 */
unsigned int CDsp::FloatTo8_24Data(float float_val)
{
    //Check invalid 8.24 float
    if(float_val>=128.0 || float_val<-128.0) {
        //ASSERT(0);
        cout << "\r\n*** DSPDrv1451_FloatTo8_24Data: invalid floating nubmer \r\n\r\n" << endl;
        return 0;
    }
    int64_t param_1;
    param_1 = float_val * (1<<24);
    unsigned int data = (unsigned int)param_1;

    return data;
}

/**
 * Convert standard float number to DSP float raw data 5.23
 *
 * @param      float_val: float value
 *
 * @return     starnard float number
 * 
 * @note       do not support negative float 
 * 
 * @example
 *   float=0.000000   => 0x00000000
 *   float=0.500000   => 0x00400000
 *   float=0.250000   => 0x00200000
 *   float=0.015625   => 0x00020000
 *   float=15.984375  => 0x07FE0000
 *   float=15.9999998807907 => 0x07FFFFFF  (max)
 *   float=-0.500000  => 0xFFC00000
 *   float=-0.250000  => 0xFFE00000
 *   float=-0.015625  => 0xFFFE0000
 *   float=-15.984375 => 0xF8020000
 *   float=-16.0      => 0xF8000000  (min)
 *
 * @ref
 *   https://wiki.analog.com/resources/tools-software/sigmastudio/usingsigmastudio/systemimplementation
 *
 */
unsigned int CDsp::FloatTo5_23Data(float float_val)
{
  int32_t param223, param227;
  unsigned int res= 0;
  unsigned char * pRes= (unsigned char *)&res;
  
  if( float_val>=16.0 || float_val<-16.0)
  {
      //ASSERT(0);
       cout << "\r\n*** CDsp::FloatTo5_23Data: invalid floating nubmer \r\n\r\n" << endl;
      return 0;
  }
  
  param223 = float_val * (1L << 23);  //multiply decimal number by 2^23
  //printf("param223= %08x (transfer from double: %f)\r\n", param223, float_val * (1L << 23));
  
  param227 = param223 ;
  param227+= (1L << 27);       //convert to positive binary      
  pRes[0] = (unsigned char)param227;         //get byte 0 (LSBs) of parameter value
  pRes[1] = (unsigned char)(param227>>8);    //get byte 1 of parameter value
  pRes[2] = (unsigned char)(param227>>16);   //get byte 2 of parameter value
  pRes[3] = (unsigned char)(param227>>24);   //get byte 3 (MSBs) of parameter value  
  //printf("pRes 1= %02x %02x %02x %02x\r\n", pRes[3], pRes[2], pRes[1], pRes[0]);
  
  pRes[3] = pRes[3] ^ 0x08;     //invert sign bit to get correct sign  
  //printf("pRes 2= %02x %02x %02x %02x\r\n", pRes[3], pRes[2], pRes[1], pRes[0]);
  
  if(pRes[3] & 0x08)
    pRes[3] |= 0xF0;  
  //printf("pRes 3= %02x %02x %02x %02x\r\n", pRes[3], pRes[2], pRes[1], pRes[0]); 
  //printf("%f => %08x\r\n", float_val, res);
  
  return res;
}
