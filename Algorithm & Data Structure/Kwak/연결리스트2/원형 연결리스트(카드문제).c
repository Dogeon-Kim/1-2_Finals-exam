#include <stdio.h> 
#include <stdlib.h>

typedef int element;
typedef struct Node{
	element data;
	struct Node *next;
}Node;

void printList(Node* head){
	Node *p = head->next;
	int count = 0;
	if (head == NULL) return;
	do {
		if(p == NULL) break;
		printf("%d->", p->data);
		p =p->next;
 }while(p!=head->next);
	printf("\n");
}

void insertFirst(Node* head, element data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;//
	if (head == NULL){//리스트에 노드가 없는경우
		head = node; //새로운 노드주소값
		head->next = head; //자신을 순환참조
	}
	else{
		node->next = head->next;//원래 리스트의 첫위치값
		head->next = node;//새로운 노드 주소값 	 
	}
	 
}
Node* insertLast(Node* head, element data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data =data;
	if (head == NULL){
		head = node;
		head->next = head;
	}
	else{
		node->next = head->next;
		head->next = node;
		head = node;
	}
	return head;
}

Node* changeCard(Node* head){
	Node* removed = head->next; //노드삭제위치 저장
  head->next = removed->next; //삭제된 다음 위치와 연결
	free(removed);
	removed=NULL; //없어도 상관X
	return head->next;// 새로운 헤드값으로 리턴
}

int main() {
	Node *head =NULL, *p;
	int n;
	printf("카드개수 입력\n");
 	scanf("%d",&n);
//	printf("마지막위치에 연결\n");
	for(int i = 1;i <= n;i++){
		head = insertLast(head, i);
	}
//	printf("head노드 = %d\n",head->data);
	while(head->next != head){
		head = changeCard(head);
		printList(head);
	}
	 printf("마지막 카드번호 : %d",head->data);
	return 0;
}
