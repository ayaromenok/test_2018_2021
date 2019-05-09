#include <opencv2/opencv.hpp>
#include <iostream>

int main(int, char**)
{
    cv::Mat frame;
    cv::VideoCapture cap("rkcamsrc device=/dev/video0 io-mode=4 isp-mode=2A tuning-xml-path=../cam_iq/OV5647.xml ! video/x-raw, format=NV12,width=640,height=480,framerate=15/1 ! videoconvert ! appsink", cv::CAP_GSTREAMER);

    if (!cap.isOpened()) {
        std::cerr << "ERROR: Can't initialize camera capture" << std::endl;
        return 1;
    }
    
    size_t nFrames = 0;
    bool enableProcessing = false;
    int64 t0 = cv::getTickCount();
    int64 processingTime = 0;
    
    for (;;) {
        cap >> frame; // read the next frame from camera
        if (frame.empty()) {
            std::cerr << "ERROR: Can't grab camera frame." << std::endl;
            break;
        }
        nFrames++;
        if (nFrames % 10 == 0)
        {
            const int N = 10;
            int64 t1 = cv::getTickCount();
            std::cout << "Frames captured: " << cv::format("%5lld", (long long int)nFrames)
                 << "    Average FPS: " << cv::format("%9.1f", (double)cv::getTickFrequency() * N / (t1 - t0))
                 << "    Average time per frame: " << cv::format("%9.2f ms", (double)(t1 - t0) * 1000.0f / (N * cv::getTickFrequency()))
                 << "    Average processing time: " << cv::format("%9.2f ms", (double)(processingTime) * 1000.0f / (N * cv::getTickFrequency()))
                 << std::endl;
            t0 = t1;
            processingTime = 0;
        }
        
        if (!enableProcessing) {
            imshow("Frame", frame);
        }
        else {
            int64 tp0 = cv::getTickCount();
            cv::Mat gray, processed;
            cv:cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
            cv::Canny(gray, processed, 400, 1000, 5);
            processingTime += cv::getTickCount() - tp0;
            imshow("Frame - pro", processed);
        }
        int key = cv::waitKey(1);
        if (key == 27/*ESC*/)
            break;
        if (key == 32/*SPACE*/)
        {
            enableProcessing = !enableProcessing;
            std::cout << "Enable frame processing ('space' key): " << enableProcessing << std::endl;
        }
    }
    std::cout << "Number of captured frames: " << nFrames << std::endl;
    return nFrames > 0 ? 0 : 1;
}

