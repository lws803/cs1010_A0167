#include <stdio.h>

int sum_digits (int );
int main () {
	int num;
	printf ("Enter digit to sum: ");
	scanf ("%d", &num);
	printf ("Sum: %d\n", sum_digits(num));
}

int sum_digits (int n) {
	// tail 
	if (n == 0) {
		return 0;
	}else {
		return n%10 + sum_digits (n/10);  
	}
}
