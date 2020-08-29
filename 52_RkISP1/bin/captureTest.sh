FNAME=$(date +"%Y_%m_%d__%H_%M_%S")
stop-gst-camera.sh
sleep 1
gst-launch-1.0 rkisp num-buffers=1 device=/dev/video0 io-mode=4 analyzer=0 enable-3a=0 ! video/x-raw,format=NV12,width=640,height=320,exposure=4 ! jpegenc ! filesink location=./out/imageTest.jpg &
sleep 3
stop-gst-camera.sh
echo "done"
gpicview ./out/imageTest.jpg