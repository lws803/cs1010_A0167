#include <stdio.h>


int main () {

	int a = 2406, b = 1296, c = 654, r;


	//Find the gcd of a and b first. 
	while (b> 0 ) {
		r = a%b;
		a = b;
		b = r;
	}

	//Then find the gcd of (a,b) and c 
	while (c > 0 ) {
		r = a%c;
		a = c;
		c = r;
	}


	printf("%d\n", a);



	return 0;
}
