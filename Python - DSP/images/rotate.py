# -*- coding: utf-8 -*-
"""
@author: Michelle Lynch
"""

import numpy as np
import cv2 as cv

# Read original image, returns a numpy.ndarray (h, w, channels)
image = cv.imread('flamingo.jpg', cv.IMREAD_COLOR)
# Save original, as we will overwrite 'image'
image_orig = image

# Get dimensions of the image
dim_orig = image.shape
height, width, channels = image.shape

# Scale, preserving aspect ratio
def scale(image, scale_by):
    w = int(image.shape[1] * scale_by)
    h = int(image.shape[0] * scale_by)
    dim = (w, h)
    image_scaled = cv.resize(image, dim, interpolation=cv.INTER_AREA)
    return image_scaled

# Rotate
def rotate(image):
    height, width, channels = image.shape
    # Centre is in tuple of (cols, rows) or (width, height) (see warp_affine doc)
    centre = (width //2, height //2)
    mx = cv.getRotationMatrix2D(centre, -45, 1.0)
    image_rot = cv.warpAffine(image, mx, (width, height))
    cv.imshow('Input Image', image_rot)
    cv.waitKey(0)
    return image_rot
    
    # Add code
    # centre = 

scale_by = 0.50
image = scale(image, scale_by)
image = rotate(image)
#cv.imshow('', image)
#cv.waitKey(0)
cv.destroyAllWindows()
