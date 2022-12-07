#include<stdio.h>
#include<stdlib.h> 
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphType{
	int n;
	int adjMatrix[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int visited[MAX_VERTICES];

void init(GraphType *g){
	g->n=0;
	for(int r=0; r<MAX_VERTICES; r++) for(int c=0; c<MAX_VERTICES; c++) g->adjMatrix[r][c]=0;
} 

void insertVertex(GraphType *g, int v){
	if(g->n+1 > MAX_VERTICES){
		printf("그래프: 정점의 개수 초과\n");
		return; 
	}
	g->n++;
} 

void insertEdge(GraphType *g, int s, int e) {
	if(s >= MAX_VERTICES || e >= MAX_VERTICES){
		printf("그래프: 정점번호 오류\n");
		return; 
	}
	g->adjMatrix[s][e]=1;
	g->adjMatrix[e][s]=1;
}
void printAdjMatrix(GraphType* g){
	for(int i=0;i<g->n;i++){
		for(int j=0;j<g->n;j++) printf("%2d ",g->adjMatrix[i][j]);
		printf("\n");
	}
}

void dfsMatrix(GraphType* g, int v){
	int w;
	visited[v]=1;
	printf("정점 %d -> ", v);
	for (w=0; w<g->n; w++) if (g->adjMatrix[v][w]==1 && visited[w]==0) dfsMatrix(g,w);
}

int main(){
	GraphType* g;
	g=(GraphType*)malloc(sizeof(GraphType));
	init(g);
	for(int i=0; i<4; i++) insertVertex(g, i);
	insertEdge(g, 0, 1);
	insertEdge(g, 0, 2);
	insertEdge(g, 0, 3);	
	insertEdge(g, 1, 2);	
	insertEdge(g, 2, 3);
	printf("깊이 우선탬색 \n");
	dfsMatrix(g, 0);
	free(g);	
	return 0;
}
