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

// Display array
void display (char matrix[size][size]) {
	int i, d;
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			printf("%c ", matrix[i][d]);
		}
		printf("\n");
	}
}


// Flips an array diagonally (South east)
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

// Newly modified for efficiency and works for all scenarios 
// Flip an array wrt to a horizontal line from the centre. 
// Note: To introduce customisable row and cols, just include new arguments and edit the size variables inside. 
void flipH(int image[][MAX_SIZE], int size) {
	int i, d;
	int start = 0;
	int end = size-1;
	for (d = 0; d < size; d++) {
		for (i = 0; i <= (end-start)/2; i++) {
			int temp = image[start + i][d];
			image[start + i][d] = image[end-i][d];
			image[end-i][d] = temp;
		}
	}
}

// Flip an array wrt to a vertical line from the centre. 
void flipV(int image[][MAX_SIZE], int size) {
	int i, d;
	int start = 0;
	int end = size-1;
	for (d = 0; d < size; d++) {
		for (i = 0; i <= (end-start)/2; i++) {
			int temp = image[d][start + i];
			image[d][start + i] = image[d][end-i];
			image[d][end-i] = temp;
		}
	}
}



// Swapping rings in a square mtx, pay attention to the new swapping technique used. 
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