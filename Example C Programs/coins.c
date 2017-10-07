#include <stdio.h>

int main(void) {
   	
   	int amnt , possible = 0 ;
	int a = 0, b = 0, c = 0, d = 0;
	int n ;

	printf("Enter amount in cents: ");
	scanf("%d" , &amnt ); 

	while (a<=20) {
		n = amnt;

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
		
		if (n == 0) {
			possible++;
		}
	}

	if ( amnt == 0 ){ 
		possible = 0 ;
	}

	printf("Number of ways to form %d cents: %d\n" , amnt , possible ) ;

   return 0;
}
