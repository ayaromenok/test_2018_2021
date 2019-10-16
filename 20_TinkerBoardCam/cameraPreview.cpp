#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

    VideoCapture cap;

    cap = VideoCapture("rkcamsrc io-mode=4 isp-mode=2A ! video/x-raw,format=NV12,width=640,height=480 ! videoconvert ! appsink");
    if(!cap.isOpened())
    {
        cout << "Couldn't find camera: " << "cameraDevice" << endl;
        return -1;
    }

    cap.set(CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CAP_PROP_FRAME_HEIGHT, 480);

    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera/video or read image

        if (frame.empty())
        {
            waitKey();
            break;
        }

        imshow("image", frame);
        if (waitKey(1) >= 0) break;
    }

    return 0;
}

