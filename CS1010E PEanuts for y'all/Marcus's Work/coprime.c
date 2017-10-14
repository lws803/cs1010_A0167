#include <stdio.h>

int main(void) {

	int number ; 
	int left , right ;
	int count = 0 ;
	int check = 0 ;
	int divisor ;

	printf("Enter a number (> 2): ") ;
	scanf("%d" , &number) ;

	for ( left = 2 ; left <= number ; left ++ ) {
		
		for ( right = left ; right <= number ; right ++) {

			for ( divisor = 2 ; divisor <= right ; divisor ++ ) {

				if ( left % divisor == 0 && right % divisor == 0) {
					check = 1 ;
				}
				
			}

			if ( check == 0 ) {
				printf("(%d,%d)\n" , left , right ) ;
				count ++ ;
			}

			else if ( check == 1 ){
				check = 0 ;
			}

		}
	}

	printf("Number of pairs of coprime integers: %d\n" , count) ;

   return 0;
}
