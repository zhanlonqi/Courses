# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt
import numpy as np
import scipy.io as scio
import sys
from KNN_Euc import KNN_Euc


#用来正常显示中文
plt.rcParams['font.sans-serif'] = ['SimHei']
#用来正常显示符号
plt.rcParams['axes.unicode_minus'] = False


data_path = sys.path[0]+'/../data/watermelon_3a.mat'


# 读取 mat 文件中的数据
data_dic = scio.loadmat(data_path)
data = data_dic['watermelon_3a']
# 生成样本�? D、对应的类别标记 D_labels 和属性集 A
x = data[:, 0:2].T                       # 训练样本集，每一列对应一个样�?
y = data[None, :, 2].astype(np.int16)    # 训练样本类别标记，每一列对应一个样�?
print(x)

# 近邻�?
k = 5

# 按点计算k近邻边界，黄色区域表示分类器会将样本标记为好瓜，绿色区域则是坏瓜
fig = plt.figure(1, facecolor='white', dpi=300)    # 新建一个画布，背景设置为白色的
fig.clf()                                          # 将画图清�?
ax = fig.add_subplot(1,1,1)                        # 设置一个多图展示，但是子图只有一�?

for ii in range(113):
    for jj in range(93):
        testSample = np.array([[0.22+ii*0.005], [0.02+jj*0.005]])
        pLabel = KNN_Euc(testSample, x, y, k)    # 计算每个点的类标�?
        
        if pLabel == 1:
            plt.plot(testSample[0, 0], testSample[1, 0], 'y.')
        else:
            plt.plot(testSample[0, 0], testSample[1, 0], 'g.')

# 画训练样本点，o表示好瓜�?+表示坏瓜 
for ii in range(17):
    if y[:, ii] == 1:
        plt.plot(x[0, ii], x[1, ii], 'ko')
    else:
        plt.plot(x[0, ii], x[1, ii], 'k+')

ax.set_xlabel('密度')
ax.set_ylabel('含糖�?')
plt.title(str(k) + '近邻')
plt.show()