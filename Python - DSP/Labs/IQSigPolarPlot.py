# -*- coding: utf-8 -*-
"""
@author: Aonghus O Domhnaill
"""

# Add import code
import numpy as np
import matplotlib.pyplot as plt

i = np.array([1.0, 0.5, -0.5, 1.25]) # In-phase/real part
q = np.array([1.0, 0.25, 0.75, 0.5])  # Quadrature/imaginary part
iq = i + 1j*q
print('IQ', iq)

theta = np.arctan2(q, i) # Calc theta, th
r = np.abs(iq)  # Calc magnitude, r

print('theta', theta)
print('r', r)

print('theta', theta*180/np.pi)

# Add code # IQ signal = i+1j*q
# Add code # Print, with label
# Add code # Calc theta, th
# Add code # Print, with labels

# Polar plot IQ signal
fig = plt.figure(figsize=(14,10))
ax = fig.add_subplot(111, projection='polar')
ax.plot(theta, r, '.', markersize=20)
ax.set_rmax(2)
ax.set_rticks([0, 1, 2])
ax.tick_params(axis='both', which='major', labelsize=20)
ax.spines['polar'].set_visible(False)
plt.show()
