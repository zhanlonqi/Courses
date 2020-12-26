# -*- coding: utf-8 -*-

import numpy as np

def comp(x):
    return x[0]


def KNN_Euc(testSample, trainmat, train_labels, k):
    # 使用基于欧氏距离的k近邻分类器对测试样本进行分类
    # 输入参数
    #   trainmat        训练样本矩阵，矩阵的每一列是一个训练样本
    #   testSample      测试样本列向量
    #   train_labels    训练样本类标记向量，是一个行向量
    #   k               k个近邻
    # 输出参数
    #   test_label      测试样本类标记
    dis=[]
    for i in range(trainmat.shape[1]):
        distrance=(trainmat[0,i]-testSample[0])**2+(trainmat[1,i]-testSample[1])**2
        dis.append([distrance,i])

    dis.sort(key=comp)

    temp=0
    for i in range(k):
        if(train_labels[0][dis[i][1]]==1):
            temp+=1
        
    if temp>k/2:
        return 1
    else:
        return 0

    
