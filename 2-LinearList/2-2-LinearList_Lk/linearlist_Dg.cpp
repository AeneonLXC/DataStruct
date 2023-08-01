#include <stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct DNode DNode;
typedef struct DNode{
	ElemType data;
	struct DNode *prior, *next;
}DNode, *DLinkList;


// double LinkList Init
bool InitList(DLinkList &L){
	L = (DNode*)malloc(sizeof(DNode));
	if(L == NULL){
		return false;
	} 
	L->prior = NULL;
	L->next = NULL;
	
	return true;
}

// double LinkList Insert node
// Insert the s node after the p node 
bool InsertList(DNode *p, DNode *s){
	if(p == NULL || s == NULL){
		return false;
	}
	s->next = p->next;
	if(p->next != NULL){
		p->next->prior = s;
	}
	s->prior = p;
	p->next = s;
	return true;
}

// double LinkList Delete node
// Insert the s node after the p node 
bool DeleteList(DNode *p){
	if(p == NULL){
		return false;
	}
	DNode *q = p->next;
	if(q == NULL){
		return false;
	}
	p->next = q->next;
	if(q->next != NULL){
		q->next->prior = p;
	}
	free(q);

	return true;
}

void displayList(DLinkList L){
	DNode *p = L;
	int len = 0;
	while(p != NULL){
		p = p->next;
		len++;
		if(p == NULL){
			continue;
		}
		else{
			printf("%d,",p->data);
		}
	}
	printf("\n");
	printf("Length-->%d\n", len);
}

int main(){
	DLinkList L;
	DNode *s;
	InitList(L);
	int i;

	for(i = 0; i < 10; i++){
		s = (DNode*)malloc(sizeof(DNode));
		s->data = i;
		InsertList(L, s);
	
	}
	
	displayList(L);
	DNode *d = L;
	while(d->data != 5){
		d = d->next;
	}
	DeleteList(d);
	displayList(L);
}
