
CURPATH=`pwd`
cd ~/sdk/dnn/darknet.cl/
./darknet detector test ./cfg/coco.data ./cfg/yolov3-tiny.cfg $CURPATH/data/yolov3-tiny.weights ./data/dog.jpg -i 0 -thresh 0.25 > $CURPATH/results/v3_tiny_cl.txt



