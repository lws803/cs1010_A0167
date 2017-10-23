#include <stdio.h>

#define MAX 10

void scanMatrix (int [MAX][MAX], int);

float d_cen (int [][MAX], int , int );

int main () {
	int matrix[MAX][MAX], size, dcen_number;
	printf("Enter size: ");
	scanf("%d", &size);
	scanMatrix(matrix, size);

	printf("Enter dcen number: ");
	scanf("%d", &dcen_number);
	printf("%f\n", d_cen(matrix, size, dcen_number));

}

void scanMatrix (int matrix[][MAX], int size) {
	int i, d;
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			scanf("%d", &matrix[i][d]);
		}
	}
}


float d_cen (int matrix[][MAX], int size, int number) {
	number -= 1;
	int i, sum_adjacent = 0;

	// Scans the columns 
	for (i = 0; i < size; i++) {
		if (matrix[number][i] == 1) {
			sum_adjacent++;
		}
	}

	float dCen = sum_adjacent/(float)(size - 1);

	return dCen;

}
