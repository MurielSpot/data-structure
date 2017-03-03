#include"Heap_Header.h"

/*
minHeap* createMinHeap(){
	return (minHeap*)malloc(sizeof(minHeap));
}

void initializeMinHeap(minHeap* h){
	h->maxsize=MAXSIZEMINHEAP-1;
	h->elemNum=0;
	h->negativeInfinity=NEGATIVEINFINITYMINHEAP;
	h->minHeapArray[0]=h->negativeInfinity;
}

void printMinHeap(minHeap* h){
	int i;
	printf("\n-----------begin------------\n"
		   "h->maxsize=%d,h->elemNum=%d,"
		   "h->minHeapArray[0]=%d\n\n"
		   "h->minHeapArray[]:",h->maxsize,h->elemNum,h->minHeapArray[0]);
	for(i=1;i<=h->elemNum;i++){
		if(h->minHeapArray[i])
			printf("%d ",h->minHeapArray[i]);
		else break;
	}
	printf("\n------------end-------------\n\b");
}


int isFullMinHeap(minHeap* h){
	if(h->elemNum>=h->maxsize){
		printf("minHeap is full!\n");
		return 1;
	}
	return 0;
}

int isEmptyMinHeap(minHeap* h){
	if(h->elemNum){
		return 0;
	}
	printf("minHeap is empty!\n");
	return 1;
}

void addElemMinHeap(elemType data,minHeap* h){
	if(!h){
		printf("minHeap doesn't exist!\n");
		return;
	}
	if(isFullMinHeap(h)){
		return;
	}
	int temp=++h->elemNum;
	while(temp/2 && data<h->minHeapArray[temp/2]){
		h->minHeapArray[temp]=h->minHeapArray[temp/2];
		temp=temp/2;
	}
	h->minHeapArray[temp]=data;
}

elemType deleteElemMinHeap(minHeap* h){
	if(!h){
		printf("minHeap doesn't exist!\n");
		return h->negativeInfinity;
	}
	if(isEmptyMinHeap(h)){
		return h->negativeInfinity;
	}

	//store the minest data
	elemType dataStore=h->minHeapArray[1];
	if(h->elemNum==1){
		h->elemNum--;
		return dataStore;
	}

	//delete the last data from minheap	
	int tempData=h->minHeapArray[h->elemNum--];
	
	//renew minheap
	int parent=1,child;
	while(parent*2<=h->elemNum){
		child=parent*2;
		if(child!=h->elemNum && h->minHeapArray[child]>h->minHeapArray[child+1]){
			child++;
		}
		if(h->minHeapArray[child]>=tempData){
			break;
		}
		h->minHeapArray[parent]=h->minHeapArray[child];
		parent=child;
	}
	h->minHeapArray[parent]=tempData;
	
	return dataStore;
}

int testMinHeap1(){
	int i,j;
	minHeap* h=createMinHeap();
	initializeMinHeap(h);
	printMinHeap(h);
	//isEmptyMinHeap(h);

	addElemMinHeap(10,h);
	addElemMinHeap(1,h);
	addElemMinHeap(-1,h);
	addElemMinHeap(-10,h);
	addElemMinHeap(-11,h);
	printMinHeap(h);
	
	printf("%d ",deleteElemMinHeap(h));
	printMinHeap(h);
	printf("%d ",deleteElemMinHeap(h));
	printMinHeap(h);
	printf("%d ",deleteElemMinHeap(h));
	printMinHeap(h);
	printf("%d ",deleteElemMinHeap(h));
	printMinHeap(h);
	printf("%d ",deleteElemMinHeap(h));
	printMinHeap(h);
	printf("%d ",deleteElemMinHeap(h));
	printMinHeap(h);
	return 0;
}
*/

//minheap--------------------
minHeap* createMinHeap(void){
	return (minHeap*)malloc(sizeof(minHeap));
}

void initializeMinHeap(minHeap* h){
	h->capacity=CAPACITYMINHEAP-1;
	h->elemNum=0;
	h->negativeInfinity=NEGATIVEINFINITYMINHEAP;
	int i;
	for(i=0;i<=h->capacity;i++){
		h->minHeapArray[i]=NULL;
	}
}

void printMinHeap(minHeap* h){
	int i;
	printf("\n---------minheap begin----------\n"
		   "h->capacity=%d,h->elemNum=%d,CAPACITY_MINHEAP=%d\n"
		   "h->minHeapArray[0]=NULL\n\n"
		   "h->minHeapArray[]:weight(source,destination):\n",h->capacity,h->elemNum,CAPACITYMINHEAP);
	for(i=1;i<=h->elemNum;i++){
		if(h->minHeapArray[i])
			printf("%d(%d,%d)\n",
					h->minHeapArray[i]->weight,
					h->minHeapArray[i]->source,
					h->minHeapArray[i]->destination);
		else break;
	}
	printf("\n----------minheap end-----------\n\n");
}

int isFullMinHeap(minHeap* h){
	if(h->elemNum>=h->capacity){
		printf("minHeap is full!\n");
		return 1;
	}
	return 0;
}

int isEmptyMinHeap(minHeap* h){
	if(h->elemNum){
		return 0;
	}
	printf("minHeap is empty!\n");
	return 1;
}

