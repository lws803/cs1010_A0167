#include <stdio.h>
#include <math.h>

int main () {
	// Splitting chunks of number 

	int n = 1234567890;
	long long num = 1234567890;


	while (n) {
		printf ("Chunk: %d\n", n%1000);

		n /= 1000;
	}
	// splits the digits from the bottom up 
	// OUTPUT: 890 567 234 1

	int i;
	int numberSegment = 3, numberOfDigits = 10;
	for (i = numberOfDigits; i >= 0; i-=numberSegment) {
		printf("Chunk top: %lli\n", (num/(long long)pow(10, i))%(long long)pow(10,numberSegment));
	}
	// splits the digits from the top down
	// OUTPUT: 0 123 456 789 

}