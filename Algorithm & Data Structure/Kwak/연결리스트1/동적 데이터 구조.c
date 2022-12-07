#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node *next;
}Node;

Node* createNode(element data);

void printAll(Node *ptr);

int main(){
	Node *head, *node1,*node2, *node3;
	node1=createNode(12);
	node2=createNode(99);
	node3=createNode(37);
	node1->next=node2;
	node2->next=node3;
	head=node1;
	printAll(node1);
}

Node* createNode(element data){
	Node *newnode;
	newnode=(Node*)malloc(sizeof(Node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}

void printAll(Node *ptr){
	while(ptr){
		if(ptr->next!=NULL){
			printf("%d->", ptr->data);
			ptr=ptr->next;
		}
		else{
			printf("%d", ptr->data);
			return;
		}
	}
}