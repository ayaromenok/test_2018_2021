#!/bin/sh
# -lstdc++ added fro pri3 build
g++ gsCamX230.cpp -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui -lopencv_videoio -lstdc++ -I /usr/local/include/opencv4/ -L/usr/local/lib -o gsCamX230
./gsCamX230
