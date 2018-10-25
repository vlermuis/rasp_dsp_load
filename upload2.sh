#!/bin/sh

DEV_IP_ADDRESS="10.10.10.5"
DEV_REMOUTE_FOLDER="/home/pi"

#scp main.cpp Makefile pi@$DEV_IP_ADDRESS:$DEV_REMOUTE_FOLDER
#echo $DEV_IP_ADDRESS
#echo $DEV_IP_ADDRESS:$DEV_REMOUTE_FOLDER

#scp src/Dsp1451.cpp src/RaspI2C.cpp pi@$DEV_IP_ADDRESS:$DEV_REMOUTE_FOLDER/src
#scp -r ../rpaudio/ pi@10.10.10.5:/home/pi

scp -r ../rpaudio/ pi@$DEV_IP_ADDRESS:$DEV_REMOUTE_FOLDER


