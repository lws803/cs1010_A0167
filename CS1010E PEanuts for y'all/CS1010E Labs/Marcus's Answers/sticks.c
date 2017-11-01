#include <stdio.h>

int main(void) {

	int n , m ;
	int oppo , win ;

	printf("Enter n: ") ;
	scanf("%d" , &n) ;

	printf("Enter m: ") ;
	scanf("%d" , &m) ;

	printf("\n") ;

	if ( n%4 != 1) {

		printf("I start first\n\n") ;

		n -= m ;

		printf("I pick %d stick(s) with %d left\n\n" , m , n) ;

	}

	else {

		printf("You start first\n\n") ;

	}

	while ( n > 1) {

		printf("How many stick(s) to pick?" ) ;
		scanf("%d" , &oppo) ;

		n -= oppo ;

		printf(" %d sticks left\n\n" , n ) ;

		win = m - oppo + 1 ;
		n -= win ;

		printf("I pick %d stick(s) with %d left\n\n" , win , n ) ;

	}

	printf("I WIN\n") ;

   return 0;
}
