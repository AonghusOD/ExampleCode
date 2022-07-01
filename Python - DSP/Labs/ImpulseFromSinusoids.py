# -*- coding: utf-8 -*-
"""
@author: Aonghus O Domhnaill
"""

import numpy as np
import matplotlib.pyplot as plt

duration = 1        # Duration
fs = 1000          # Sampling frequency
N = fs * duration   # Number of samples
t = np.linspace(-duration/2, duration/2, num=N, endpoint=False) # Time axis for time-domain plot
# Create the impulse in the time domain
num_sins=10      # Number of sinusoids to sum
impulse_t = np.zeros(t.size)
for f in range(0,num_sins):
    # Add code to create new sinusoid, s, use np.cos(2*np.pi*f*t)
    s = np.cos(2*np.pi*f*t)
    impulse_t = impulse_t + s
    
# Compute the FFT (Fast Fourier Transform) of the impulse function

impulse_f = np.fft.fft(impulse_t)

impulse_f_amp = (1/N)*np.abs(impulse_f)
impulse_f_amp[0] = 'NaN'
impulse_f_amp[N//2] = 'NaN'
freqs = np.fft.fftfreq(N, 1/fs)

# Plot impulse in time domain
fig1 = plt.figure(figsize=(12,8))
ax1 = fig1.add_subplot(211)
ax1.plot(t, impulse_t, color='k')
ax1.spines['bottom'].set_visible(False)
ax1.spines['top'].set_visible(False)
ax1.spines['left'].set_visible(False)
ax1.spines['right'].set_visible(False)
ax1.set_xticklabels([])
ax1.set_yticklabels([])
ax1.set_xticks([])
ax1.set_yticks([])

# Plot impulse in frequency domain
ax2 = fig1.add_subplot(212)
markerlines, stemlines, baseline = ax2.stem(freqs, impulse_f_amp)
plt.setp(stemlines, color='k', linewidth=1.0)
plt.setp(baseline, color='k', linewidth=1.0)
plt.setp(markerlines, color='k', markersize=2)
markerlines.set_clip_on(False)
ax1.spines['bottom'].set_visible(False)
ax2.spines['top'].set_visible(False)
ax2.spines['left'].set_visible(False)
ax2.spines['right'].set_visible(False)
ax2.set_xticklabels([])
ax2.set_yticklabels([])
ax2.set_xticks([])
ax2.set_yticks([])

plt.show()
