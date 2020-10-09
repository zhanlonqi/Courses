import scipy.io as sio 
import numpy as np
import matplotlib.pyplot as plt
import os
path=os.getcwd()
datafile=path+"\\ex02\\data\\uci_wine.mat"
print(datafile)
f =sio.loadmat(datafile)
print(f.keys())
