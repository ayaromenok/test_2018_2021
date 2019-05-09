echo "capture 300 frames to h264 video file"
gst-launch-1.0 rkcamsrc num-buffers=300 device=/dev/video0  io-mode=4 ! video/x-raw,format=NV12,width=640,height=480,framerate=30/1 ! queue ! mpph264enc ! queue ! h264parse ! mpegtsmux ! filesink location=out/_video640x480h264.ts
echo "dode"