# -*- coding: utf-8 -*-
"""
@author: Aonghus O Domhnaill
"""

import numpy as np
import matplotlib.pyplot as plt

def even(n):
    e = np.zeros(n.size)
    x = np.linspace(1, -1, 6, endpoint=True)
    e[6:11] = x[0:5]
    for i in range(0, 6):
        e[i] = e[int(n.size)-1-i]
    return e

def odd(n):
    o = np.zeros(n.size)
    x = np.linspace(0, 0.5, 16, endpoint=True)
    o[15:31] = x[0:16]
    for i in range(0, 15):
        o[i] = -o[int(n.size)-1-i]
    return o

n = np.arange(-5, 6)
e = even(n)
o = odd(n)
x = e + o

def format_stem():
    plt.setp(stemlines, color='k', linewidth=2.0)
    plt.setp(baseline, color='k', linewidth=2.0)
    plt.setp(markerline, color='k', markersize=10)
    ax.set_xlabel('n', fontsize=28, labelpad=12)
    ax.set_yticks([-1.0, -0.5, 0, 0.5, 1.0])
    ax.spines['top'].set_color('none')
    ax.spines['right'].set_color('none')
    ax.spines['bottom'].set_color('none')
    ax.spines['left'].set_color('none')
    ax.tick_params(axis='both', which='both', labelsize=20, length=0)
    plt.axvline(x=-15, ymin=0.03, color='k', linestyle='-', linewidth=2)
 
'''
fig = plt.figure(figsize=(16,14))
ax = fig.add_subplot(3,1,1)
markerline, stemlines, baseline = ax.stem(n, e, markerfmt='o',  use_line_collection=True)
plt.ylabel('e[n]', fontsize=28, labelpad=15)
format_stem()


ax = fig.add_subplot(3,1,2)
markerline, stemlines, baseline = ax.stem(n, o, markerfmt='o',  use_line_collection=True)
plt.ylabel('o[n]', fontsize=28, labelpad=15)
format_stem()

ax = fig.add_subplot(3,1,3)
markerline, stemlines, baseline = ax.stem(n, x, markerfmt='o',  use_line_collection=True)
plt.ylabel('x[n]', fontsize=28, labelpad=15)
format_stem()
plt.subplots_adjust(hspace=0.5)
'''

plt.show()