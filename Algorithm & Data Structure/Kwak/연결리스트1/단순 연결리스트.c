#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct Node{
	element data;
	struct Node *next;
}Node;

int main(){
	Node *n1, *n2 ,*n3, *head;
	n1 = (Node*)malloc(sizeof(Node));
	n2 = (Node*)malloc(sizeof(Node));
	n3 = (Node*)malloc(sizeof(Node));
	n1->data=10;
	n1->next=n2;
	n2->data=20;
	n2->next=n3;
	n3->data=30;
	n3->next=NULL;
	head=n1;
	while(head != NULL){
			printf("%d->", head->data);
			head=head->next;
    }
}
