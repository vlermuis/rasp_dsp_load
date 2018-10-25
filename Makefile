all:
	g++ -g -o dsp1451_load main.cpp src/RaspI2C.cpp src/Dsp1451.cpp -Iinclude
clean:
        rm dsp1451_load

