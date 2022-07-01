# -*- coding: utf-8 -*-
"""
@author: Michelle Lynch
"""

import numpy as np
import cv2 as cv
from matplotlib import pyplot as plt

# Read original image
image = cv.imread('iguana.jpg', cv.IMREAD_COLOR)
image_orig = image

# First, scale down
scale_by = 0.05
w = int(image.shape[1] * scale_by)
h = int(image.shape[0] * scale_by)
dim = (w, h)
image = cv.resize(image, dim, interpolation=cv.INTER_AREA)
cv.imshow('Scaled Image', image)
cv.waitKey(0)


# Next scale up, keeping aspect ratio & test different interpolation types
scale_by = 2
w = int(image.shape[1] * scale_by)
h = int(image.shape[0] * scale_by)
dim = (w, h)
# Test Nearest Neighbour Interpolation
image_test1 = cv.resize(image, dim, interpolation=cv.INTER_NEAREST) 
cv.imshow('Nearest Neighbour', image_test1)
# Test Bilinear Interpolation
image_test2= cv.resize(image, dim, interpolation=cv.INTER_LINEAR)
cv.imshow('Bilinear Interpolation', image_test2)
# Test Area Interpolation
image_test3 = cv.resize(image, dim, interpolation=cv.INTER_AREA)
cv.imshow('Area Interpolation', image_test3)
# Test Cubic Interpolation
image_test4 = cv.resize(image, dim, interpolation=cv.INTER_CUBIC)
cv.imshow('Cubic Interpolation', image_test4)


'''
# Try resizing, without maintaining aspect ratio
dim = (1000, 1000)
image_test5 = # Add code
cv.imshow('New Aspect Ratio', image_test5)
cv.waitKey(0)
cv.destroyAllWindows()
'''


