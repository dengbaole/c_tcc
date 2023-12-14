#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

typedef struct node {
	int data;
    struct node* pre;
	struct node* next;
} NODE;

/*
1. 初始化的时候list 创建之后不会销毁吗，返回为什么可以    可以返回指针但是不能返回值

*/

NODE* initlist(void) {
	NODE* list = (NODE*)malloc(sizeof(NODE));
	list -> data = 0;
	list -> next = NULL;
    list ->pre = NULL;
	return list;
}

void headinsert(NODE* list,int data){
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node ->data = data;
    if(list -> next == NULL){
        //链表空
        node->next = list -> next;
        node -> pre = list;
        list ->next = node;
    }else{
        node ->pre = list;
        node ->next = list->next;
        list ->next ->pre = node;
        list ->next = node;
    }
    
}


void tailinsert(NODE* list,int data){
    NODE* l = list;
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node -> data = data;
    while (l -> next != NULL){
        l = l ->next;
    }
    node ->next = l ->next;
    l ->next = node;
    node -> pre = l;
}


int deletelist(NODE* list,int data){
    NODE* node = list -> next;
    while(node!= NULL){
        if(node ->data == data){
            //删除操作
            node -> pre -> next = node ->next;
            node ->next ->pre = node ->pre;
            free(node);
            return TRUE;
        }
        node = node -> next;
    }
    return FALSE;
}

void printlist(NODE* list){
    NODE* node = list ->next;
    while(node){
        printf("%d -> ",node->data);
        node = node ->next;
    }
    printf("NULL\n");
}


int main(void) {
    NODE* list = initlist();
    headinsert(list,1);
    headinsert(list,2);
    headinsert(list,3);
    headinsert(list,4);
    headinsert(list,0);
    headinsert(list,5);
    tailinsert(list,6);
    deletelist(list,1);
    printlist(list);
	return 0;
}


