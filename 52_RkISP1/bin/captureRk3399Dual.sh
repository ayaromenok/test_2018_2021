FNAME=$(date +"%Y_%m_%d__%H_%M_%S")
sleep 1
gst-launch-1.0 rkisp num-buffers=8 device=/dev/video0 io-mode=4 ! video/x-raw,format=NV12,width=640,height=320 ! jpegenc ! multifilesink location=./out/imageL_$FNAME.jpg &
sleep 3
stop-gst-camera.sh
gst-launch-1.0 rkisp num-buffers=8 device=/dev/video5 io-mode=4 ! video/x-raw,format=NV12,width=640,height=320 ! jpegenc ! multifilesink location=./out/imageR_$FNAME.jpg &
sleep 3
stop-gst-camera.sh

echo "done"
