#!/bin/bash
#!/usr/bin/python3
# -*- coding:utf-8 -*-
#encoding:utf-8
import os,sys
import csv
import time
import RPi.GPIO as GPIO

switch = 26
GPIO.setmode(GPIO.BCM)
GPIO.setup(switch,GPIO.OUT)
try:
    while True:
        now = time.strftime("%Y-%m-%d-%H_%M_%S",time.localtime(time.time()))
        str = 'sudo raspivid  -t 10000 -o ./out/left'+now+ '.h264'
        GPIO.output(switch,GPIO.HIGH)
        os.system(str)  
        time.sleep(5)
        now = time.strftime("%Y-%m-%d-%H_%M_%S",time.localtime(time.time()))
        str = 'sudo raspivid -t 10000 -o ./out/right'+now+ '.h264'
        GPIO.output(switch,GPIO.LOW)
        os.system(str) 
        time.sleep(5)
except:
    print("except")
GPIO.cleanup()
