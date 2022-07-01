# -*- coding: utf-8 -*-
"""
@author: Michelle Lynch
"""

import cv2 as cv

# Read original image, returns a numpy.ndarray (h, w, channels)
image = cv.imread('flamingo.jpg', cv.IMREAD_COLOR)
# Save copy of original image
image_orig = image
cv.imshow('', image)
cv.waitKey(0)

# Print image attributes
print(type(image))
print(image.shape)
print(image.size)
print(image.dtype)

# Get dimensions of the image
dim_orig = image.shape
height, width, channels = image.shape


# Scale, preserving aspect ratio
def scale(image, scale_by):
    # Add code to calculate new width & height, w & h
    w = int(image.shape[1]*scale_by)
    h = int(image.shape[0]*scale_by)
    dim = (w, h)
    image_scaled = cv.resize(image, dim, interpolation=cv.INTER_AREA)
    cv.imshow('', image_scaled)
    cv.waitKey(0)
    return image_scaled


# Convert to grayscale
def grayscale(image):
    # Add code to create image_gray, use opencv's cvtColor function
    image_gray=(cv.cvtColor(image, cv.COLOR_BGR2GRAY))
    cv.imshow(' ', image_gray)
    cv.waitKey(0)
    return image_gray


# Extract a Region of Interest (ROI)
def roi(image):
    # Create image_roi by slicing into the image matrix
    image_roi = image[50:300,50:250]
    cv.imshow('', image_roi)
    cv.waitKey(0)
    return image_roi


# Black out part of the image
def black_out(image):
    dim = image.shape
    image[dim[0]-50:dim[0], dim[1]-300:dim[1]-200] = [0,128,0]# Add code for BGR black
    cv.imshow('', image)
    cv.waitKey(0)
    return image

# Draw on the image
def draw_on(image):
    # Draw a line on the image, specifying start & end coords, BGR color, linewidth
    dim = image.shape
    cv.arrowedLine(image, (0,0), (dim[0]//2,dim[1]//2), (255,255,255), 20)
    # Draw rectangle, from top left to bottom right, BGR, linewidth
    cv.rectangle(image, (50,100), (450,600), (0,200,255), 30)
    # Add some text
    cv.putText(image,'DSP!',(50,100), cv.FONT_HERSHEY_SIMPLEX, 10, (255,255,255), 20)
    cv.imshow('', image)
    cv.waitKey(0)
    return image

scale_by = 0.25
image_scaled = scale(image_orig, scale_by)
#image_scaled_copy = image_scaled
#image_gray = grayscale(image_scaled)
#image_roi = roi(image_scaled)
image_blackout = black_out(image_scaled)
#image_drawon = draw_on(image_scaled)


cv.destroyAllWindows()
