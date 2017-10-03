// multiples5or7.c 
// Reads a positive integer num and count the number
// of multiples of 5 or 7 in the range [1, num].

#include <stdio.h>

int count_multiples(int);

int main(void) {
	int num, i, count = 0;

	printf("Enter positive integer: ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		if (count_multiples(i)){
			count++;
		}
	}

	switch (count) {
		case 1: 
		printf("There is %d multiple of 5 or 7 in [1,%d].\n", count, num);
		break;
		case 0:
		printf("There are no multiples of 5 or 7 in [1,%d].\n", num);
		break;
		default:
		printf("There are %d multiples of 5 or 7 in [1,%d].\n", count, num);
	}


	return 0;
}

// Precond: value > 0
int count_multiples(int value) {
	int boolean = 0;

	if (value % 5 == 0 || value % 7 == 0) {
		boolean = 1;
	}
	return boolean;
	
}
