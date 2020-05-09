#include <stdio.h>
#include <stdlib.h>



int pos(int a[], int low, int high);
void quickSort(int a[], int low, int high);


int main()
{

	int a[10] = { 8,9,3,12,34,56,9,5 ,1,2};

	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}

	quickSort(a, 0, 9);
	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}


}





int pos(int a[], int low, int high) {
	int val = a[low];

	while (low < high) {

		while (low<high&& a[high] >= val)
			high--;

		a[low] = a[high];

		while (low<high&&a[low] <= val)
			low++;

		a[high] = a[low];



	}

	a[low] = val;
	return low;
}





void quickSort(int a[], int low, int high) {
	int p;
	if (low < high) {
		p = pos(a, low, high);
		quickSort(a, low, p - 1);
		quickSort(a, p + 1, high);
	}
	return;
}


