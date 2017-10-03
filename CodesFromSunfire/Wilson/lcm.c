#include "stdio.h"


int main () {
	int a = 5, b = 7, r;

	int multiply = a*b;

	while (b > 0) {
		r = a%b;
		a = b;
		b = r;
	}


	printf("%d\n", multiply/a);


}
