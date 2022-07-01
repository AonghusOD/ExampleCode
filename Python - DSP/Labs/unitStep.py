# -*- coding: utf-8 -*-
"""
@author: Aonghus O Domhnaill
"""

import numpy as np
import matplotlib.pyplot as plt

def unit_step(n, m):
    u = np.zeros(n.size)
    for i in range(0, n.size):
        if n[i] >= m:
            u[i] = 1
    return u

def plot_unit_step(n, u):
    markerlines, stemlines, baseline = ax.stem(n, u, markerfmt='o', use_line_collection=True)
    plt.setp(stemlines, color='k', linewidth=2.0)
    plt.setp(baseline, color='k', linewidth=2.0)
    plt.setp(markerlines, color='k', markersize=10)
    markerlines.set_clip_on(False)
    ax.set_ylabel('u[n]', fontsize=28, labelpad=15)
    ax.set_xlabel('n', fontsize=24, labelpad=12)
    ax.set_ylim(-.02, 1.02)
    ax.set_xlim(-15.2, 15.2)
    ax.set_yticks([0, 0.5, 1.0])
    ax.spines['top'].set_color('none')
    ax.spines['right'].set_color('none')
    ax.spines['bottom'].set_color('none')
    ax.spines['left'].set_color('none')
    ax.tick_params(axis='both', which='both', labelsize=20, length=0)
    plt.axvline(x=-15, ymin=0.02, color='k', linestyle='-', linewidth=2)

fig = plt.figure(figsize=(14,10))
ax = fig.add_subplot(2,1,1)
n = np.arange(-15, 16)

# Add code to set delay, m
m = 2
# Add code to call unit_step function
u = unit_step(n, m)
plot_unit_step(n, u)