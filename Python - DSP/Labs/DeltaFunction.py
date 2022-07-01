# -*- coding: utf-8 -*-
"""
@author: Aonghus O Domhnaill
"""

import numpy as np
import matplotlib.pyplot as plt

def delta_function(n, m):
    d = np.zeros(n.size)
    for i in range(0, n.size):
        if n[i] == m:
         d[i] = 1.0
         
    return d

def plot_delta_function(n, d, m):
    markerlines, stemlines, baseline = ax.stem(n, d, markerfmt='k.', linefmt='k', use_line_collection=True )
    plt.setp(stemlines, color='k', linewidth=2.0)
    plt.setp(baseline, color='k', linewidth=2.0)
    plt.setp(markerlines, color='k', markersize=10)
    markerlines.set_markersize(10)
    markerlines.set_clip_on(False)
    ax.set_ylabel(r'$\delta[n-m]$', fontsize=24, labelpad=15)
    ax.set_xlabel('n', fontsize=24, labelpad=12)
    ax.set_ylim(-.02, 1.02)
    ax.set_xlim(-15.2, 15.2)
    ax.set_yticks([0, 0.5, 1.0])
    #ax.set_xticks([])
    ax.spines['top'].set_color('none')
    ax.spines['right'].set_color('none')
    ax.spines['bottom'].set_color('none')
    ax.spines['left'].set_color('none')
    ax.tick_params(axis='both', which='both', labelsize=20, length=0)
    plt.axvline(x=-15, ymin=0.02, color='k', linestyle='-', linewidth=2)
    
fig = plt.figure(figsize = (14, 10))
ax = fig.add_subplot(2, 1, 1)
n = np.arange(-15, 16)
m = 5
# Add code to set delay
# Add code to call delta_function function
d = delta_function(n, m)
plot_delta_function(n, d, m)