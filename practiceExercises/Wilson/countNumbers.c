#include <stdio.h>

int count_numbers(int, int, int, int);

int main() {
	int divisor1, divisor2, limit1, limit2;


	do {
		printf("Enter 2 divisors: ");
		scanf("%d %d", &divisor1, &divisor2);
	}while (divisor1 == divisor2 || divisor1 <= 0 || divisor2 <= 0);


	do {
		printf("Enter lower and upper limits: ");
		scanf("%d %d", &limit1, &limit2);
	}while(limit1 == limit2 || limit1 <= 0 || limit2 <= 0 || limit2 < limit1);
	



	printf("Answer = %d\n", count_numbers(limit1, limit2, divisor1, divisor2));

}


int count_numbers (int limit1, int limit2, int div1, int div2) {
	int i, count = 0;
	for (i = limit1; i <= limit2; i++) {
		if (i%div2 != 0 && i%div1 != 0) {
			count++;
		}
	}

	return count;
}