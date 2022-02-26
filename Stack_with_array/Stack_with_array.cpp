//	�迭�� �̿��� ���� ����
#define _CRT_SECURE_NO_WARNINGS
#include "Stack_with_array.h"
#include <stdlib.h>
#define MAX_CAPACITY 100

char stack[MAX_CAPACITY];	//	stack �迭�� ����Ǵ� �������� Ÿ���� ����(char)��� ��������.
int top = -1;				//	index of top element.
							//	����, top = 0 �� �ʱ�ȭ�ϸ� top�� ���� �� �������� �� ĭ ���� ����Ŵ.

void push(char ch) {
	if (is_full()) {
		printf("Stack is fulled.\n");
		return;
	}
	top++;
	stack[top] = ch;
}

char pop() {	//	pop�� ȣ���ϱ� ���� ���� empty���� �˻��ؾ� �Ѵ�.
	if (is_empty()) {
		return NULL;
	}
	char tmp = stack[top];
	top--;
	return tmp;
}

char peek() {	//	peek�� ȣ���ϱ� ���� ���� empty���� �˻��ؾ� �Ѵ�.
	return stack[top];
}

int is_empty() {
	return top == -1;
}

int is_full() {		//	�ε����� 0���� ���۵Ǵϱ� -1 ���ش�.
	return top == MAX_CAPACITY - 1;
}