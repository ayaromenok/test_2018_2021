#!/bin/sh
# no 3D support
# fps bigger than 15 give a additional lag
mjpg_streamer -o "output_http.so -w ./www" -i "input_raspicam.so -fps 15"
