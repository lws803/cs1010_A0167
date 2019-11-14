/**
 * pyramid.c
 * This program computes the maximum-value path
 * in a triangular matrix.
 */

#include <stdio.h>
#define MAX_ROWS 10

int maxPathValue(...);
int scanTriangularArray(int [][MAX_ROWS]);
void printTriangularArray(int [][MAX_ROWS], int);

int main(void) {
	int size; // number of rows
	int table[MAX_ROWS][MAX_ROWS];
	int r, c;

	size = scanTriangularArray(table);
	// printTriangularArray(table, size);   // for checking

	printf("Maximum path value = %d\n", maxPathValue(...));

	return 0;
}

// Compute the path that gives the maximum value
int maxPathValue(...) {

}

// Read data into 2-dimensional triangular array arr,
// and return the number of rows.
int scanTriangularArray(int arr[][MAX_ROWS]) {

}

// Print elements in the 2-dimensional triangular array arr.
// For checking purpose.
void printTriangularArray(int arr[][MAX_ROWS], int size) {
	int r, c;

	for (r = 0; r < size; r++) {
		for (c = 0; c <= r; c++) {
			printf("%d\t", arr[r][c]);
		}
		printf("\n");
	}
}
