#include <stdio.h>
#include <stdbool.h>

int main(void) {

	int now , before ;
	bool isSame = false ;
	int count = 0 ;

	printf("Enter sequence: ") ;
	scanf("%d" , &before ) ;
	scanf("%d" , &now ) ;

	while ( now != -1 ) {
		if ( now != before && isSame == true ) {
			isSame = false ;
		}

		else if ( now == before && isSame == false ) {
			count ++ ;
			isSame = true ;
		}

		else if ( now == before && isSame == true ) {
			
		}

		else {
			isSame = false ;
		}

		before = now ;
		scanf("%d" , &now ) ;

	}

	printf("Number of repeats: %d\n" , count ) ;

   return 0;
}
