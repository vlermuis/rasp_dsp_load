all:
	g++ -g -o dsp_load_test main.cpp src/RaspI2C.cpp src/Dsp.cpp src/Dsp1451.cpp src/Dsp1761.cpp -Iinclude -Idsp_hfiles
lib:
	g++ -c -o  raspi2c.o src/RaspI2C.cpp  -Iinclude -Idsp_hfiles
	g++ -c -o dsp.o src/Dsp.cpp -Iinclude -Idsp_hfiles
	g++ -c -o dsp1451.o src/Dsp1451.cpp -Iinclude -Idsp_hfiles
	g++ -c -o dsp1761.o src/Dsp1761.cpp -Iinclude -Idsp_hfiles
	ar rcs rpaudio.a raspi2c.o dsp.o dsp1451.o dsp1761.o
wlib:
	g++ -g -o dl main.cpp rpaudio.a -Iinclude -Idsp_hfiles
clean:
	rm dsp_load_test dl *.o *.a


