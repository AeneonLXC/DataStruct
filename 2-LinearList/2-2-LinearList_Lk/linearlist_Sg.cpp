#include <stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode LNode;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

// not head node
//bool InitList(LinkList &L){
//	L  = NULL;
//	return true;
//}

// have head node
bool InitList(LinkList &L){
	L  = (LNode*)malloc(sizeof(LNode));
	if(L == NULL){
		return false;
	} 
	L->next = NULL;
	return true;
}

bool InsertNextNode(LNode *p, ElemType e){
	if(p == NULL){
		return false;
	}
	LNode *s  = (LNode*)malloc(sizeof(LNode));
	if(s == NULL){
		return false;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	
}

bool InsertPriorNode(LNode *p, ElemType e){
	if(p == NULL){
		return false;
	}
	LNode *s  = (LNode*)malloc(sizeof(LNode));
	if(s == NULL){
		return false;
	}
	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;
	return true;
}

LNode *GetElem(LinkList &L, int i){
	if(i < 0){
		return NULL;
	}
	LNode *p;
	int j = 0;
	p = L;
	while(p != NULL && j < i){
		p = p->next;
		j++;
	}
	return p;
}

bool ListInsert(LinkList &L, int i, ElemType e){
	if(i < 1){
		return false;
	} 
	LNode *p = GetElem(L, i-1);
	return InsertNextNode(p, e);
}

bool ListDelete(LinkList &L, int i, ElemType &e){
	if(i < 1){
		return false;
	} 
	LNode *p = GetElem(L, i-1);
	if(p == NULL){
		return false;
	}
	LNode *q = p->next;
	e = q->data;
	p->next = q->next;
	free(q); 
	
	return true;
}

bool LocateElem(LinkList L, ElemType e){
	LNode *p = L->next;
	while(p != NULL && p->data != e){
		p = p->next;
	}
	return p;
}

int Length(LinkList L){
	int len = 0;
	LNode *p = L;
	while(p != NULL){
		p = p->next;
		len++;
	}
	return len;
}

void displayList(LinkList L){
	LNode *p = L;
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
	LinkList L;
	InitList(L);
	int e = 0;
	
	for(int i = 0; i < 10; i++){
		ListInsert(L, i, i);
	}
	
	displayList(L);
	ListDelete(L, 5, e);
	displayList(L);
}
