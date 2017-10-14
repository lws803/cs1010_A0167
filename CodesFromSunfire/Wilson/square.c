/**
 * CS1010 AY2017/8 Semester 1 Lab5 Ex1
 * square.c
 * Given the size of a square and the values in
 * in the square, this program determines whether 
 * the given square is a semi-magic square.
 * <LER WEI SHENG>
 * <C04>
 */

#include <stdio.h>
#define MAXSIZE 9

int scanSquare(int [][MAXSIZE]);
int isSemiMagic (int [][MAXSIZE], int);

int main(void) { 
	// Use the following printf statements 
	// for printing the output.
	int square[MAXSIZE][MAXSIZE];

	if (isSemiMagic(square, scanSquare(square))) {
		printf("It is a semi-magic square.\n");  

	}else{
		printf("It is not a semi-magic square.\n");
	}


	return 0;
}

// Read in size of square and values in the square. 
// Return the size of square.
int scanSquare(int square[][MAXSIZE]) {
	int r, c, size;

	printf("Enter size of square: ");
	scanf("%d", &size);

	printf("Enter values in the square: \n");
	for (r=0; r<size; r++) {
		for (c=0; c<size; c++) {
			scanf("%d", &square[r][c]);
		}
	}

	return size;
}

/**
Checks if the square is semi magic or not
Precond: none
*/

int isSemiMagic (int square[][MAXSIZE], int size) {
	// condition 1: must contain all numbers from 1 to n^2
	// condition 2: row sums and column sums must be the same 

	// To check if a square contains all numbers from 1 to n^2
	// Using brute force 
	int i,d, check, count = 0; 
	for (check = 1; check <= size*size; check++) {
		for (i = 0; i < size; i++) {
			for (d = 0; d < size; d++) {
				if (square[i][d] == check) {
					count++;
				}
			}
		}
	}
	
	if (count != size*size) {
		return 0;
	}


	int constant = 0, firstRun = 0, sum = 0;
	// Column checker 
	for (i = 0; i < size; i++) {
		sum = 0;
		for (d = 0; d < size; d++) {
			if (!firstRun) {
				constant += square[i][d];
			} 
			sum += square[i][d];
 		}
 		firstRun = 1;
 		if (sum != constant) {
 			return 0;
 		}
	}

	// Row checker
	for (i = 0; i < size; i++) {
		sum = 0;
		for (d = 0; d < size; d++) {
			sum += square[d][i];
		}
		if (sum != constant) {
			return 0;
		}
	}

	return 1;
}

