#!/bin/sh
export DISPLAY=:0.0
#export GST_DEBUG=ispsrc:5
#export GST_DEBUG_FILE=./debugIps.txt
# isp-mode=2A works only with camiq
#2592x1944 not supported - only half: 1296x972
#gst-launch-1.0 rkcamsrc device=/dev/video0  io-mode=4  ! video/x-raw,format=NV12,width=640,height=480,framerate=60/1 ! rkximagesink
gst-launch-1.0 rkcamsrc device=/dev/video0  io-mode=4  ! video/x-raw,format=NV12,width=1296,height=972,framerate=30/1 ! rkximagesink
