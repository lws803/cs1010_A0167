// primeTest.c
// To check if a number is prime.
#include <stdio.h>

int is_prime(int);

int main(void) {    
	int value;

	printf("Enter a positive integer: ");
	scanf("%d", &value);

	if (is_prime(value)) 
		printf("%d is a prime.\n", value);
	else
		printf("%d is not a prime.\n", value);

	return 0;
}

// Write a description for this function,
// and fill in the precondition below.
// Precond: integer must be positive above 0
int is_prime(int n) {
	int counter;
	if (n < 2){
		return 0;
	}
	for (counter = 2; counter < n; counter++){
		if (n%counter == 0) {
			return 0;
		}
	}
	return 1;
}
