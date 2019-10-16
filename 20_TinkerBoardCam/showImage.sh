gst-launch-1.0 rkcamsrc device=/dev/video0 io-mode=4 ! video/x-raw,format=NV12,width=640,height=480 ! rkximagesink
