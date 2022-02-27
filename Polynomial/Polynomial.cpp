#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_POLYS 50 
/*
1. 1�� ���׽��� ������ �� �ִ�. ���׽��� �̸��� x�� ������ ���� �ҹ����̴� (��: f, g ��)
2. ������ �׻� x�̴�.
3. �� ���� ������ ���� �ƴ� �����̰�, ����� �����̴�.
4. =, +, - ���� �յڷ� �ϳ� �̻��� ������ ���� ���� �ְ� ���� ���� �ִ�.
5. �׵��� �ݵ�� ������ ���� ������������ �ԷµǴ� ���� �ƴϸ�, ���� ������ ���� ���� �������� �ִ�.
6. �Լ��� �׻� ������ ���� ���������ɷ� ���ĵǾ� ����ǰ� ��µǾ�� �Ѵ�.
7. ���� �̸��� �Լ��� ���� ������ ���� �ִ�. �� ��� ������ �Լ��� ��������.
*/

//	�ϳ��� �� ����ü
struct term {	//	c^e
	int coef;	//	���
	int expo;	//	����(����)
	struct term* next;		//	���� ���� ����Ű�� ������
};
typedef struct term Term;

//	���׽� ����ü
typedef struct polynomial {
	char name;		//	f, g, h
	Term* first;	//	ù��° ��
	int size = 0;
}Polynomial;

Polynomial* polys[MAX_POLYS];	//	polys�� ���׽ĵ鿡 ���� �������� �迭�̴�.
int n = 0;	//	����� ���׽��� �����̴�.


//	�ϳ��� ���� ���� �� �ּڰ��� ��ȯ�ϴ� �Լ�
Term* create_term_instance() {
	Term* t = (Term*)malloc(sizeof(Term));
	t->coef = 0;
	t->expo = 0;
	return t;
}

//	�̸��� �������ָ鼭 ���׽� ��ü�� �����ϴ� �Լ�
Polynomial* create_polynomial_instance(char name) {
	Polynomial* ptr_poly = (Polynomial*)malloc(sizeof(Polynomial));
	ptr_poly->name = name;
	ptr_poly->size = 0;
	ptr_poly->first = NULL;		
	return ptr_poly;
}

//	poly�� ����Ű�� ���׽Ŀ� ���ο� �ϳ��� ��(c, e)�� �߰��ϴ� �Լ�
void add_term(int c, int e, Polynomial* poly) {
	if (c == 0)
		return;
	Term* p = poly->first, *q = NULL;

	while (p != NULL && p->expo > e) {		//	q�� p�� �� ĭ �ڸ� �����
		q = p;
		p = p->next;
	}

	if (p != NULL && p->expo == e) {	//	���� ������ ���� �����ϴ� ���
		p->coef += c;
		if (p->coef == 0) {		//	���ߴ��� ����� 0�� �Ǵ� ���
			if (q == NULL)
				poly->first = p->next;	//	q�� ���� ��带 �����Ѵ�. ��, q�� NULL�̸� ù��° ��带 �����Ѵ�. 
			else
				q->next = p->next;
			poly->size--;
			free(p);
		}
		return;
	}

	//	�̱��� ������ ���� ������ ���� �������� �ʴ� ���: Term* �� ����
	Term* term = create_polynomial_instance();
	term->coef = c;
	term->expo = e;

	if (q == NULL) {		//	�� �տ� �����ϴ� ���
		term->next = poly->first;
		poly->first = term;
	}
	else {					//	q�� ��, p�� �տ� ����(p�� NULL�� ���� ����)
		term->next = p;
		q->next = term;
	}
	poly->size++;
}

//	���׽��� ���� ����ϴ� �Լ�
int eval(polynomial* poly, int x) {
	int result = 0;
	Term* t = poly->first;
	while (t != NULL) {
		result += eval(t, x);	//	������ ���� ���� ����Ͽ� ���Ѵ�.
		t = t->next;
	}
	return result;
}

//	�ϳ��� ���� ���� ����ϴ� �Լ� -> c*x^e
int eval(Term* term, int x) {	
	int result = term->coef;
	for (int i = 0; i < term->expo; i++) {
		result *= x;
	}
	return result;
}

//	�ϳ��� ���׽��� ����ϴ� �Լ�
void print_poly(Polynomial* p) {
	printf("%c=", p->name);
	Term* t = p->first;
	while (t != NULL) {
		print_term(t);
		printf("+");
		t = t->next;
	}
}

//	�ϳ��� ���� ����ϴ� �Լ�
//	�� �Լ��� �Ϻ����� �ʴ�. �����ϴ� ���� ������ ���� �д�.   -> 3x^2 +- 5x^1 + 3x^0  �̷������� �Ǵ°� ����
void print_term(Term* pTerm) {
	printf("%dx^%d", pTerm->coef, pTerm->expo);
}

//	main���� ȣ��Ǿ ������� ����� �޾Ƽ� ó���ϴ� �Լ�
void process_command() {

}











