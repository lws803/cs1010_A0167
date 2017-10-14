#include <stdio.h>

int main(void) {

   int a , b , lcm = 0 , i ; 

   printf("Enter two integers: ") ;
   scanf("%d %d" , &a , &b ) ; 

   if ( a%b == 0 ) {
      lcm = a ; 
   } 
   
   if (b%a == 0 ) { 
      lcm = b ; 
   } 

   else {

   for ( i=1 ; lcm == 0 ; i++ ) { 
      if ( ( i%a == 0 ) && ( i%b == 0 ) ) { 
         lcm = i ; 
      }
   } } 

   printf("The LCM of %d and %d is %d\n" , a , b , lcm ) ; 

   return 0;
}
