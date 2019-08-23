import tensorflow as tf
from tensorflow import keras
import numpy as np
import matplotlib.pyplot as plt
from keras.datasets import fashion_mnist
from tensorflow.python.ops.metrics_impl import _streaming_sparse_false_positive_at_k

print(tf.__version__)

#Download training and testing data by keras
fashion_mnist = keras.datasets.fashion_mnist
(train_images, train_labels), (test_images, test_labels) = fashion_mnist.load_data()

#Set Class name for each label
class_names = ['T-shirt/top', 'Trouser', 'Pullover', 'Dress', 'Coat',
               'Sandal', 'Shirt', 'Sneaker', 'Bag', 'Ankle boot']

#Check the shape of each downloaded data
print(type(train_images), type(train_labels), type(test_images), type(test_labels))

#show preprocess the data
# plt.figure()
# plt.imshow(train_images[0])
# plt.colorbar()
# plt.grid(False)
# plt.show()

#Scaling the feature first (make gradient descent faster) to the range [0, 1]
train_images = train_images / 255.0
test_images = test_images / 255.0

#Show the first 25 images in training set with its affiliated label name
# plt.figure(figsize=(10,10))
# for i in range(25):
#     plt.subplot(5, 5, i+1)
#     plt.xticks([])
#     plt.yticks([])
#     plt.grid(False)
#     plt.imshow(train_images[i], cmap=plt.cm.binary)
#     plt.xlabel(class_names[train_labels[i]])
# plt.show()

# Build DNN module
# How we initialize the model
#  
model = keras.Sequential([
    keras.layers.Flatten(input_shape=(28, 28)),
    keras.layers.Dense(128, activation=tf.nn.relu),   # For how to treat training data while training
    keras.layers.Dense(64, activation=tf.nn.sigmoid), # The second layer is sigmoid
    keras.layers.Dense(10, activation=tf.nn.softmax)  # classify the case in to 1 of 10 categories
    ])

model.compile(optimizer='adam',  # how the model be updated 
              loss='sparse_categorical_crossentropy',  #loss function identification 
              metrics=['accuracy']) #how to monitor training steps

#Training data 
model.fit(train_images, 
          train_labels, 
          epochs=2) # how may times of propagation should be done

print(model.summary())
#Evaluate accuracy (using testing data)
test_loss, test_acc = model.evaluate(test_images, test_labels)
print("Test loss", test_loss)
print("Test accuracy", test_acc)

#Predict
predictions = model.predict(test_images)
print(predictions.shape)
print(predictions[0])
print(np.argmax(predictions[0]))


#Build Model 
#Step 1: Setup the layers 





print("Hello World!")
