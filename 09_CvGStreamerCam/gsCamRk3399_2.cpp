#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using std::cout; using std::cerr; using std::endl;

int main(int, char**)
{
    Mat frame, frame2;
    cout << "Opening camera..." << endl;
    VideoCapture capture(" rkisp device=/dev/video0 sensor-id=1 io-mode=4 path-iqf=/etc/cam_iq/rk-ov4689.xml ! video/x-raw,format=NV12,width=672,height=380,framerate=30/1 ! videoconvert ! appsink", CAP_GSTREAMER);
    VideoCapture capture2(" rkisp device=/dev/video4 sensor-id=5 io-mode=4 path-iqf=/etc/cam_iq/rk-ov4689.xml ! video/x-raw,format=NV12,width=672,height=380,framerate=30/1 ! videoconvert ! appsink", CAP_GSTREAMER);

    if (!capture.isOpened()) {
        cerr << "ERROR: Can't initialize camera capture/1" << endl;
        return 1;
    }
    if (!capture2.isOpened()) {
        cerr << "ERROR: Can't initialize camera capture/2" << endl;
        return 1;
    }
    cout << "Frame width: " << capture.get(CAP_PROP_FRAME_WIDTH) << endl;
    cout << "     height: " << capture.get(CAP_PROP_FRAME_HEIGHT) << endl;
    cout << "Capturing FPS: " << capture.get(CAP_PROP_FPS) << endl;

    cout << endl << "Press 'ESC' to quit, 'space' to toggle frame processing" << endl;
    cout << endl << "Start grabbing..." << endl;

    size_t nFrames = 0;
    bool enableProcessing = false;
    int64 t0 = cv::getTickCount();
    int64 processingTime = 0;
    for (;;)
    {
        capture >> frame; // read the next frame from camera
	capture2 >> frame2; // read the next frame from camera        
	if (frame.empty()) {
            cerr << "ERROR: Can't grab camera frame." << endl;
            break;
        }
	if (frame2.empty()) {
            cerr << "ERROR: Can't grab camera frame/2." << endl;
            break;
        }
        nFrames++;
        if (nFrames % 10 == 0)
        {
            const int N = 10;
            int64 t1 = cv::getTickCount();
            cout << "Frames captured: " << cv::format("%5lld", (long long int)nFrames)
                 << "    Average FPS: " << cv::format("%9.1f", (double)getTickFrequency() * N / (t1 - t0))
                 << "    Average time per frame: " << cv::format("%9.2f ms", (double)(t1 - t0) * 1000.0f / (N * getTickFrequency()))
                 << "    Average processing time: " << cv::format("%9.2f ms", (double)(processingTime) * 1000.0f / (N * getTickFrequency()))
                 << std::endl;
            t0 = t1;
            processingTime = 0;
        }
        if (!enableProcessing)
        {
            imshow("Frame", frame);
	    imshow("Frame2", frame2);
        }
        else
        {
            int64 tp0 = cv::getTickCount();
            Mat processed, processed2;
            cv::Canny(frame, processed, 400, 1000, 5);
	    cv::Canny(frame2, processed2, 400, 1000, 5);
            processingTime += cv::getTickCount() - tp0;
            imshow("Frame - processed", processed);
            imshow("Frame/2 - processed", processed2);
        }
        int key = waitKey(1);
        if (key == 27/*ESC*/)
            break;
        if (key == 32/*SPACE*/)
        {
            enableProcessing = !enableProcessing;
            cout << "Enable frame processing ('space' key): " << enableProcessing << endl;
        }
    }
    std::cout << "Number of captured frames: " << nFrames << endl;
    return nFrames > 0 ? 0 : 1;
}

