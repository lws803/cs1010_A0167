#include <stdio.h>
#include <math.h>
#define XMAX 60
#define YMAX 20

double polynomial (double);
void plotGraph (char [YMAX][XMAX], double, double);
void display (char [YMAX][XMAX]);
void init (char [YMAX][XMAX]);
double findMin (double , double );
double findMax (double , double );
void plant_Y_axis (char [YMAX][XMAX], double, double);
void plant_X_axis (char [YMAX][XMAX], double, double);

int main () {
	double rangeX_1, rangeX_2;
	char matrix[YMAX][XMAX];
	init(matrix);
	printf("Enter range: ");
	scanf("%lf %lf", &rangeX_1, &rangeX_2);
	plotGraph(matrix, rangeX_1, rangeX_2);

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
			printf("%c", matrix[i][d]);
		}
		printf("\n");
	}
}

void plotGraph (char matrix[YMAX][XMAX], double rangeX_1, double rangeX_2) {
	double i, min, max, y_range;
	int d, c;

	double increment = fabs(rangeX_2 - rangeX_1)/XMAX;
	max = findMax(rangeX_1, rangeX_2);
	min = findMin(rangeX_1, rangeX_2);

	plant_Y_axis(matrix, rangeX_1, rangeX_2);
	plant_X_axis(matrix, rangeX_1, rangeX_2);
	printf("Min: %lf Max: %lf\n", min, max);
	// TODO: Add the axis 


	for (i = rangeX_1, d = 0; i < rangeX_2; i += increment, d++) {
		// Ratio 
		int Y = ((polynomial(i)-max)/(min-max))*(YMAX-1);
		matrix[Y][d] = 'x';
	}


}

double polynomial (double x) {
	double y = x*x*x + 2*x*x +5.0;
	//double y = x*x - 5;
	return y;
}

double findMin (double rangeX_1, double rangeX_2) {
	double i, min;
	min = polynomial(rangeX_1);
	double increment = fabs(rangeX_2 - rangeX_1)/XMAX;

	for (i = rangeX_1; i < rangeX_2; i += increment) {
		if (polynomial(i) < min) {
			min = polynomial(i);
		}
	}
	return min;
}

double findMax (double rangeX_1, double rangeX_2) {
	double i, max;
	max = polynomial(rangeX_1);
	double increment = fabs(rangeX_2 - rangeX_1)/XMAX;
	for (i = rangeX_1; i < rangeX_2; i += increment) {
		if (polynomial(i) > max) {
			max = polynomial(i);
		}
	}
	return max;
}

void plant_Y_axis (char matrix[YMAX][XMAX], double rangeX_1, double rangeX_2) {
	int d, index;
	double increment = fabs(rangeX_2 - rangeX_1)/XMAX;
	double i, closestTo = rangeX_1;
	if (rangeX_1 <= 0 && rangeX_2 >= 0) {
		for (i = rangeX_1, d = 0; i < rangeX_2; i += increment, d++) {
			if (fabs(i) < fabs(closestTo)) {
				closestTo = i;
				index = d;
			}
		}
		for (d = 0; d < YMAX; d++) {
			matrix[d][index] = '|';
		}
	}
}

void plant_X_axis (char matrix[YMAX][XMAX], double rangeX_1, double rangeX_2) {
	int index, d;
	double max = findMax(rangeX_1, rangeX_2);
	double min = findMin(rangeX_1, rangeX_2);
	double increment = fabs(rangeX_2 - rangeX_1)/XMAX;
	double i, closestTo = ((polynomial(rangeX_1)-max)/(min-max))*(YMAX-1);

	if (findMin(rangeX_1, rangeX_2) <= 0 && findMax(rangeX_1, rangeX_2) >= 0) {
		for (i = rangeX_1; i < rangeX_2; i += increment) {
			if (fabs(polynomial(i)) < fabs(closestTo)) {
				int Y = ((polynomial(i)-max)/(min-max))*(YMAX-1);
				closestTo = polynomial(i);
				index = Y;
			}
		}
		for (d = 0; d < XMAX; d++) {
			if (matrix[index][d] == '|') {
				matrix[index][d] = '+';
			}else {
				matrix[index][d] = '-';
			}
		}
	}
}