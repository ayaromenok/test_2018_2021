#!/bin/sh
export DISPLAY=:0.0
g++ cameraPreview.cpp -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui -lopencv_videoio -lstdc++ -I /usr/local/include/opencv4/ -L/usr/local/lib \
-o cameraPreview
./cameraPreview
