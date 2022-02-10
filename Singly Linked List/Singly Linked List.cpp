#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {			//	'�ڱ� ������ ����ü'
	const char* data;	//	'������ڿ�'�� ����Ʈ����
	struct node* next;	//	���� ����� �ּҸ� ������ �ʵ� 
};
typedef struct node Node;

Node* head = NULL;		//	���Ḯ��Ʈ�� ù ��° ����� �ּҸ� ������ ������. 
						//	���� ������ �δ� ���� ���� �Լ����� ����ϱ⿡ ���ϴ�.
						//	main ���� ���� ������ head�� �����ϰ� ����Ѵٸ�, �Լ����� head�� �ּڰ��� �Ű� ������ �޾ƾ��Ѵ�. 
						//	�ܼ����Ḯ��Ʈ���� -> � ��带 ����, �����ϱ����ؼ��� �׻� �� �� ����� �ּҸ� �˾ƾ� �����ϴ�.

void add_first(char* item);
int add_after(Node* prev, char* item);
int add(int index, char* item);
void add_to_ordered_list(char* item);

Node* remove_first();
Node* remove_after(Node* prev);
Node* remove(int index);
Node* remove(char* item);

Node* find(char* word);
Node* get_node(int index);

int main() {
	/*
	�����δ� �̷��� ������ ���� �ʰ�, �Լ�ȭ �ؼ� ���

	head = (Node*)malloc(sizeof(Node));
	head->data = "Tuesday";
	head->next = NULL;

	Node* q = (Node*)malloc(sizeof(Node));
	q->data = "Thursday";
	q->next = NULL;
	head->next = q;		//	��� �� ���� ����

	//	���� �տ� ����
	q = (Node*)malloc(sizeof(Node));
	q->data = "Monday";
	q->next = head;		//	��� �� ���� ����
	head = q;

	//	��带 ó������ ������ ���鼭 data ���
	Node* p = head;		//	Ž���� ��� ������ p. head �� �׻� ù ��带 ����Ű�� �־���ϱ� ������
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;	//	�ſ� ���� ������ �ڵ� (�� ĭ ����)
	}
	*/
	//add_first("����");

}

//	���Ḯ��Ʈ�� �� �տ� ���ο� ��带 �����ϴ� �Լ�
void add_first(char* item) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = head;
	head = temp;
}

//	������ ��� �ڿ� ���ο� ��带 �����ϴ� �Լ�
//	���Կ� �����ϸ� 1�� ��ȯ, �����ϸ� 0�� ��ȯ
int add_after(Node* prev, char* item) {
	if (prev == NULL) {
		return 0;
	}

	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = prev->next;
	prev->next = tmp;

	return 1;
}

//	ù ��° ��带 �����ϴ� �Լ�
//	������ ����� �ּҸ� ��ȯ
Node* remove_first() {
	if (head == NULL) {
		return NULL;
	}
	else {
		Node* tmp = head;
		head = head->next;
		return tmp;
	}
}

//	������ ����� ���� ��带 �����ϴ� �Լ�
//	�ܼ����Ḯ��Ʈ����, � ��带 ������ ���� ������ ����� �ٷ� �� ����� �ּҰ� �ʿ��ϴ�. ������ ����� �ּҸ����δ� ������ �� ����.
//	������ ����� �ּҸ� ��ȯ
Node* remove_after(Node* prev) {
	Node* tmp = prev->next;
	if (tmp == NULL) {		//	���� ��尡 ���� ��� NULL ��ȯ�ϸ� ����
		return NULL;
	}
	else {
		prev->next = tmp->next;
		return tmp;
	}
}

//	���Ḯ��Ʈ�� ��ȸ�ϴ� �Լ� (traverse)
//	��ȸ�ϴ� ������ �پ��� �� ����. �� �Լ������� �˻��ϴ� ���� ����.
//	ã�����ϴ� ���ڿ��� ������ �ܾ ������ ��� ������ ã�Ƽ� �� ������ �ּҸ� ��ȯ
Node* find(char* word) {
	Node* p = head;		//	head�� �ǵ帮�� �ʱ�!!
	while (p != NULL) {
		if (strcmp(p->data, word) == 0) {	//	p->data �� word �� ���ٸ�
			return p;
			p = p->next;
		}
	}
	return NULL;		//	������ ��ȸ������ �˻��� ���� �ʾ��� ��
}

//	���Ḯ��Ʈ�� ��ȸ�ϴ� �Լ� (traverse)
//	�� �Լ������� index��° ����� �ּҸ� ��� ���� ����.
//	���Ḯ��Ʈ�� index��° ����� �ּҸ� ��ȯ
Node* get_node(int index) {
	if (index < 0) {
		return NULL;
	}
	Node* p = head;		//	head�� �ǵ帮�� �ʱ�!!
	for (int i = 0; i < index && p != NULL; i++) {		//	p != NULL ������ �ɾ, index�� max index�� �Ѿ�� �ʵ��� ��
		p = p->next;
		return p;
	}
}

//	���Ḯ��Ʈ�� index��° ��ġ�� ���ο� ��带 ���� �����ϴ� �Լ�
//	���� �����ϸ� 1�� ��ȯ, �����ϸ� 0�� ��ȯ
//	������ �Լ����� Ȱ��
int add(int index, char* item) {
	if (index < 0) {
		return 0;
	}

	if (index == 0) {
		add_first(item);
		return 1;
	}

	Node* prev = get_node(index - 1);
	if (prev != NULL) {
		add_after(prev, item);
		return 1;
	}
	return 0;
}

//	index��° ��带 �����ϰ�, �� ��忡 ����� �����͸� ��ȯ�ϴ� �Լ�
//	������ �Լ����� Ȱ��
Node* remove(int index) {
	if (index < 0) {
		return NULL;
	}

	if (index == 0) {
		return remove_first();
	}

	Node* prev = get_node(index - 1);
	if (prev == NULL) {
		return NULL;
	}
	else {
		return remove_after(prev);
	}
}

//	�Էµ� ��Ʈ���� ������ ���(���� ���� ��� ���� �տ� �ִ� ���)�� ã�Ƽ� �����ϰ�, ������ ����� �ּҸ� ��ȯ�ϴ� �Լ�
Node* remove(char* item) {
	Node* p = head;
	Node* q = NULL;
	while (p != NULL && strcmp(p->data, item) != 0) {
		q = p;
		p = p->next;
	}
	if (p == NULL) {
		return NULL;
	}
	if (q == NULL) {
		return remove_first();
	}
	else {
		return remove_after(q);
	}
}

//	���Ḯ��Ʈ�� �����͵��� ������������ ���ĵǾ� �ִٴ� �����Ͽ��� ���ο� �����͸� �����ϴ� �Լ�
void add_to_ordered_list(char* item) {
	Node* p = head;
	Node* q = NULL;
	while (p != NULL && strcmp(p->data, item) <= 0) {
		q = p;
		p = p->next;
	}
	if (q == NULL) {
		add_first(item);
	}
	else {
		add_after(q, item);
	}
}