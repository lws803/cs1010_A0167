#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct { 
	int r , i ;
} Complex ;

int main(void) {
	Complex num = { 0 , 0 } ;
	int a , b , c , d ;
	char word[10] ;
	bool isEnd = false ;

	while ( isEnd == false ) {
		scanf("%s" , &word[0] ) ;

		if ( word[0] == 'c') {
			scanf("%d" , &num.r) ;
			scanf("%d" , &num.i) ;
		}

		else if ( word[0] == 'a') {
			scanf("%d" , &a) ;
			scanf("%d" , &b) ;

			num.r += a ;
			num.i += b ;
		}

		else if ( word[0] == 's') {
			scanf("%d" , &a) ;
			scanf("%d" , &b) ;

			num.r -= a ;
			num.i -= b ;			
		}

		else if ( word[0] == 'm') {
			scanf("%d" , &a) ;
			scanf("%d" , &b) ;

			c = num.r ;
			d = num.i ;

			num.r = ( c * a) - ( d * b) ;
			num.i = ( d * a) + ( c * b) ;						
		}	

		else if ( word[0] == 'p') {
			if ( num.i >= 0 ) {
				printf("%d+%di\n" , num.r , num.i) ;	
				}
			else {
				printf("%d%di\n" , num.r , num.i) ;				
			}	
		}		

		else if ( word[0] == 'e') {
			isEnd = true ;
		}					
	}


   return 0;
}
