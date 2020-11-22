/*
 * @Author: your name
 * @Date: 2020-11-20 14:55:21
 * @LastEditTime: 2020-11-22 22:02:17
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
    int num_nodes;
    char names[MAX_VERTEX_NUM];
    for(int i=0;i<MAX_VERTEX_NUM;i++){
        for(int j=0;j<MAX_VERTEX_NUM;j++){
            g->edge[i][j]=0;
        }
    }
    printf("Please input number of nodes ");
    scanf("%d",&num_nodes);
    getchar();
    for(int i=0;i<num_nodes;i++){
        printf("\nPlease input name of node %d ",i);
        char c=getchar();
        names[i]=c;
        getchar();
    }
    for(int i=0;i<num_nodes;i++){
        printf("\nPlease input nodes that is connected ot node %c ",names[i]);
        int count=0;
        char c;
        while(count<num_nodes&&(c=getchar())!='\n'){
            printf(" %d  %d\n",names[i]-'a',c-'a');
            g->edge[names[i]-'a'][c-'a']=1;
            g->edge[c-'a'][names[i]-'a']=1;
            count++;
        }
    }
    for(int i=0;i<MAX_VERTEX_NUM;i++){
        printf("\n");
        for(int j=0;j<MAX_VERTEX_NUM;j++){
            printf("  %d ",g->edge[i][j]);
        }
    }
}

void DFSTraverse(Graph *g, int visited[])   //图的深度优先搜索
{
   // int visited[MAX_VERTEX_NUM];
}

void BFSTraverse(Graph *g, int visited[])   //图的广度优先搜索
{

}

void main()  
{  
    Graph *graph;
    int i, visited[MAX_VERTEX_NUM];

    //初始化graph
    graph = (Graph *)malloc(sizeof(Graph));
    createdGraph(graph);

    //初始化visited
  //for(i=0; i<MAX_VERTEX_NUM; i++)
  //    visited[i] = 0;
  ////深度优先
  //DFSTraverse(graph, visited);

  ////初始化visited
  //for(i=0; i<MAX_VERTEX_NUM; i++)
  //    visited[i] = 0;

  ////广度优先
  //BFSTraverse(graph, visited);
  return ;
}