# -*- coding: utf-8 -*-


def nbc_test(nbModel, testSample):
    # 基于朴素贝叶斯分类器的测试样本分类
    #   nbModel       训练好的分类器，字典类型
    #   testSample    测试样本，是一个行向量
    # 输出参数
    #   test_label    测试样本类标记
    #   prob          测试样本归属于每个类的概率
