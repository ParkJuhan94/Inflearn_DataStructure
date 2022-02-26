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
#include "../Stack_with_array/Stack_with_array.h"
#include <string.h>

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

int is_balanced(char* expr) {
	int balanced = 1;
	int index = 0;
	while (balanced && (index < strlen(expr)))
	{
		char ch = expr[index];
		if (is_open(ch) > -1)		//	���� ��ȣ�� ���ÿ� push�Ѵ�.
			push(ch);
		else if (is_close(ch) > -1) {	//	�߿�. �ݴ� ��ȣ�� ����������� �˻��Ѵ�. ������� ����
			if (is_empty()) {
				balanced = 0;
				break;
			}
			char top_ch = pop();		//	�ݴ� ��ȣ�� ������ ���ÿ��� pop�Ͽ�
			if (is_open(top_ch) != is_close(ch)) {		//	���� ������ ��ȣ���� �˻��Ѵ�.		�¿� �Ű����� �ݴ� �ƴϾ�.....?
				balanced = 0;
			}
		}
		index++;
	}
	return (balanced == 1 && is_empty() == 1);
}

int is_open(char ch) {
	for (int i = 0; i < strlen(OPEN); i++) {
		if (OPEN[i] == ch)	//	���� �Ұ�ȣ�� 0, ���ȣ�� 1, �߰�ȣ�� 2�� ��ȯ�Ѵ�.
			return i;		
	}
	return -1;	//	���� ��ȣ�� �ƴϸ� -1�� ��ȯ�Ѵ�.	
}	

int is_close(char ch) {
	for (int i = 0; i < strlen(CLOSE); i++) {
		if (CLOSE[i] == ch)		//	�ݴ� �Ұ�ȣ�� 0, ���ȣ�� 1, �߰�ȣ�� 2�� ��ȯ�Ѵ�.
			return i;
	}
	return -1;	//	�ݴ� ��ȣ�� �ƴϸ� -1�� ��ȯ�Ѵ�.
}