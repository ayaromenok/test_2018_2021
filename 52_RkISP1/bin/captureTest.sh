#rkimagesink required io-mode=4 and work correctly only with sinle camera(but faster)
#glimagesink - for dual cam(but with delay)
rm ./out/imageTest*
export DISPLAY=:0.0
# 0.. 3..4..5
DBG_LEVEL=0
BUFFERS=5
gst-launch-1.0 rkisp device=/dev/video0  io-mode=4 path-iqf=../cam_iq/ov4689_0.2.5.xml --gst-debug-level=$DBG_LEVEL num-buffers=$BUFFERS ! video/x-raw,format=NV12,width=640,height=360 ! jpegenc ! multifilesink location=./out/imageTest%d.jpg &
sleep 2
stop-gst-camera.sh

gpicview ./out/imageTest0.jpg