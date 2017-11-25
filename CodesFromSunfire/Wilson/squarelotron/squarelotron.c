#include "stdio.h"
void flipLeftRight (int [][10], int , int );
int read(int [][10], int*); 
void print (int [][10], int );


int main(int argc, char const *argv[])
{
	int square[10][10];
	int index;
	int size = read (square, &index);

	print (square, size);

	flipLeftRight(square, size, index);

	print(square, size);


	return 0;
}


int read(int square[][10], int* index) {
	int size;
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		for (int d = 0; d < size; d++) {
			scanf("%d", &square[i][d]);
		}
	}
	scanf ("%d", index);


	return size;
}

void print (int square[][10], int size) {
	for (int i = 0; i < size; i++) {
		for (int d = 0; d < size; d++) {
			printf("%2d ", square[i][d]);
		}
		printf("\n");
	}
}


void flipLeftRight (int square[][10], int size, int index) {
	int i;
	// Flip the sides
	for (i = index; i < size; i++) {
		int temp = square[i][index];
		square[i][index] = square[i][size-index-1];
		square[i][size-index-1] = temp;
	}

	// Flip inner 
	int starting = index + 1; 
	int ending = size - index - 2;

	printf("(ending-starting)/2: %d\n", (ending-starting)/2);
	// Really really tricky part
	// Instead of letting i be the starting index we let it be zero. 
	// This will not double swap and we do not have to consider cases of odd size or even size. 
	// It's because starting+i and ending-i will arrive at the same element, thus swapping among themselves 
	for (i = 0; i <= (ending-starting)/2; i++) {
		int temp = square[index][starting + i];
		square[index][starting + i] = square[index][ending-i];
		square[index][ending-i] = temp;


		temp = square[size - index - 1][starting + i];
		square[size - index - 1][starting + i] = square[size - index - 1][ending-i];
		square[size - index - 1][ending-i] = temp;
	}
}