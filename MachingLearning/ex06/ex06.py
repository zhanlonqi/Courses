from sklearn import preprocessing
import matplotlib.pyplot as plt
import numpy as np
import scipy.io as scio
import sys
import cvxopt 
from cvxopt import matrix

def gauss_kernel(x1,x2):
    sigma=1
    return np.exp(-1*np.matmul(x1,x2.T)*0.5/(sigma*sigma))



path=sys.path[0]
datafile=path+'/../data/watermelon_3a.mat'
data_dic=scio.loadmat(datafile)
data=data_dic['watermelon_3a']
avg=np.mean(data[:,0:2],axis=0)

label=data[:,2:3]
label=label*2-1 
print(label)
data=(data[:,0:2]-avg)
var=np.var(data[:,0:2],axis=0)
data=np.divide(data[:,0:2],var)

m=data.shape[0]
alpha=np.zeros((m,1))
Y=np.zeros((m,m))
K=np.zeros((m,m))
E=np.ones((m,1))
y=np.zeros((1,m))
for i in range(m):
    Y[i,i]=label[i]
    y[0,i]=label[i]
    for j in range(m):
        K[i,j]=gauss_kernel(data[i],data[j])

result=cvxopt.solvers.qp(matrix(Y*K*Y),matrix(E),matrix(-1*np.identity(m)),matrix(0.0,(m,1)),matrix(y),matrix(0.0))

alpha=result['x']
b=1/m;
for i in range(m):
    temp=1/label[i]
    for j in range(m):
        temp-=alpha[i]*label[i]*data[i].dot(data[j].T)
    
print(b)




