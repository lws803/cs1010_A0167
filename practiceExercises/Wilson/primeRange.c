// countPrimes.c
// To count the number of primes in the range [1, limit]
// where limit is entered by user.
#include <stdio.h>

int is_prime(int);

int main(void) {    
	int limit, c, numberOfPrimes=0;

	printf("Enter limit: ");
	scanf("%d", &limit);


	for (c=1; c<=limit; c++) {
		if (is_prime(c)) {
			numberOfPrimes++;
		}
	}

	printf("Number of primes (1-%d): %d\n", limit, numberOfPrimes);

	return 0;
}

int is_prime(int i) {
	int counter = 2, boolean = 1;
	while(counter<i) {
		if (i%counter == 0){
			boolean = 0;
			break;
		}
		counter++;
	}

	if (i == 1) {
		boolean = 0;
	}
	return boolean;
}