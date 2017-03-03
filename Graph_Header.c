#include"Graph_Header.h"

/*
graph* initializeGraph();
	function:	create and initialize a graph
*/
graph* createGraph(void){
	graph* aGraph=(graph*)malloc(sizeof(graph));
	return aGraph;
}

void initializeGraph(graph* aGraph){
	int i,j;
	
	if(!aGraph){
		puts("graph doesn't exist!!");
	}
	aGraph->infinity=INFINITYGRAPH;
	aGraph->maxsize=MAXSIZEGRAPH;
	for(i=0;i<aGraph->maxsize;i++){
		for(j=0;j<aGraph->maxsize;j++){
				aGraph->connect[i][j]=aGraph->infinity;
		}
		aGraph->connect[i][i]=0;
		aGraph->visited[i]=0;
	}
}//initializeGraph

void autoInputGraph(graph* aGraph){
	//输入的节点数需要和maxsize对应。
/*
	aGraph->connect[0][1]=aGraph->connect[1][0]=1;
	aGraph->connect[0][2]=aGraph->connect[2][0]=2;
	aGraph->connect[0][3]=aGraph->connect[3][0]=3;
	aGraph->connect[0][5]=aGraph->connect[5][0]=5;
	aGraph->connect[2][3]=aGraph->connect[3][2]=5;
	aGraph->connect[4][6]=aGraph->connect[6][4]=10;
	aGraph->connect[6][7]=aGraph->connect[7][6]=3;
	
	aGraph->connect[4][3]=aGraph->connect[3][4]=7;
*/
/*
	aGraph->connect[0][1]=aGraph->connect[1][0]=1;
	aGraph->connect[1][3]=aGraph->connect[3][1]=4;
	aGraph->connect[1][5]=aGraph->connect[5][1]=6;
	aGraph->connect[2][3]=aGraph->connect[3][2]=5;
	aGraph->connect[2][4]=aGraph->connect[4][2]=6;
	aGraph->connect[3][5]=aGraph->connect[5][3]=8;
	aGraph->connect[5][6]=aGraph->connect[6][5]=6;
	aGraph->connect[6][7]=aGraph->connect[7][6]=8;
*/

	aGraph->connect[0][1]=aGraph->connect[1][0]=1;
	aGraph->connect[0][2]=aGraph->connect[2][0]=12;
	aGraph->connect[0][3]=aGraph->connect[3][0]=3;
	aGraph->connect[0][5]=aGraph->connect[5][0]=5;
	aGraph->connect[1][2]=aGraph->connect[2][1]=3;
	aGraph->connect[2][3]=aGraph->connect[3][2]=5;
	//aGraph->connect[3][7]=aGraph->connect[7][3]=1;
	aGraph->connect[4][6]=aGraph->connect[6][4]=1;
	aGraph->connect[6][7]=aGraph->connect[7][6]=3;

}//autoInputGraph

void inputGraph(graph* aGraph){
	int count;
	int start,end,dist;

	printf("input how many paths:\n");
	scanf("%d",&count);

	while(count--){
		puts("input two cities' number and the distance between them:");
		scanf("%d %d %d",&start,&end,&dist);
		aGraph->connect[start][end]=aGraph->connect[end][start]=dist;
	}
}//inputGraph

void printGraph(graph* aGraph){
	int i,j;

	printf("**********************\n");
	printf("aGraph->maxsize:%d,aGraph->infinity:%d\n",aGraph->maxsize,aGraph->infinity);
	for(i=0;i<aGraph->maxsize;i++){
		for(j=0;j<aGraph->maxsize;j++){
			printf("%6d ",aGraph->connect[i][j]);
		}
		puts("\n");
	}
	puts("\n**********END************\n\n");
}//printGraph

int testGraph(void){
	graph* temp=createGraph();
	initializeGraph(temp);
	printGraph(temp);
	autoInputGraph(temp);
	printGraph(temp);
	inputGraph(temp);
	printGraph(temp);

	return 0;
}//testGraph


