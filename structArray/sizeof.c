
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int array[], int num) {
	//int num=8;
	//num = (sizeof(array)) / sizeof(array[0]);不在本函数里，sizeof（）不可测数组长度。
	for (int j = 0; j < num - 1; j++) {
		for (int i = 0; i < num - 1; i++) {
			if (array[i] < array[i + 1]) {
				int t;
				t = array[i];
				array[i] = array[i + 1];
				array[i + 1] = t;
			}
		}
	}
	return;
}


void select_sort(int array[], int num) {
	int temp;
	for (int i = 0; i < num; i++) {
		for (int j = i+1; j < num; j++) {
			if (array[i] > array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	return;
	}

int main()
{
	int a[8] = { 2,3,5,1,9,6,4,0 };
	int num;
	num = sizeof(a) / sizeof(a[0]);
	bubble_sort(&a, num);
	for (int i = 0; i < 8; i++) {
		printf("%d\n", a[i]);
	}
	printf("select sort:\n");
	select_sort(&a, num);
	for (int i = 0; i < 8; i++) {
		printf("%d\n", a[i]);
	}

	return 0;
}
