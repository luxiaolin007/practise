
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int data;
	struct Node* pNext;
}NODE;
//


typedef struct Stack {
	NODE* pTop;
	NODE* pBottom;
}STACK;

void creative(STACK* p);

void push(STACK* p,int val);

void pop(STACK* p);

void clear(STACK* p);








int main()
{

	STACK s;
	s.pBottom = NULL;
	s.pTop = NULL;
	printf("%p-%p\n", s.pBottom, s.pTop);


	creative(&s);
	if(s.pBottom!=NULL)
	printf("%p-%p\n", s.pBottom, s.pTop);


	for (int i = 10; i < 100; i+=10) {
		push(&s, i);
		if (s.pTop != NULL)
			printf("%d-%d\n", s.pBottom->data, s.pTop->data);
	}
	

	pop(&s);
	if (s.pTop != NULL)
	printf("%d-%d\n", s.pBottom->data, s.pTop->data);


	clear(&s);
	printf("%d-%d\n", s.pBottom->data, s.pTop->data);


	

	return 0;

}








void creative(STACK* p) {
	NODE* pNew = (NODE*)malloc(sizeof(NODE));
	if (pNew == NULL) {
		printf("creative fail,not enough memory\n");
		exit(0);
	}
	else
	{
		p->pBottom = pNew;
		p->pTop = pNew;
		p->pBottom->pNext = NULL;
		p->pTop->pNext = NULL;
	}

	return;

}




void push(STACK* p, int val){
	NODE* pNew = (NODE*)malloc(sizeof(NODE));
	if (pNew == NULL) {
		printf("creative fail,not enough memory\n");
		exit(0);
	}

	pNew->pNext = p->pTop;
	pNew->data = val;
	p->pTop = pNew;
	
	
	return;

}



void pop(STACK* p)
{

	if (p->pTop == p->pBottom) {
		printf("empty stack\n");
		exit(0);
	}
	else {
		NODE* q = p->pTop;
		p->pTop = p->pTop->pNext;
		free(q);
		q = NULL;
	}
	return;
}



void clear(STACK* p) {
	if (p->pBottom == p->pTop) {
		printf("empty already\n");
		exit(0);
	}
	else {
		NODE* q =NULL;

		while (p->pTop != p->pBottom) {
			q = p->pTop;
			p->pTop = p->pTop->pNext;
			free(q);
			q = NULL;
		}
	}
	return;
}
