#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_POLYS 50 
/*
1. 1원 다항식을 정의할 수 있다. 다항식의 이름은 x를 제외한 영문 소문자이다 (예: f, g 등)
2. 변수는 항상 x이다.
3. 각 항의 지수는 음이 아닌 정수이고, 계수는 정수이다.
4. =, +, - 등의 앞뒤로 하나 이상의 공백이 있을 수도 있고 없을 수도 있다.
5. 항들이 반드시 차수에 대해 내림차순으로 입력되는 것은 아니며, 동일 차수의 항이 여럿 있을수도 있다.
6. 함수는 항상 차수에 대한 내림차수능로 정렬되어 저장되고 출력되어야 한다.
7. 동일 이름의 함수를 새로 정의할 수도 있다. 이 경우 기존의 함수는 지워진다.
*/

//	하나의 항 구조체
struct term {	//	c^e
	int coef;	//	계수
	int expo;	//	지수(차수)
	struct term* next;		//	다음 항을 가리키는 포인터
};

typedef struct term Term;

//	다항식 구조체
typedef struct polynomial {
	char name;		//	f, g, h
	Term* first;	//	첫번째 항
	int size = 0;
}Polynomial;

Polynomial* polys[MAX_POLYS];	//	polys는 다항식들에 대한 포인터의 배열이다.
int n = 0;	//	저장된 다항식의 개수이다.


//	하나의 항을 만들어서 그 주솟값을 반환하는 함수
Term* create_term_instance() {
	Term* t = (Term*)malloc(sizeof(Term));
	t->coef = 0;
	t->expo = 0;
	return t;
}

//	이름을 지정해주면서 다항식 객체를 생성하는 함수
Polynomial* create_polynomial_instance(char name) {
	Polynomial* ptr_poly = (Polynomial*)malloc(sizeof(Polynomial));
	ptr_poly->name = name;
	ptr_poly->size = 0;
	ptr_poly->first = NULL;		
	return ptr_poly;
}

//	poly가 가리키는 다항식에 새로운 하나의 항(c, e)를 추가하는 함수
void add_term(int c, int e, Polynomial* poly) {
	if (c == 0)
		return;
	Term* p = poly->first, *q = NULL;

	while (p != NULL && p->expo > e) {
		q = p;
		p = p->next;
	}

	if (p != NULL && p->expo == e) {	//	동일 차수의 항이 존재하는 경우
		p->coef += c;
		if (p->coef == 0) {		//	더했더니 계수가 0이 되는 경우
			if (q == NULL)
				poly->first = p->next;
		}
	}
}













