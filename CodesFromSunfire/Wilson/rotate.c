// rotate.c
#include <stdio.h>
#define MAX_SIZE 10

int scan(int [][MAX_SIZE]);
void print(int [][MAX_SIZE], int);
void rotate(int [][MAX_SIZE], int, int);
void transpose_90 (int matrix[][MAX_SIZE], int size); 


int main(void) {
	int image[MAX_SIZE][MAX_SIZE], size = scan (image), degree;
	printf("Enter degree of rotation: ");
	scanf ("%d", &degree);
	printf("The image after rotation: \n");
	rotate(image, size, degree);

	print (image, size);
	return 0;
}

void rotate(int image[][MAX_SIZE], int size, int degree) {
	switch (degree) {
		case 90:
		transpose_90 (image, size);
		break;
		case 180:
		transpose_90(image, size);
		transpose_90(image, size);
		break;
		case 270:
		transpose_90(image, size);
		transpose_90(image, size);
		transpose_90(image, size);
		break;
	}
}

// To read in an image
int scan(int image[][MAX_SIZE]) {
	int size, i, d;
	printf("Enter size: ");
	scanf ("%d", &size);
	printf("Enter values: \n");
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			scanf("%d", &image[i][d]);
		}
	}

	return size;
}

// To print an image
void print(int image[][MAX_SIZE], int size) {
	int row, col;

	for (row = 0; row < size; row++) {
		for (col = 0; col < size; col++) 
			printf("%d ", image[row][col]);
		printf("\n");
	}
}

void transpose_90 (int matrix[][MAX_SIZE], int size) {
	int matrix_dupe[MAX_SIZE][MAX_SIZE];
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
