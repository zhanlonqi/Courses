import scipy.io as sio 
import numpy as np
import matplotlib.pyplot as plt
import sys
#https://blog.csdn.net/qq_43711697/article/details/104175500
datafile="C:\\Users\\Administrator\\Desktop\\Courses\\yalemat\\data\\yalemat.mat"
print(datafile)
f =sio.loadmat(datafile)
a=np.array(32*32)
a=f['yalemat'].T[2]
#print(f.keys())
a.shape=32,32
a=a.T
#print(a)
plt.imshow(a,cmap="gray")
plt.show()