void addElemMinHeap(edge* ht,minHeap* h){
	if(!h){
		printf("minHeap doesn't exist!\n");
		return;
	}
	if(isFullMinHeap(h)){
		return;
	}
	edge* restore=ht;//因为是传引用调用，所以移动数组2的值到1时，ht会改变，最后赋值就出错了h->minHeapArray[temp]->weight=ht->weight;
	int temp=++h->elemNum;
	while(temp/2 && restore->weight<h->minHeapArray[temp/2]->weight){
		h->minHeapArray[temp]=h->minHeapArray[temp/2];
		temp=temp/2;
	}
	h->minHeapArray[temp]=restore;
}

edge* deleteElemMinHeap(minHeap* h){
	if(!h){
		printf("minHeap doesn't exist!\n");
		return NULL;
	}
	if(isEmptyMinHeap(h)){
		return NULL;
	}

	//store the minest node
	edge* minEdge=h->minHeapArray[1];
	
	//if only one node left,delete it straight
	if(h->elemNum==1){
		h->minHeapArray[1]=NULL;
		h->elemNum--;
		return minEdge;
	}

	//delete the last node from minheap
	edge* tempNode=h->minHeapArray[h->elemNum];
	h->minHeapArray[h->elemNum]=NULL;
	h->elemNum--;
	
	//renew minheap
	int parent=1,child;
	while(parent*2<=h->elemNum){
		child=parent*2;
		if(child!=h->elemNum && h->minHeapArray[child]->weight>h->minHeapArray[child+1]->weight){
			child++;
		}
		if(h->minHeapArray[child]->weight>=tempNode->weight){
			break;
		}
		h->minHeapArray[parent]=h->minHeapArray[child];
		parent=child;
	}
	h->minHeapArray[parent]=tempNode;
	
	return minEdge;
}
//minheap end--------------------

//test--------------------

int testHeap_2(){
	int i=1;
	minHeap* h=createMinHeap();
	initializeMinHeap(h);
	printMinHeap(h);
	isEmptyMinHeap(h);

	edge* e;
	e=(edge*)malloc(sizeof(edge));
	e->weight=10;
	addElemMinHeap(e,h);
	printMinHeap(h);

	e=(edge*)malloc(sizeof(edge));
	e->weight=18;
	addElemMinHeap(e,h);
	printMinHeap(h);

	e=(edge*)malloc(sizeof(edge));
	e->weight=16;
	addElemMinHeap(e,h);
	printMinHeap(h);

	e=(edge*)malloc(sizeof(edge));
	e->weight=188;
	addElemMinHeap(e,h);
	printMinHeap(h);


	e=(edge*)malloc(sizeof(edge));
	e->weight=17;
	addElemMinHeap(e,h);
	printMinHeap(h);

	e=(edge*)malloc(sizeof(edge));
	e->weight=7;
	addElemMinHeap(e,h);
	printMinHeap(h);

	e=(edge*)malloc(sizeof(edge));
	e->weight=26;
	addElemMinHeap(e,h);
	printMinHeap(h);
	
	e=(edge*)malloc(sizeof(edge));
	e->weight=108;
	addElemMinHeap(e,h);
	printMinHeap(h);

	printf("\n");

	printf("%d ",deleteElemMinHeap(h)->weight);
	printf("%d ",deleteElemMinHeap(h)->weight);
	printf("%d ",deleteElemMinHeap(h)->weight);
	printf("%d ",deleteElemMinHeap(h)->weight);
//	printf("%d ",deleteElemMinHeap(h)->weight);
//return null,to get weight will be wrong
	return 0;
}

int testHeap_1(){
	int i=1;
	minHeap* h=createMinHeap();
	initializeMinHeap(h);
	printMinHeap(h);
	isEmptyMinHeap(h);

	h->minHeapArray[i]=(edge*)malloc(sizeof(edge));
	h->minHeapArray[i]->weight=10;
	addElemMinHeap(h->minHeapArray[i],h);
	printMinHeap(h);
	i++;

	h->minHeapArray[i]=(edge*)malloc(sizeof(edge));
	h->minHeapArray[i]->weight=7;
	addElemMinHeap(h->minHeapArray[i],h);
	printMinHeap(h);
	i++;

	h->minHeapArray[i]=(edge*)malloc(sizeof(edge));
	h->minHeapArray[i]->weight=9;
	addElemMinHeap(h->minHeapArray[i],h);
	printMinHeap(h);
	i++;

	h->minHeapArray[i]=(edge*)malloc(sizeof(edge));
	h->minHeapArray[i]->weight=1;
	addElemMinHeap(h->minHeapArray[i],h);
	printMinHeap(h);
	i++;

	h->minHeapArray[i]=(edge*)malloc(sizeof(edge));
	h->minHeapArray[i]->weight=-1;
	addElemMinHeap(h->minHeapArray[i],h);
	printMinHeap(h);
	i++;

	printf("\n");
	
	printf("%d ",deleteElemMinHeap(h)->weight);
	printf("%d ",deleteElemMinHeap(h)->weight);
	printf("%d ",deleteElemMinHeap(h)->weight);
	printf("%d ",deleteElemMinHeap(h)->weight);
//	printf("%d ",deleteElemMinHeap(h)->weight);
//return null,to get weight will be wrong
	return 0;
}
