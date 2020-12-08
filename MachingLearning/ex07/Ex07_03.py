# -*- coding: utf-8 -*-

import numpy as np
import scipy.io as scio
import sys
from nbc_test import nbc_test
from nbc_train import nbc_train


data_path = sys.path[0]+'/../data/watermelon_3.mat'
# 读取 mat 文件中的数据
data_dic = scio.loadmat(data_path)
data = data_dic['watermelon_3']
atts = data_dic['attributes']
# 生成样本集 D、对应的类别标记 D_labels 和属性集 A
D = data[:, 0:8]                # 训练样本集，每一行对应一个样本
D_labels = data[:, 8, None]     # 训练样本类别标记，每一行对应一个样本
A = []                          # 属性集，每个元素对应一个属性

for ii in range(9):
    att = {}
    
    if ii < 6:      # 离散属性
        att['name'] = atts[0, ii]['name'][0][0][0]
        att['values'] = atts[0, ii]['values'][0][0]
        att['continue'] = atts[0, ii]['continue'][0][0][0][0]
        att['id'] = atts[0, ii]['id'][0][0][0][0]
    elif ii < 8:    #连续属性
        att['name'] = atts[0, ii]['name'][0][0][0]
        att['continue'] = atts[0, ii]['continue'][0][0][0][0]
        att['id'] = atts[0, ii]['id'][0][0][0][0]
    else:           # 类别属性
        att['name'] = atts[0, ii]['name'][0][0][0]
        att['values'] = atts[0, ii]['values'][0][0]

    A.append(att)


# 测试样本
testSample = np.array([11, 21, 31, 41, 51, 61, 0.697, 0.460])
#testSample = np.array([12, 22, 31, 41, 52, 62, 0.36, 0.37])
testSample = testSample[np.newaxis, :]


# 训练拉普拉斯修正的朴素贝叶斯分类器
nbModel = nbc_train(D, D_labels, A, 1)

# 测试样本分类
test_label, prob = nbc_test(nbModel, testSample)
print(test_label)
print(prob)
