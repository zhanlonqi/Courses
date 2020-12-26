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
X_scaler = StandardScaler()
x = X_scaler.fit_transform(X)

pca = PCA(n_components=0.9)# 保证降维后的数据保持90%的信息
pca.fit(x)
pca.transform(x)
print(x.shape)


for j in range(15):
    plt.subplot(5,3,j+1)
    plt.imshow(x[j].reshape(32,32).T,cmap='gray')
plt.show()
#print(inv_X)