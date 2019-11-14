#include <stdio.h>
#define MAX_SLICES 200000

int maxCherries(int [], int);
int sumSlices (int [MAX_SLICES], int, int);

int main(){
	int arr[MAX_SLICES] = {1,1,1,1,1};
	int size = 5;
	printf("Total: %d\n", sumSlices(arr, size, 3));

	return 0;
}


int sumSlices (int arr[MAX_SLICES], int size, int index) {
	int i, sum = 0, count = 0;
	for (i = index; count < size; i++) {
		sum += arr[i];
		count++;
		if (i == size - 1) {
			i = 0;
		}
	}
	return sum;
}