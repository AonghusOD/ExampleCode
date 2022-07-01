# -*- coding: utf-8 -*-
"""
@author: Aonghus O Domhnaill
"""
import numpy as np
import matplotlib.pyplot as plt

# Add code to create signal x
x = np.array([0, 1.73, 0, 0, 0, -1.73])
print('Signal x', x)


# Add code to print x
N = x.size  #     
fs = 4      # 
n = np.arange(0, N)  #
nT = n/fs            #Time sample number
y = np.fft.fft(x)# Add code to calculate FFT of x
print('FFT ', y)
y_abs = np.abs(y)
print('Magnitude ', y_abs)
# Add code to print FFT of x
# Add code to calculate magnitude of FFT 
# Add code to print magnitude of FFT
# Calculate the frequencies for x-axis of FFT plot
# Frequencies are multiples of Fs/N, where N is the number of samples
freqs = np.fft.fftfreq(N, 1/fs)
# Calculate the inverse FFT
inv = np.fft.ifft(y)
# Add code to print the inverse FFT

# Plot code
fig = plt.figure(figsize = (12, 10))
ax = fig.add_subplot(2, 1, 1)
markerline, stemlines, baseline = ax.stem(nT, x, use_line_collection=True)
plt.setp(stemlines, color='k', linewidth=1)
plt.setp(baseline, color='k', linewidth=2)
plt.setp(markerline, color='k', markersize=5)
ax.tick_params(axis='both', which='both', labelsize=16, length=0, pad=15)
ax.set_yticks([-1, 0, 1])
ax.set_xlabel('Time (s)', fontsize=20, labelpad=15)
ax.set_ylabel('Signal Magnitude', fontsize=20, labelpad=15)
ax.spines['top'].set_color('none')
ax.spines['bottom'].set_color('none')
ax.spines['left'].set_color('none')
ax.spines['right'].set_color('none')
ax.set_title('Time-Domain Signal', fontsize=20, color='sienna', pad=15)
ax = fig.add_subplot(2, 1, 2)
ax.set_xlabel('Frequency')
ax.set_ylabel('DFT Magnitude')
ax.set_title('DFT')
markerline, stemlines, baseline = ax.stem(freqs, y_abs, use_line_collection=True)
plt.setp(stemlines, color='k', linewidth=1)
plt.setp(baseline, color='k', linewidth=2)
plt.setp(markerline, color='k', markersize=5)
ax.tick_params(axis='both', which='both', labelsize=16, length=0, pad=15)
ax.set_xlabel('Frequency (Hz)', fontsize=20, labelpad=15)
ax.set_ylabel('DFT Magnitude', fontsize=20, labelpad=15)
ax.set_title('Frequency-Domain Signal', fontsize=20, color='sienna', pad=15)
ax.spines['top'].set_color('none')
ax.spines['bottom'].set_color('none')
ax.spines['left'].set_color('none')
ax.spines['right'].set_color('none')
plt.subplots_adjust(hspace = 0.5)