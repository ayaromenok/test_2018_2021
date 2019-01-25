#!/bin/sh
# -lstdc++ added fro pri3 build
g++ gsCamRk3399_2.cpp -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui -lopencv_videoio -lstdc++ -I /usr/local/include/opencv4/ -L/usr/local/lib -o gsCamRk3399_2
#./gsCamRk3399_2

