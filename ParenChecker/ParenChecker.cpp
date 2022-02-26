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
#include "../Stack_with_LinkedList/Stack_with_LinkedList.h"

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