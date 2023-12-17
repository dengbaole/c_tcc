#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

/// 队列先进后出
typedef struct Node {
	int data;
	struct Node* next;
} NODE;

NODE* initqueue(void){
	NODE* Q = (NODE*)malloc(sizeof(NODE));
	Q ->data = 0;
	Q ->next = NULL;
	return Q;
}


int isempty(NODE* Q){
	if(Q ->next == NULL){
		return 1;
	}else{
		return 0;
	}
}


/// @brief 
/// @param Q 
/// @param data 
/// @return 
NODE* enqueue(NODE* Q,int data){
	NODE* q;
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node ->data = data;
	while(q->next!=NULL){
		q = q ->next;
	}
	node->next = q->next;
	q ->next = node;
}


int delqueue(NODE* Q){
	if(isempty(Q)){
		return -1;	
	}else{
		NODE* node = Q ->next;
		int data = node ->data;
		Q ->next = node ->next;
		free(node);
		return data;
	}

}

int test(){
	int i = 0;
	return i;
}
void printqueue(NODE* Q){
	NODE* node = Q ->next;
	while (node){
		printf("%d ->",node->data);
		node = node ->next;
	}
	printf("NULL");
}

int main(void){
	NODE* Q = initqueue();
	enqueue(Q,1);
	enqueue(Q,3);
	enqueue(Q,3);
	enqueue(Q,4);
	delqueue(Q);
	printqueue(Q);
	return 0;
}