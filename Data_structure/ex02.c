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

void str_input(char str[]){
    printf("Please input : ");
    //输入可包含空格的字符串，输入字符串存放在str中
    char c;
    int count=0;
    gets(str);
}

int TextStatistics(char text[], char ch[], float weight[]) {
    //统计每种字符的出现频次，返回出现的不同字符的个数
    //出现的字符存放在ch中，对应字符的出现频次存放在weight中
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
    //构造一棵Huffman树，树结点存放在HuffNodes中
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
    //最后还有个根节点
}

void HuffmanCode(HNodeType HuffNodes[], HCodeType HuffCodes[], int n)  {
    //生成Huffman编码，Huffman编码存放在HuffCodes中
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
    //Huffman树的中序遍历，遍历结果存放在result中，返回下一个result位置索引
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