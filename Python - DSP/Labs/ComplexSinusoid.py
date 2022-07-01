# -*- coding: utf-8 -*-
"""
@author: Aonghus O Domhnaill
"""

import numpy as np
import matplotlib.pyplot as plt

# Set up figure window & axes with 3D projection
fig = plt.figure(figsize=(16,12))
ax = fig.add_subplot(111, projection = '3d')
# Configure complex sinusoid parameters
f = 5              # Frequency, Hz
fs = 1000            # Sampling frequency, Hz
duration = 1         # Duration, s
N = int(duration*fs) # Total number of samples
# Create an array with sample numbers 0 to N
n = np.arange(0, N)
# Create another array of discrete times n*T
nT = n/fs
# Put time on x-axis, sine on z-axis and cosine on y-axis


# Add code for x-axis
x = nT

# Add code for z-axis
z = np.sin(2*np.pi*f/fs*n)


# Add code for y-axis
y = np.cos(2*np.pi*f/fs*n)



# Plot the 3 axes & a grey line along the x-axis
ax.plot3D(x, y, z, 'steelblue', linewidth = 2)
ax.plot3D(x, [0]*n, z, color = 'violet', linewidth = 2, alpha = 0.5)
ax.plot3D(x, y, [0]*n, color = 'orange', linewidth = 2, alpha = 0.5)
ax.plot3D((-0.1, N/fs * 1.1), (0, 0), (0, 0), color = 'gray', linewidth = 2)
ax.set_axis_off()
#ax.view_init(30,45)


plt.show()