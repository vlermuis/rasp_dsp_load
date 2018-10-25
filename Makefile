all:
	g++ -g -o dsp1451_load main.cpp src/RaspI2C.cpp src/Dsp1451.cpp -Iinclude
lib:
        g++ -c -o  raspi2c.o src/RaspI2C.cpp  -Iinclude
#       ar rcs raspi2c.a raspi2c.o
        g++ -c -o dsp1451.o src/Dsp1451.cpp -Iinclude
#       ar rcs dsp1451.a dsp1451.o
        ar rcs rpaudio.a raspi2c.o dsp1451.o
wlib:
        g++ -g -o dl main.cpp rpaudio.a -Iinclude
clean:
        rm dsp1451_load dl *.o *.a

