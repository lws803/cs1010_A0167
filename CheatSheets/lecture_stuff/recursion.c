#include <stdio.h>

int factorial (int);
int fibonacci (int);
int euclid (int, int);
int count = 0;

int main () {
	// Common uses: Factorial, Fibonacci, TOH
	// A function that calls itself.
	// Iterative code is one with loops rather than recursion 
	printf ("Factorial: \n");
	printf("%d, count: %d runs\n", factorial (12), count);




	count = 0;
	printf ("Fib: \n");
	printf ("%d, count: %d runs\n", fibonacci (12), count);

	count = 0;
	printf ("GCD: \n");
	printf ("%d, count: %d runs\n", euclid (12, 10), count);

}

// Factorial 
int factorial (int n) {
	count++;
	if (n == 0) { // base case
		// Termination - stopping condition 
		return 1;
	}else{
		// Recursion 
		return n * factorial (n-1);
	}
}


// Fibonacci series 
int fibonacci (int n) {
	count++;
	if (n < 2) { // Base case
		// Termination
		return n;
	}else {
		// Recursion 
		return fibonacci (n-1) + fibonacci (n-2);
	}
}

// Euclid's algo 
int euclid (int a, int b) {
	if (b == 0) {
		return a;
	}else {
		return euclid (b, a%b);
	}
}

// Order of statements in recursive functions matter 
// Tracing of recursion algos 
void mystery (int n) {
	if (n > 0) {
		printf ("%d", n%10);
		mystery (n/10);
	}
}
/* vs */
void mystery2 (int n) {
	if (n > 0) {
		mystery (n/10);
		printf ("%d", n%10);
	}
}


// Can create a recursive function header to start off the recursion streak

// TOH 
/* 
if (n>0):
	move n – 1 disks from the source peg to the temp peg using the dest peg
	move disk n from the source peg to the dest peg
	move n – 1 disks from the temp peg to the dest peg using the source peg
*/
