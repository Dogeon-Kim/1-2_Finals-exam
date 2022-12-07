#include <stdio.h>
#include<stdlib.h>
#define MAX 200

typedef int element;
typedef struct{
	element heap[MAX];
	int heap_size;
}HeapType;

void insertMaxHeap(HeapType *h, element item){
	int i;
	i=++(h->heap_size);
	while((i!=1) && (item>h->heap[i/2])){
		h->heap[i]=h->heap[i/2];
		i=i/2;
	}
	h->heap[i]=item;
}

element deleteMaxHeap(HeapType *h){ 
	int parent, child;
	element item, temp;
	item=h->heap[1];
	temp=h->heap[(h->heap_size)--];
	parent=1; child=2;
	while(child<=h->heap_size){
		if(child<h->heap_size && h->heap[child]<h->heap[child+1]) child++;	
		if(temp>=h->heap[child]) break;
		h->heap[parent]=h->heap[child];
		parent=child;
		child*=2;
	}
	h->heap[parent]=temp;
	return item;
}

void printHeap(HeapType *heap){
	for(int i=1; i<=heap->heap_size; i++) printf("[%d]: %d ", i, heap->heap[i]);
	printf("\n");
}

int main(){
	element e1=10, e2=5, e3=30;
	HeapType *heap=(HeapType*)malloc(sizeof(HeapType));
	heap->heap_size=0;
	printf("최대힙 삽입\n");
	insertMaxHeap(heap,e1);	printHeap(heap);
	insertMaxHeap(heap,e2);	printHeap(heap);
	insertMaxHeap(heap,e3);	printHeap(heap);
	printf("최대힙 삭제\n");
	printHeap(heap);
	deleteMaxHeap(heap);	printHeap(heap);
	deleteMaxHeap(heap);	printHeap(heap);
	deleteMaxHeap(heap);	printHeap(heap);
	free(heap);
	return 0;
}