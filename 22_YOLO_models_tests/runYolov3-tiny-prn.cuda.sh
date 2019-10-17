
CURPATH=`pwd`
cd ~/sdk/dnn/darknet/
./darknet detector test ./cfg/coco.data $CURPATH/data/yolov3-tiny-prn.cfg $CURPATH/data/yolov3-tiny-prn.weights ./data/dog.jpg -i 0 -thresh 0.25 > $CURPATH/results/v3_tiny_prn_cuda.txt



