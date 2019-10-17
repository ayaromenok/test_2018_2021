echo "gathering YOLO v3"
wget https://pjreddie.com/media/files/yolov3.weights -O ./data/yolov3.weights

echo "gathering yolo v3 TINY"
wget https://pjreddie.com/media/files/yolov3-tiny.weights -O ./data/yolov3-tiny.weights

echo "gathering yolo v3 tiny PRN"
wget https://raw.githubusercontent.com/WongKinYiu/PartialResidualNetworks/master/cfg/yolov3-tiny-prn.cfg -O ./data/yolov3-tiny-prn.cfg
wget https://drive.google.com/uc\?export\=download\&id\=1FlHeQjWEQVJt0ay1PVsiuuMzmtNyv36m -O ./data/yolov3-tiny-prn.weights
