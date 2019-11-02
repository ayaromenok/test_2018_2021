from keras.preprocessing import image
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np


imgShow=mpimg.imread("image.jpg")
imgplot = plt.imshow(imgShow)
#plt.show()

img = image.load_img("image.jpg",target_size=(90,90))
img = np.asarray(img)
#plt.imshow(img)
img = np.expand_dims(img, axis=0)

from keras.models import load_model
saved_model = load_model("vgg16_ySize.h5")

output = saved_model.predict(img)
if output[0][0] > output[0][1]:
    print("cat")
else:
    print('dog')
