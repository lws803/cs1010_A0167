#include <stdio.h>

int checkPrime ( int value ) ;

int main(void) {

   int number ;
   int first ;
   int flag1 , flag2 ;
   int second ;

   scanf("%d" , &number) ;

   for ( first = 2 ; first <= number/2 ; first++ ) {
   		flag1 = checkPrime ( first ) ;

   		if ( flag1 == 0 ) {
   			second = number - first ;

   			flag2 = checkPrime( second ) ;

   			if ( flag2 == 0 ) {
   				printf("%d = %d + %d\n" , number , first , second ) ;
   			}
  			
   		}

   		flag1 = 0 ;
   		flag2 = 0 ;
   	}


   return 0;
}

int checkPrime ( int value ) {
	int i , flag = 0 ;

	for ( i = 2 ; i <= value/2 ; i++ ) {
   			if ( value % i == 0) {
   				flag = 1 ;
   				return flag ;
   			}

   			else {
   				flag = 0 ;
   			}
   		}

   	return flag ;

}