//----#include"BfsDfsDijkstraFloyd_Header.h"----
int testBfsDfsDijkstraFloyd_4(void){
	graph* aGraph=createGraph();
	initializeGraph(aGraph);
	autoInputGraph(aGraph);
	printGraph(aGraph);

	floyd(aGraph);

	return 0;
}

int testBfsDfsDijkstraFloyd_3(void){
	graph* aGraph=createGraph();
	initializeGraph(aGraph);
	autoInputGraph(aGraph);
	printGraph(aGraph);

	dijkstra(2,aGraph);

	return 0;
}

int testBfsDfsDijkstraFloyd_2(void){
	graph* aGraph=createGraph();
	initializeGraph(aGraph);
	autoInputGraph(aGraph);
	printGraph(aGraph);

	queue* aQueue;
	aQueue=createQueue();
	printQueue(aQueue);

	dfs(2,aGraph);
	initializeGraph(aGraph);
	puts("---");
	autoInputGraph(aGraph);
	bfs(2,aGraph,aQueue);

	return 0;
}

int testBfsDfsDijkstraFloyd_1(void){
	graph* aGraph;
	aGraph=createGraph();
	initializeGraph(aGraph);
	autoInputGraph(aGraph);
	printGraph(aGraph);

	dfs(2,aGraph);

	return 0;
}


void bfs(int source,graph* aGraph,queue* aQueue){
	if(!aGraph){
		puts("no such a graph!");
		return;
	}else if(!aQueue){
		puts("no such a queue!");
		return;
	}

	aGraph->visited[source]=1;
	enQueue(source,aQueue);

	int count;
	while(!isEmptyQueue(aQueue)){
		source=deQueue(aQueue);
		printf("%d  ",source);
		for(count=0;count<aGraph->maxsize;count++){
			if(!(aGraph->visited[count])
				  && aGraph->connect[count][source]<aGraph->infinity
				  && aGraph->connect[count][source]>0){
				enQueue(count,aQueue);
				aGraph->visited[count]=1;
			}
		}
	}
	puts("-----bfs end-----");
}

void dfs(int source,graph* aGraph){
	if(!aGraph){
		puts("no such a graph!");
		return;
	}
	if(source>=aGraph->maxsize){
		puts("give a non-existing node,that is,source>=aGraph->maxsize!!");
		return;
	}
	int count;

	printf("%d  ",source);
	aGraph->visited[source]=1;
	for(count=0;count<aGraph->maxsize;count++){
		//traverse all the unvisited  reachable(excluding the source) graph node with the source node(1.all,	2.unvisited,  3.reachable,  4.connected with source node)
		if(!aGraph->visited[count]
		   && aGraph->connect[source][count] < (aGraph->infinity)
		   && aGraph->connect[source][count] > 0){
			dfs(count,aGraph);
		}
	}
}

void dijkstra(int source,graph* aGraph){//attention!! every array should renew in while loop
	if(source>=aGraph->maxsize){
		printf("source exceeds the maxsize of graph~~\n");
		return;
	}

	int dist[aGraph->maxsize];
	int path[aGraph->maxsize];

	//initialize record array
	int i,i2;
	for(i=0;i<aGraph->maxsize;i++){
		dist[i]=aGraph->infinity;
		path[i]=-2;//equals -2 representing invalid path,-1 connected with source
		aGraph->visited[i]=0;
	}

	//first node
	int minElem=source;
	int minDist;
	path[source]=-1;
	dist[source]=0;
	while(1){
		//find nearest graph node
		minDist=aGraph->infinity;
		for(i=0;i<aGraph->maxsize;i++){
			if(!aGraph->visited[i] && minDist>dist[i]){
				minDist=dist[i];
				minElem=i;
			}
		}
		if(minDist==aGraph->infinity)break;
		aGraph->visited[minElem]=1;

		//renew all the distance to source
		for(i=0;i<aGraph->maxsize;i++){
			if(!aGraph->visited[i]
			    && aGraph->connect[i][minElem]+dist[minElem]<dist[i]){
			    path[i]=minElem;
				dist[i]=aGraph->connect[i][minElem]+dist[minElem];
			}
		}
	}

	//print
	for(i=0;i<aGraph->maxsize;i++){
		printf("dist[%d]:%d \n",i,dist[i]);
	}
	printf("\n\n");
	for(i=0;i<aGraph->maxsize;i++){
		printf("visited[%d]:%d\n",i,aGraph->visited[i]);
	}
	printf("\n\n");
	for(i=0;i<aGraph->maxsize;i++){
		printf("path[%d]:%d \n",i,path[i]);
		//printf("%c",(i%3==0)?'\n':' ');
	}

	puts("\n**********END************\n\n");
}

