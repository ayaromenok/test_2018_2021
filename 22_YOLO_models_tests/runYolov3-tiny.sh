

~/sdk/dnn/darknet/darknet -nogpu detector test ~/sdk/dnn/darknet/cfg/coco.data ~/sdk/dnn/darknet/cfg/yolov3-tiny.cfg ./data/yolov3-tiny.weights ~/sdk/dnn/darknet/data/dog.jpg -i 0 -thresh 0.25 > ./results/v3_tiny.txt



