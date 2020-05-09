#include <stdio.h>
#include <stdlib.h>
//

#define A  2
#define B  5

int main()
{

	typedef struct multinomial {
		int coe;
		int expon;
		char x;
		struct multinomial* pNext;
	}*PM, M;

	char ch;
	ch = 'x';


	PM ap[A][B];
	for (int i = A - 1; i > -1; i--) {
		for (int j = B - 1; j > -1; j--) {

			ap[i][j] = (PM)malloc(sizeof(M));

			if (j == 4) {
				ap[i][j]->pNext = NULL;
			}
			else {
				ap[i][j]->pNext = ap[i][j + 1];
			}

			ap[i][j]->coe = 15-j+i;
			ap[i][j]->expon = 20-j-i;
			ap[i][j]->x = ch;

		}
	}

	//ap[0][2]->coe = -15; test continue.

	for (int i = 0; i < A; i++) {
		for (int j = 0; j < B; j++) {

			//printf("ap[%d[%d]->pNext Address to %p  ap[%d][%d] Addresee %p\n",i, j, ap[i][j]->pNext,i,j,ap[i][j]);

			printf("ap[%d][%d]->expon %d,",i,j,ap[i][j]->expon);

			printf("ap[%d][%d]->coe %d,", i, j, ap[i][j]->coe);


			printf("%c\n\n", ap[i][j]->x);

		}
	}


	PM pm1=(PM)malloc(sizeof(M)),pm2=(PM)malloc(sizeof(M));


	PM pHead = (PM)malloc(sizeof(M));
	PM pt = pHead;

	pm1->pNext = ap[0][0];
	pm2->pNext = ap[1][0];


	while (pm1->pNext != NULL || pm2->pNext != NULL) {
		if(pm1->pNext!=NULL&&pm2->pNext!=NULL){
			if (pm1->pNext->expon == pm2->pNext->expon) {
				PM pNew = (PM)malloc(sizeof(M));
				pNew->expon = pm1->pNext->expon;
				pNew->coe = pm1->pNext->coe + pm2->pNext->coe;
				pNew->x = pm1->pNext->x;
				pm1 = pm1->pNext;
				pm2 = pm2->pNext;
				if (pNew->coe == 0) {
					free(pNew);
					continue;
				}
				pHead->pNext = pNew;
				pHead = pNew;
			}
			else if (pm1->pNext->expon > pm2->pNext->expon) {
				PM pNew = (PM)malloc(sizeof(M));
				pNew->coe = pm1->pNext->coe;
				pNew->expon = pm1->pNext->expon;
				pm1 = pm1->pNext;
				pNew->x = pm1->pNext->x;
				pHead->pNext = pNew;
				pHead = pNew;
			}
			else {
				PM pNew = (PM)malloc(sizeof(M));
				pNew->coe = pm2->pNext->coe;
				pNew->expon = pm2->pNext->expon;
				pNew->x = pm1->pNext->x;
				pm2 = pm2->pNext;
				pHead->pNext = pNew;
				pHead = pNew;
			}

		}
		else	if (pm1->pNext == NULL) {
			PM pNew = (PM)malloc(sizeof(M));
			pNew->coe = pm2->pNext->coe;
			pNew->expon = pm2->pNext->expon;
			pNew->x = pm2->pNext->x;
			pm2 = pm2->pNext;
			pHead->pNext = pNew;
			pHead = pNew;
		}
		else {
			PM pNew = (PM)malloc(sizeof(M));
			pNew->coe = pm1->pNext->coe;
			pNew->expon = pm1->pNext->expon;
			pm1 = pm1->pNext;
			pNew->x = pm1->pNext->x;
			pHead->pNext = pNew;
			pHead = pNew;
		}
		pHead->pNext = NULL;

	}

	pHead = pt;

	
	while (pt->pNext!=NULL) {
		pt = pt->pNext;

		printf("%d*%c^%d", pt->coe, pt->x, pt->expon);
		if (pt->pNext != NULL) {
			printf("+");

		}
		else {
			printf("=");
		}

	}

}