void floyd(graph* aGraph){
	int dist[aGraph->maxsize][aGraph->maxsize];
	int path[aGraph->maxsize][aGraph->maxsize];
	int i,j,k;

	//initialize
	for(i=0;i<aGraph->maxsize;i++){
		for(j=0;j<aGraph->maxsize;j++){
			dist[i][j]=aGraph->connect[i][j];
			path[i][j]=-1;
		}
	}

	//
	for(k=0;k<aGraph->maxsize;k++){
		for(i=0;i<aGraph->maxsize;i++){
			for(j=0;j<aGraph->maxsize;j++){
				if(dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
					path[i][j]=k;
				}
			}
		}
	}

	//print
	for(i=0;i<aGraph->maxsize;i++){
		for(j=0;j<aGraph->maxsize;j++){
			printf("%7d ",dist[i][j]);
		}
		printf("\n");
	}
	puts("");
	for(i=0;i<aGraph->maxsize;i++){
		for(j=0;j<aGraph->maxsize;j++){
			printf("%7d ",path[i][j]);
		}
		printf("\n");
	}
}

//--------
void listComponentsDfs(graph* g){
	int i;
	for(i=0;i<g->maxsize;i++){
		if(!g->visited[i]){
			dfs(i,g);
			printf("\n--one list componet ends\n");
		}
	}
}

void listComponentsBfs(graph* g,queue* q){
	int i;
	for(i=0;i<g->maxsize;i++){
		if(!g->visited[i]){
			bfs(i,g,q);
			printf("\n");
		}
	}
}

int testListComponents_1(){
	graph* aGraph;
	aGraph=createGraph();
	initializeGraph(aGraph);
	autoInputGraph(aGraph);
	printGraph(aGraph);
	
	listComponentsDfs(aGraph);
	
	return 0;
}

int testListComponents_2(){
	graph* aGraph;
	aGraph=createGraph();
	initializeGraph(aGraph);
	autoInputGraph(aGraph);
	printGraph(aGraph);

	queue* aQueue;
	aQueue=createQueue();
	printQueue(aQueue);

	listComponentsBfs(aGraph,aQueue);

	return 0;
}

