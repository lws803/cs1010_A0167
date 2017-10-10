#include <stdio.h>
#define MAX 8


// Mine sweeper scanner 

/*
Example input
Minefield: 
___****_
_*_**_**
********
_*_*__*_
********
**_*_**_
________
********

Search pattern:
***
*_*

Answer = 4

*/

int searchFunc(char[][MAX], char[][3]);


int main () {
	char minefield[MAX][MAX];
	char search[2][3];
	int i, d;
	printf("Enter minefield:\n");
	for (i = 0; i < MAX; i++){
		for (d = 0; d < 8; d++){
			scanf(" %c", &minefield[i][d]);
		}
	}

	printf("Enter search pattern:\n");
	for (i = 0; i < 2; i++){
		for (d = 0; d < 3; d++){
			scanf(" %c", &search[i][d]);
		}
	}

	printf("Answer = %d\n", searchFunc(minefield, search));

}



int searchFunc(char minefield[][MAX], char search[][3]){
	int c, d, count = 0;;

	for (c = 0; c < MAX - 2; c++){
		for (d = 0; d < MAX - 3; d++) {
			if (minefield[c][d] == search[0][0] && minefield[c][d+1] == search[0][1] && minefield[c][d+2] == search[0][2]){
				if (minefield[c+1][d] == search[1][0] && minefield[c+1][d+1] == search[1][1] && minefield[c+1][d+2] == search[1][2]){
					count++;
				}
			}
		}
	}

	return count;
}
