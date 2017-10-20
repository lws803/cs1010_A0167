// sumDigits.c
#include <stdio.h>
#define MAX 1000


int summing (char [MAX]);


int main(void) {
	int sum;
	char str[MAX];

	printf("Enter input: ");
	scanf ("%s", str);

	sum = summing(str);

	printf("Sum = %d\n", sum);

	return 0;
}

int summing (char str[MAX]) {
	int i, total = 0;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] <= 57 && str[i] >= 48) {
			total += str[i] - 48;
		}
	}
	return total;
}

