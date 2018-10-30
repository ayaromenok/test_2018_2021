#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>  // cv::Canny()
#include <iostream>

using namespace cv;
using std::cout; using std::cerr; using std::endl;

int main(int, char**)
{
    Mat frame, frame2, frame3;
    cout << "Opening camera..." << endl;
    VideoCapture capture("/dev/video0", CAP_V4L); // open the first camera
    capture.set(CAP_PROP_FRAME_WIDTH, 640);
    capture.set(CAP_PROP_FRAME_HEIGHT, 480);
    VideoCapture capture2("/dev/video1", CAP_V4L); // open the second camera
    capture2.set(CAP_PROP_FRAME_WIDTH, 640);
    capture2.set(CAP_PROP_FRAME_HEIGHT, 480);
    VideoCapture capture3("/dev/video2", CAP_V4L); // open the second camera
    capture3.set(CAP_PROP_FRAME_WIDTH, 640);
    capture3.set(CAP_PROP_FRAME_HEIGHT, 480);
    if (!capture.isOpened())
    {
        cerr << "ERROR: Can't initialize camera capture" << endl;
        return 1;
    }
    
    if (!capture2.isOpened())
    {
        cerr << "ERROR: Can't initialize camera capture" << endl;
        return 1;
    }

    if (!capture3.isOpened())
    {
        cerr << "ERROR: Can't initialize camera capture" << endl;
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
        capture3 >> frame3; // read the next frame from camera

        if (frame.empty())
        {
            cerr << "ERROR: Can't grab camera frame." << endl;
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
            imshow("Frame3", frame3);
        }
        else
        {
            int64 tp0 = cv::getTickCount();
            Mat processed, processed2, processed3;
            cv::Canny(frame, processed, 400, 1000, 5);
            cv::Canny(frame2, processed2, 400, 1000, 5);
            cv::Canny(frame3, processed3, 200, 2000, 5);
            processingTime += cv::getTickCount() - tp0;
            imshow("Frame - pro", processed);
            imshow("Frame2 - pro", processed2);
	    imshow("Frame3 - pro", processed3);
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

