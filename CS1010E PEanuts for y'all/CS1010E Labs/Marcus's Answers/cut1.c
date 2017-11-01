#include <stdio.h>

int main(void) {

   int n ;
   int price[100] = { 0 } ;
   int i ;

   scanf("%d" , &n ) ;

   for ( i = 0 ; i < n ; i++ ) {

      scanf("%d" ,&price[i] ) ;
   }

   printf("Length: %d\n" , n ) ;

   for ( i = 0 ; i < n ; i++ ) {

      printf("Price of length %d: %d\n" , i+1 , price[i] ) ; 
   } 

   return 0;
}
