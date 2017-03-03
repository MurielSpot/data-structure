#ifndef _GRAPH_HEADER_H_
#define _GRAPH_HEADER_H_
/*
  *
  *初始化一个图，可重用
  *
  */
#include<stdio.h>
#include<stdlib.h>

#include"Queue_Header.h"
#include"Set_Header(unfinished).h"
#include"Heap_Header.h"

#define MAXSIZEGRAPH 8
#define INFINITYGRAPH 10000

typedef struct graph{
	int infinity;
	int maxsize;//means the element number in the graph
	int connect[MAXSIZEGRAPH][MAXSIZEGRAPH];
	int visited[MAXSIZEGRAPH];
}graph;

graph* createGraph(void);
void initializeGraph(graph* aGraph);
void inputGraph(graph* aGraph);
void printGraph(graph* aGraph);
void autoInputGraph(graph* aGraph);

int testGraph(void);

/**
 *title:	traverse graph & the shortest path
 */

void dfs(int source,graph* aGraph);
void bfs(int source,graph* aGraph,queue* aQueue);
void dijkstra(int source,graph* aGraph);
void floyd(graph* aGraph);

int testBfsDfsDijkstraFloyd_1(void);
int testBfsDfsDijkstraFloyd_2(void);
int testBfsDfsDijkstraFloyd_3(void);
int testBfsDfsDijkstraFloyd_4(void);

//--------
void listComponentsDfs(graph* g);
void listComponentsBfs(graph* g,queue* q);

int testListComponents_1();
int testListComponents_2();

//----Minimum Spanning Tree----
void prim(int source,graph* g);
void kruskal(graph* g,minHeap* edge);

#endif
