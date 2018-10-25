#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>		//Needed for I2C port
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "RaspI2C.h"

using namespace std;
CRaspI2C::CRaspI2C()
{
    //ctor
}

CRaspI2C::~CRaspI2C()
{
    //dtor
}

CRaspI2C::CRaspI2C(int dev_addr) {

	InitDevice(dev_addr);
}

void CRaspI2C::Init()
{
	if (0 != device_address)
	{
		InitDevice(device_address);
	}
}

void CRaspI2C::SetAddress(int dev_addr)
{
	device_address = dev_addr;
}

int CRaspI2C::GetErrorCode(){
	return lastErrCode;
}

void CRaspI2C::InitDevice(int dev_addr)
{
	char *filename = (char*)"/dev/i2c-1";
	if ((file_i2c = open(filename, O_RDWR)) < 0)
	{
		//ERROR HANDLING: you can check errno to see what went wrong
		cout << "Failed to open the i2c bus" << endl;
		lastErrCode = -1;
	}

	if (ioctl(file_i2c, I2C_SLAVE, dev_addr) < 0)
	{
		cout << "Failed to acquire bus access and/or talk to slave.\n" << endl;
		//ERROR HANDLING; you can check errno to see what went wrong
		lastErrCode = -1;
	}
	lastErrCode = 0;
}

void CRaspI2C::Read(int reg, int size, unsigned char* data){

    unsigned char addr_dat[2];
    addr_dat[1] = 0xaa;//(unsigned char)(reg & 0xFF);
    addr_dat[0] = 0x0b;//(unsigned char)(reg >> 8);
    // write register address we want to read from
	if (write(file_i2c, addr_dat, 2) != 2)		//write() returns the number of bytes actually written, if it doesn't match then an error occurred (e.g. no response from the device)
	{
		/* ERROR HANDLING: i2c transaction failed */
		cout << "Failed to write to the i2c bus.\n" << endl;
        lastErrCode = -3;
	}
	//----- READ BYTES -----
	if (read(file_i2c, data, size) != size)		//read() returns the number of bytes actually read, if it doesn't match then an error occurred (e.g. no response from the device)
	{
		//ERROR HANDLING: i2c transaction failed
		cout << "Failed to read from the i2c bus.\n" << endl;
        lastErrCode = -4;
	}
	lastErrCode = 0;
}

void CRaspI2C::Write(int size, unsigned char* data){

	if (write(file_i2c, data, size) != size)		//read() returns the number of bytes actually read, if it doesn't match then an error occurred (e.g. no response from the device)
	{
		//ERROR HANDLING: i2c transaction failed
		cout << "Failed to write to the i2c bus.\n" << endl;
        lastErrCode = -3;
	}
	lastErrCode = 0;
}

void CRaspI2C::WriteToReg(int reg, int size, unsigned char* data){

    unsigned char dat_to_write[MAX_WRITE_BUF];
    dat_to_write[1] = (unsigned char)(reg & 0xFF);
    dat_to_write[0] = (unsigned char)(reg >> 8);
    if (size > (MAX_WRITE_BUF -2))
    {
        cout << "Message too big, cannot write!\n" << endl;
        lastErrCode = -5;
    }
    memcpy(&dat_to_write[2], data, size);
	//----- WRITE BYTES -----
	if (write(file_i2c, data, size + 2) != size)		//read() returns the number of bytes actually read, if it doesn't match then an error occurred (e.g. no response from the device)
	{
		//ERROR HANDLING: i2c transaction failed
		cout << "Failed to write to the i2c bus.\n" << endl;
        lastErrCode = -3;
	}
    lastErrCode = 0;
}

