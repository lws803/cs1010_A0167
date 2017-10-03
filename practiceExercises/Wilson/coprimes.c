// countCoprimes.c
// To count the number of pairs of integers in the range [2, limit]
// which are coprime.
#include <stdio.h>

//int count_coprimes(int);
int gcd(int, int);
int count_coprimes(int);

int main(void) {
	
	int limit;

	printf("Enter limit: ");
	scanf("%d", &limit);

	printf("Answer = %d\n", count_coprimes(limit));



	return 0;
}


// Return the number of pairs of integers in the range [2, lim]
// which are coprime.
// Precond: lim > 2
int count_coprimes(int lim) {
	int i, count = 0;

	for (i = 2; i < lim; ++i)
	{
		int j;
		for (j = 3; j<=lim; j++){
			if (gcd(j, i) == 1 && j>i) {
				count++;
			}
		}

	}

	return count; // this is just a dummy return value
}

// Return the GCD of a and b
// This is a badly written gcd() function. We will discuss this
// function and write a better one in Week 6 discussion session. 
// Precond: a>=0, b>=0 and not both = 0
int gcd(int a, int b) {
	int divisor, r, notDivisor;

	if (a == 0) return b;
	else if (b == 0) return a;

	if (a < b) {
		divisor = a;
		notDivisor = b;
	} 
	else 
	{
		divisor = b;
		notDivisor = a;
	}

	while (divisor>0) {
		r = notDivisor%divisor;
		notDivisor = divisor;
		divisor = r;
	}
	return notDivisor;
}
