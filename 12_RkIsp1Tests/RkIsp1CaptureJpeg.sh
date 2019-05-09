echo "save 10 jpegs to ./out folder"
export DISPLAY=:0.0
gst-launch-1.0 rkcamsrc device=/dev/video0  num-buffers=10 io-mode=4 ! video/x-raw,format=NV12,width=640,height=480 ! jpegenc ! multifilesink location=out/image_%04d.jpg
echo "save 10 jpegs: done"