#!/bin/sh
# no 3D support
# lag related to network speed
# max 90 fps due to native 640x480x90 max
# 

#mjpg_streamer -o "output_http.so -w ./www" -i "input_raspicam.so -width 160 -height 120 -fps 90"
mjpg_streamer -o "output_http.so -w ./www" -i "input_raspicam.so -width 320 -height 240 -fps 90"
#mjpg_streamer -o "output_http.so -w ./www" -i "input_raspicam.so -width 640 -height 480 -fps 30"
#mjpg_streamer -o "output_http.so -w ./www" -i "input_raspicam.so -width 1296 -height 972 -fps 15"
#mjpg_streamer -o "output_http.so -w ./www" -i "input_raspicam.so -width 2592 -height 1944 -fps 5"
