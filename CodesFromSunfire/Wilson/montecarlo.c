/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex4
 * montecarlo.c
 * <Type your name here>
 * <Type your discussion group here>
 * <Fill in a description of this program>
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Given function prototype must not be changed
int throwDarts(int);

int main(void) {
	int darts_total,   // number of darts to be thrown
	    darts_inside;  // number of darts inside quadrant


	printf("How many darts? ");
	scanf("%d", &darts_total);


	darts_inside = throwDarts(darts_total);
	printf("Darts landed inside unit circle's quadrant = %d\n", darts_inside);
	printf("Approximated pi = %.4f\n", ((float)darts_inside/darts_total)*4.0);
	return 0;
}

int throwDarts(int darts_total) {
	int i=0, darts_inside;
	for (i = 0; i<darts_total; i++) {
		double x = rand()/2147483647.0;
		double y = rand()/2147483647.0;

		if (pow(x,2) + pow(y,2) <=1) {
			darts_inside++;
		}


	}
	return darts_inside;
}
