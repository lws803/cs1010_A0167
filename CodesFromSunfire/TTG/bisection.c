/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex3
 * bisection.c
 * Tan Tze Guang
 * C06
 * This program computes the root r of a function f.
 */

#include <stdio.h>
#include <math.h>

// Given function prototype must not be changed
double polynomial(double, int, int, int, int);

int main(void) {
	int    c3, c2, c1, c0; // coefficients of polynomial
	double a, b,           // endpoints
	       pA, pB;         // function values at endpoints
	double m, pM;          // midpoint and function value at midpoint

	printf("Enter coefficients (c3,c2,c1,c0) of polynomial: ");
	scanf("%d %d %d %d", &c3, &c2, &c1, &c0);

	printf("Enter endpoints a and b: ");
	scanf("%lf %lf",&a,&b);
	
	do {
		m = ((a+b)/2.0);
		pM = polynomial(m,c3,c2,c1,c0);
		pA = polynomial(a,c3,c2,c1,c0);
		pB = polynomial(b,c3,c2,c1,c0);
		
		if ((pM > 0 && pA >0) || (pM < 0 && pA < 0)) {
			a = m;
		}
		else if ((pM > 0 && pB >0) || (pM < 0 && pB < 0)) {
			b = m;
		}
		
	} while ((fabs(a-b) >= 0.0001) && (pM != 0));

	if (fabs(a-b)<= 0.0001) {
		m = (a+b)/2;
	}
	pM = polynomial(m,c3,c2,c1,c0);
	printf("root = %f\n", m);
	printf("p(root) = %f\n", pM);

	return 0;
}

// Returns the result of the polynomial after substituting the values into the equation
double polynomial(double m,int c3,int c2,int c1,int c0) {
	double coe3 = c3*pow(m,3.0);
	double coe2 = c2*pow(m,2.0);
	double coe1 = c1*pow(m,1.0);
	double cons = (double) c0;
	double result = coe3 + coe2 + coe1 + cons;
	return result;
}