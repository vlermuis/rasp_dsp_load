#ifndef DSP_H
#define DSP_H

/* Get bit range from a 4bytes value, for example,
 *   UINT32_GET_BIT_RANGE(0x12345678, 7,  0)  ==>  return 0x8
 *   UINT32_GET_BIT_RANGE(0x12345678, 15, 8)  ==>  return 0x7
 */
#define UINT32_GET_BIT_RANGE(ver, high_pos, low_pos) \
   ((((unsigned int)ver)<<(32-(high_pos)-1))>>(32-(high_pos)+(low_pos)-1))
/* Get bit range from a 4bytes value, for example,
 *   UINT32_GET_BIT_RANGE(0x12345678, 3)  ==>  return 0x1
 *   UINT32_GET_BIT_RANGE(0x12345678, 2)  ==>  return 0x0
 */ 
#define UINT32_GET_BIT(ver, pos) \
   ((((unsigned int)ver)>>(pos)) & 1)

class CDsp
{
    public:
        CDsp();
        virtual ~CDsp();
        virtual void Load();
        virtual void SetVolume(unsigned int volume);
        virtual void Sleep(unsigned int mode);
        float DataToFloat(unsigned int data, unsigned char fmt_num, unsigned char fmt_frac);

    protected:

    private:
};

#endif // DSP_H
