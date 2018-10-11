#ifndef RASPI2C_H
#define RASPI2C_H


class RaspI2C
{
    public:
        RaspI2C();
        ~RaspI2C();
        RaspI2C(int dev_addr);
        void Init();
        void SetAddress(int dev_addr);

        int GetErrorCode();
        void Read(int reg, int size, unsigned char* data);
        void Write(int size, unsigned char* data);
        void WriteToReg(int reg, int size, unsigned char* data);

    protected:


    private:
	int device_address;
	int lastErrCode;
	int file_i2c;
	int length;

	void InitDevice(int dev_addr);

};

#endif // RASPI2C_H
