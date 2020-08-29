FNAME=$(date +"%Y_%m_%d__%H_%M_%S")
stop-gst-camera.sh
sleep 1
gst-launch-1.0 rkisp num-buffers=8 device=/dev/video0 io-mode=4 ! video/x-raw,format=NV12,width=640,height=320 ! jpegenc ! multifilesink location=./out/imageL_$FNAME.jpg
echo "done"
