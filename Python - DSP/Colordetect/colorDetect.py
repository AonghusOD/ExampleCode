# -*- coding: utf-8 -*-
"""
@author: Aonghus O Domhnaill
"""
import cv2 as cv
import numpy as np

# Create an image
image = np.zeros((400,400,3), np.uint8)
# Add code to create an image with red, blue, red & yellow squares
image[100:200, 100:200] = (0, 0, 255) #RED (bgr)
image[100:200, 200:300] = (255, 0, 0) #BLUE (bgr)
image[200:300, 100:200] = (0, 255, 0) #Green (bgr)
image[200:300, 200:300] = (0, 255, 255) #Yellow (bgr)
# Plot image
cv.imshow('Input Image', image)
cv.waitKey(0)


# Convert to HSV colour model
image_hsv = cv.cvtColor(image, cv.COLOR_BGR2HSV)# Add code, use opencv's cvtColor function


# Create mask
# Note: green hue 60, Blue hue 120, Yellow hue 30, Red hue 0
lower = np.array([50, 10, 10]) # Add code to create an array with BGR colours for lower threshold
upper = np.array([70, 255, 255])# Add code to create an array with BGR colours for upper threshold
mask = cv.inRange(image_hsv, lower, upper)

# Apply mask to input image to get ouput image
# Add code to create outpu image, use cv.bitwise_and(image, image, mask=mask)
image_out = cv.bitwise_and(image, image, mask=mask)

# Plot mask & output image
cv.imshow('Mask', mask)
cv.waitKey(0)

cv.imshow('Output Image', image_out)
cv.waitKey(0)
