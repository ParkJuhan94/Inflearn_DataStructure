//	배열을 이용한 스택 구현
#define _CRT_SECURE_NO_WARNINGS
#include "Stack_with_array.h"
#include <stdlib.h>
#define MAX_CAPACITY 100

char stack[MAX_CAPACITY];	//	stack 배열에 저장되는 데이터의 타입을 문자(char)라고 가정하자.
int top = -1;				//	index of top element.
							//	만약, top = 0 로 초기화하면 top은 가장 위 데이터의 한 칸 위를 가리킴.

void push(char ch) {
	if (is_full()) {
		printf("Stack is fulled.\n");
		return;
	}
	top++;
	stack[top] = ch;
}

char pop() {	//	pop을 호출하기 전에 먼저 empty인지 검사해야 한다.
	if (is_empty()) {
		return NULL;
	}
	char tmp = stack[top];
	top--;
	return tmp;
}

char peek() {	//	peek을 호출하기 전에 먼저 empty인지 검사해야 한다.
	return stack[top];
}

int is_empty() {
	return top == -1;
}

int is_full() {		//	인덱스는 0부터 시작되니까 -1 해준다.
	return top == MAX_CAPACITY - 1;
}