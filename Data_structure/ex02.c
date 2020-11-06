/*
    设置一个结构数组HuffNodes保存哈夫曼树中各结点的信息。
        根据二叉树的性质可知，具有n个叶子结点的哈夫曼树共有2n-1个结点，所以数组HuffNodes的大小设置为2n-1。

    设置一个结构数组HuffCodes用来存放各字符的哈夫曼编码信息。

    求叶结点的编码：
        该过程实质上就是在已建立的哈夫曼树中，从叶结点开始，沿结点的双亲链域回退到根结点，每回退一步，就走过了哈夫曼树的一个分支，从而得到一位哈夫曼码值。
        由于一个字符的哈夫曼编码是从根结点到相应叶结点所经过的路径上各分支所组成的0、1序列，因此先得到的分支代码为所求编码的低位，后得到的分支代码为所求编码的高位码。

    Huffman编码实现过程：
        首先通过HuffmanTree函数构造哈夫曼树。
        然后在HuffmanCode函数中，自底向上开始(也就是从数组序号为零的结点开始)向上层层判断，若是父结点左孩子，则置码为0，若是右孩子，则置码为1。
        最后在main函数中输出生成的编码。

    测试输入序列：AAAAABBBBCCCDDE
    码表为：      A->11，B->10，C->00，D->011，E->010
    中序遍历为：  3，6，1，3，2，15，4，9，5 / 15
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXVALUE  100000        //输入文本最大字符个数
#define MAXLEAF   256           //最大叶结点个数，即最大不同字符个数
#define MAXBIT    MAXLEAF-1     //编码最大长度
#define MAXNODE   MAXLEAF*2-1   //最大结点个数

typedef struct{        //Huffman编码结构体
    int bit[MAXBIT];   //字符的哈夫曼编码
    int start;         //该编码在数组bit中的开始位置
} HCodeType;

typedef struct{        //Huffman树结点结构体
    float weight;      //结点权值
    int parent;        //父结点位置索引，初始-1
    int lchild;        //左孩子位置索引，初始-1
    int rchild;        //右孩子位置索引，初始-1
} HNodeType;

void str_input(char str[]) {
    //输入可包含空格的字符串，输入字符串存放在str中
    char c;
    int count=0;
    while((c=getchar())!='\0'){
        str[count++]=c;
    }
}

int TextStatistics(char text[], char ch[], float weight[]) {
    //统计每种字符的出现频次，返回出现的不同字符的个数
    //出现的字符存放在ch中，对应字符的出现频次存放在weight中
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
    //构造一棵Huffman树，树结点存放在HuffNodes中
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
    //生成Huffman编码，Huffman编码存放在HuffCodes中

}

int MidOrderTraverse(HNodeType HuffNodes[], float result[], int root, int resultIndex) {
    //Huffman树的中序遍历，遍历结果存放在result中，返回下一个result位置索引

}

void main()
{
    HNodeType HuffNodes[MAXNODE];   // 定义一个结点结构体数组
    HCodeType HuffCodes[MAXLEAF];   // 定义一个编码结构体数组
    char text[MAXVALUE+1], ch[MAXLEAF];
    float weight[MAXLEAF], result[MAXNODE];
    int i, j, n, resultIndex;

    str_input(text);
    n = TextStatistics(text, ch, weight);

    // 输出哈夫曼编码
    HuffmanTree(HuffNodes, weight, n);
    HuffmanCode(HuffNodes, HuffCodes, n);

    for (i=0; i<n; i++) { 
        printf("%c的Huffman编码是：", ch[i]);

        for(j=HuffCodes[i].start; j<n-1; j++)
            printf("%d", HuffCodes[i].bit[j]);

        printf("\n");
    }

    // 输出Huffman树的中序遍历结果
    resultIndex = MidOrderTraverse(HuffNodes, result, 2*n-2, 0);
    printf("\nHuffman树的中序遍历结果是：");

    for (i=0; i<resultIndex; i++) 
        if (i < resultIndex-1)
            printf("%.4f, ", result[i]);
        else
            printf("%.4f\n\n", result[i]);
}