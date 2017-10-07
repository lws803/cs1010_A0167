#include <stdio.h>

int main(void) {

   int n , integer, reversedNumber = 0 , remainder ; 

   printf("Enter a non-negative number: ") ; 
   scanf("%d" , &n ) ;

   integer = n ;

   while ( n!= 0 ) { 

      remainder = n%10 ; 

      reversedNumber = ( reversedNumber * 10 ) + remainder ; 

      n/= 10 ; 
   } 

   printf("The reverse of %d is %d\n" , integer , reversedNumber)  ; 

   return 0;
}
