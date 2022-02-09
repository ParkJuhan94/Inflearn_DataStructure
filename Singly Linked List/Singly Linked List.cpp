#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {			//	'자기 참조형 구조체'
	const char* data;	//	'상수문자열'의 포인트변수
	struct node* next;	//	다음 노드의 주소를 저장할 필드 
};
typedef struct node Node;

Node* head = NULL;		//	연결리스트의 첫 번째 노드의 주소를 저장할 포인터. 
						//	전역 변수로 두는 것이 여러 함수에서 사용하기에 편리하다.
						//	main 에서 지역 변수로 head를 선언하고 사용한다면, 함수에서 head의 주솟값을 매개 변수로 받아야한다. 

//	연결리스트의 맨 앞에 새로운 노드를 삽입하는 함수
void add_first(char* item) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = head;
	head = temp;
}

//	지정한 노드 뒤에 새로운 노드를 삽입하는 함수
//	삽입에 성공하면 1을 반환, 실패하면 0을 반환
int add_after(Node *prev, char *item) {
	if (prev == NULL) {
		return 0;
	}

	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = prev->next;
	prev->next = tmp;

	return 1;
}

//	첫 번째 노드를 삭제하는 함수
//	삭제한 노드의 주소를 반환
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

//	지정한 노드의 다음 노드를 삭제하는 함수
//	단순연결리스트에서, 어떤 노드를 삭제할 때는 삭제할 노드의 바로 앞 노드의 주소가 필요하다. 삭제할 노드의 주소만으로는 삭제할 수 없다.
//	삭제한 노드의 주소를 반환
Node* remove_after(Node *prev) {
	Node* tmp = prev->next;
	if (tmp == NULL) {		//	다음 노드가 없을 경우 NULL 반환하며 종료
		return NULL;
	}
	else {
		prev->next = tmp->next;
		return tmp;
	}
}

//	연결리스트를 순회하는 함수 (traverse)
//	순회하는 목적은 다양할 수 있음. 이 함수에서는 검색하는 것이 목적.
//	찾고자하는 문자열과 동일한 단어를 저장한 모든 노드들을 찾아서 그 노드들의 주소를 반환
Node* find(char *word) {
	Node* p = head;
	while (p != NULL) {
		if (strcmp(p->data, word) == 0) {	//	p->data 와 word 가 같다면
			return p;
			p = p->next;
		}
	}
	return NULL;		//	끝까지 순회했지만 검색이 되지 않았을 때
}








int main() {
	/*
	실제로는 이렇게 일일이 쓰지 않고, 함수화 해서 사용

	head = (Node*)malloc(sizeof(Node));
	head->data = "Tuesday";
	head->next = NULL;

	Node* q = (Node*)malloc(sizeof(Node));
	q->data = "Thursday";
	q->next = NULL;
	head->next = q;		//	노드 두 개를 연결

	//	제일 앞에 삽입
	q = (Node*)malloc(sizeof(Node));
	q->data = "Monday";
	q->next = head;		//	노드 두 개를 연결
	head = q;

	//	노드를 처음부터 끝까지 돌면서 data 출력
	Node* p = head;		//	탐색용 노드 포인터 p. head 는 항상 첫 노드를 가리키고 있어야하기 때문에
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;	//	매우 자주 나오는 코드 (한 칸 전진)
	}
	*/
	
}