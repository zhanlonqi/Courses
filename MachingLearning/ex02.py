import numpy as np
import pandas as pd
import scipy.io as scio
import sys

def sigmoid(z):
    return 1.0/(1.0+np.exp(-z))

def grad(train_X,lables,iters=2000):
    m,n=train_X.shape
    alpha=0.05
    weights=np.ones((n,1))
    for k in range(iters):
        P=sigmoid(train_X.dot(weights))
        error=lables-P 
        weights+=alpha*np.dot(train_X.T,error)
    return weights

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


path=sys.path[0]
datafile=path+"\\data\\uci_wine.mat"
datafile2=path+"\\data\\uci_iris.mat"
df=scio.loadmat(datafile)
df2=scio.loadmat(datafile2)
data=df['wine']
data2=df2['iris']

X=data[:,0:13]
Y=data[:,13:14]
X2=data2[:,0:data2.shape[1]-1]
Y2=data2[:,data2.shape[1]-1:data2.shape[1]]
total=data.shape[0]
num_split=int(total/10);
sum=0
for k in range(10):
    test_index=range(k*num_split,(k+1)*num_split)
    test_X=X[test_index]
    test_Y=Y[test_index]
    train_X=np.delete(X,test_index,axis=0)
    train_Y=np.delete(Y,test_index,axis=0)
    weight=grad(train_X,train_Y,2000)
    P=predict(test_X,weight)
    sum+=accuracy(P,test_Y)

ans=sum/10
if ans<0.5:
    ans=1-ans
print("10折检验wine：",ans*100,"%")

num_split=1;
sum=0
for k in range(total):
    test_index=range(k*num_split,(k+1)*num_split)
    test_X=X[test_index]
    test_Y=Y[test_index]
    train_X=np.delete(X,test_index,axis=0)
    train_Y=np.delete(Y,test_index,axis=0)
    weight=grad(train_X,train_Y,2000)
    P=predict(test_X,weight)
    sum+=accuracy(P,test_Y)
    ans=sum/total
    if ans<0.5:
        ans=1-ans
print("留一法wine：",ans*100,"%")

num_split=int(X2.shape[0]/10)
for k in range(10):
    test_index=range(k*num_split,(k+1)*num_split)
    test_X=X2[test_index]
    test_Y=Y2[test_index]
    train_X=np.delete(X2,test_index,axis=0)
    train_Y=np.delete(Y2,test_index,axis=0)
    weight=grad(train_X,train_Y,2000)
    P=predict(test_X,weight)
    sum+=accuracy(P,test_Y)

ans=sum/10
if ans<0.5:
    ans=1-ans
print("10折检验iris：",ans*10,"%")

num_split=1;
sum=0
for k in range(X2.shape[0]):
    test_index=range(k*num_split,(k+1)*num_split)
    test_X=X2[test_index]
    test_Y=Y2[test_index]
    train_X=np.delete(X2,test_index,axis=0)
    train_Y=np.delete(Y2,test_index,axis=0)
    weight=grad(train_X,train_Y,2000)
    P=predict(test_X,weight)
    sum+=accuracy(P,test_Y)
    ans=sum/total
    if ans<0.5:
        ans=1-ans
print("留一法wine：",ans*100,"%")