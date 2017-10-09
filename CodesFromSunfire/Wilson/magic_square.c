// magic_square.c
// To generate a magic square for nxn matrix (n is odd integer)

#include <stdio.h>
#define MAX_SIZE 15

void printMagic(int [][MAX_SIZE], int);
void generateMagic(int [][MAX_SIZE], int);
void init_array (int[][MAX_SIZE], int);

int main(void) {
	int magic[MAX_SIZE][MAX_SIZE] = { {0} }; 
	int size; 

	printf("Enter size of matrix: ");
	scanf("%d", &size);
	generateMagic(magic, size);
	printMagic(magic, size);

	return 0;
}

// To generate the magic square
void generateMagic(int arr[][MAX_SIZE], int size) {
	init_array(arr, size);
	int num;
	// Put 1 in middle
	int x = size/2;
	int y = 0;
	for (num = 1; num <= size*size; num++) {
		if (num == 1){
			arr[y][x] = num;
		}else {
			// Perform the steps as demonstrated in the question
			int positionX = x;
			int positionY = y;
			x += 1;
			y -= 1;

			// Step 1: Move diagonally up and check 
			if (y < 0) {
				y += size;
			}else if (y > size -1) {
				y -= size;
			}

			if (x < 0){
				x += size;
			}else if (x > size - 1) {
				x -= size;
			}

			// Check if the position is already filled 
			if (arr[y][x] == 0) {
				arr[y][x] = num;
			}else {
				y = positionY;
				x = positionX;
				y += 1;
				arr[y][x] = num;
			}
		}
	}
	

}

// To print the magic square
void printMagic(int arr[][MAX_SIZE], int size) {
	int row, col;

	for (row=0; row<size; row++) {
		for (col=0; col<size; col++) 
			printf("%d ", arr[row][col]);
		printf("\n");
	}
}


void init_array (int arr[][MAX_SIZE], int size) {
	int i, d;
	// Vertical rows 
	for (i = 0; i < size; i++) {
		// Horizontal rows 
		for (d = 0; d < size; d++){
			arr[i][d] = 0;
		}
	}
}

