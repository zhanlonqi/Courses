# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt
import numpy as np
import scipy.io as scio
from PIL import Image
import sys

from sklearn import preprocessing
from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler


data_path =sys.path[0]+'/../data/yalemat.mat'


# 读取 mat 文件中的数据
data_dic = scio.loadmat(data_path)
X = data_dic['yalemat'].T    # 样本集，每一行对应一个样本

pca = PCA(n_components=0.95)# 保证降维后的数据保持90%的信息

x=pca.fit_transform(X.T)
res=pca.inverse_transform(x)
print(res.shape)

k=4
for j in range(k):
    plt.subplot(2,k,j+1)
    plt.imshow(res.T[j].reshape(32,32).T,cmap='gray')
    plt.subplot(2,k,j+1+k)
    plt.imshow(X[j].reshape(32,32).T,cmap='gray')

plt.show()
#print(inv_X)