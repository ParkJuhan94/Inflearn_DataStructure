/*
* 
1.입력 수식의 괄호가 올바른지 검사한다.
	예: [a + b * {c / (d - e)}] + (d / e)

2.단순히, 여는 괄호와 닫는 괄호의 개수 비교 만으로는 부족하다.

3.스택을 이용하여 검사한다.
	- 여는 괄호는 스택에 push함
	- 닫는 괄호가 나오면 스택에서 pop한 후, 두 괄호가 같은 유형이어야 함
	- 마지막에 스택에 남는 괄호가 없어야 함
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 100
#include "../Stack_with_array/Stack_with_array.h"
#include <string.h>

char OPEN[] = "([{";
char CLOSE[] = ")]}";

int is_balanced(char* expr);
int is_open(char ch);
int is_close(char ch);

int main() {
	char expr[MAX_LENGTH];
	scanf("%s", expr);	//	입력은 괄호만으로 이루어진 하나의 문자열이다.
	
	if (is_balanced(expr))
		printf("%s: balanced.\n", expr);
	else
		printf("%s: unbalanced.\n", expr);
}

int is_balanced(char* expr) {
	int balanced = 1;
	int index = 0;
	while (balanced && (index < strlen(expr)))
	{
		char ch = expr[index];
		if (is_open(ch) > -1)		//	여는 괄호는 스택에 push한다.
			push(ch);
		else if (is_close(ch) > -1) {	//	중요. 닫는 괄호면 비었는지부터 검사한다. 비었으면 종료
			if (is_empty()) {
				balanced = 0;
				break;
			}
			char top_ch = pop();		//	닫는 괄호가 나오면 스택에서 pop하여
			if (is_open(top_ch) != is_close(ch)) {		//	같은 유형의 괄호인지 검사한다.		좌우 매개변수 반대 아니야.....?
				balanced = 0;
			}
		}
		index++;
	}
	return (balanced == 1 && is_empty() == 1);
}

int is_open(char ch) {
	for (int i = 0; i < strlen(OPEN); i++) {
		if (OPEN[i] == ch)	//	여는 소괄호는 0, 대괄호는 1, 중괄호는 2를 반환한다.
			return i;		
	}
	return -1;	//	여는 괄호가 아니면 -1을 반환한다.	
}	

int is_close(char ch) {
	for (int i = 0; i < strlen(CLOSE); i++) {
		if (CLOSE[i] == ch)		//	닫는 소괄호는 0, 대괄호는 1, 중괄호는 2를 반환한다.
			return i;
	}
	return -1;	//	닫는 괄호가 아니면 -1을 반환한다.
}