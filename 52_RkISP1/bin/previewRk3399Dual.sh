#rkimagesink required io-mode=4 and work correctly only with sinle camera(but faster)
#glimagesink - for dual cam(but with delay)
export DISPLAY=:0.0

gst-launch-1.0 rkisp device=/dev/video0 io-mode=4 path-iqf=../cam_iq/ov4689_0.2.5.xml ! video/x-raw,format=NV12,width=640,height=360,framerate=30/1 ! glimagesink &
gst-launch-1.0 rkisp device=/dev/video5 io-mode=4 path-iqf=../cam_iq/ov4689_0.2.5.xml ! video/x-raw,format=NV12,width=640,height=360,framerate=30/1 ! glimagesink
