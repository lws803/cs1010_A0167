#include "stdio.h"
#define MAX 50

void read_mtx(char [][MAX], int *, int *);
int put_trucks (char mtx[][MAX], int row, int col, int n);

int main(int argc, char const *argv[])
{
	int row, col;
	char mtx[MAX][MAX];
	read_mtx(mtx, &row, &col);
	for (int i = 0; i <= 4; i++) {
		printf("%d\n", put_trucks(mtx, row, col, i));
	}


	return 0;
}


// Must flatten n number of cars at the same time while it is parking

void read_mtx(char mtx[][MAX], int *row, int *col) {
	scanf ("%d %d", row, col);
	int i, d;
	for (i = 0; i < *row; i++) {
		for (d = 0; d < *col; d++) {
			scanf(" %c", &mtx[i][d]);
		}
	}
}

int put_trucks (char mtx[][MAX], int row, int col, int n) {
	int i, d, count = 0;
	for (i = 0; i < row-1; i++) {
		for (d = 0; d < col-1; d++) {
			int cars = 0, parking = 0;
			if (mtx[i][d] == 'X') cars++;
			if (mtx[i+1][d] == 'X') cars++;
			if (mtx[i+1][d+1] == 'X') cars++;
			if (mtx[i][d+1] == 'X') cars++;

			if (mtx[i][d] == '.') parking++;
			if (mtx[i+1][d] == '.') parking++;
			if (mtx[i+1][d+1] == '.') parking++;
			if (mtx[i][d+1] == '.') parking++;

			if (cars + parking == 4 && cars == n) {
				count++;
			}
		}
	}

	return count;
}