//----mst----
void prim(int source,graph* g){
	if(source>=g->maxsize){
		printf("source exceeds the maxsize of graph~~\n");
		return;
	}

	int mst[g->maxsize];
	int dist[g->maxsize];
	int path[g->maxsize];
	
	//initialize record array
	int i;
	for(i=0;i<g->maxsize;i++){
		dist[i]=g->infinity;
		path[i]=-2;//equals -2 representing invalid path,-1 connected with source
		g->visited[i]=0;
		mst[i]=-1;
	}
	
	
	path[source]=-1;
	dist[source]=0;
	int min,minElem;
	int i2=0;
	while(1){
		min=g->infinity;
		minElem=-1;
		for(i=0;i<g->maxsize;i++){
			if(!g->visited[i] && dist[i]<min){
				min=dist[i];
				minElem=i;
			}
		}
		if(minElem==-1){
			printf("while loop end\n");
			break;
		}
		
		/*
		g->visited[minElem]=1;
		mst[i2++]=minElem;
		
		//renew
		for(i=0;i<g->maxsize;i++){
			if(!g->visited[i] && g->connect[i][minElem]+dist[minElem]<dist[i]){
				dist[i]=g->connect[i][minElem]+dist[minElem];
				path[i]=minElem;
			}
		}
		*/
		g->visited[minElem]=1;
		mst[i2++]=minElem;
		dist[minElem]=0;
		
		for(i=0;i<g->maxsize;i++){
			if(dist[i]!=0){
				if(g->connect[minElem][i]<dist[i]){
					dist[i]=g->connect[minElem][i];
					path[i]=minElem;
				}
			}
		}
	}
	
	if(i2!=g->maxsize){
		printf("mst doesn't exist!");
		return;
	}
	//print
	for(i=0;i<g->maxsize;i++){
		printf("dist[%d]:%d \n",i,dist[i]);
	}
	printf("\n\n");
	for(i=0;i<g->maxsize;i++){
		printf("visited[%d]:%d\n",i,g->visited[i]);
	}
	printf("\n\n");
	for(i=0;i<g->maxsize;i++){
		printf("path[%d]:%d \n",i,path[i]);
		//printf("%c",(i%3==0)?'\n':' ');
	}
	printf("\n\n");
	for(i=0;i<g->maxsize;i++){
		printf("mst[%d]:%d \n",i,mst[i]);
		//printf("%c",(i%3==0)?'\n':' ');
	}
	
	puts("\n**********END************\n\n");
	
}

void kruskal(graph* g,minHeap* edges){
	sets* s=createSets();
	initializeSets(s);
	printSets(s);
	
	edge* mst[g->maxsize];//收入的是edge
	int i=0;//mst is empty at the beginning
	edge* e;
	while(i<g->maxsize-1 && edges->elemNum!=0){//g->maxsize-1 means the number of edges
		e=deleteElemMinHeap(edges);
		printMinHeap(edges);
		if(findElem_Sets(s,e->source)==s->invalidData){
			addElem_Sets(e->source,-1,s);
		}
		if(findElem_Sets(s,e->destination)==s->invalidData){
			addElem_Sets(e->destination,-1,s);
		}
		if(findElem_Sets(s,e->source)!=findElem_Sets(s,e->destination)){
			mst[i++]=e;
			union_Sets(s,e->source,e->destination);//e->destination should be smaller than e->source,is this comprehension right?
			printSets(s);
		}else{
			
		}
	}
	int j=i;
	i=0;
	printf("\nmst[i]:weight(source,destination):\n");
	while(i<j){
		printf("mst[%d]:%d(%d,%d)\n",i,mst[i]->weight,mst[i]->source,mst[i]->destination);
		i++;
	}
	if(j<g->maxsize-1){
		printf("\nthe mst doesn't exist!\n");
	}
	printf("----------kruskal end---------\n\n");
	return;
}

int testKruskal(){
	graph* aGraph;
	aGraph=createGraph();
	initializeGraph(aGraph);
	autoInputGraph(aGraph);
	printGraph(aGraph);

	minHeap* h=createMinHeap();
	initializeMinHeap(h);
	printMinHeap(h);
	
	int i,j;//thie loop has some errors!!!!!!!

	edge* edgeOfHeap=NULL;
	for(i=0;i<aGraph->maxsize;i++){
		for(j=i+1;j<aGraph->maxsize;j++){
			if(aGraph->connect[i][j]!=aGraph->infinity){
				edgeOfHeap=(edge*)malloc(sizeof(edge));
				edgeOfHeap->weight=aGraph->connect[i][j];
				edgeOfHeap->source=i;
				edgeOfHeap->destination=j;
				addElemMinHeap(edgeOfHeap,h);
				printMinHeap(h);
				if(h->elemNum>h->capacity){
					printf("heap is full");
					i=j=aGraph->maxsize;
				}
			}
		}
	}
	printMinHeap(h);

	kruskal(aGraph,h);
	printMinHeap(h);

	return 0;
}

int testPrim(){
	graph* aGraph;
	aGraph=createGraph();
	initializeGraph(aGraph);
	autoInputGraph(aGraph);
	printGraph(aGraph);

	prim(0,aGraph);
	
	return 0;
}


