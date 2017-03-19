#include"Sort_Header.h"

//浠庡皬鍒板ぇ鎺掑簭锛屽鏁存暟鎺掑簭

void print(elemType elem[],int elemnum){
	int i;
	cout<<"\nsortArray[0-"<<elemnum<<"]:";
	for(i=0;i<elemnum;i++){
		cout<<elem[i]<<" ";
	}
	cout<<"\n-----print sortArray-----\n\n";
}

void swap(elemType *a,elemType *b){
	elemType temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void bubbleSort(elemType elem[],int elemnum){
		int i,p,flag;
		elemType temp;
		for(p=elemnum;p>0;p--){
			flag=1;
			for(i=0;i<p-1;i++){
				if(elem[i]>elem[i+1]){
					temp=elem[i];
					elem[i]=elem[i+1];
					elem[i+1]=temp;
					flag=0;
				}
			}
			if(flag){
				break;
			}
		}

//		int i;
//		int p;//position
//		int temp;
//		int flag;
//		for(p=elemnum;p>=0;p--){
//			flag=0;
//			for(i=0;i<p;i++){		//overflow?? i<p???//涓€瓒熷啋娉?
//				if(elem[i]>elem[i+1]){
//					temp=elem[i];
//					elem[i]=elem[i+1];
//					elem[i+1]=temp;
//					flag=1;
//				}
//			}
//			if(flag==0)break;//鍏ㄧ▼鏃犱氦鎹?
//		}
}

void insertionSort(elemType elem[],int elemnum){
	int i,j;
	elemType temp;
	for(i=1;i<elemnum;i++){
		temp=elem[i];
		for(j=i;j>0&&elem[j-1]>temp;j--){//not elem[j]<elem[j-1] but elem[j-1]>temp
			elem[j]=elem[j-1];
		}
		elem[j]=temp;
	}
	
//	int p;
//	int i;
//	elemType temp;
//	for(p=1;p<elemnum;p++){
//		temp=elem[p];
//		for(i=p;i>0&&elem[i-1]>temp;i--){
//			elem[i]=elem[i-1];
//		}
//		elem[i]=temp;
//	}
}

void shellSort(elemType elem[],int elemnum){
	int d;
	int i,j;
	elemType temp;
	for(d=elemnum/2;d>0;d/=2){
		for(i=d;i<elemnum;i++){//i initialized with d not with 0
			temp=elem[i];
			for(j=i;j>=d&&elem[j-d]>temp;j-=d){
				elem[j]=elem[j-d];
			}
			elem[j]=temp;
		}
	}
}

void selectionSort(elemType elem[],int elemnum){
	int i;
	for(i=0;i<elemnum;i++){
		//find the position of the minimum elem
//		minPosition=scanForMin(elem,i,elemnum);
		//adjust array,minimum elem will be adjusted to the ordered position.
//		swap(elem[i],elem[minPosition]);
	}
}


HeapSort::HeapSort(){
	
}
HeapSort::~HeapSort(){
	
}
//dont have sentry,element begins with 0
void HeapSort::percDown(elemType elem[],int first,int elemnum){
//	int child;
//	int parent;
//	int i;
//	for(i=elemnum-1;i>first;i--){
//		child=i;
//		while((parent=(child-1.0)/2-0.5)>=first){
//			if(elem[child]>elem[parent]){
//				swap(&elem[child],&elem[parent]);
//				print(elem,elemnum);
//			}
//			child=parent;
//		}
//	}

//attention!! down,from up to down
//only adjust 1 sequence from first to elemnum
	int parent=first;
	int child;
	while((child=parent*2+1)<elemnum){
		if((child+1)<elemnum&&elem[child]<elem[child+1]){
			child++;
		}
		if(elem[child]>elem[parent]){
			swap(&elem[child],&elem[parent]);
		}
		parent=child;
	}
}
void HeapSort::heapSort2(elemType elem[],int elemnum){
	int i;
	for(i=elemnum/2-1;i>=0;i--){
		percDown(elem,i,elemnum);
		print(elem,elemnum);
	}
	cout<<"--------------\n";
	for(i=elemnum-1;i>0;i--){
		swap(&elem[0],&elem[i]);
		percDown(elem,0,i);
		print(elem,elemnum);
	}
}

//merge----------------------------------------
Merge::Merge(){
		cout<<"----merge created----"<<endl;
}
Merge::~Merge(){
		cout<<"----merge deleted----"<<endl;
}
void Merge::merge(elemType elem[],elemType elemTemp[],int L,int R,int rightEnd){
	
//need to write again to be more familiar
	int leftEnd=R-1;
	int tmp=L;
	int elemNum=rightEnd-L+1;

	while(L<=leftEnd && R<=rightEnd){
		if(elem[L]<elem[R]){
			elemTemp[tmp++]=elem[L++];
		}else{
			elemTemp[tmp++]=elem[R++];
		}
	}
	while(L<=leftEnd){
		elemTemp[tmp++]=elem[L++];
	}
	while(R<=rightEnd){
		elemTemp[tmp++]=elem[R++];
	}
	int i;
//	print(elemTemp,rightEnd+1);
	for(i=0;i<elemNum;i++,rightEnd--){
		elem[rightEnd]=elemTemp[rightEnd];
	}
//	int leftEnd=R-1;
//	int tmp=L;
//	int elemNum=rightEnd-L+1;
//	while(L<=leftEnd && R<=rightEnd){
//		if(elem[L]<=elem[R]){
//			elemTemp[tmp++]=elem[L++];
//		}else{
//			elemTemp[tmp++]=elem[R++];
//		}
//	}
//	while(L<=leftEnd){
//		elemTemp[tmp++]=elem[L++];
//	}
//	while(R<=rightEnd){
//		elemTemp[tmp++]=elem[R++];
//	}
//	int i;
//	for(i=0;i<elemNum;i++,rightEnd--){
//		elem[rightEnd]=elemTemp[rightEnd];
//	}
}
//recursion
void Merge::mSort(elemType elem[],elemType elemTemp[],int L,int rightEnd){
	int center;
	if(L<rightEnd){
		center=(L+rightEnd)/2;
		mSort(elem,elemTemp,L,center);
		mSort(elem,elemTemp,center+1,rightEnd);
		merge(elem,elemTemp,L,center+1,rightEnd);	
	}
}
//unify function interface
void Merge::mergeSort1(elemType elem[],int n){
	elemType* elemTemp;
	elemTemp=(elemType*)malloc(n*sizeof(elemType));

	if(elemTemp!=NULL){
		mSort(elem,elemTemp,0,n-1);
		free(elemTemp);
	}else{
		cout<<"space is full!"<<endl;
		exit(1);
	}
}
//non-recursion
void Merge::merge1(elemType elem[],elemType elemTemp[],int L,int R,int rightEnd){
	int leftEnd=R-1;
	int tmp=L;
	int elemNum=rightEnd-L+1;

	while(L<=leftEnd && R<=rightEnd){
		if(elem[L]<elem[R]){
			elemTemp[tmp++]=elem[L++];
		}else{
			elemTemp[tmp++]=elem[R++];
		}
	}
	while(L<=leftEnd){
		elemTemp[tmp++]=elem[L++];
	}
	while(R<=rightEnd){
		elemTemp[tmp++]=elem[R++];
	}
}
void Merge::mergePass(elemType elem[],elemType elemTemp[],int n,int length){
	int i,j;
	for(i=0;i<=n-2*length;i+=2*length){
		merge1(elem,elemTemp,i,i+length,i+2*length-1);
	}
	if(i+length<n){
		merge1(elem,elemTemp,i,i+length,i+2*length-1);
	}else{
		for(j=i;j<n;j++){
			elemTemp[j]=elem[j];
		}
	}
}
//unify function interface
void Merge::mergeSort2(elemType elem[],int n){
	elemType* elemTemp;
	elemTemp=(elemType*)malloc(n*sizeof(elemType));
	int length=1;
	if(elemTemp!=NULL){
		while(length<n){
			mergePass(elem,elemTemp,n,length);
			length*=2;
			mergePass(elemTemp,elem,n,length);
			length*=2;
		}
		free(elemTemp);
	}else{
		cout<<"space if full!"<<endl;
		exit(1);
	}
}
//merge ending----------------------------------

//quicksort-------------------------------
QuickSort::QuickSort(){
	cout<<"----QuickSort created----"<<endl;
}
QuickSort::~QuickSort(){
	cout<<"----QuickSort deleted----"<<endl;
}
elemType QuickSort::median3(elemType elem[],int left,int right){
	int center=(left+right)/2;
	if(elem[left]>elem[center]){
		swap(&elem[left],&elem[center]);
	}
	if(elem[left]>elem[right]){
		swap(&elem[left],&elem[right]);
	}
	if(elem[center]>elem[right]){
		swap(&elem[right],&elem[center]);
	}
	swap(&elem[center],&elem[right-1]);
	return elem[right-1];
}
void QuickSort::quicksort(elemType elem[],int left,int right){
	elemType pivot;
	int i,j;
	int cutoff=2;//can set 'cutoff' as a larger number,then use insertionSort when cutoff>right-left
	if(cutoff<=right-left){
		pivot=median3(elem,left,right);
		i=left;
		j=right-1;
		for(;;){
			while(elem[++i]<pivot){	}
			while(elem[--j]>pivot){	}
			if(i<j){
				swap(&elem[i],&elem[j]);
			}else{
				break;
			}
		}
		swap(&elem[i],&elem[right-1]);
		quicksort(elem,left,i-1);
		quicksort(elem,i+1,right);
	}
}
void QuickSort::quickSort(elemType elem[],int n){
	quicksort(elem,0,n-1);
}
//quicksort ending-----------------------------

TableSort::TableSort(){
	int i;
	for(i=0;i<MAXSIZE_SORT;i++){
		tableArray[i]=i;
	}
	cout<<"----TableSort created----"<<endl;
}
TableSort::~TableSort(){
	cout<<"----TableSort deleted----"<<endl;
}
void TableSort::tableSort(elemType elem[],int n){
	int p,i;
	for(p=1;p<n;p++){
		int tempp=tableArray[p];
		for(i=p;i>0;i--){
			if(elem[tempp]<elem[tableArray[i-1]]){
				tableArray[i]=tableArray[i-1];
			}else{
				break;
			}
		}
		tableArray[i]=tempp;
	}
	print(tableArray,15);
}
void TableSort::physicalSort(elemType elem[],int n){
	elemType tmpElem;
	int p;
	int i=0;int j;
	for(p=0;p<n;p++){
		i=p;
		tmpElem=elem[i];//don't forget to restore the elem at p
		while(i!=tableArray[i]){
			if(tableArray[i]==p){
				elem[i]=tmpElem;
			}else{
				elem[i]=elem[tableArray[i]];
			}
			j=tableArray[i];//j is to record the table number of next element
			tableArray[i]=i;
			i=j;
		}
	}

	for(p=0;p<n;p++){
		cout<<elem[tableArray[p]]<<" ";
	}
	cout<<endl;
}

BucketSort::BucketSort(){
	int i;
	for(i=0;i<MAXSIZE_SORT;i++){
		bucket[i]=NULL;
	}
	cout<<"----BucketSort created----\n";
}
BucketSort::~BucketSort(){
	cout<<"----BucketSort deleted----\n";
}
void BucketSort::bucketSort(elemType elem[],int n){
	int i;
	link* tl;
	for(i=0;i<n;i++){
		if(tl=bucket[elem[i]]){
			while(tl->next){
				tl=tl->next;
			}
			tl->next=(link*)malloc(sizeof(link));
			tl=tl->next;
			tl->data=elem[i];
			tl->next=NULL;
		}else{
			bucket[elem[i]]=(link*)malloc(sizeof(link));
			bucket[elem[i]]->data=elem[i];
			bucket[elem[i]]->next=NULL;
		}
	}
}
int BucketSort::unit(int num){
	return num%10;
}
int BucketSort::ten(int num){
	return num/10%10;
}
int BucketSort::hundred(int num){
	return num/100%10;
}
void BucketSort::radixSort(elemType elem[],int n,int whichdigit){
	//least significant digit(ci wei you xian)
	link* tl;
	int d;
	int i;
	for(i=0;i<n;i++){
		if(whichdigit==1){
			d=unit(elem[i]);
		}else if(whichdigit==2){
			d=ten(elem[i]);
		}else if(whichdigit==3){
			d=hundred(elem[i]);
		}else{
			break;
		}

		if(tl=bucket[d]){
			while(tl->next){
				tl=tl->next;
			}
			tl->next=(link*)malloc(sizeof(link));
			tl=tl->next;
			tl->data=elem[i];
			tl->next=NULL;
		}else{
			bucket[d]=(link*)malloc(sizeof(link));
			bucket[d]->data=elem[i];
			bucket[d]->next=NULL;
		}
	}
	int j=0;
	link* tl2;
	for(i=0;i<n;i++){
		tl=bucket[i];
		cout<<i<<"-th: ";
		while(tl){
			cout<<(elem[j++]=tl->data)<<",";
			tl2=tl;
			tl=tl->next;
			free(tl2);
		}
		bucket[i]=NULL;
		cout<<endl;
	}
}
void BucketSort::print(int size){
	int i;
	link* l;
	for(i=0;i<size;i++){
		l=bucket[i];
		cout<<i<<"-th: ";
		while(l){
			cout<<(l->data)<<",";
			l=l->next;
		}
		cout<<endl;
	}
}

int testSort2(){
	//elemType sortArray[MAXSIZE_SORT]={9,5,2,3,4,  7,8,6,0,1,  9,9,1,1,2};
	//print(sortArray,MAXSIZE_SORT);

	elemType sortArray2[MAXSIZE_SORT]={900,521,22,3,445,  74,8,26,0,13,  93,93,13,13,2};
	print(sortArray2,MAXSIZE_SORT);
	
	//Merge* m=new Merge();
	//m->mergeSort1(sortArray,10);
	//m->mergeSort2(sortArray,10);
	//delete(m);

//	QuickSort* qs=new QuickSort();
//	qs->quickSort(sortArray,15);
//	print(sortArray,15);
//	delete(qs);

//    TableSort* t=new TableSort();
//	t->tableSort(sortArray,15);
//	t->tableMoveSort(sortArray,15);
//	delete(t);
	
//	BucketSort* b=new BucketSort();
//	b->bucketSort(sortArray,MAXSIZE_SORT);
//	b->print(MAXSIZE_SORT);
//	delete(b);
	
	BucketSort* bs=new BucketSort();
	bs->radixSort(sortArray2,MAXSIZE_SORT,1);
	cout<<endl;
	bs->radixSort(sortArray2,MAXSIZE_SORT,2);
	cout<<endl;
	bs->radixSort(sortArray2,MAXSIZE_SORT,3);
	cout<<endl;
	bs->print(MAXSIZE_SORT);
	print(sortArray2,MAXSIZE_SORT);
	delete(bs);
	
	return 0;
}

int testSort(){
	elemType sortArray[MAXSIZE_SORT]={99,10,22,2,123,		32,32,33,45,43};

//	bubbleSort(sortArray,10);
//	insertionSort(sortArray,10);
//	shellSort(sortArray,10);

	HeapSort* hs=new HeapSort();
	print(sortArray,10);
	hs->heapSort2(sortArray,10);

//	int elemnum=10;
//	int i;
//	for(i=elemnum/2-1;i>=0;i--){
//		percDown(sortArray,i,elemnum);
//		//print(sortArray,elemnum);
//	}

//	int f=0;
//	f=((f-1.0)/2);
//	printf("%d",f);

	return 0;
}
