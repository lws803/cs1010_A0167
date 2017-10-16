#include <stdio.h>
#define size 3

void display (char [size][size]);
void transpose_neg_90 (char [size][size]);
void transpose_90 (char [size][size]);

int main () {
	char matrix [size][size] = {{'a','b','c'},{'d','e','f'},{'g','h','i'}};

	printf("----UN-TRANSPOSED MATRIX----\n");
	display(matrix);

	printf("----TRANSPOSED MATRIX----\n");
	transpose_90(matrix);
	display(matrix);

}

void transpose_neg_90 (char matrix[size][size]) {
	char matrix_dupe[size][size];

	int i, d;
	// Clone and transpose
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			matrix_dupe[i][d] = matrix[d][i];
		}
	}

	// Fix the transposition back to the original array 
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			matrix[i][d] = matrix_dupe[i][d];
		}
	}
}


void transpose_90 (char matrix[size][size]) {
	char matrix_dupe[size][size];

	int i, d;
	// Clone and transpose
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			// Starts from bottom row first column
			matrix_dupe[i][d] = matrix[size - d - 1][i];
		}
	}

	// Fix the transposition back to the original array 
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			matrix[i][d] = matrix_dupe[i][d];
		}
	}
}


void display (char matrix[size][size]) {
	int i, d;
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			printf("%c ", matrix[i][d]);
		}
		printf("\n");
	}
}