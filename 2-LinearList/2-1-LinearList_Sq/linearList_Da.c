#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#define MAX 10
#define InitSize 10

typedef int ElemType;
typedef struct{
	ElemType *data;
	int length, Maximum;
}SqList;

// init list
void InitList(SqList *L){
	int i = 0;
	for(; i < MAX; i++){
		(*L).data[i] = 0;
	}
	
	(*L).length = 0;
}

// insert ElemType
bool ListInsert(SqList *L, int i, int e){
	if(i < 1 || i > (*L).length + 1){
		return false;
	}
	if((*L).length >= (*L).Maximum){
		return false;
	}
	int j = (*L).length;
	for(; j >= i; j--){
		(*L).data[j] = (*L).data[j-1];
	}
	(*L).data[i-1]=e;
	(*L).length++;
	return true;
}

// delete element
bool ListDelete(SqList *L, int i, int e){
	if(i < 1 || i > (*L).length){
		return false;
	}
	e=(*L).data[i-1];
	int j = i;
	for(; j < (*L).length; j++){
		(*L).data[j-1] = (*L).data[j];
	}
	(*L).length--;
	return true;
}

// imshow List for sigle element
void displayList(SqList *L){
	int i = 0;
	for(; i < (*L).length; i++){
		printf("%d,",(*L).data[i]);
	}
	printf("\n");
}

// find element locate
int LocateElem(SqList L, int e){
	int i = 0;
	for(; i < L.length; i++){
		if(L.data[i] == e){
			return i+1;
		}
	}
	return -1;
}

// get compute list of size for display
void getListLength(SqList *L){
	printf("L.length-> %d\n",(*L).length);
}

int main(){
	SqList L;
	// equal C++ --> L.data = new ElemType[InitSize]
	L.data = (ElemType*)malloc(sizeof(ElemType)*InitSize); 
	InitList(&L);
	L.Maximum = MAX;
	int i = 0;
	for(; i < 10; i++){
		L.data[i]=i;
		L.length++;
	}
	
	getListLength(&L);
	displayList(&L);
	
	// Open up new storage space
	L.data = (ElemType*)realloc(L.data, sizeof(ElemType)*InitSize+1); 
	L.Maximum = InitSize+1;
	ListInsert(&L, 5, -1);
	getListLength(&L);
	
	printf("%d\n", LocateElem(L, 8));
	
	displayList(&L);
	
	ListDelete(&L, 5, 8);
	getListLength(&L);
	displayList(&L);
	
} 
