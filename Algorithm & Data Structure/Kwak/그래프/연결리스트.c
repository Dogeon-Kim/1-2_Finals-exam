#include <stdio.h>
#define MAX_VERTEX 30

typedef struct GraphNode{
	int vertex;
	struct GraphNode *link;
}GraphNode;
typedef struct GraphType{
	int n;
	GraphNode *adjList[MAX_VERTEX];
}GraphType;

void createGraph(GraphType *g){
	g->n=0;
	for(int v=0; v<MAX_VERTEX; v++) g->adjList[v]=NULL;
}

void insertVertex(GraphType *g, int v){
	if(((g->n)+1)>MAX_VERTEX){
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	g->n++;
}

void insertEdge(GraphType *g, int u, int v){
	GraphNode *node;
	if(u >= g->n || v >= g->n){
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	node=(GraphNode*)malloc(sizeof(GraphNode));
	node->vertex=v;
	node->link=g->adjList[u];
	g->adjList[u]=node;
}

void print_adjList(GraphType *g){
	GraphNode *p;
	for(int i=0; i<g->n; i++){
		printf("\n정점 %C의 인접리스트 ", i+65);
		p=g->adjList[i];
		while(p!=NULL){
			printf(" -> %c", p->vertex+65);
			p=p->link;
		}
	}
}

int main(){
	GraphType *G;
	G=(GraphType*)malloc(sizeof(GraphType));
	createGraph(G); 
	for(int i=0; i<4; i++) insertVertex(G, i);
	insertEdge(G, 0, 1);
	insertEdge(G, 1, 3);
	insertEdge(G, 1, 2);
	insertEdge(G, 1, 0);
	insertEdge(G, 2, 3);
	insertEdge(G, 2, 1);
	insertEdge(G, 3, 2);
	insertEdge(G, 3, 1);
	printf("<G의 인접 리스트>");
	print_adjList(G);
    return 0;
} 