import cv2

# load model
net = cv2.dnn.readNetFromTensorflow("result/frozen_tensorflow_model.pb")

# load a sample image
image = cv2.imread("image.jpg")

# this will resize your sample image to input size that is required by your model (W, H) 
# and can perform a mean substraction of (mean0, mean1, mean2) for normalzing it.

blob = cv2.dnn.blobFromImage(image, 1, (16, 16), (103.93, 116.77, 123.68), True, False)

# set the blob as input to the network and perform a forward-pass to
# obtain our output classification
net.setInput(blob)
preds = net.forward()

# sort the indexes of the probabilities in descending order (higher first) and get the first 
idx = np.argsort(preds[0])[0]

# print the prediction label and probability
print ("Label: {}, {:.2f}%".format(idx, preds[0][idx] * 100))
