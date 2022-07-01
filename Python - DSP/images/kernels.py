# -*- coding: utf-8 -*-
"""
@author: MiLynch
"""

import numpy as np
import cv2 as cv

# Read original image, returns a numpy.ndarray (h, w, channels)
image = cv.imread('flamingo.jpg', cv.IMREAD_COLOR)

# Save copy of original image
image_orig = image
#cv.imshow('', image)
#cv.waitKey(0)

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

scale_by = 0.3
image = scale(image_orig, scale_by)
cv.imshow('Original Image, Scaled', image)
cv.waitKey(0)


def boxBlur(image):
    kernel = np.ones((5,5), np.float32)/25
    print(kernel)
    image_box_blur = cv.filter2D(image,-1,kernel)
    stack = np.hstack((image, image_box_blur))
    cv.imshow('Box Blur', stack)
    cv.waitKey(0)
    

def gaussianBlur(image):
   # kernel = 1/16*np.array([[1,2,1],
    #                        [2,4,2],
    #                        [1,2,1]])
    #image_Gaussian_blur = cv.filter2D(image, -1, kernel)
    image_Gaussian_blur = cv.GaussianBlur(image, (25, 25), 0)
    # Stack images horizontally
    stack = np.hstack((image, image_Gaussian_blur)) 
    cv.imshow('Gaussian Blur', stack)
    cv.waitKey(0)

def sharpen(image):
    kernel = np.array([[-1,-1,-1],
                      [-1,9,-1],
                      [-1,-1,-1]])
    image_sharpen = cv.filter2D(image, -1, kernel)
    stack = np.hstack((image, image_sharpen))
    cv.imshow('Sharpen', stack)
    cv.waitKey(0)
    return image_sharpen


def Laplacian(image):
    kernel = np.array([[0, -1, 0],
                       [-1, 4, -1],
                       [0, -1, 0]])
    image_Laplacian = cv.filter2D(image, -1, kernel)
    stack = np.hstack((image, image_Laplacian))
    cv.imshow('Laplacian', stack)
    cv.waitKey(0)
    return image_Laplacian

def canny(image):
    image_edges = cv.Canny(image, 0, 100, 3)
    image2D=image[:,:,0]
    stack = np.hstack((image2D, image_edges))
    cv.imshow('Canny Edge Detect Image', stack)
    cv.waitKey(0)
    return image_edges
'''
def PrewittOpV(image):
    kernel = np.array([[1, 0 ,-1],
                       [1, 0 ,-1],
                       [1, 0 ,-1]])
    image_gray = cv.cvtColor(image, cv.COLOR_BGR2GRAY)
    image_lines = cv.filter2D(image_gray, -1, kernel)
    stack = np.hstack((image_gray, image_lines))
    cv.imshow('Prewitt Operator, Vertical', stack)
    cv.waitKey(0)
    return image_lines
'''
#This good for spectrogram
def HorizontalPrewittOpV(image):
    kernel = np.array([[1, 1 , 1],
                       [0, 0 , 0],
                       [-1, -1 ,-1]])
    image_gray = cv.cvtColor(image, cv.COLOR_BGR2Lab)
    image_lines = cv.filter2D(image_gray, -1, kernel)
    stack = np.hstack((image_gray, image_lines))
    cv.imshow('Prewitt Operator, Horizontal', stack)
    cv.waitKey(0)
    return image_lines


def fromSlides(image):
    kernel = np.array([[4, 0 , 0],
                       [0, 0 , 0],
                       [0, 0 , -4]])
    image_gray = cv.cvtColor(image, cv.COLOR_BGR2GRAY)
    image_lines = cv.filter2D(image_gray, -1, kernel)
    stack = np.hstack((image_gray, image_lines))
    cv.imshow('From slides Operator, Vertical', stack)
    cv.waitKey(0)
    return image_lines

'''
def SobelOpV(image):
    kernel = np.array([[-1,0 , 1],
                       [-2, 0 , 2],
                       [-1, 0 , 1]])
    image_gray = cv.cvtColor(image, cv.COLOR_BGR2GRAY)
    image_lines = cv.filter2D(image_gray, -1, kernel)
    stack = np.hstack((image_gray, image_lines))
    cv.imshow('Sobel Operator, Vertical', stack)
    cv.waitKey(0)
    return image_lines
'''
# Add code to run functions
#boxBlur(image)
gaussianBlur(image)
#sharpen(image)
#Laplacian(image)
#canny(image)
#PrewittOpV(image)
#HorizontalPrewittOpV(image)
#SobelOpV(image)
#fromSlides(image)