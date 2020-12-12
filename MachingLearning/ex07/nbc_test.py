# -*- coding: utf-8 -*-
import math
def Normal_distribution(x,u,sigma):
    return 1/(math.sqrt(2*math.pi)*sigma)*math.exp(-1*(x-u)**2/2/sigma**2)

def nbc_test(nbModel, testSample):
    result1=0
    result2=0
    for i in range(len(testSample[0])):
        if(i<6):
            att=int(testSample[0][i]%10)-1
            result1+=(nbModel['attributes_pos'][i][att]+1)/(nbModel['num_pos']+nbModel['Ni'][i])
            result2+=(nbModel['attributes_neg'][i][att])/(nbModel['num_neg']+nbModel['Ni'][i])
        else:
            result1+=Normal_distribution(testSample[0][i],nbModel['attributes_pos'][i][0],nbModel['attributes_pos'][i][1])
            result2+=Normal_distribution(testSample[0][i],nbModel['attributes_neg'][i][0],nbModel['attributes_neg'][i][1])
    print(result1,result2)
    if(result1>result2):
        return 1,1
    else:
        return 0,0
    # 基于朴素贝叶斯分类器的测试样本分类
    #   nbModel       训练好的分类器，字典类型
    #   testSample    测试样本，是一个行向量
    # 输出参数
    #   test_label    测试样本类标记
    #   prob          测试样本归属于每个类的概率
