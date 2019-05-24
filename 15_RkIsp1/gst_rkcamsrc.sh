#!/bin/sh

export DISPLAY=:0.0 

#1296x972 binning 2x2
gst-launch-1.0 rkcamsrc device=/dev/video0 io-mode=4 isp-mode=2A ! videoconvert ! video/x-raw,format=NV12,width=1296,height=972  ! rkximagesink

#640x480 binning 4x4
#gst-launch-1.0 rkcamsrc device=/dev/video0 io-mode=4 isp-mode=2A ! videoconvert ! video/x-raw,format=NV12,width=640,height=480  ! rkximagesink

#2592x1944 no binning 
#gst-launch-1.0 rkcamsrc device=/dev/video0 io-mode=4 isp-mode=2A ! videoconvert ! video/x-raw,format=NV12,width=2592,height=1944  ! rkximagesink

#1920x1080 no binning, partial FOV
#gst-launch-1.0 rkcamsrc device=/dev/video0 io-mode=4 isp-mode=2A ! videoconvert ! video/x-raw,format=NV12,width=1920,height=1080  ! rkximagesink

#rpi cam v2.1
#gst-launch-1.0 rkcamsrc device=/dev/video0 io-mode=4 isp-mode=2A tuning-xml-path=/etc/cam_iq/IMX219.xml ! videoconvert ! video/x-raw,format=NV12,width=1600,height=900  ! rkximagesink
