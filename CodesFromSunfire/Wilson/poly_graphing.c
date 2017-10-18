#include <stdio.h>
#include <math.h>
#define XMAX 60
#define YMAX 20

double polynomial (double);
void plotGraph (char [YMAX][XMAX], double, double);
void display (char [YMAX][XMAX]);
void init (char [YMAX][XMAX]);


int main () {
	char matrix[YMAX][XMAX];


	init(matrix);

	plotGraph(matrix, -5.1, 5.0);

	display (matrix);
}

void init (char matrix[YMAX][XMAX]) {
	int i, d;
	for (i = 0; i < YMAX; i++) {
		for (d = 0; d < XMAX; d++) {
			matrix[i][d] = ' ';		
		}
	}
}

void display (char matrix[YMAX][XMAX]) {
	int i, d;
	for (i = 0; i < YMAX; i++) {
		for (d = 0; d < XMAX; d++) {
			printf("%c ", matrix[i][d]);
		}
		printf("\n");
	}
}


void plotGraph (char matrix[YMAX][XMAX], double rangeX_1, double rangeX_2) {
	double i, min;
	int d;

	double increment = fabs(rangeX_2 - rangeX_1)/XMAX;

	double Y_range = fabs(polynomial(rangeX_2) - polynomial(rangeX_1));

	// Find min 

	if (polynomial(rangeX_1) > polynomial(rangeX_2)) {
		min = polynomial(rangeX_2);
	}else{
		min = polynomial(rangeX_1);
	}

	for (i = rangeX_1, d = 0; i <= rangeX_2; i += increment, d++) {
		int Y = (YMAX-1) - (fabs(polynomial(i) - min)/Y_range)*(YMAX-1); 
		matrix[Y][d] = 'x';

	}
}

double polynomial (double x) {
	double y = x*x*x + 2*x*x + 5.0;

	return y;
}