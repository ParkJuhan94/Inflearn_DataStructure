#include <stdio.h>

void push(char* item);
char* pop();
char* peek();

int is_empty();
//	배열과 달리 연결리스트로 구현한 스택은 is_full() 이 필요하지 않다. 동적할당 받으면 되니까.