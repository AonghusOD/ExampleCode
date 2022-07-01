# -*- coding: utf-8 -*-
"""
@author: Aonghus O Domhnaill
"""
import numpy as np
from scipy import signal
import matplotlib.pyplot as plt

# Create an input test signal, eg 1Hz + 10Hz sinusoids
fs = 50         # Add code for fs           # Sampling frequency of input signal (Hz)
duration = 4    # Add code for duration      # Duration of input signal
N = duration*fs # Add code to calc N   # Number of samples in input signal
n = np.arange(0, duration*fs)   # Array of sample numbers
nT = n/fs       # Add code to create array nT        # Array of discrete sample times (s)
s_1Hz = np.sin(2*np.pi*1*nT)     # Add code to create a sinusoid test signal      
s_10Hz = np.sin(2*np.pi*10*nT)       # Add code to create second sinusoid test signal at a different frequency
s_3Hz = np.sin(2*np.pi*3*nT) 
#x = s_1Hz + s_10Hz  # Add code to create a composite signal, x, of the two sinuosoids (by addition) 
x = s_3Hz + s_10Hz
#change cutoff to change signal cutoff hz
# Design the filter & perform filtering
f_cutoff = 6  # Add cut-off value   # Cut-off frequency, e.g. max of 24 for fs = 50
f_nyq = 0.5*fs # Specify the Nyquist frequency (fs/2)
cutoff = f_cutoff/f_nyq # Save the cut-off frequency, scale 0 to 1
# Add code to create the filter, use signal.butter

#change here high or low pass filter
b,a = signal.butter(10, cutoff, btype='low', analog=False)
# Add code to filter the test signal with the new filter, output y
y = signal.filtfilt(b, a, x)


# Plot input and filtered output signals
fig = plt.figure(figsize=(16,10))
ax1 = fig.add_subplot(211)
ax1.plot(nT, x, color='steelblue') # Plot the input test signal, x
ax1.tick_params(axis='both', which='both', labelsize=16, length=0, pad=15)
ax1.set_title('Input Signal & Filtered Output', fontsize=18, color='sienna', pad=15)
ax1.set_xlabel('Time (s)', fontsize=16, labelpad=10)
ax1.set_ylabel('Amplitude', fontsize=16, labelpad=10)
ax1.spines['top'].set_color('none')
ax1.spines['right'].set_color('none')
ax1.plot(nT, y, color='orange') # Overlay the output filtered signal, y

# Get filter frequency response
w, h = signal.freqz(b,a)
# Plot filter frequency response
ax2 = fig.add_subplot(212)
plt.plot(0.5*fs*w/np.pi, 20*np.log10(np.abs(h)))
ax2.set_ylim(-40, 5)
ax2.set_xlim(0, 0.5*fs)
ax2.tick_params(axis='both', which='both', labelsize=16, length=0, pad=15)
ax2.set_xlabel('Frequency (Hz)', fontsize=16, labelpad=10)
ax2.set_ylabel('Gain (dB)', fontsize=16, labelpad=10)
ax2.set_title("Filter Frequency Response", fontsize=18)
ax2.spines['top'].set_color('none')
ax2.spines['right'].set_color('none')

plt.subplots_adjust(hspace = 0.5)
plt.show()
