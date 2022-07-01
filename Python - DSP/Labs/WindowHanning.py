# -*- coding: utf-8 -*-
"""
@author: Aonghus O Domhnaill
"""

import numpy as np
import matplotlib.pyplot as plt


def window(x, w):
    wx = np.zeros(w.size)
    for i in range(0, w.size):
        wx[i] = x[i]*w[i]
    return wx

def format_stem():
    plt.setp(stemlines, color='k', linewidth=2.0)
    plt.setp(baseline, color='k', linewidth=2.0)
    plt.setp(markerline, color='k', markersize=10)
    ax.set_xlabel('n', fontsize=24, labelpad=5)
    ax.spines['top'].set_color('none')
    ax.spines['right'].set_color('none')
    ax.spines['bottom'].set_color('none')
    ax.spines['left'].set_color('none')
    ax.tick_params(axis='both', which='both', labelsize=18, length=0)
    markerline.set_clip_on(False)
    
x = np.array([2, 2, 2, 2, 2, 2, 2, 2, 2, 2]) 
n = np.arange(0, x.size)
win_size = 10
hann = np.hanning(win_size)
n_hann = np.arange(0, win_size)
wx = window(x, hann)

fig = plt.figure(figsize=(18,12))
ax = fig.add_subplot(311)
markerline, stemlines, baseline = ax.stem(n, x, markerfmt='o', use_line_collection=True)
plt.ylabel('x[n]', fontsize=24, labelpad=10)
plt.title("Original Signal", fontsize=24, pad=10)
format_stem()
ax = fig.add_subplot(312)
markerline, stemlines, baseline = ax.stem(n_hann, hann, markerfmt='o', use_line_collection=True)
plt.ylabel('Hann[n]', fontsize=24, labelpad=10)
plt.title("Hanning Window", fontsize=24, pad=10)
format_stem()
ax = fig.add_subplot(313)
markerline, stemlines, baseline = ax.stem(n_hann, wx, markerfmt='o', use_line_collection=True)
plt.ylabel('wx[n]', fontsize=24, labelpad=10)
plt.title("Windowed Signal", fontsize=24, pad=10)
format_stem()

plt.subplots_adjust(hspace=0.5)

plt.show()