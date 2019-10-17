

~/sdk/dnn/darknet/darknet -nogpu detector test ~/sdk/dnn/darknet/cfg/coco.data ~/sdk/dnn/darknet/cfg/yolov3.cfg ./data/yolov3.weights ~/sdk/dnn/darknet/data/dog.jpg -i 0 -thresh 0.25 > ./results/v3.txt



