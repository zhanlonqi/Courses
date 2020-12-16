# -*- coding: utf-8 -*-

import scipy.io as scio
import matplotlib.pyplot as plt

from k_means import k_means

import sys

data_path =sys.path[0]+'/../data/watermelon_4.mat'
#用来正常显示中文
plt.rcParams['font.sans-serif'] = ['SimHei']
#用来正常显示符号
plt.rcParams['axes.unicode_minus'] = False

# 绘制分类结果图
def plot_results(D, k, C, U):
    fig = plt.figure(1, facecolor='white', dpi=600)    # 新建一个画布，背景设置为白色的
    fig.clf()                                          # 将画图清空
    ax = fig.add_subplot(1,1,1)                        # 设置一个多图展示，但是子图只有一个

    for ii in range(k):
        x1 = D[C[ii], 0]
        x2 = D[C[ii], 1]
    
        if ii == 0:
            plt.plot(x1, x2, 'ro')
        elif ii == 1:
            plt.plot(x1, x2, 'go')
        elif ii == 2:
            plt.plot(x1, x2, 'bo')
        elif ii == 3:
            plt.plot(x1, x2, 'co')
        elif ii == 4:
            plt.plot(x1, x2, 'mo')
        elif ii == 5:
            plt.plot(x1, x2, 'yo')
        else:
            plt.plot(x1, x2, 'ko')

    plt.plot(U[:, 0], U[:, 1], 'k+')
    ax.set_xlabel('密度')
    ax.set_ylabel('含糖率')
    plt.show()


# 读取 mat 文件中的数据
data_dic = scio.loadmat(data_path)
data = data_dic['watermelon_4']
# 生成样本集 D、对应的类别标记 D_labels 和属性集 A
D = data[:, 0:2]                # 训练样本集，每一行对应一个样本
D_labels = data[:, 2, None]     # 训练样本类别标记，每一行对应一个样本

# 设置参数
U_index = [5, 11, 23]    # 初始均值向量选择第8个和第16个样本
k = len(U_index )

# k均值聚类
C, U = k_means(D, k, U_index)

# 绘制分类结果图
plot_results(D, k, C, U)