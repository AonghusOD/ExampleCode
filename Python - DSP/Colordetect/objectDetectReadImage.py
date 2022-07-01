# -*- coding: utf-8 -*-
"""
@author: Aonghus O Domhnaill
"""

import cv2 as cv
import numpy as np

# Read original image, returns a numpy.ndarray (h, w, channels)
# Add code to read file, use 

image = cv.imread('mountain.jpg', cv.IMREAD_COLOR)

# Scale, preserving aspect ratio
def scale(image, scale_by):
    w = int(image.shape[1] * scale_by)
    h = int(image.shape[0] * scale_by)
    dim = (w, h)
    image_scaled = cv.resize(image, dim, interpolation=cv.INTER_AREA)
    return image_scaled

scale_by = 0.75
image = scale(image, scale_by)

cv.imshow('Input Image', image)
cv.waitKey(0)


# Convert from BGR to HSV colour model
image_hsv = cv.cvtColor(image, cv.COLOR_BGR2HSV)


# Set thresholds for colour to be detected, based on hue
# Adapt following code for your image
# HSV Hue, Saturation, Value (Brightness)
lower_green = np.array([10,30,30])
upper_green = np.array([50,245,245])

lower_green = np.array([105,30,30])
upper_green = np.array([135,245,245])

# Create mask
mask = cv.inRange(image_hsv, lower_green, upper_green)
cv.imshow('Mask',mask)
cv.waitKey(0)
'''
# Apply mask
image_out = cv.bitwise_and(image, image, mask=mask)

# Show images
cv.imshow('Original Image, Scaled', image)
cv.imshow('Mask', mask)
cv.imshow('Output Image', image_out)
cv.waitKey(0)

'''
cv.destroyAllWindows()