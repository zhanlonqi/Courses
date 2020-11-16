/*
    ����һ���ṹ����HuffNodes������������и�������Ϣ��
        ���ݶ����������ʿ�֪������n��Ҷ�ӽ��Ĺ�����������2n-1����㣬��������HuffNodes�Ĵ�С����Ϊ2n-1��

    ����һ���ṹ����HuffCodes������Ÿ��ַ��Ĺ�����������Ϣ��

    ��Ҷ���ı��룺
        �ù���ʵ���Ͼ������ѽ����Ĺ��������У���Ҷ��㿪ʼ���ؽ���˫��������˵�����㣬ÿ����һ�������߹��˹���������һ����֧���Ӷ��õ�һλ��������ֵ��
        ����һ���ַ��Ĺ����������ǴӸ���㵽��ӦҶ�����������·���ϸ���֧����ɵ�0��1���У�����ȵõ��ķ�֧����Ϊ�������ĵ�λ����õ��ķ�֧����Ϊ�������ĸ�λ�롣

    Huffman����ʵ�ֹ��̣�
        ����ͨ��HuffmanTree�����������������
        Ȼ����HuffmanCode�����У��Ե����Ͽ�ʼ(Ҳ���Ǵ��������Ϊ��Ľ�㿪ʼ)���ϲ���жϣ����Ǹ�������ӣ�������Ϊ0�������Һ��ӣ�������Ϊ1��
        �����main������������ɵı��롣

    �����������У�AAAAABBBBCCCDDE
    ���Ϊ��      A->11��B->10��C->00��D->011��E->010
    �������Ϊ��  3��6��1��3��2��15��4��9��5 / 15
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXVALUE  100000        //�����ı�����ַ�����
#define MAXLEAF   256           //���Ҷ�������������ͬ�ַ�����
#define MAXBIT    MAXLEAF-1     //������󳤶�
#define MAXNODE   MAXLEAF*2-1   //��������

typedef struct{        //Huffman����ṹ��
    int bit[MAXBIT];   //�ַ��Ĺ���������
    int start;         //�ñ���������bit�еĿ�ʼλ��
} HCodeType;

typedef struct{        //Huffman�����ṹ��
    float weight;      //���Ȩֵ
    int parent;        //�����λ����������ʼ-1
    int lchild;        //����λ����������ʼ-1
    int rchild;        //�Һ���λ����������ʼ-1
} HNodeType;

void str_input(char str[]){
    printf("Please input : ");
    //����ɰ����ո���ַ����������ַ��������str��
    char c;
    int count=0;
    gets(str);
}

int TextStatistics(char text[], char ch[], float weight[]) {
    //ͳ��ÿ���ַ��ĳ���Ƶ�Σ����س��ֵĲ�ͬ�ַ��ĸ���
    //���ֵ��ַ������ch�У���Ӧ�ַ��ĳ���Ƶ�δ����weight��
    int count=0;
    int i=0,j=0;
    char c;
    while ((c=text[i++])!=0)
    {
        for(j=0;j<count;j++){
            if(c==ch[j]){
                break;
                }
        }
        if(j==count){
            ch[count]=c;
            weight[count]=1.f;
            count++;
        }
        else {
            weight[j]+=1.f;
        }
    }
    for(j=0;j<count;j++){
        weight[j]=weight[j]/(i-1);
    }
    return count;
}

void HuffmanTree(HNodeType HuffNodes[], float weight[], int n){
    //����һ��Huffman�������������HuffNodes��
    float *temp=(float*)malloc(sizeof(float)*(2*n-1));
    int *occupied=(int*)malloc(sizeof(int)*(2*n-1));
    
    for(int i=0;i<2*n-1;i++){
        temp[i]=0;
        occupied[i]=0;
    }
    for(int i=0;i<n;i++){
        temp[i]=weight[i];
    }
        float least=1.f;
        int least_index=0;
        float second_least=1.f;
        int second_least_index=0;
    for(int i=0;i<n-1;i++){
         least=1.f;
         least_index=0;
         second_least=1.f;
         second_least_index=0;
        for(int j=n+i-1;j>=0;j--){
            if(occupied[j]!=1&&temp[j]<=least){
                second_least=least;
                second_least_index=least_index;
                least=temp[j];
                least_index=j;
            }
            else if(occupied[j]!=1&&temp[j]<=second_least){
                second_least=temp[j];
                second_least_index=j;
            }
        }
        HNodeType lchild,rchild,parent;
        lchild.parent=n+i;
        lchild.weight=least;
        if(least_index<n){
            lchild.lchild=-1;
            lchild.rchild=-1;
        }
        else{
        lchild.lchild=HuffNodes[least_index].lchild;
        lchild.rchild=HuffNodes[least_index].rchild;
        }
        HuffNodes[least_index]=lchild;

        rchild.weight=second_least;
        rchild.parent=n+i;
        if(second_least_index<n){
            rchild.lchild=-1;
            rchild.rchild=-1;
        }
        else{
        rchild.lchild=HuffNodes[second_least_index].lchild;
        rchild.rchild=HuffNodes[second_least_index].rchild;
        }
        HuffNodes[second_least_index]=rchild;

        parent.lchild=least_index;
        parent.rchild=second_least_index;
        parent.weight=least+second_least;
        parent.parent=-1;
        HuffNodes[n+i]=parent;

        occupied[least_index]=1;
        occupied[second_least_index]=1;
        temp[n+i]=least+second_least;
    }          
    //����и����ڵ�
}

void HuffmanCode(HNodeType HuffNodes[], HCodeType HuffCodes[], int n)  {
    //����Huffman���룬Huffman��������HuffCodes��
    for(int i=0;i<n;i++){
        HNodeType node=HuffNodes[i];
        HNodeType temp=HuffNodes[node.parent];
        int count=0;
        int index=i;
        printf("\n");
        HCodeType code;
        while(1){
            //printf("node: %d  %s->",index,temp.lchild==index?"left":"right");
            code.bit[n-2-count++]=(temp.lchild==index)?0:1;
            index=node.parent;
            node=temp;
            if(temp.parent==-1)
                break;
            temp=HuffNodes[temp.parent];
        }
        code.start=n-1-count;
        HuffCodes[i]=code;
    }
}

int MidOrderTraverse(HNodeType HuffNodes[], float result[], int root, int resultIndex) {
    printf("\ntraversing node: %d\n",root);
    //Huffman�������������������������result�У�������һ��resultλ������
    HNodeType rootNode=HuffNodes[root];
    int next;
    if(rootNode.lchild==-1){
        printf("leaf !: %d \n");
        result[resultIndex]=rootNode.weight;
        return resultIndex+1;
    }
    else{
        printf("node : %d\n");
        next=MidOrderTraverse(HuffNodes,result,rootNode.lchild,resultIndex);
        printf("adding node : %f",HuffNodes[next].weight);
        result[next]=HuffNodes[next].weight;
        next++;
        next=MidOrderTraverse(HuffNodes,result,rootNode.rchild,next);
    }
    return next;
}

void main()
{
    HNodeType HuffNodes[MAXNODE];   // ����һ�����ṹ������
    HCodeType HuffCodes[MAXLEAF];   // ����һ������ṹ������
    char text[MAXVALUE+1], ch[MAXLEAF];
    float weight[MAXLEAF], result[MAXNODE];
    int i, j, n, resultIndex;

    str_input(text);
    n = TextStatistics(text, ch, weight);
    // �������������
    HuffmanTree(HuffNodes, weight, n);
    HuffmanCode(HuffNodes, HuffCodes, n);

    for (i=0; i<n; i++) { 
        printf("%c��Huffman�����ǣ�", ch[i]);
        for(j=HuffCodes[i].start; j<n-1; j++)
            printf("%d", HuffCodes[i].bit[j]);
        printf("\n");
    }

    // ���Huffman��������������
    resultIndex = MidOrderTraverse(HuffNodes, result, 2*n-2, 0);
    printf("\nHuffman���������������ǣ�");

    for (i=0; i<resultIndex; i++) 
        if (i < resultIndex-1)
            printf("%.4f, ", result[i]);
        else
            printf("%.4f\n\n", result[i]);
}