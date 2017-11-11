// Count the number of islands surounded by water 

#include <stdio.h>
#define MAX 100

void scan_island (int [][MAX], int *, int *); 
int count_islands (int [][MAX], int , int ); 
void floodfill (int [][MAX], int , int , int , int ); 

int main () {

	int row, col, arr[MAX][MAX];
	scan_island (arr, &row, &col);

	printf("Num islands: %d\n", count_islands(arr, row, col));
}


void scan_island (int arr[][MAX], int *row, int *col) {
	int srow, scol;
	printf("Enter num rows: ");
	scanf ("%d", &srow);
	printf("Enter num cols: ");
	scanf("%d", &scol);

	int i, d;
	for (i = 0; i < srow; i++) {
		for (d = 0; d < scol; d++) {
			scanf ("%d", &arr[i][d]);
		}
	}
	*row = srow;
	*col = scol;
}

int count_islands (int arr[][MAX], int row, int col) {
	int count = 0;
	int i, d;
	for (i = 0; i < row; i++) {
		for (d = 0; d < col; d++) {
			if (arr[i][d] == 1) {
				count++;
				// Drops the seed 
				floodfill (arr, d, i, row, col); // Flood fill and change em to 2
			}
		}
	}
	return count;
}


void floodfill (int arr[][MAX], int x, int y, int row, int col) {
	arr[y][x] = 2;
	if (y+1 < row && arr[y+1][x] == 1) {
		floodfill (arr, x, y+1, row, col);
	}
	if (y-1 >= 0 && arr[y-1][x] == 1) {
		floodfill (arr, x, y-1, row, col);
	}
	if (x+1 < col && arr[y][x+1] == 1) {
		floodfill (arr, x+1, y, row, col);
	}
	if (x-1 >= 0 && arr[y][x+1] == 1) {
		floodfill (arr, x-1, y, row, col);
	}
}