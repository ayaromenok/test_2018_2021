#!/bin/sh
# -lstdc++ for RPi3 build
g++ cvRkIsp1Gs.cpp -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui -lopencv_videoio -lstdc++ -I /usr/local/include/opencv4/ -L/usr/local/lib \
-o cvRkIsp1Gs
export DISPLAY=:0.0
./cvRkIsp1Gs
