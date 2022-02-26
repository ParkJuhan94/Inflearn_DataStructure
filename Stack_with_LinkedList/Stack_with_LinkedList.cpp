#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	char* data;				//	���ڿ��� �����ϴ� ����
	struct node* next;
};
typedef struct node Node;

Node* top = NULL;

void push(char* item) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = item;
	p->next = top;
	top = p;
}

int is_empty() {
	return top == NULL;
}

char* pop() {
	if (is_empty()) {
		return NULL;
	}
	char* result = top->data;
	top = top->next;
	return result;
}

char* peek() {
	if (is_empty()) {
		return NULL;
	}
	return top->data;
}
