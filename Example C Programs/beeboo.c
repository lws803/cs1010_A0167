#include <stdio.h>

int main(void) {
   
   int value , valueEntered ;
   int first = 0 , last = 0 ;
   int digits ; 
   int beeboo ; 
   int beebooLast ;  
   char beebooCode ; 

   printf("Enter a positive integer: ") ; 
   scanf("%d" , &value) ;

   valueEntered = value ;

   last = value % 10 ;

   for ( digits = 0 ; value > 0 ; digits++ ) {
      first = value % 10 ;
      value = value / 10 ;
   } 

   beeboo = (( first * first ) + ( last * last ) ) * digits ;
   
   beebooLast = beeboo % 10 ;

   if ( beebooLast == 0 ) {
      beebooCode = 'C' ;
   } 

   if ( beebooLast == 1 ) {
      beebooCode = 'D' ;
   } 

   if ( beebooLast == 2 ) {
      beebooCode = 'E' ;
   } 

   if ( beebooLast == 3 ) {
      beebooCode = 'F' ;
   } 

   if ( beebooLast == 4 ) {
      beebooCode = 'G' ;
   } 

   if ( beebooLast == 5 ) {
      beebooCode = 'H' ;
   } 

   if ( beebooLast == 6 ) {
      beebooCode = 'I' ;
   } 

   if ( beebooLast == 7 ) {
      beebooCode = 'J' ;
   } 

   if ( beebooLast == 8 ) {
      beebooCode = 'K' ;
   } 

   if ( beebooLast == 9 ) {
      beebooCode = 'L' ;
   } 
   printf("%d\n%d\n%c\n" , valueEntered , beeboo, beebooCode ) ;

   

   return 0;
}
