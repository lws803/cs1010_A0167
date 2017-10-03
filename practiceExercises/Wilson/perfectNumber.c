// perfectNumber.c 
// Repeatedly reads a non-negative value, and stops when zero is read.
// For each positive value read, it checks if the value is a perfect number.

#include <stdio.h>

int is_perfect(int);

int main(void) {
	int num = 1;

	do {
		printf("Enter number: ");
		scanf("%d", &num);

		if (is_perfect(num) != num && num != 0) {
			printf("%d is not a perfect number.\n", num);
		}else if (num != 0){
			printf("%d is a perfect number.\n", num);
		}
	}while(num > 0);


	return 0;
}


int is_perfect(int num) {
	int i, sum = 0;

	for (i = 1; i<num; i++){
		if (num % i == 0) {
			sum += i;
		}
	}

	return sum;
}