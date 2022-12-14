#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node{
	element data;
	struct Node *next;
}Node;

Node* insertFirst(Node *head, element data){
	Node *p=(Node*)malloc(sizeof(Node));
	p->data=data;
	p->next=head;
	head=p;
	return head;
}

Node* insert(Node *head, Node *pre, element data){
	Node *p=(Node*)malloc(sizeof(Node));
	p->data=data;
	p->next=pre->next;
	pre->next=p;
	return head;
}

Node* deleteFirst(Node *head){
	Node *removed;
	if(head==NULL) return NULL;
	removed=head;
	head=removed->next;
	free(removed);
	return head;
}

Node* delete(Node *head, Node *pre){
	Node *removed;
	removed=pre->next;
	pre->next=removed->next;
	free(removed);
	return head;
}

void printList(Node *head){
	for(Node *p=head; p!=NULL; p=p->next) printf("%d->", p->data);
	printf("NULL\n");
}

int main(){
	Node *head=NULL, *temp=NULL;
	printf("[첫 위치 삽입]\n");
	for(int i=0; i<5; i++){
		head = insertFirst(head, i);
		printList(head);
		if(i==2) temp=head;
	}
	printf("[중간위치 삽입]\n");
	head=insert(head, temp, 100); printList(head); printf("[중간위치 삭제]\n");
	head=delete(head, temp); printList(head); printf("[첫 위치 삭제]\n");
	for(int i=0; i<5; i++){
		head=deleteFirst(head);
		printList(head);
	}
	return 0;
}