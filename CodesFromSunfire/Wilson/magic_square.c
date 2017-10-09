// magic_square.c
// To generate a magic square for nxn matrix (n is odd integer)

#include <stdio.h>
#define MAX_SIZE 15

void printMagic(int [][MAX_SIZE], int);
void generateMagic(int [][MAX_SIZE], int);

int main(void) {
	int magic[MAX_SIZE][MAX_SIZE] = { {0} }; 
	int size; 

	printf("Enter size of matrix: ");
	scanf("%d", &size);
	printf("%d\n", size);
	generateMagic(magic, size);
	printMagic(magic, size);

	return 0;
}

// To generate the magic square
void generateMagic(int arr[][MAX_SIZE], int size) {

}

// To print the magic square
void printMagic(int arr[][MAX_SIZE], int size) {
	int row, col;

	for (row=0; row<size; row++) {
		for (col=0; col<size; col++) 
			printf("%5d", arr[row][col]);
		printf("\n");
	}
}
