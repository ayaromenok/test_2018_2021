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
        str = 'sudo raspistill -o ./out/left'+now+ '.jpg'
        GPIO.output(switch,GPIO.HIGH)
        os.system(str)  
        time.sleep(1)
        now = time.strftime("%Y-%m-%d-%H_%M_%S",time.localtime(time.time()))
        str = 'sudo raspistill -o ./out/right'+now+ '.jpg'
        GPIO.output(switch,GPIO.LOW)
        os.system(str) 
        time.sleep(5)
except:
    print("except")
GPIO.cleanup()
