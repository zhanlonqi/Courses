#include <stdio.h>
#include<stdlib.h>  
typedef struct node{
    char * value;
} node;
typedef struct  array
{
    node * data;
    int head,tail;
    int len;
} LinkedList;

LinkedList* init(int len){
    node *data=(int *)malloc(len*sizeof(node));
    for(int i=0;i<len;i++){
        data[i].value="null";
    }
    LinkedList*  arr=(LinkedList*)malloc(sizeof(LinkedList));
    arr->data=data;
    arr->head=0;
    arr->tail=0;
    arr->len=len;
    return arr;
}

void add(LinkedList * list,node * target){
    if(((*list).head+1)%(*list).len==(*list).tail){
        printf("error!\n");
        return;
    }
    (*list).data[(*list).head]=*target;
    (*list).head=((*list).head+1)%(*list).len;
}

char* get(LinkedList *list){
    if((*list).tail==(*list).head){
        printf("error\n");
        return "NULL";
    }
    char* ans= (*list).data[(*list).tail].value;
    (*list).tail=((*list).tail+1)%(*list).len;
    return ans;
}

int main(){
    LinkedList * head=init(5);
    node *nod=(node*)malloc(sizeof(node));
    nod->value="fuck";
    add(head,nod);
    
    for(int i=0;i<5;i++){
        char * s=get(head);
        printf("%s\n",s);
    }
    return 0;
}
