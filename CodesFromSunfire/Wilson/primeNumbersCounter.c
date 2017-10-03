#include "stdio.h"


int main(int argc, char const *argv[])
{
	
	int low, high, i; 
	printf("Enter high low to find the prime numbers in b/w: ");
	scanf("%d %d", &low, &high);

	for (i = low; i < high; ++i)
	{
		int primeNumberChecker, successfulDivisions = 0;

		for (primeNumberChecker = 2; primeNumberChecker<i; ++primeNumberChecker)
		{
			if (i % primeNumberChecker==0){
				successfulDivisions++;
			}
		}
		if (successfulDivisions == 0 && i != 1) {
			printf("%d is a prime\n", i);
		}

	}

	return 0;
}
