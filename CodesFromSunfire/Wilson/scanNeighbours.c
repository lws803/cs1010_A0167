#include <stdio.h>
#define MAX 3


void display (int [MAX][MAX]);
void search_surrounding (int [MAX][MAX], int, int);

int main () {
	int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	printf("Current matrix:\n");
	display(arr);


	printf("We will now search and print all surrounding elements near 5...\n");
	search_surrounding(arr, 1, 1);
}


void display (int arr[MAX][MAX]) {
	int i, d;
	for (i = 0; i < 3; i++) {
		for (d = 0; d < 3; d++) {
			printf("%d ", arr[i][d]);
		}
		printf("\n");
	}
}

void search_surrounding (int arr[MAX][MAX], int x, int y) {
	int i, d;
	for (i = -1; y+i < MAX && y+i >= 0 && i < 2; i++) {
		for (d = -1; x+d < MAX && x+d >= 0 && d < 2; d++) {
			if (i == 0 && d == 0) {
				// position is at original coords
			}else {
				printf("%d ", arr[y+i][x+d]);
			}
		}
	}
	printf("\n");
}