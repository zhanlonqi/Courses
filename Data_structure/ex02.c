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

void str_input(char str[]) {
    //����ɰ����ո���ַ����������ַ��������str��
    char c;
    int count=0;
    while((c=getchar())!='\0'){
        str[count++]=c;
    }
}

int TextStatistics(char text[], char ch[], float weight[]) {
    //ͳ��ÿ���ַ��ĳ���Ƶ�Σ����س��ֵĲ�ͬ�ַ��ĸ���
    //���ֵ��ַ������ch�У���Ӧ�ַ��ĳ���Ƶ�δ����weight��
    int count=0,i=0;
    char c;
    while((c=text[i++])!='\0'){
        for( i=0;i<count;i++){
            if(c==ch[i]){
                weight[i]++;
                break;
            }
        }
        if(i==count){
            weight[i]=1;
        }
    }
    return count;
}

void HuffmanTree(HNodeType HuffNodes[], float weight[], int n){
    //����һ��Huffman�������������HuffNodes��
    float temp[2*n-1];
    int occupied[2*n-1];
    for(int i=0;i<n;i++){
        temp[i]=weight[i];
    }
    
    for(int i=0;i<n;i++){
        int count=0;
        int least=MAXVALUE;
        int least_index=0;
        int second_least=MAXVALUE;
        int second_least_index=0;
        for(int j=0;j<n+i;j++){
            if(weight[j]<least&&occupied[j]==0){
                second_least=least;
                second_least_index=least_index;
                least=weight[j];
                least_index=j;
            }
            occupied[least_index]=1;
            occupied[second_least_index]=1;
            temp[n+i]=least+second_least;
        }
        HNodeType root;
        root.weight=least+second_least;
        int root_index=n+count++;
        HuffNodes[root_index]=root;

        if(least_index<n){
            HNodeType node;
            node.lchild=NULL;
            node.rchild=NULL;
            node.parent=root_index;
            node.weight=least+second_least;
            HuffNodes[least_index]=node;
        }
        else{

        }
        if(second_least_index<n){
            HNodeType node2;
            node2.lchild=NULL;
            node2.rchild=NULL;
            node2.weight=least+second_least;
            HuffNodes[count++]=node2;
        }    
        
        
    }

}

void HuffmanCode(HNodeType HuffNodes[], HCodeType HuffCodes[], int n) {
    //����Huffman���룬Huffman��������HuffCodes��

}

int MidOrderTraverse(HNodeType HuffNodes[], float result[], int root, int resultIndex) {
    //Huffman�������������������������result�У�������һ��resultλ������

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