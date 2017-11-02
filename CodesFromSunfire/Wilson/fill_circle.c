#include <stdio.h>
#include <math.h>
#define MAX 30


void print (char [][MAX]);

void init_array (char [][MAX]);
double cartesian_distance (int , int , int , int);
void fill_circle (char [][MAX], int , int , double);

int main () {
	int x, y;
	double radius;
	char matrix[MAX][MAX];
	
	init_array (matrix);

	printf ("Enter x,y coords: ");
	scanf ("%d %d", &x, &y);

	printf ("Enter radius: ");
	scanf ("%lf", &radius);

	fill_circle (matrix, x, y, radius);


	print (matrix);

}

void print (char matrix[][MAX]) {
	int i,d;
	for (i = 0; i < MAX; i++) {
		for (d = 0; d < MAX; d++) {
			printf ("%c ", matrix[i][d]);
		}
		printf ("\n");
	}
}

void init_array (char matrix[][MAX]) {
	int i, d;
	for (i = 0; i < MAX; i++) {
		for (d = 0; d < MAX; d++) {
			matrix[i][d] = ' ';
		}
	}
}

void fill_circle (char matrix[][MAX], int x, int y, double radius) {

	int i, d;
	for (i = 0; i < MAX; i++) {
		for (d = 0; d < MAX; d++) {
			if (cartesian_distance (x, y, d, i) <= radius) {
				matrix[i][d] = 'x';
			}
		}
	}
}

double cartesian_distance (int x, int y, int targetX, int targetY) {
	double differenceX = targetX - x;
	double differenceY = targetY - y;

	return sqrt (differenceX * differenceX + differenceY * differenceY); 
}
