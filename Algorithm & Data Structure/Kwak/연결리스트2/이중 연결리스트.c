#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DNode{
	element data;
	struct DNode* prev;
	struct DNode* next;
}DNode;

void init(DNode* phead){
	phead->prev=phead;
	phead->next=phead;
}

void dinsert(DNode* before,element data){	
	DNode* newnode = (DNode *)malloc(sizeof(DNode));
	newnode->data = data;
	newnode->prev = before;
	newnode->next = before->next;
	before->next->prev=newnode; //이전노드의 넥스트 노드의 prev값을 새로운 노드 주소값으로 저장
	before->next = newnode;//이전노드의 next값을 새로운 노드 주소값으로 저장;
}

void ddelete(DNode* head, DNode* removed){
	if(removed == head) return;
	removed->prev->next = removed->next;
	removed->next->prev = removed->prev;
	free(removed);
}

void printDlist(DNode* phead){
	DNode* p;
	for(p=phead->next; p!=phead; p=p->next){//초기값:head->next, head위치가 아니면 출력
		printf("<-| |%d| |->", p->data);
	}
	printf("\n");
}

int main(void){
	DNode* head = (DNode *)malloc(sizeof(DNode));    
	init(head); //헤드노드 초기화
	printf("추가단계\n");
	for(int i = 0;i< 5;i++){
		dinsert(head, i);
		printDlist(head);
	}
	printf("삭제단계\n");
	for(int i = 0;i<5;i++){
		printDlist(head);
		ddelete(head, head->next);
	}
	free(head);
	return 0;
}
