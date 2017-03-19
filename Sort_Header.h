#ifndef _SORT_HEADER_H_
#define _SORT_HEADER_H_

#include<iostream>
#include<cstdlib>
using namespace std;


#define MAXSIZE_SORT 15

typedef int elemType;

//simple selection sort
void bubbleSort(elemType elem[],int elemnum);
void insertionSort(elemType elem[],int elemnum);

//shell
void shellSort(elemType elem[],int elemnum);
void selectionSort(elemType elem[],int elemnum);

class HeapSort{
public:
	HeapSort();
	~HeapSort();
	void percDown(elemType elem[],int first,int elemnum);
	void heapSort1(elemType elem[],int elemnum);
	void heapSort2(elemType elem[],int elemnum);
};

//need to write again to be more familiar
class Merge{
public:
	Merge();
	~Merge();
	
	void merge(elemType elem[],elemType elemTemp[],int L,int R,int rightEnd);
	//recursion
	void mSort(elemType elem[],elemType elemTemp[],int L,int RightEnd);
	//unify function interface
	void mergeSort1(elemType elem[],int n);
	//non-recursion
	void merge1(elemType elem[],elemType elemTemp[],int L,int R,int rightEnd);
	void mergePass(elemType elem[],elemType elemTemp[],int n,int length);
	//unify function interface
	void mergeSort2(elemType elem[],int n);
};

class QuickSort{
public:
	QuickSort();
	~QuickSort();
	//test different pivots' influence
	elemType median3(elemType elem[],int left,int right);
	void quicksort(elemType elem[],int left,int right);
	void quickSort(elemType elem[],int n);
};

class TableSort{
private:
	int tableArray[MAXSIZE_SORT];
public:
	TableSort();
	~TableSort();
	void tableSort(elemType elem[],int n);//only sort table
	void physicalSort(elemType elem[],int n);//sort table and move elements the table pointing to
};

typedef struct link{
	elemType data;
	struct link* next;
}link;
class BucketSort{
private:
	link* bucket[MAXSIZE_SORT];
private:
	int unit(int num);
	int hundred(int num);
	int ten(int num);
public:
	BucketSort();
	~BucketSort();
	void bucketSort(elemType elem[],int n);
	void radixSort(elemType elem[],int n,int whichdigit);
	void print(int size);
	
};


int testSort();
int testSort2();

#endif
