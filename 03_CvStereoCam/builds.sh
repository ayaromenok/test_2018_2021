# -lstdc++ added fro pri3 build
gcc stereoCam.cpp -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui -lopencv_videoio -lstdc++ -I /usr/local/include/opencv4/ -o stereoCam
