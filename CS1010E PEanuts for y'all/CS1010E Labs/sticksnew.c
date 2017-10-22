#include <stdio.h>

int pickNext ( int sticksLeft , int max , int limitMultiple ) ;

int main(void) {

	int n , m  , k ;
	int losePick , winPick ;

	printf("Enter total number of sticks in play: ") ;
	scanf("%d" , &n) ;

	printf("Enter maximum number of sticks that can be picked up in one turn: ") ;
	scanf("%d" , &m) ;

	printf("\n") ;

	k = n / m ;

	if ( n%4 != 1) {

		printf("I start first\n\n") ;

		winPick = pickNext ( n , m , k ) ;

		n -= winPick ;

		printf("I pick %d stick(s) with %d left\n\n" , winPick , n) ;

		if ( n == 1 ) {

			printf("I WIN\n") ;

		}

	}

	else {

		printf("You start first\n\n") ;

	}

	while ( n > 1) {

		printf("How many stick(s) to pick?\n" ) ;
		scanf("%d" , &losePick) ;

		while ( losePick > m ) {
			printf("You have picked up too much!\n\n") ;

			printf("How many stick(s) to pick?\n" ) ;
			scanf("%d" , &losePick) ;

		}

		n -= losePick ;

		printf(" %d stick(s) left\n\n" , n ) ;

		if ( n == 1 ) {
			printf("YOU WIN (by making such a shit game)\n") ;
			break ;
		}

		winPick = pickNext ( n , m , k ) ;

		n -= winPick ;

		printf("I pick %d stick(s) with %d left\n\n" , winPick , n ) ;

		if ( n == 1 ) {
			printf("I WIN\n") ;
		}


	}

   return 0;
}

int pickNext ( int sticksLeft , int max , int limitMultiple ) {
	
	int pick ;

	pick = sticksLeft - ( ( limitMultiple * ( max + 1 ) ) + 1 ) ;

	while ( pick < 1 || pick > max ) {

		limitMultiple -= 1 ;

		pick = sticksLeft - ( ( limitMultiple * ( max + 1 ) ) + 1 ) ;

	}

return pick ;

}