
#include <stdio.h>
#include <stdlib.h>

#define N 10  



typedef struct Queue {
    int* pBase;
    int front;
    int rear;
}Q ;



void init(Q*);


void traverse(Q* p);


int isfull(Q* p);


void input(Q*, int);


void out(Q*);


int main()
{
    Q q;


    init(&q);

    for (int i =0 ; i < 8; i++) {
        input(&q, i);

    }
    traverse(&q);

    for (int i = 0; i < 8; i++) {
        out(&q);
        traverse(&q);
    }
    return 0;

}




void init(Q* p) {
    p->pBase = (int*)malloc(sizeof(int) * N);
    p->front = p->rear = 0;
    return;
}




void traverse(Q* p) {
    if (p->front==p->rear) {
        printf("empty\n");
        exit(0);
    }
    else {
        int i = p->front;
        while (i != p->rear) {
            printf("%4d", p->pBase[i]);
            i++;
            
        }
        printf("\n");
    }
    return;
}



int isfull(Q* p) {
    if ((p->rear + 1) % N == p->front) {
        return 1;
    }
    else
        return 0;
}




void input(Q* p, int val) {
    if (isfull(p)) {
        printf("full\n");
        exit(0);
    }
    else {
        p->pBase[p->rear] = val;
        p->rear = (p->rear + 1) % N;
        printf("input %d\n", val);
        return;
    }
}




void out(Q* p) {
    if (p->front == p->rear) {
        printf("empty queue\n");
        exit(0);
    }
    else {
        int num = p->pBase[p->front];
        p->front = (p->front + 1) % N;
        printf("out %d\n", num);
        return;
    }
}
