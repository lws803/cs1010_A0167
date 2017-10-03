#include <stdio.h>


int main () {

	int amnt , possible = 0;

	printf("Enter amount: ");
	scanf("%d", &amnt);

	int a = 0, b = 0, c = 0, d = 0;


	while (a<=20) {
		int n = amnt;

		n -= a*20;
		n -= b*10;
		n -= c*5;
		n -= d*1;

		d++;

		if (d == 21) {
			d = 0;
			c++;
		}

		if (c == 21) {
			c = 0;
			b++;
		}

		if (b == 21) {
			b = 0;
			a++;
		}
		
		if (n == 0 && amnt > 0) {
			possible++;
		}
	}
	

	printf("Possibilities: %d\n", possible);

	return 0;
}
