#include <stdio.h>

int main(void) {
   
	int rows , n ;
	int add = 1 , value = 0 ; 
	int addO = 1 , valueO = 0 ;
	int check = 0 ;
	
	scanf("%d" , &rows );

	while ( rows > 0 ) {
		
		for ( n = 1 ; n <= rows ; n++ ) {
			value += add ;
			add++ ;
			
			if ( n == 1 && check == 0) {
				printf("%d" , value ) ;
				valueO = value ;
			}

			else if ( n == 1) {
				printf("%d" , value ) ;
				valueO = value ;
				add++ ;
			}

			else {
				printf(",%d" , value ) ;
			}
			
		}

		printf("\n") ; 
 

			value = valueO ; 
			add = addO ;
			addO += 1 ;
			rows -- ;
			check = 1 ;
		
	}

   return 0;
}
