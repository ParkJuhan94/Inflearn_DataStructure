/*
* 
1.�Է� ������ ��ȣ�� �ùٸ��� �˻��Ѵ�.
	��: [a + b * {c / (d - e)}] + (d / e)

2.�ܼ���, ���� ��ȣ�� �ݴ� ��ȣ�� ���� �� �����δ� �����ϴ�.

3.������ �̿��Ͽ� �˻��Ѵ�.
	- ���� ��ȣ�� ���ÿ� push��
	- �ݴ� ��ȣ�� ������ ���ÿ��� pop�� ��, �� ��ȣ�� ���� �����̾�� ��
	- �������� ���ÿ� ���� ��ȣ�� ����� ��
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
	scanf("%s", expr);	//	�Է��� ��ȣ������ �̷���� �ϳ��� ���ڿ��̴�.
	
	if (is_balanced(expr))
		printf("%s: balanced.\n", expr);
	else
		printf("%s: unbalanced.\n", expr);
}