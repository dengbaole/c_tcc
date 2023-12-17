#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

//栈的特点 先进后出
typedef struct Node {
	int data;
	struct Node* next;
} NODE;

NODE* initstack(void) {
	NODE* S = (NODE*)malloc(sizeof(NODE));
	S -> data = 0;
	S -> next = NULL;
	return S;
}


int isempty(NODE* S) {
	if(S -> next == NULL) {
		return 1;
	} else {
		return 0;
	}
}

int gitTOP(NODE* S) {
	if(isempty(S)) {
		return -1;
	} else {
		return S -> next -> data;
	}
}

/// @brief 出栈
/// @param S 
/// @return 
int pop(NODE* S) {
	if(isempty(S)) {
		return -1;
	}else{
		NODE* node = S->next;
		int data = node ->data;
		S->next = node ->next;
		free(node);
		return data;
	}
}


void push(NODE* S, int data) {
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node ->data = data;
	node ->next = S ->next;
	S ->next = node;
}


void printstack(NODE* S) {
	NODE* node = S ->next;
	while (node) {
		printf("%d -> ", node ->data);
		node = node->next;
	}
	printf("NULL\n");
}


int main(void) {
	NODE* S = initstack();
	push(S, 1);
	push(S, 4);
	push(S, 2);
	push(S, 3);
	printstack(S);
	int i = pop(S);
	printf("%d \n",i);
	return 0;
}
