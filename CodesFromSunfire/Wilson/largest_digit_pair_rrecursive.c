#include <stdio.h>

int largest_digit_pair (int);
int main () {
	int n;
	
	printf ("Enter a number: ");
	scanf ("%d", &n);
	printf("Largest pair: %d\n", largest_digit_pair (n));

}

int largest_digit_pair (int n) {
	int m;
	// Exit condition 
	if (n == 0) {
		return 0;
	}else {
		// Keep checking to look for largest pair
		m = largest_digit_pair (n/100);
		return (n%100 > m%100) ? n%100 : m%100;
	}
}
