#!/bin/sh
gst-launch-1.0 -v v4l2src ! video/x-raw,format=YUY2,width=640,height=480 !  xvimagesink
