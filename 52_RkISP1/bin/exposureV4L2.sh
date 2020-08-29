EXP=400
v4l2-ctl -d /dev/video0 --list-ctrls
v4l2-ctl -d /dev/video0 --get-ctrl=exposure
echo "set value to: $EXP"
v4l2-ctl -d /dev/video0 --set-ctrl=exposure=$EXP
v4l2-ctl -d /dev/video0 --get-ctrl=exposure
#gst-launch-1.0 rkisp device=/dev/video0 num-buffers=8 ! video/x-raw,format=NV12,width=2688,height=1520,expousre=40! videoconvert ! jpegenc ! multifilesink location=_out%d.jpg
