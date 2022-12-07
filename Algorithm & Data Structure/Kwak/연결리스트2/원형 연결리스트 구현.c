#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node{
	element data;
	struct Node *next;
}Node;

void printList(Node *head){
	Node *p=head->next;
	int cnt=0;
	if(head==NULL) return;
	do{
		if(p==NULL) break;
		printf("%d->", p->data);
		p=p->next;
		cnt++;
	}while(cnt<10);
	printf("\n");
}

Node* insertFirst(Node *head, element data){
	Node *node=(Node*)malloc(sizeof(Node));
	node->data=data;
	if (head==NULL){
		head=node;
		node->next=head;
	}
	else{
		node->next=head->next;
		head->next=node;
	}
	return head;
}

Node* insertLast(Node *head, element data){
	Node *node=(Node*)malloc(sizeof(Node));
	node->data =data;
	if (head==NULL){
		head=node;
		node->next=head;
	}
	else{
		node->next=head->next;
		head->next=node;
		head=node;
	}
	return head;
}

int main(){
	Node *head=NULL, *tail, *ptr;
	printf("처음위치에 연결\n");
	for(int i = 1;i< 5;i++){
		head = insertFirst(head, i);
	}
	printList(head);
	printf("마지막위치에 연결\n");
	for(int i=11; i<15; i++){
		head = insertLast(head, i);
	}
	printList(head);
	return 0;
}


