/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex3
 * bisection.c
 * <Park Junhyuk>
 * <C06>
 * <Programme for bisection>
 */

#include <stdio.h>
#include <math.h>

double polynomial(double, int, int, int, int);

int main(void) {
	int    c3, c2, c1, c0; // coefficients of polynomial
	double a, b,           // endpoints
		   pA, pB;         // function values at endpoints
	double m, pM;
	double gradient;
	// midpoint and function value at midpoint

	printf("Enter coefficients (c3,c2,c1,c0) of polynomial: ");
	scanf("%d %d %d %d", &c3, &c2, &c1, &c0);

	printf("Enter endpoints a and b: ");
	scanf("%lf %lf",&a, &b); 
	do {
		m = (a+b)/2;
		pA= polynomial(a,c3,c2,c1,c0);
		pB= polynomial(b,c3,c2,c1,c0);
		pM= polynomial(m,c3,c2,c1,c0);
		gradient = pB - pA; //determine whether it has a downward slope or upward slope 
		if (gradient > 0 && pM > 0) { //if loops are used here to determine whether to replace a or b with m
			pB = pM;
			b = m; 
		}
		else if (gradient > 0 && pM < 0) {
			pA = pM;
			a = m;
		}
		else if (gradient < 0 && pM > 0) {
			pA = pM;
			a = m; 
		}
		else if (gradient < 0 && pM < 0){
			pB=pM;
			b = m;
		}
	} 
	while(fabs(a-b)>=0.0001 && pM!=0); 
	if (pM!=0) {
		m = (a+b)/2;
		pM = polynomial(m,c3,c2,c1,c0);
	}

	printf("root = %lf\n", m);
	printf("p(root) = %lf\n", pM);

	return 0;
}

double polynomial(double input,int c3,int c2,int c1,int c0) { //function used to calculate the value of the polynomial given x
	double value;
	value = c3*pow(input,3) + c2*pow(input,2) + c1*input + c0;
	return value;
}

