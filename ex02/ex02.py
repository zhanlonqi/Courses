import scipy.io as sio 
import numpy as np
import matplotlib.pyplot as plt
import os
def sigmoid(z):
    return 1.0/(1.0+np.exp(-z))

def grad(train_X,lables,iters=2000):
    m,n=train_X.shape
    alpha=0.05
    weight=np.ones((n,1))

    for k in range(iters):
        P=sigmoid(train_X.dot(weight))
        error=lables-P 
        weight+=alpha*np.dot(train_X.T,error)

    return weight

def predict(test_X,weight):
    m=test_X.shape[0]
    p=np.dot(test_X,weight)
    for k in range(m):
        if p[k]>0:
            p[k]=1
        else:
            p[k]=0
    return p

def accuracy(predict_Y,Y):
    m,n=Y.shape
    Matched=0
    for k in range(m):
        if predict_Y[k]==Y[k]:
            Matched+=1
        else:
            Matched+=0

    return Matched/m


path=os.getcwd()
datafile=path+"\\ex02\\data\\uci_wine.mat"
f =sio.loadmat(datafile)
print(f['wine'][0].T)


