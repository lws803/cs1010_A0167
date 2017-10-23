/**
 * CS1010 AY2017/8 Semester 1 Lab5 Ex2
 * Given a 12x12 integer array, fill it with integers, and
 * find the longest sequence of a digit that appears in 
 * the array horizontally, vertically or diagonally.
 * <Tan Tze Guang>
 * <C06>
 */

#include <stdio.h>
#define DIM 12

// Fill in the function prototypes below
int scanBoard(int[][DIM]);
int search(int[][DIM],int,int*, int*);
int lookD(int[][DIM],int,int,int);
int lookV(int[][DIM],int,int,int);
int lookH(int[][DIM],int,int,int);

int main(void) {
	int board[DIM][DIM] = { {0} };
	int search_digit;     
	int length;           // length of the longest sequence of search digit
	int bestRow, bestCol; // where the longest sequence of search digit starts in the board

	// call scanBoard() 
	search_digit = scanBoard(board);
	// call search()
	length = search(board,search_digit,&bestRow,&bestCol);		// Used pointers to simplify extracting the coordinates of the sequence.

	if (length > 0) {
		printf("Length of longest sequence = %d\n", length); 
		printf("Start at (%d,%d)\n", bestRow, bestCol);      
	}
	else
		printf("No such sequence.\n");

	return 0;
}

// 	Accepts user input into the array of 12 by 12.
//	Fills up the array with numbers until the array has reached its limit.
//	Accepts final user input as the search digit, returns it to be used in the main function.
//	Precond: NIL 
int scanBoard(int arr[][DIM]) {
	int i,j,searchDigit;
	for (i=0;i<DIM;i++)				// Initialise the table of values
		for(j=0;j<DIM;j++)
			scanf("%d",&arr[i][j]);
	scanf("%d",&searchDigit);		// Grab the search digit and 
	
	return searchDigit;
}

//	Searches the array for the search digit. Once found, it will determine the length of the sequences
//	in the 3 directions of vertical, horizontal and diagonal.
//	It will then take the first instance of the longest subsequence and store it in the pointers pointing to the bestRow and bestCol.
//	If there are no subsequences found in any direction in the entire array, return 0.
// 	Precond: array is not empty, Digit is a number.
int search(int arr[][DIM],int digit,int *r, int *c) {
	int i,j;
	int longest=1,change = 0;
	int r1,r2,r3;
	
	for (i=0;i<DIM;i++){			// Searches for the digit in the array of numbers
		for(j=0;j<DIM;j++){
			if (arr[i][j] == digit){// Once found, the check for the 3 methods the sequence can go.
				r1 = lookV(arr,digit,i,j);
				r2 = lookH(arr,digit,i,j);
				r3 = lookD(arr,digit,i,j);
				
				if (r1 > longest){
					longest = r1;
					*r = i;
					*c = j;
				}
				if (r2 > longest){
					longest = r2;
					*r = i;
					*c = j;
				}
				if (r3 > longest){
					longest = r3;
					*r = i;
					*c = j;
				}
			}
		}
	}
	if (longest == 1)				// If no sequence is found when the length is 1, return 0.
		return 0;
	return longest;
}
//	Returns the length of the longest string found in the Vertical direction.
// 	Precond: array is not empty, Digit is a number.
int lookV(int arr[][DIM],int digit,int i,int j){
	int length = 0;
	for (;i<DIM;i++){
		if (arr[i][j]==digit){
			length++;
		}
		else break;
	}
	return length;
}

//	Returns the length of the longest string found in the Horizontal direction.
// 	Precond: array is not empty, Digit is a number.
int lookH(int arr[][DIM],int digit,int i,int j){	
	int length = 0;
	for (;j<DIM;j++){
		if (arr[i][j]==digit){
			length++;
		}
		else break;
	}
	return length;
}

//	Returns the length of the longest string found in the Diagonal direction.
// 	Precond: array is not empty, Digit is a number.
int lookD(int arr[][DIM],int digit,int i,int j){
	int length = 0;
	for (;i<DIM;i++){
		if (arr[i][j]==digit){
			length++;
		}
		else break;
		j++;
	}
	
	return length;
}