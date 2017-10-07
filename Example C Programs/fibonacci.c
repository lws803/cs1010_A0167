#include <stdio.h>

int main(void) {

   int n , a = 0 , b = 1 , i = 0 , flag ;

   printf("Enter n: ") ; 
   scanf("%d" , &n ) ; 

   if ( n == 0 ) { 
      i = a ; 
   } 

   if ( n == 1 ) { 
      i = b ; 
   } 

   else { 

      for ( flag = 2 ; flag <= n ; flag++ ) { 
         i = a + b ; 
         a = b ; 
         b = i ; 
      } 
   } 

   printf("F(%d) is %d\n" , n , i) ;

   return 0;
}
