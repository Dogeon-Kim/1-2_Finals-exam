#include <stdio.h> 
#include <stdlib.h>

typedef int element;
typedef struct Node{
	element data;
	struct Node *next;
}Node;

void printList(Node *head){
	Node *p=head->next;
	int count=0;
	if(head==NULL) return;
	do{
		if(p==NULL) break;
		printf("%d->", p->data);
		p=p->next;
	}while(p!=head->next);
	printf("\n");
}

void insertFirst(Node *head, element data){
	Node *node=(Node*)malloc(sizeof(Node));
	node->data=data;
	if(head==NULL){
		head=node;
		head->next=head;
	}
	else{
		node->next=head->next;
		head->next=node; 	 
	}
}

Node* insertLast(Node *head, element data){
	Node *node=(Node*)malloc(sizeof(Node));
	node->data =data;
	if(head==NULL){
		head=node;
		head->next=head;
	}
	else{
		node->next=head->next;
		head->next=node;
		head=node;
	}
	return head;
}

Node* changeCard(Node *head){
	Node *removed=head->next;
	head->next=removed->next;
	free(removed);
	removed=NULL;
	return head->next;
}

int main(){
	Node *head=NULL, *p;
	int n;
	printf("카드개수 입력\n");
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		head=insertLast(head, i);
	}
	while(head->next!=head){
		head=changeCard(head);
		printList(head);
	}
	printf("마지막 카드번호 : %d", head->data);
	return 0;
}
