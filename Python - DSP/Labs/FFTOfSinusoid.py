# -*- coding: utf-8 -*-
"""
@author: Aonghus O Domhnaill
"""

import numpy as np
import matplotlib.pyplot as plt

# Create a sinusoid for input to the FFT
f = 3 # Add code to set f # frequency (Hz)
fs = 7 # Add code to set fs # sampling frequency (Hz)
duration = 1 # Add code to set duration # duration (s)
N = int(duration*fs) # Total number of samples
n = np.arange(0, N)  # Sample numbers array
nT = n/fs            # Sample numbers mapped to real time instants, for x-axis 
# Create continuous version of sinusoid, s_cont, for plotting purposes
t = np.linspace(0, duration, num=100, endpoint=True)
s_cont = np.sin(2*np.pi*f*t)
# Create discrete sinusoid, s_disc
s_disc = np.sin(2*np.pi*f/fs*n)

# Get DFT of the signal, y, using the FFT algorithm
# Note: np.fft output is standard format with 0Hz frequency first, 
# followed by ascending positive, then descending negative
y = np.fft.fft(s_disc)# Add code
# Calculate absolute value, y_abs
y_abs=(np.abs(y))
# Calculate values in decibels, y_db
y_db = 20*np.log10(np.abs(y)/N )# Add code
# Create frequency axis for frequency-domain plot
# Note: frequencies are multiples of fs/N, where N is the number of samples
#freqs = np.arange(0, N) * fs/N
freqs = np.fft.fftfreq(N, 1/fs)

# First subplot: Time-Domain
fig = plt.figure(figsize = (12, 10))
ax = fig.add_subplot(2, 1, 1)
# Adapt code to plot both continuous & discrete signals on one plot
ax.plot(t, s_cont, color='k')
ax.plot(nT, s_disc, color='k', linestyle='', marker='o')
ax.tick_params(axis='both', which='both', labelsize=16, length=0, pad=15)
ax.set_yticks([-1, 0, 1])
ax.set_xlabel('Time (s)', fontsize=20, labelpad=15)
ax.set_ylabel('Signal Magnitude', fontsize=20, labelpad=15)
ax.spines['top'].set_color('none')
ax.spines['bottom'].set_color('none')
ax.spines['left'].set_color('none')
ax.spines['right'].set_color('none')
ax.set_title('Time-Domain Signal', fontsize=22, color='sienna', pad=15)
# Second subplot: Frequency-Domain 
ax = fig.add_subplot(2, 1, 2)
# Adapt code to stem plot FFT output
markerlines, stemlines, baseline = ax.stem(freqs, y_abs, use_line_collection=True)
ax.set_xlabel('Frequency')
ax.set_ylabel('DFT Magnitude')
ax.set_title('DFT')
plt.setp(stemlines, color='k', linewidth=1)
plt.setp(baseline, color='k', linewidth=2)
plt.setp(markerlines, color='k', markersize=5)
ax.tick_params(axis='both', which='both', labelsize=16, length=0, pad=15)
ax.set_xlabel('Frequency (Hz)', fontsize=20, labelpad=15)
ax.set_ylabel('DFT Magnitude', fontsize=20, labelpad=15)
ax.set_title('Frequency-Domain Signal', fontsize=20, color='sienna', pad=15)
ax.spines['top'].set_color('none')
ax.spines['bottom'].set_color('none')
ax.spines['left'].set_color('none')
ax.spines['right'].set_color('none')
#ax.set_xlim(-fs//2, fs//2)
markerlines.set_clip_on(False)
plt.subplots_adjust(hspace = 0.5)