#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

typedef struct node {
	int data;
	struct node* next;
} NODE;

/*
1. 初始化的时候list 创建之后不会销毁吗，返回为什么可以    可以返回指针但是不能返回值

*/

NODE* initlist(void) {
	NODE* list = (NODE*)malloc(sizeof(NODE));
	list -> data = 0;
	list -> next = list;
	return list;
}

void headinsert(NODE* list,int data){
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node ->data = data;
    node ->next = list ->next;
    list ->next = node;
}


void tailinsert(NODE* list,int data){
    NODE* n = list;
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node ->data = data;
    node ->next = n;
    while (n ->next !=list){
        n = n->next;
    }
    n ->next = node;
}

void printlist(NODE* list){
    NODE* node = list ->next;
    while (node != list){
        printf("%d ",node ->data);
        node = node ->next;
    }
    printf("\n");
}


int deletelist(NODE* list,int data){
    NODE* prenode = list;
    NODE* node = list ->next;
    while (node!= list){
        if(node ->data == data){
            prenode ->next = node ->next;
            free(node);
            return TRUE;
        }
        prenode = node;
        node = node ->next;
    }
    return FALSE;
}


int main(void) {
    NODE* list = initlist();
    headinsert(list,1);
    headinsert(list,2);
    headinsert(list,3);
    headinsert(list,4);
    headinsert(list,5);
    headinsert(list,6);
    tailinsert(list,7);
    tailinsert(list,8);
    deletelist(list,3);
    printlist(list);
	return 0;
}


