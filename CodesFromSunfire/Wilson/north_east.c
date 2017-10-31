// north_east.c
// Compute the number of north-east paths.
#include <stdio.h>

int ne(int, int);

int main(void) {
	int rows, cols;

	printf("Enter rows and columns apart: ");
	scanf("%d %d", &rows, &cols);
	printf("Rows and columns apart: %d %d\n", rows, cols);

	printf("Number of NE-paths = %d\n", ne(rows, cols));
	
	return 0;
}

// Compute number of north-east paths between two points 
// that are x rows and y columns apart.
// Precod: x>=0, y>=0
int ne(int y, int x) {

	if (x == 0 && y == 0) {
		return 1;
	} 
	int npaths = 0, epaths = 0;
	if (y != 0) {
		npaths = ne(y - 1, x);
	}
	if (x != 0) {
		epaths = ne (y, x - 1);
	}
	return npaths + epaths;
}

