import numpy as np
import matplotlib.pyplot as plt
 
# data to plot
n_groups = 4
means_frank = (26, 51, 70, 85)
means_guido = (39, 65, 83, 100)
 
# create plot
fig, ax = plt.subplots()
index = np.arange(n_groups)
bar_width = 0.35
opacity = 0.8
 
rects1 = plt.bar(index, means_frank, bar_width,
alpha=opacity,
color='b',
label='Conventional Memory')
 
rects2 = plt.bar(index + bar_width, means_guido, bar_width,
alpha=opacity,
color='g',
label='ReRAM')
 
plt.xlabel('Fractional run-time')
plt.ylabel('Operations Completed')
plt.title('Operations completed vs. Run duration')
plt.xticks(index + bar_width, ('0.5', '0.5625', '0.625', '0.6875'))
plt.legend()
 
plt.tight_layout()
plt.show()