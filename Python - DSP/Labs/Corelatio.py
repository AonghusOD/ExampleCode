# -*- coding: utf-8 -*-
"""
@author: Aonghus O Domhnaill
"""

import numpy as np

x = np.array([1, -2, 3, 4])                   
#y = np.array([-1, 2, -3, -4])              
y = np.array([-2, -1, 3, -1])              

def correlate(x, y):
    norm_x = np.linalg.norm(x)
    norm_y = np.linalg.norm(y)
    dot_prod = np.inner(x, y)
    corr = dot_prod / (norm_x * norm_y)
    return corr

corr = correlate(x, y)
print(corr)
