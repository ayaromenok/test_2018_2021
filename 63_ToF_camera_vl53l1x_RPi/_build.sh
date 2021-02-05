#! /bin/sh
rm ./VL53L1X_I2C

g++ VL53L1X_I2C.cpp -l wiringPi -o VL53L1X_I2C

sudo ./VL53L1X_I2C
