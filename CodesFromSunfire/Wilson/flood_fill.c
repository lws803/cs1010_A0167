#include <stdio.h>
#define MAX 12


void print (char [][MAX]);
void fill (char [][MAX], int , int );
void scan_array (char [][MAX]);


int main () {
	char matrix[MAX][MAX];
	int x, y;

	printf ("Enter array: \n");

	scan_array (matrix);

	printf ("Enter x y coords: ");

	scanf ("%d %d", &x, &y);


	fill (matrix, x, y);

	print (matrix);


}


void print (char matrix[][MAX]) {
	int i, d;
	for (i = 0; i < MAX; i++) {
		for (d = 0; d < MAX; d++) {
			printf ("%c ", matrix[i][d]);
		
		}
		printf ("\n");
	}
}


void scan_array (char matrix[][MAX]) {

	int i, d;
	for (i = 0; i < MAX; i++) {
		for (d = 0; d < MAX; d++) {
			scanf (" %c", &matrix[i][d]);
		}
	}
}


void fill (char matrix[][MAX], int x, int y) {	
	matrix[y][x] = 'x';


	if (x+1 < MAX && matrix[y][x+1] != 'x')
		fill (matrix, x+1, y);
	if (x-1 >= 0 && matrix[y][x-1] != 'x')
		fill (matrix, x-1, y);
	if (y-1 >= 0 && matrix[y-1][x] != 'x')
		fill (matrix, x, y-1);
	if (y+1 < MAX && matrix[y+1][x] != 'x')
		fill (matrix, x, y+1);
	
	// 8 directions not needed 

	/**
	if (x+1 < MAX && y+1 < MAX && matrix[y+1][x+1] != 'x')
		fill (matrix, x+1, y+1);
	
	if (x+1 < MAX && y-1 >= 0 && matrix[y-1][x+1] != 'x')
		fill (matrix, x+1, y-1);
	
	if (x-1 >= 0 && y+1 < MAX && matrix[y+1][x-1] != 'x')
		fill (matrix, x-1, y+1);
	
	if (x-1 >= 0 && y-1 >= 0 && matrix[y-1][x+1] != 'x')
		fill (matrix, x-1, y-1);
	
	*/
}
