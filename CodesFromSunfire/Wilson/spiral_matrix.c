#include <stdio.h>
#define MAX 50

void display(int [MAX][MAX], int);
void populate (int [MAX][MAX], int);
int spiral (int [MAX][MAX], int, int);

int main () {
	// One sequence: Right -> Down -> Left -> Up (n-1) -> 
	int matrix[MAX][MAX], size, sequence = 0;
	printf("Enter size: ");
	scanf("%d", &size);
	populate(matrix, size);


	printf("-----Matrix-----\n");
	display(matrix, size);

	printf("-----SPIRALED-Matrix-----\n");
	while (spiral(matrix, size, sequence)) {
		sequence++;
	}
	
	printf("\n");

	return 0;

}


void display(int matrix[MAX][MAX], int size) {
	int i,d; 

	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			printf("%d\t", matrix[i][d]);
		}
		printf("\n");
	}
}

void populate (int matrix[MAX][MAX], int size) {
	int i, d, count = 1;
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			matrix[i][d] = count++;
		}
	}
}

int spiral (int matrix[MAX][MAX], int size, int sequence) {
	int i, keep_spiral = 1;
	// Right
	for (i = sequence; i < size - (sequence + 1); i++) {
		printf("%d ", matrix[sequence][i]);
	}
	// Down 
	for (i = sequence; i < size - (sequence + 1); i++) {
		printf("%d ", matrix[i][size - (sequence + 1)]);
	}
	// Left 
	for (i = size - (sequence + 1); i > sequence; i--) {
		printf("%d ", matrix[size - (sequence + 1)][i]);
	}
	// Up 
	for (i = size - (sequence + 1); i > sequence  ; i--) {
		printf("%d ", matrix[i][sequence]);
	}
	if (sequence == size/2 && size%2 == 0) {
		keep_spiral = 0;
	}else if (sequence == size/2) {
		keep_spiral = 0;
		printf("%d ", matrix[size/2][size/2]);
	}

	return keep_spiral;
}