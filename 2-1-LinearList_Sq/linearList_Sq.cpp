#include <stdio.h>
#define MAX 10
#define InitSize 100
//typedef struct{
//	int *data;
//	int MaxSize, length;
//}SqList;

typedef struct{
	int data[MAX];
	int length;
}SqList;

// init list
void InitList(SqList &L){
	for(int i = 0; i < MAX; i++){
		L.data[i] = 0;
	}
	L.length = 0;
}

// insert element
bool ListInsert(SqList &L, int i, int e){
	if(i < 1 || i > L.length + 1){
		return false;
	}
	if(L.length >= MAX){
		return false;
	}
	for(int j = L.length; j >= i; j--){
		L.data[j] = L.data[j-1];
	}
	L.data[i-1]=e;
	L.length++;
	return true;
}

// delete element
bool ListDelete(SqList &L, int i, int e){
	if(i < 1 || i > L.length){
		return false;
	}
	e=L.data[i-1];
	for(int j = i; j < L.length; j++){
		L.data[j-1] = L.data[j];
	}
	L.length--;
	return true;
}

// imshow List for sigle element
void displayList(SqList &L){
	for(int i = 0; i < L.length; i++){
		printf("%d,",L.data[i]);
	}
	printf("\n");
}

// find element locate
int LocateElem(SqList L, int e){
	int i;
	for(i = 0; i < L.length; i++){
		if(L.data[i] == e){
			return i+1;
		}
	}
	return 0;
}

// get compute list of size for display
void getListLength(SqList &L){
	printf("L.length-> %d\n",L.length);
}

int main(){
	SqList L;
	InitList(L);

	for(int i = 0; i < 5; i++){
		L.data[i]=1;
		L.length++;
	}
	
	getListLength(L);
	ListInsert(L, 5, 8);
	getListLength(L);
	
	printf("%d\n", LocateElem(L, 8));
	
	displayList(L);
	
	ListDelete(L, 5, 8);
	getListLength(L);
	displayList(L);
	
} 
