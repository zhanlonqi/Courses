# -*- coding: utf-8 -*-
import numpy as np
import math
    # 训练朴素贝叶斯分类器，参数说明如下
    #   D         训练样本集，每一行是一个训练样本
    #   D_labels  训练样本类标记，每一行是一个训练样本类标记
    #   A         训练样本属性集
    #   lp        是否进行拉普拉斯修正，1是，0否
    # 输出参数
    #   nbModel   训练好的分类器，字典类型

def nbc_train(D, D_labels, A, lp=1):
    top=0;
    if(lp==1):
        top=1;
    Ni=[]
    
    for i in range(6):
        if(lp==1):
            Ni.append(len(A[i]['values']))
        else:
            Ni.append(0);

    P_positive=np.sum(D_labels)
    P_negative=len(D_labels)-np.sum(D_labels)
    attributes_pos=[]
    attributes_neg=[]
    for i in range(D.shape[1]):
        temp_pos=[]
        temp_neg=[]
        if(i<6):
            for j in range(len(A[i]['values'])):
                temp_pos.append(0.0)
                temp_neg.append(0.0)
            
                for k in range(D.shape[0]):
                    if(D[k][i]%10==j+1):
                        if(D_labels[k]==1):
                            temp_pos[j]+=+1;
                        else:
                            temp_neg[j]+=1;
            attributes_pos.append(temp_pos)
            attributes_neg.append(temp_neg)
        else:
            for k in range(D.shape[0]):
                if(D_labels[k]==1):
                    temp_pos.append(D[k][i])
                else:
                    temp_neg.append(D[k][i])
            attributes_pos.append([np.mean(temp_pos),np.std(temp_pos,ddof=1)])
            attributes_neg.append([np.mean(temp_neg),np.std(temp_neg,ddof=1)])

    return {'num_pos':P_positive,'num_neg':P_negative,'attributes_pos':attributes_pos,'attributes_neg':attributes_neg,'top':top,'Ni':Ni}

            


