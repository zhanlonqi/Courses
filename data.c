#include<stdio.h>
#include<stdlib.h>
typedef struct array array;
struct  array
{
    char* value;
    array *next;
};

void initArray(array* header,int len){
    array * curr=header;
    array * last=header;
    char *value="NULL";//set the default num as "null"
    for(int i=0;i<len;i++){
        array *element=(array*)malloc(sizeof(array));
        curr=element;
        (*curr).value=value;
        (*curr).next=NULL;
        last->next=curr;
        last=curr;
    }
}

void addArray(array* header,array * arr,int pos){
    array* pointer=header;
    int count=pos;
    while(count--){
        pointer=(*pointer).next;
        if(pointer){
            printf("the pos is out of boundary!\n");
            return;
        }
    }
    array* temp=(*pointer).next;
    (*pointer).next=arr;
    arr=temp->next;
    
}

void destoryArray(array* header){
    array *pointer=(*header).next;
    do{
        array* curr=pointer;
        pointer=(*pointer).next;
        free(curr);
    }while(pointer);
    header->next=NULL;
}

int main(){
    array *header=(array*)malloc(sizeof(array));
    char * value="header";
    header->value=value;
    header->next=NULL;
    initArray(header,4);
    
    array *addedArray=(array*)malloc(sizeof(array));
    char * value2="added";
    addedArray->value=value2;
    addedArray->next=NULL;
  
    addArray(header,addedArray,100);

    destoryArray(header); 
    array * pointer=header;
    while(pointer){ 
    printf("%s\n",(*pointer).value);
    pointer=(*pointer).next;
    }
    return 0;
}
