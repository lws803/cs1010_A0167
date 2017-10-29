// This program counts the number of negative numbers in a matrix 
// Time complexity (row + col)

#include <stdio.h>
#define MAX 5

int count_neg (int[][MAX], int);

int main () {
	int arr[MAX][MAX] = {{-2,-1,0},{1,2,3},{-3,-2,-1}};
	int size = 3;

	printf ("Number of neg: %d\n", count_neg(arr, size));
}

// Precond: Matrix must be sorted
int count_neg (int arr[][MAX], int size) {
	int i, d, count = 0;
	for (i = 0; i < size; i++) {
		for (d = size - 1; d >= 0; d--) {
			if (arr[i][d] < 0) {
				count += d + 1;
				break;
			}
		}
	}
	return count;
}
