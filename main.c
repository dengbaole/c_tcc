#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef struct node {
	int data;
	struct node* next;
} NODE;

/*
1. 初始化的时候list 创建之后不会销毁吗，返回为什么可以  ： 因为malloc动态创建在堆上不会被销毁，普通变量创建在栈上可以销毁

*/


/// @brief 初始化
/// @return
NODE* initlist(void) {
	NODE* list = (NODE*)malloc(sizeof(NODE));
	list ->data = 0;
	list ->next = NULL;
    printf("list p =%p \n",list);
    return list;
}

/// @brief 列表中传入数据
/// @param list
/// @param data
void headinsert(NODE* list, int data) {
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node ->data = data;
	node ->next = list ->next;
	list ->next = node;
	list ->data++;
}

void tailinsert(NODE* list, int data) {
	NODE* head = list;
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node ->data =  data;
	node->next = NULL;
	while(list ->next) {
		list = list -> next;
	}
	list ->next = node;
	head ->data++;
}


void delete_list(NODE* list, int data) {
	NODE* pre = list;
	NODE* current = list -> next;
	while (current) {
		if(current -> data == data) {
			pre ->next = current ->next;
			free(current);
			break;
		}
		pre = current;
		current = current ->next;
	}
    list -> data--;
}


void printlist(NODE* list){
    list = list -> next;
    while (list){
        printf("%d \n",list -> data);
        list = list -> next;
    }
    printf("\n");
    
}


int main(void) {
    NODE* list = initlist();
    printf("list p =%p \n",list);
    headinsert(list,1);
    delete_list(list,2);
    printlist(list);
	return 0;
}


