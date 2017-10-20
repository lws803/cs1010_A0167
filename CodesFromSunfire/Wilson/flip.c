// flip.c

#include <stdio.h>
#define MAX_SIZE 10

int scan(int [][MAX_SIZE]);
void print(int [][MAX_SIZE], int);
void flipH(int [][MAX_SIZE], int);
void flipD(int [][MAX_SIZE], int);

int main(void) {
	int image [MAX_SIZE][MAX_SIZE];
	int size = scan (image);
	char answer;
	printf("Enter direction: ");
	scanf (" %c", &answer);
	printf("The image after rotation: \n");
	

	switch (answer) {
		case 'h':
		flipH(image, size);	
		break;
		case 'd':
		flipD(image, size);
		break;
	}

	print(image, size);

	
	return 0;
}

// To flip an image horizontally
void flipH(int image[][MAX_SIZE], int size) {
	int i, d;
	if (size%2 != 0) {
		// even number of height
		for (i = 0; i < size/2; i++) {
			for (d = 0; d < size; d++) {
				// Swapping
				int t = image[i][d];
				image[i][d] = image[size - i - 1][d];
				image[size - i - 1][d] = t;
			}
		}

	}else {
		// odd number of height
		for (i = 0; i <= size/2; i++) {
			for (d = 0; d < size; d++) {
				// swapping
				int t = image[i][d];
				image[i][d] = image[size - i - 1][d];
				image[size - i - 1][d] = t;
			}
		}
	}

}

// To flip an image diagonally
void flipD(int image[][MAX_SIZE], int size) {
	int i, d;
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			// Ensures that only elements past the diagonal line is flipped
			if (d > i) {
				int t = image[i][d];
				image[i][d] = image[d][i];
				image[d][i] = t;
			}
			
		}
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
			scanf ("%d", &image[i][d]);
		}
	}

	return size;
}

// To print an image
void print(int image[][MAX_SIZE], int size) {
	int row = size, col = size;

	for (row = 0; row < size; row++) {
		for (col = 0; col < size; col++) 
			printf("%d ", image[row][col]);
		printf("\n");
	}
}
