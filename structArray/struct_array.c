#include <stdio.h>
#include <stdlib.h>


typedef struct Array A;

struct Array
{
	int len;

	int* next;
};

A* init(struct Array* p);
void show(A* p);
void add(A* p, int val);

int main()
{

	A* p1;


	A student1;
	int len;

	printf("please input variable array length:");
	scanf("%d", &len);


	while (len < 0 || len > 9) {
		printf("please input variable array length:");
		scanf("%d", &len);

	}
	p1 = init(&student1, len);

	add(p1, len);
	show(p1);



	return 0;
}

A* init(A* p, int length) {

	(*p).next = (A*)malloc(length * sizeof(int));
	p->len = length;
	return p;

}

void show(A* p) {
	for (int i = (p->len) - 1; i >= 0; i--) {
		//printf("%d\n", p->next[i]);
		printf("%d\n", *(p->next + i));

	}
}

void add(A* p, int val) {
	for (int i = 0; i < p->len; i++)
		//p->next[i] =val++;
		*(p->next + i) = val++;
}