#include "stdio.h"
#define MAX 100

void fill (char matrix[][MAX], int x, int y, int row, int col);
int count (char mtx[][MAX], int row, int col);
void read (char mtx[][MAX]);

int main(int argc, char const *argv[])
{
	char mtx[MAX][MAX];
	read (mtx);


	return 0;
}

void read (char mtx[][MAX]) {
	int row, col, thisCase = 0;
	while (scanf("%d %d", &row, &col) != EOF) {
		thisCase++;
		for (int i = 0; i < row; i++) {
			for (int d = 0; d < col; d++) {
				scanf(" %c", &mtx[i][d]);
			}
		}
		printf("Case %d: %d\n", thisCase, count(mtx, row, col));
	}
}


int count (char mtx[][MAX], int row, int col) {
	int i, d, num = 0;

	for (i = 0; i < row; i++) {
		for (d = 0; d < col; d++) {
			if (mtx[i][d] == '-') {
				fill(mtx, d, i, row, col);
				num++;
			}
		}
	}
	return num;
}

void fill (char matrix[][MAX], int x, int y, int row, int col) {	
	matrix[y][x] = 'x';


	if (x+1 < col && matrix[y][x+1] == '-')
		fill (matrix, x+1, y, row, col);
	if (x-1 >= 0 && matrix[y][x-1] == '-')
		fill (matrix, x-1, y, row, col);
	if (y-1 >= 0 && matrix[y-1][x] == '-')
		fill (matrix, x, y-1, row, col);
	if (y+1 < row && matrix[y+1][x] == '-')
		fill (matrix, x, y+1, row, col);
}