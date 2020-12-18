#include<stdio.h>
#include<stdlib.h>
#define MAX_DATA_NUM 30   //输入数据最大数量

typedef struct   //数据表的结构定义
{
    int data[MAX_DATA_NUM];
    int length;
}DataTable;

int Search_Bin(DataTable *L, int key)
{
    //在升序有序表L中二分查找值等于key的数据元素
    //若找到，则函数返回值为该元素在表中的位置索引，否则为-1

}

void Insert_Sort(DataTable *L)  //直接插入排序
{

}

void Bubble_Sort(DataTable *L)  //冒泡排序
{

}

void DataTable_Output(DataTable *L) //依次输出数据表的每个元素
{
    int i;

    for(i=0; i < L->length - 1; i++)
        printf("%d, ", L->data[i]);

    printf("%d\n\n", L->data[i]);
}

void main()  
{  
    DataTable *L1, *L2;
    int i;

    //初始化数据表
    L1 = (DataTable *)malloc(sizeof(DataTable));
    L2 = (DataTable *)malloc(sizeof(DataTable));

    printf ("请输入数据表的元素个数，不超过%d个：", MAX_DATA_NUM);
    scanf("%d", &L1->length);
    L2->length = L1->length;

    for(i=0; i < L1->length; i++) {
        printf("请输入数据表第%d个元素值：", i+1);
        scanf("%d", &L1->data[i]);
        L2->data[i] = L1->data[i];
    }
    printf("\n");

    printf ("排序前的数据表L1：");
    DataTable_Output(L1);

    printf ("直接插入排序后的数据表L1：");
    Insert_Sort(L1);
    DataTable_Output(L1);

    printf ("排序前的数据表L2：");
    DataTable_Output(L2);

    printf ("冒泡排序后的数据表L2：");
    Bubble_Sort(L2);
    DataTable_Output(L2);

    printf ("请输入要查找的元素值：");
    scanf("%d", &i);

    printf ("在数据表L1中二分查找元素%d的结果是：%d\n", i, Search_Bin(L1, i));
}
