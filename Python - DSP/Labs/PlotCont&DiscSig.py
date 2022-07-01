# -*- coding: utf-8 -*-
"""
@author: Aonghus O Domhnaill
"""

import numpy as np
import matplotlib.pyplot as plt


f = 4   # Frequency of original signal, f (Hz)
fs = 10  # Sampling frequency, fs (Hz)
duration = 1 # Add code   # Duration of the signal, duration (s)
N = fs * duration # Add code   # Total number of samples in the discrete signal, N
t = np.linspace(0, duration, 1000, endpoint=False) # Time x-axis for the continous plot, t
n = np.arange(0, N)  # Sample number x-axis for the discrete plot, n
nT = n/fs   # Time x-axis for the discrete plot, nT
s_cont = np.sin(2*np.pi*f*t)    # Create the continuous signal, s_cont # scale
s_disc = np.sin(2*np.pi*f*nT)   # Create the discrete-time signal, s_disc

# Plot the simulated continuous signal
fig = plt.figure(figsize = (14, 10))
ax = fig.add_subplot(2,1,1)
ax.plot(t, s_cont, color='k')
plt.title('Continuous Signal', fontsize=22, color='sienna')
# Format the plot aesthetics
ax.tick_params(axis='both', which='both', labelsize=16, length=0, pad=15)
ax.set_xlim(0, 1)
ax.set_xlabel('t (s)', fontsize=20, labelpad=15)
ax.set_ylabel('sin(t)', fontsize=20, labelpad=15)
ax.xaxis.set_ticks_position('bottom')
ax.spines['top'].set_color('none')
ax.spines['bottom'].set_color('none')
ax.spines['right'].set_color('none')
ax.spines['left'].set_color('none')

# Stem plot the discrete signal
ax = fig.add_subplot(2, 1, 2)
markerline, stemlines, baseline = ax.stem(nT, s_disc, use_line_collection=True)
plt.title('Discrete Signal', fontsize=22, color='sienna')
# Format the plot aesthetics
plt.setp(stemlines, color='k', linewidth=1)
plt.setp(baseline, color='k', linewidth=2)
plt.setp(markerline, color='k', markersize=6)
markerline.set_clip_on(False)
ax.tick_params(axis='both', which='both', labelsize=16, length=0, pad=15)
ax.set_xlim(0, 1)
ax.set_xlabel('nT (s)', fontsize=20, labelpad=15)
ax.set_ylabel('sin[nT]', fontsize=20, labelpad=15)
ax.spines['top'].set_color('none')
ax.spines['bottom'].set_color('none')
ax.spines['right'].set_color('none')
ax.spines['left'].set_color('none')
plt.subplots_adjust(hspace=0.5)
plt.show()