# -*- coding: utf-8 -*-
"""
@author: Aonghus O Domhnaill
"""

import numpy as np
import matplotlib.pyplot as plt

def window(x, N1, N2):
    wx = np.zeros(x.size)
    for i in range(0, x.size):
        if i >= N1 and i <= N2:
            wx[i] = x[i]
        else:
            wx[i] = 0
    return wx

def format_stem():
    plt.setp(stemlines, color='k', linewidth=2.0)
    plt.setp(baseline, color='k', linewidth=2.0)
    plt.setp(markerline, color='k', markersize=10)
    ax.set_xlabel('n', fontsize=24, labelpad=12)
    ax.spines['top'].set_color('none')
    ax.spines['right'].set_color('none')
    ax.spines['bottom'].set_color('none')
    ax.spines['left'].set_color('none')
    ax.tick_params(axis='both', which='both', labelsize=18, length=0)
    markerline.set_clip_on(False)
    
x = np.array([1, -1, 3, 0, 4, 5, -2, -1, 0, 3]) # Create signal, x
n = np.arange(0, x.size) # Create array of sample numbers, n
wx = window(x, 0, 6) # Calculate windowed signal, wx
 
fig = plt.figure(figsize=(14,10))
ax = fig.add_subplot(211)
# Add code # Stem plot x
markerline, stemlines, baseline = ax.stem(n, x, use_line_collection=True)
plt.ylabel('x[n]', fontsize=24, labelpad=15)
plt.title("Original Signal", fontsize=24, pad=15)
format_stem()
ax = fig.add_subplot(212)
# Add code # Stem plot wx
markerline, stemlines, baseline = ax.stem(n, wx, use_line_collection=True)
plt.ylabel('wx[n]', fontsize=24, labelpad=15)
plt.title("Windowed Signal", fontsize=24, pad=15)
format_stem()
plt.subplots_adjust(hspace=0.5)

plt.show()