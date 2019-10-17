

~/sdk/dnn/darknet/darknet -nogpu detector test ~/sdk/dnn/darknet/cfg/coco.data ./data/yolov3-tiny-prn.cfg ./data/yolov3-tiny-prn.weights ~/sdk/dnn/darknet/data/dog.jpg -i 0 -thresh 0.25 > ./results/v3_tiny_prn.txt



