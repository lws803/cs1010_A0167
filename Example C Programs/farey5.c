#include <stdio.h>

int main(void) {

   int n ; 
   int denominator , numerator ;
   int divisor , reduce ;
   int denomCheck = 0 ;

   scanf("%d" , &n ) ;

   for ( denominator = 1 ; denominator <= n ; denominator++ ) {
         denomCheck = 0 ;

     for ( numerator = 0 ; numerator <= denominator ; numerator++ ) {
         reduce = 0 ;

         for ( divisor = 2 ; divisor <= denominator ; divisor++ ) {
            if ( numerator % divisor == 0 && denominator % divisor == 0 ) {
               reduce = 1 ; 
            }
         } 

         if ( reduce == 0 && denomCheck == 0 ) {
           printf("%d/%d" , numerator , denominator) ;
           denomCheck = 1 ;
            }

       else if ( reduce == 0 && denomCheck == 1 ) {
            printf(",%d/%d" , numerator , denominator) ;
         } 
         
         if ( numerator == denominator ) {
            printf("\n") ;
         } 

      }

   }

   


   return 0;
}
