import keras, os
from keras.models import Sequential
from keras.layers import Dense, Conv2D, MaxPool2D, Flatten
from keras.preprocessing.image import ImageDataGenerator
import numpy as np
import tensorflow as tf

from keras.backend.tensorflow_backend import set_session
config = tf.ConfigProto()
config.gpu_options.per_process_gpu_memory_fraction = 0.2
set_session(tf.Session(config=config))

trdata = ImageDataGenerator()
traindata = trdata.flow_from_directory(directory="../data/train", target_size=(16,16))
tsdata = ImageDataGenerator()
testdata =  trdata.flow_from_directory(directory="../data/validation", target_size=(16,16))

model = Sequential()
#16x16x8
model.add(Conv2D(input_shape=(16,16,3),filters=8,kernel_size=(3,3),padding="same", activation="relu"))
#model.add(Conv2D(filters=8,kernel_size=(3,3),padding="same", activation="relu"))
#8x8x8
model.add(MaxPool2D(pool_size=(2,2),strides=(2,2)))
model.add(Conv2D(filters=8, kernel_size=(3,3), padding="same", activation="relu"))
#4x4
model.add(MaxPool2D(pool_size=(2,2),strides=(2,2)))
#latest
model.add(Flatten())
model.add(Dense(units=128,activation="relu"))
model.add(Dense(units=64,activation="relu"))
model.add(Dense(units=2, activation="softmax"))

#compilation
from keras.optimizers import Adam
opt = Adam(lr=0.001)

model.compile(optimizer=opt, loss=keras.losses.categorical_crossentropy, metrics=['accuracy'])
model.summary()

model_json = model.to_json()
with open('someModel16x16_v2.json', "w") as json_file:
	json_file.write(model_json)


from keras.callbacks import ModelCheckpoint, EarlyStopping

checkpoint = ModelCheckpoint("someModel16x16_v2.h5", monitor='val_accuracy', verbose=1, save_best_only=True, save_weights_only=False, mode='auto', period=1)
early = EarlyStopping(monitor='val_accuracy', min_delta=0, patience=20, verbose=1, mode='auto')
hist = model.fit_generator(steps_per_epoch=100,generator=traindata, validation_data= testdata, validation_steps=10,epochs=10,callbacks=[checkpoint,early])


import matplotlib.pyplot as plt
plt.plot(hist.history["accuracy"])
plt.plot(hist.history['val_accuracy'])
plt.plot(hist.history['loss'])
plt.plot(hist.history['val_loss'])
plt.title("model accuracy")
plt.ylabel("Accuracy")
plt.xlabel("Epoch")
plt.legend(["Accuracy","Validation Accuracy","loss","Validation Loss"])
plt.show()



from keras.preprocessing import image
img = image.load_img("image.jpg",target_size=(16,16))
img = np.asarray(img)
plt.imshow(img)
img = np.expand_dims(img, axis=0)

from keras.models import load_model
saved_model = load_model("someModel16x16_v2.h5")
output = saved_model.predict(img)
if output[0][0] > output[0][1]:
    print("cat")
else:
    print('dog')


