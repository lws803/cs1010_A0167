/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex3
 * bisection.c
 * <LER WEI SHENG>
 * <C04>
 * <Fill in a description of this program>
 */

#include <stdio.h>
#include "math.h"

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
	scanf("%lf %lf", &a, &b);


	while (pM != 0 && fabs(a - b)>0.0001){
		m = (a+b)/2.0;
		pA = polynomial(a, c3, c2, c1, c0);
		pB = polynomial(b, c3, c2, c1, c0);
		pM = polynomial(m, c3, c2, c1, c0);

		if ((pA > 0 && pM > 0 )|| (pA < 0 && pM < 0)){
			a = m;
		}
		else if ((pB > 0 && pM > 0) || (pB < 0 && pM < 0) ) {
			b = m;
		}
	}

	if (fabs(a-b) <= 0.0001) {
		//Approximated root
		m = (a+b)/2;
	}

	printf("root = %f\n", m);
	printf("p(root) = %f\n", polynomial(m, c3, c2, c1, c0));

	return 0;
}

//This function calculates the y value given the x coords
double polynomial(double x, int c3, int c2, int c1, int c0) {
	//x^3
	double coeff3 = pow(x, 3) * c3;
	double coeff2 = pow(x, 2) * c2;
	double coeff1 = x * c1;
	double constant = c0;

	return coeff3 + coeff2 + coeff1 + constant;
}







