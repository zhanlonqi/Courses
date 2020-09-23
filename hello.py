import scipy.io as sio 
#https://blog.csdn.net/qq_43711697/article/details/104175500
datafile="C:\\Users\\Administrator\\Desktop\\hello\\data\\yalemat.mat"
f =sio.loadmat(datafile)
print(f[f.keys[0]].shape)


