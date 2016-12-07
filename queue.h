/*
 * queue.h
 *
 * Created on: 2016-12-7
 *     Author: ZhangGuangJie
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#define infiniteElem 10000
 
typedef struct QNode{
	int data;
	struct QNode *next;
}QNode;

typedef struct{		//链式存储
	QNode *first;
	QNode *last;
	int elemNum;	//存储的元素的个数
	int capacity;
}Queue;

Queue* CreateQueue();
void EnQueue(int x,Queue *q);
int DeQueue(Queue* q);
int IsFullQ(Queue* q);
int IsEmptyQ(Queue* q);
void printQ(Queue *q);

#endif /*queue.h*/
