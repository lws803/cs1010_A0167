/**
 * CS1010 AY2017/8 Semester 1 Lab5 Ex1
 * square.c
 * Given the size of a square and the values in
 * in the square, this program determines whether 
 * the given square is a semi-magic square.
 * <Tan Tze Guang>
 * <C06>
 */

#include <stdio.h>
#define MAXSIZE 9

int scanSquare(int [][MAXSIZE]);
int isSemiMagic(int [][MAXSIZE],int);

int main(void) { 
	int magicSquare[MAXSIZE][MAXSIZE];
	int size,i,j;
	
	size = scanSquare(magicSquare);
	
	if (isSemiMagic(magicSquare,size))
		printf("It is a semi-magic square.\n");  
	else
		printf("It is not a semi-magic square.\n");

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

// A boolean function that sums the rows and columns of the array and checks that the sums are all the same.
// Also checks that all the numbers from 1 to n^2 are in the semi magic square to determine if it is indeed semi magic.
// Precond: size > 1
int isSemiMagic(int arr[][MAXSIZE],int size){
	int r,c,i,first=1;
	int Sum = 0;
	int	magicNo = 0,counter = 0,checkNo = 1;
	
	for (r=0;r<size;r++){			// summing up values in rows.
		Sum = 0;
		for (c=0;c<size;c++){
			Sum += arr[r][c];
		}
		if (first){					// check if it is the first run.
			magicNo = Sum;
			first = 0;
		}
		if (Sum != magicNo)
			return 0;
	}
	
	for (r=0;r<size;r++){			// summing up values in columns.
		Sum = 0;
		for (c=0;c<size;c++){
			Sum += arr[c][r];
		}
		if (Sum != magicNo)
			return 0;
	}
	for (i=1;i<=size*size;i++){		// check that all numbers that should be around are present
		for (r=0;r<size;r++){
			for (c=0;c<size;c++){
				if (arr[r][c] == checkNo){
					counter++;
					checkNo++;
				}
			}
		}
	}
	if (counter != size*size)
		return 0;

	return 1;
}