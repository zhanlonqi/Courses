/*
 * @Author: your name
 * @Date: 2020-11-20 14:55:21
 * @LastEditTime: 2020-11-25 00:53:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Courses\Data_structure\实验3\ex03.c
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 26

typedef struct   //图的结构定义
{
    int vertexNum;
    char vertex[MAX_VERTEX_NUM];
    int edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];                                                                            
}Graph;

void createdGraph(Graph *g)   //创建图
{
    for(int i=0;i<MAX_VERTEX_NUM;i++){
        for(int j=0;j<MAX_VERTEX_NUM;j++){
            g->edge[i][j]=0;
        }
    }
    printf("Please input number of nodes ");
    scanf("%d",&g->vertexNum);
    getchar();
    for(int i=0;i<g->vertexNum;i++){
        printf("\nPlease input name of node %d ",i);
        char c=getchar();
        g->vertex[i]=c;
        getchar();
    }
    for(int i=0;i<g->vertexNum;i++){
        printf("\nPlease input nodes that is connected ot node %c ",g->vertex[i]);
        int count=0;
        char c;
        while(count<g->vertexNum&&(c=getchar())!='\n'){
            int index=-1;
            for(int j=0;j<g->vertexNum;j++){
                if(g->vertex[j]==c){
                    index=j;
                }
            }
            if(index==-1){
                printf("wrong node! ");
                return;
            }
            g->edge[i][index]=1;
            g->edge[index][i]=1;
            count++;
        }
    }
printf("\n");
}

void DFSTraverse(Graph *g, int visited[])   //图的深度优先搜索
{
        int index=0;
        while(index<g->vertexNum&&visited[index]!=0){//得到下一个未被访问的节点
            index++;
        }
        if(index>=g->vertexNum){
            return;
        }
        while(visited[index]==0){
        printf(" %c  ->",g->vertex[index]);
        visited[index]=1;
        for(int i=0;i<g->vertexNum;i++){
                if(visited[i]==0&&g->edge[index][i]==1){
                    index=i;
                    break;
                }
            }
        }
        
        DFSTraverse(g,visited);
}

void BFSTraverse(Graph *g, int visited[])   //图的广度优先搜索
{
    int index=0;
    while(index<g->vertexNum&&visited[index]!=0){//得到下一个未被访问的节点
        index++;
    }
    if(index>=g->vertexNum){
        return;
    }
    printf(" %c  ->",g->vertex[index]);
    visited[index]=1;
    for(int i=0;i<g->vertexNum;i++){
        if(visited[i]==0&&g->edge[i][index]==1){
            printf(" %c  -> ",g->vertex[i]);
            visited[i]=1;
        }
    }
    BFSTraverse(g,visited);
}

void main()  
{  
    Graph *graph;
    int i, visited[MAX_VERTEX_NUM];

    //初始化graph
    graph = (Graph *)malloc(sizeof(Graph));
    createdGraph(graph);

    //初始化visited
  for(i=0; i<MAX_VERTEX_NUM; i++)
      visited[i] = 0;
  //深度优先
  DFSTraverse(graph, visited);

  //初始化visited
  for(i=0; i<MAX_VERTEX_NUM; i++)
      visited[i] = 0;
    printf("\n");
  ////广度优先
  BFSTraverse(graph, visited);
  return ;
}