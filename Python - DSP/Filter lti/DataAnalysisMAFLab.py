# -*- coding: utf-8 -*-
"""
@author: Aonghus O Domhnaill

https://www.met.ie/climate/available-data/historical-data
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
import datetime
from matplotlib.ticker import (MultipleLocator, FormatStrFormatter,
                               AutoMinorLocator)

# Read data from csv file (source: met.ie); parse the data on the column named 'date'; data type is unicode; first ~17 rows are header
data_athenry = pd.read_csv("hly1875.csv", skiprows = 17, parse_dates = ['date'], dtype = 'unicode')
# Print the array dimensions
print(data_athenry.shape)
# Print the entire table (Python will print some rows & use ... for the rest)
print(data_athenry.head)
# Print some values to see data & datatypes

# Add code to print some dates & times, eg 0 to 10
print(data_athenry['date'][103890:104633])
# Add code to print some temperatures, eg 100000 to 100020
print(data_athenry['temp'][103890:104633])


# Plot the temperature data vs the date for one month
fig1 = plt.figure(figsize = (20, 12))
ax1 = fig1.add_subplot(1, 1, 1)
# Find the first & last row for the chosen month in the data file
start = 95111  #add number start janurary
stop =  start + 744    # Add number # e.g. start + 744 for a 31 day month
# The type of the following arrays are Panda series, convert type 'object' to float 
temp_data = data_athenry['temp'][start:stop].astype(float)
date_data = data_athenry['date'][start:stop]

# Plot original data
# Add code to specify x & y axes below
ax1.plot_date(date_data, temp_data, linestyle='-', linewidth=2, marker = ',', color='steelblue', markersize = 10)
ax1.xaxis.set_major_locator(mdates.DayLocator(bymonthday=[1, 5, 10, 15, 20, 25, 30]))
ax1.xaxis.set_major_formatter(mdates.DateFormatter('%d/%m'))
ax1.set_xlim([pd.to_datetime('2022-01-01 00:00:00'), pd.to_datetime('2022-01-31 23:00:00')])
ax1.tick_params(axis='both', which='major', labelsize=20, pad=15)
ax1.set_ylabel('Temperature ($^\circ$C)', fontsize=24, labelpad=15)
ax1.set_title('Athenry Temperature Data, January 2022', fontsize=26, pad=20)
yticks = np.arange(-5, 16, 5)
ax1.set_yticks(yticks)

# Moving average filter
def moving_average(x, N):
    y = np.zeros(x.size)
    for n in range(0, x.size):
        for k in range(0, N):
            if n >= k:
                y[n] = y[n] + x[n-k]
    y = y*1/N
    return y

# Format temperature data into a numpy array, then filter
x = np.array(temp_data)
# Add code to call the MAF & generate output y, use filter taps N = 24
#Change here for much smoother signal ## put higher number in here 
y = moving_average(x, 24)




# Plot filtered output data
# Add code to specify x & y axes below
ax1.plot_date(date_data, y, linestyle='-', marker = ',', color = 'orange', markersize = 15)


# Adjust for the delay in the plot, do this on a new plot
fig2 = plt.figure(figsize = (20, 12))
ax2 = fig2.add_subplot(1, 1, 1)



# Plot original data again
ax2.plot_date(date_data, temp_data, linestyle='-', linewidth=2, marker = ',', color='steelblue', markersize = 10)

# Add code to specify x & y axes below
#ax2.plot_date(#, #, linestyle='-', marker = ',', color='steelblue', markersize = 10)
ax2.xaxis.set_major_locator(mdates.DayLocator(bymonthday=[1, 5, 10, 15, 20, 25, 30]))
ax2.xaxis.set_major_formatter(mdates.DateFormatter('%d/%m'))
ax2.set_xlim([pd.to_datetime('2021-01-01 00:00:00'), pd.to_datetime('2021-01-31 23:00:00')])
ax2.tick_params(axis='both', which='major', labelsize=20, pad=15)
ax2.set_ylabel('Temperature ($^\circ$C)', fontsize=24, labelpad=15)
ax2.set_title('Athenry Temperature, January 2022', fontsize=26, pad=20)
yticks = np.arange(-5, 23, 5)
ax2.set_yticks(yticks)
# Plot filtered output data
# Add code to specify x & y axes below, adjusting for the filter delay
ax2.plot_date(data_athenry['date'][start:stop-11], y[11:], linestyle='-', marker = ',', color = 'orange', markersize = 15)


# Get average temp for each hour of data, over month
# i should have 24*31 data value = 744

temp_data_np = temp_data.to_numpy()
date_data_np = data_athenry['date'][start:stop].to_numpy()
hours_data=np.zeros((24, 31))
hours_data_mean=np.zeros(24)
for i in range(24):
    #Extract the set 31 temperture values for each hour
    #they are 24 hours apart
    hours_data[i,:] = temp_data_np[i::24]
    #Average the 31 data values for each hour
    hours_data_mean[i]=np.mean(hours_data[i,:])
    
# Plot hours data
h = np.arange(0,24)
fig3 = plt.figure(figsize = (16, 12))
ax3=fig3.add_subplot(111)
ax3.plot(h,hours_data_mean)
ax3.xaxis.set_major_locator(MultipleLocator(1))






plt.show()
