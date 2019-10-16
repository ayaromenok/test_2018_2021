#!/bin/sh
export DISPLAY=:0.0
g++ facedetect.cpp -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui -lopencv_videoio -lopencv_objdetect -lstdc++ -I /usr/local/include/opencv4/ -L/usr/local/lib \
-o facedetect
