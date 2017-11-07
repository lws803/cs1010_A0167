#include <stdio.h>
#define MAX_ROWS 8
#define MAX_COLS 8

int search(char[][MAX_COLS],char[][3]);
int comparePattern(char A[][MAX_COLS],char pattern[][3],int row,int col);
void printA(char arr[][MAX_COLS],int size,int size2);

int main(void) {
	char A[MAX_ROWS][MAX_COLS];
	char pattern[2][3];
	int repetitions;
	int i,j;
	
	for (i=0;i<MAX_ROWS;i++){
		for (j=0;j<MAX_COLS;j++){
			scanf(" %c",&A[i][j]);
		}
	}
	
	for (i=0;i<2;i++){
		for (j=0;j<3;j++){
			scanf(" %c",&pattern[i][j]);
		}
	}
	
	printA(A,MAX_ROWS,MAX_COLS);
	printf("\n");
	printA(pattern,2,3);
	printf("\n");
	
	repetitions = search(A,pattern);
	printf("Answer = %d",repetitions);
	return 0;
	
}

int search(char A[][MAX_COLS],char pattern[][3]){
	int i,j,q;
	int count = 0;
	for (i=0;i<MAX_ROWS-3;i++){				//loop through the rows
		for (j=0;j<MAX_COLS-4;j++){			//loop through the columns
			if (comparePattern(A,pattern,i,j))
				count++;	//Compare pattern
		}
	}
	return count;
}

int comparePattern(char A[][MAX_COLS],char pattern[][3],int row,int col){
	int i,j;
	if ((A[row][col]==pattern[0][0]) && (A[row][col+1]==pattern[0][1]) && (A[row][col+2]==pattern[0][2]) 
		&& (A[row+1][col]==pattern[1][0]) && (A[row+1][col+1]==pattern[1][1]) && (A[row+1][col+2]==pattern[1][2]))
		return 1;
	else
		return 0;
}

void printA(char arr[][MAX_COLS],int size,int size2){
	int i,j;
	for (i=0;i<size;i++){
		for (j=0;j<size2;i++){
			printf("%c",arr[i][j]);
		}
		printf("\n");
	}
}
