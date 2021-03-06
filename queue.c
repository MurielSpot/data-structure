/*
 类型名称 ：队列(Queue)
 
 数据对象集： 一个有0 个或多个元素的有穷线性表。
 
 操作集 ：长度为MaxSize 的队列Q ? ? Queue ，队列元素item ? ? ElementType
    1 、Queue* CreatQueue( int MaxSize ) ：生成长度为MaxSize 的空队列；
    2 、int IsFullQ( Queue* q ) ：判断队列Q 是否已满；
    3 、void EnQueue( ElementType item, Queue* q) ：  将数据元素item 插入队列Q 中；
    4 、int IsEmptyQ( Queue* q ) ：  判断队列Q 是否为空；
    5 、ElementType DeQueue( Queue* q ) ：将队头数据元素从队列中删除并返回。
    6 、void printQ(Queue *q)：打印队列
 */
#include"queue.h"
#include<stdio.h>
#include<stdlib.h>

#define PRINT_HELP_TO_DEBUG 0
#define FUNCTION_END_PROMPT 0
#define MAIN 0

#if MAIN
int main(void)
{
	Queue* q;
	int elem,i,capacity;
 
	puts("capacity/MaxSize:");
	scanf("%d",&capacity);	
	q=CreateQueue(capacity);
	
	puts("0 to end,1 to EnQueue,2 to DeQueue,3 to print:");
	scanf("%d",&i);//输入字母时会出错
	
	while(i){
	if(i==1){
		puts("EnQueue elem:");
		scanf("%d",&i);
		EnQueue(i,q);
	}else if(i==2){
		printf("get elem:%d\n",elem=DeQueue(q));
	}else if(i==3){
		printQ(q);
	}
	puts("0 to end,1 to EnQueue,2 to DeQueue,3 to print:");
	scanf("%d",&i);
	}
	
	return 0;
}//main
#endif

void printQ(Queue *q){
	if(!q->first){
		printf("empty!\nq->first=%d,q->last=%d,q->elemNum=%d,q->capacity=%d\n",q->first,q->last,q->elemNum,q->capacity);
		
		printf("\n-----print end-----\n\n");
		return;
	}
	
	int i=q->elemNum;
	QNode *temp=q->first;
	printf("temp=q->first=%d\n",temp);
	while(i--){
		printf("%d ",temp->data);
		temp=temp->next;
	}
#if FUNCTION_END_PROMPT
	printf("\n-----print end-----\n\n");
#endif
}//printQ

Queue* CreateQueue(int MaxSize){
	Queue *q=(Queue*)malloc(sizeof(Queue));
	q->first=NULL;	//q->first,q->last指向QNode元素
	q->last=NULL;
	q->elemNum=0;
	q->capacity=MaxSize;
	
#if PRINT_HELP_TO_DEBUG
	printf("q->first=%d,q->last=%d,q->elemNum=%d,q->capacity=%d\n",
			q->first,q->last,q->elemNum,q->capacity);
#endif
#if FUNCTION_END_PROMPT
	puts("\n--------CreateQueue end!--------\n");
	return q;
#endif
}//CreateQueue

void EnQueue(int x,Queue *q){
	QNode *temp;
	
	if(IsFullQ(q)){
		return;	//不能返回NULL，因为q是指向头结点的，事实上根本不需要返回值 
	}
	
	temp=(QNode*)malloc(sizeof(QNode));
	temp->data=x;
	temp->next=NULL;
	
	q->elemNum++;
	if(!q->first){
		q->first=temp;
		q->last=temp;
	}else{
		(q->last)->next=temp;
		q->last=temp;
	}
	
#if PRINT_HELP_TO_DEBUG
	printf("temp=%d,temp->data=%d,temp->next=%d\n",
			temp,temp->data,temp->next);
#endif

#if PRINT_HELP_TO_DEBUG
	printf("q->first=%d,q->last=%d,q->elemNum=%d,q->capacity=%d\n",
			q->first,q->last,q->elemNum,q->capacity);
#endif
#if FUNCTION_END_PROMPT
	puts("\n--------EnQueue end!--------\n");
#endif
}//EnQueue

int DeQueue(Queue* q){//有错误 
	QNode *temp;
	int elem;
	
	if(IsEmptyQ(q)){
		return infiniteElem;
	}
	
	temp=q->first;
	elem=temp->data;
	
#if PRINT_HELP_TO_DEBUG
	printf("temp=q->first=%d,elem=%d\n",temp,elem);
#endif	

	if(q->first==q->last){
		q->first=q->last=NULL;
	}else{
		q->first=q->first->next;
	}
	q->elemNum--;
	
#if PRINT_HELP_TO_DEBUG
printf("temp=%d,指向next后的q->first=%d,elem=%d\n",temp,q->first);
#endif

	free(temp);
#if FUNCTION_END_PROMPT
	puts("\n--------DeQueue end!--------\n");
#endif
	return elem;
}//DeQueue

int IsFullQ(Queue* q){
	if(q->elemNum==q->capacity){
		puts("queue is full !!\n");
		return 1;
	}
	return 0;
}//IsFullQ

int IsEmptyQ(Queue* q){
	if(q->elemNum){
		return 0;
	}
	puts("queue is empty !!\n");
	return 1; 
}//IsEmptyQ
