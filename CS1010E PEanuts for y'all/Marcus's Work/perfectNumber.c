#include <stdio.h>

int main(void) {
   
   int number , divisor , sumOfDivisors = 0 ; 

   printf("Enter integer: " ) ; 
   scanf( "%d" , &number ) ; 

   for ( divisor = 1 ;  divisor < number ;  divisor ++ ) { 
      if ( number % divisor == 0 ) { 
         sumOfDivisors += divisor ;
      } 
   } 

   if (sumOfDivisors == number ) { 
      printf("%d is a perfect number\n" , number) ; 

     }

     else {
        printf("%d is not a perfect number\n" , number) ;
} 
   return 0;
}
