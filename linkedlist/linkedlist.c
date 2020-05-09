

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void showArray();

void linkedlist();

struct list
{
    int data;

    struct list* pNext;
};

typedef struct list ST;

ST* creative_list();

void trverse(ST* pHead);

int freelist(ST* pHead);

void sort3(ST* pHead);

void remove1(ST* pHead, int which);

void insert(ST* pHead, int pos, int val);

int main()
{
    //showArray();

    //linkedlist();

    ST* pHead=creative_list();

    trverse(pHead);

    //printf("%d nodes have been released\n",freelist(pHead));

    //sort3(pHead);
    //printf("%d\n", pHead->pNext->pNext->data);

    //remove1(pHead, 2);

    insert(pHead, 3,9);

    trverse(pHead);




    return 0;
}

void showArray(){ 
    int* ap[5];
    int a = 5;
    ap[0] = &a;
    printf("%d\n", *ap[0]);
    int (*pa)[3];
    int b[3] = { 1,2 ,0};
    pa = &b;
    printf("%d  %d\n",*(*pa+2), *(pa[0]+2));
    int c[2][3] = { 1,2,3,4,5,6 };
    int(*pc)[3];
    pc = c;
    printf("%4d%4d\n", *(*pc + 1), *(pc[1]+ 1));//二维数组元素
    return;
}

void linkedlist() {

   
    
    ST *p, * p1;

    p1 = NULL;
    p = NULL;

    ST st1 = { 1 ,p1 }, st2 = { 2 }, st3 = { 3 }, st4 = { 4 };

    
    

    p = &st1;

    st1.pNext = &st2;

    st2.pNext = &st3;

    st3.pNext = &st4;

    st4.pNext = NULL;

    int d2;
    d2 = p->pNext->data;

    ST st5 ;

    st4.pNext = &st5;
    st5.pNext = NULL;
    int d5;

    d5=p->pNext->pNext->pNext->pNext->data = 5;
    

    //d2 = sizeof(ST);ST类型占8个字节，分配位置在内存中不连续。
   

}

ST* creative_list() {

    int len;//linkedlist length
    int val;//temporary value

    printf("please input the linkedlist lenth:");
    scanf("%d", &len);

    if (len < 1) {
        exit(0);
    }

    ST* pHead;
    pHead = (ST*)malloc(sizeof(ST));
    pHead->pNext = NULL;

    if (len == 1) {
        printf("only one head node");
        exit(0);
    }

    ST* pTail = pHead;



    for (int i = 0; i < len; i++) {

        printf("please input which linkedlist value:");
        scanf("%d", &val);

        ST* pNew = (ST*)malloc(sizeof(ST));
        if (NULL == pNew) {
            exit(0);
        }
        pNew->data = val;
        pTail->pNext = pNew;
        pTail = pNew;
        
    }
    pTail->pNext = NULL;

    /*printf("%p\n", pHead);
    if (pHead->pNext == NULL) {
        exit(0);
    }
    for (int i = 0; i < len; i++) {
        printf("%d\n", pHead->pNext->data);
        pHead = pHead->pNext;
    }
    printf("%p\n", pHead);*/

    return pHead;
}

void trverse(ST* pHead) {
    ST* ptemp;
    ptemp = pHead->pNext;
    while (ptemp != NULL) {
        printf("%d\n", ptemp->data);
        ptemp = ptemp->pNext;
    }
    return;
}

int freelist(ST* pHead) {
    int i = 0;
    ST* ptemp;
    while (pHead != NULL) {
        ptemp = pHead;

        pHead = pHead->pNext;
        free(ptemp);
        i++;
    }
    return i;
}

void sort(ST* pHead,int len) {
    int temp;
    ST* p, * q;
    

    p = pHead->pNext;
    for( int j=0;j<len-1;j++){

        q = p->pNext;
        for (int  i = j+1; i < len ; i++) {

            if (p->data>q->data){

                temp = p->data;
                p->data = q->data;
                q->data = temp;

            }
            q = q->pNext;
        }
        p=p->pNext;
    }
    return;
}

void sort2(ST* pHead) {

    int temp=0;

    int count = 0;

    ST* pCount = pHead;

    printf("%p-%p\n", pHead,pHead->pNext);

    if (pCount == NULL) {
        printf("empty");
        exit(0);
    }
    while (pCount->pNext != NULL) {
        count++;
        pCount = pCount->pNext;
    }

    printf("%p-%p\n", pHead, pHead->pNext);


   pHead = pHead->pNext;

   ST* p;

    for (int i = 0; i < count-1; i++) {
        p = pHead->pNext;

        for (int j = i + 1; j < count ; j++) {

            if (pHead->data > p->data) {
                temp = pHead->data;
                pHead->data = p->data;
                p->data = temp;
            }
            p= p->pNext;

        }
        pHead = pHead->pNext;


    }

}

void sort3(ST* pHead) {
    int count = 0;

    ST* pCount = pHead;

    printf("%p-%p\n", pHead, pHead->pNext);

    if (pCount == NULL) {
        printf("empty");
        exit(0);
    }
    while (pCount->pNext != NULL) {
        count++;
        pCount = pCount->pNext;
    }

    printf("%p-%p\n", pHead, pHead->pNext);

    pHead = pHead->pNext;
    ST* p;
    p = pHead;
    int temp = 0;
    for (int j = 0; j < count - 1; j++) {
        for (int i = 0; i < count - 1; i++) {

            if (pHead->data > pHead->pNext->data) {
                temp = pHead->data;
                pHead->data = pHead->pNext->data;
                pHead->pNext->data = temp;
            }
            pHead = pHead->pNext;

        }
        pHead = p;
//        printf("j=%d,%d-%d-%d\n", j, pHead->data, pHead->pNext->data, pHead->pNext->pNext->data);

    }
}

void remove1(ST* pHead, int which) {
    ST* pt;

    int i = 0;

    pt = pHead;
    while (NULL != pt && i < which - 1) {
        pt = pt->pNext;
        i++;
    }

    if (NULL == pt) {
        return false;
    }
    ST* p = pt->pNext;
    pt->pNext = p->pNext;
    free(p);
    p = NULL;
    return;

}

void insert(ST* pHead, int pos, int val) {

    int i = 0;

    ST* p = pHead;

    while (NULL != p && i < pos - 1) {
        p = p->pNext;
        i++;
    }

    if (NULL == p) {
        exit(0);
    }

    ST* pNew = (ST*)malloc(sizeof(ST));
    pNew->data = val;
    pNew->pNext = p->pNext;
    p->pNext = pNew;
}
