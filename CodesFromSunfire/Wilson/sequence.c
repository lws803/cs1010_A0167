/**
 * CS1010 AY2017/8 Semester 1 Lab5 Ex2
 * Given a 12x12 integer array, fill it with integers, and
 * find the longest sequence of a digit that appears in 
 * the array horizontally, vertically or diagonally.
 * <Ler Wei Sheng>
 * <C04>
 */

#include <stdio.h>
#define DIM 12

// Fill in the function prototypes below

void search(int [DIM][DIM], int);
void scanBoard(int [][DIM]);

int checkDiag (int [DIM][DIM], int, int, int);
int checkHorizontal (int [DIM][DIM], int, int, int);
int checkVertical (int [DIM][DIM], int, int, int);

int main(void) {
	int board[DIM][DIM] = { {0} };
	int search_digit;     

	scanBoard(board); 

	scanf("%d", &search_digit);

	search(board, search_digit);

	return 0;
}

// Fill in the description of the function.
void scanBoard(int arr[][DIM]) {
	int i, d;
	for (i = 0; i < DIM; i++) {
		for (d = 0; d < DIM; d++) {
			scanf("%d", &arr[i][d]);
		}
	}

}


// Fill in the description of the function.
void search(int board[DIM][DIM], int number) {
	// Horizontal check 
	int i, d, count_overall = 0, X, Y;
	for (i = 0; i < DIM; i++) {
		for (d = 0; d < DIM; d++) {
			if (board[i][d] == number) {
				int count_horizontal = checkHorizontal(board, number, d, i);
				int count_vertical = checkVertical(board, number, d, i);
				int count_diagonal = checkDiag(board, number, d, i);

				if (count_overall < count_horizontal) {
					count_overall = count_horizontal;
					X = d;
					Y = i;
				}

				if (count_overall < count_vertical) {
					count_overall = count_vertical;
					X = d;
					Y = i;
				}

				if (count_overall < count_diagonal) {
					count_overall = count_diagonal;
					X = d;
					Y = i;
				}
			}
		}
	}

	if (count_overall > 0) {
		printf("Length of longest sequence = %d\n", count_overall);
		printf("Start at (%d,%d)\n", Y, X);
	}else {
		printf("No such sequence.\n");
	}
	

}

int checkDiag (int board[DIM][DIM], int number, int startingX, int startingY) {
	int i, d, count = 0;
	for (i = startingX; i < DIM; i++) {
		if (board[startingY][i] == number) {
			count++;
		}else {
			break;
		}
		startingY++;
	}
	return count;
}

int checkHorizontal (int board[DIM][DIM], int number, int startingX, int startingY) {
	int i, count = 0;
	for (i = startingX; i < DIM; i++) {
		if (board[startingY][i] == number) {
			count++;
		}else {
			break;
		}

	}
	return count;
}


int checkVertical (int board[DIM][DIM], int number, int startingX, int startingY) {
	int i, count = 0;
	for (i = startingY; i < DIM; i++) {
		if (board[i][startingX] == number) {
			count++;
		}else {
			break;
		}
	}
	return count;
}



