#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A 5000

struct array {
	int a[A];
	struct array* pa;
};


struct array * read();




int search(struct array*, int);

int main()
{
	

	clock_t start, end;

	struct array* p;
	p=read();


	int target = 4999;
	/*printf("input target\n");
	scanf("%d", &target);*/

	start = clock();
	int pos=search(p,target);
	end = clock();
	double t = (double)(start - end) / CLOCKS_PER_SEC;

	free(p);
	printf("%-4d%8f", pos,t);
}




struct array* read() {
	
	struct array* pa = (struct array*)malloc(sizeof(struct array));;

	/*printf("please input sevarl numbers(not 10)%:" );
	scanf("%d", &(pa->a[0]));*/

	for (int i = 0; i < A; i++) {
		pa->a[i] = i;
	}

	/*for (int i = 1; i < A; i++) {
		printf("%4d", pa->a[i]);
		if (i % 10 == 0)
			printf("\n");
	}*/

	printf("\n");
	return pa;
}





int search(struct array* pa, int n) {
		
	int *mid;
	int  low = 0, high = A,midnum;
	//midnum = (low + high) / 2;
	int i = 0;

	while (low <= high) {
		i++;
		midnum = (low + high) / 2;
		mid = &(pa->a[midnum]);

		if (n == *mid) {
			return midnum;
		}
		else if (n > * mid) {
			low=midnum+1;
		}
		else {
			high = midnum - 1;
		}

		printf("%-15d%-15d%-4d\n", *mid, midnum,i);
	}
	return -1;
}




