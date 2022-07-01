# -*- coding: utf-8 -*-
"""
@author: Aonghus O Domhnaill
"""

import numpy as np
import matplotlib.pyplot as plt

def energy(x):
    e = 0
    for i in range(0, x.size):
        e = e + np.abs(x[i])**2
    return e

def power(x):
    p = 0
    for i in range(0, x.size):
        p = p + np.abs(x[i])**2
    p =  p / x.size
    return p
'''
def norm2(x):
    norm = 0
    for i in range(0, x.size):
    # Add code to calculate norm
    return norm
'''
#x = np.array([1, 2, 3])
x = np.array([-2, -1, 3, 1])
n = np.arange(0, x.size) 

e = energy(x)
print('Energy ', e)

p = power(x)
print('Power ', p)

# Add code to execute each of the 3 functions & print results

# Uncomment code below to plot signal x
'''
fig = plt.figure(figsize = (14, 10))
ax = fig.add_subplot(2, 1, 1)
markerline, stemlines, baseline = ax.stem(n, x, use_line_collection=True)
# Format the plot aesthetics
plt.setp(stemlines, color='k', linewidth=1)
plt.setp(baseline, color='k', linewidth=2)
plt.setp(markerline, color='k', markersize=6)
markerline.set_clip_on(False)
ax.tick_params(axis='both', which='both', labelsize=16, length=0, pad=15)
ax.set_xlabel('n', fontsize=20, labelpad=15)
ax.set_ylabel('x[n]', fontsize=20, labelpad=15)
ax.spines['top'].set_color('none')
ax.spines['bottom'].set_color('none')
ax.spines['right'].set_color('none')
ax.spines['left'].set_color('none')
plt.subplots_adjust(hspace=0.5)
plt.show()
'''