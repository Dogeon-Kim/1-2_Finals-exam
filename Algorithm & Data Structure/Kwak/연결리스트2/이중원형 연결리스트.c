#include <stdio.h>
#include <stdlib.h>

typedef struct DNode{
	int index;
	int data;
	struct DNode *prev;
	struct DNode *next;
}DNode;

typedef struct Head{
	int size;
	DNode *link;
}Head;

void insertLast(Head *head, int data);
void deleteNode(Head *head);

int main(){
	Head *head=(Head*)malloc(sizeof(Head));
	head->link=NULL;
	head->size=0;
	int size, num;
	scanf("%d", &size);
	for(int i=0; i<size; i++){
		scanf("%d", &num);
		insertLast(head, num);
	}
	for(int i=0; i<size; i++) deleteNode(head);
	free(head->link);
	free(head);
	return 0;
}

void insertLast(Head *phead, int data){
	DNode *head=phead->link;
	DNode *newNode=(DNode*)malloc(sizeof(DNode));
	newNode->data=data;
	newNode->index=phead->size+1;
	if(head==NULL){
		phead->link=newNode;
		newNode->prev=newNode;
		newNode->next=newNode;
	}
	else{	
		newNode->prev=head->prev;
		newNode->next=head;
		head->prev->next=newNode;
		head->prev=newNode;
	}
	phead->size++;
}

void deleteNode(Head *phead){
	DNode *head=phead->link;
	int index=head->index;
	int count = head->data;
	printf("%d ", index);
	if(phead->size==1){
		phead->size--;
		return;
	}
	DNode *removed=head;
	DNode *p=head;
	if(count>0){
		for(int i=0; i<count; i++){
			p=p->next;
			if(p==removed) p=p->next;
		}
	}
	else{
		for(int i=0; i<count*(-1); i++){
			p=p->prev;
			if(p==removed) p=p->prev;
		}
	}
	phead->link = p;
	removed->prev->next = removed->next;
	removed->next->prev = removed->prev;
	free(removed);
	phead->size--;
}

void printList(Head *phead){
	DNode *p=phead->link;
	do{
		printf("[%d] ->", p->data);
		p=p->next;	
	}while(p!=phead->link);
}