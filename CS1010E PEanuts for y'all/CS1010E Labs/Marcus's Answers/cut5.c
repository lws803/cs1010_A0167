#include <stdio.h>

int main(void) {

   int n ;
   int price[100] = { 0 } ;
   int i , j ;
   int max[100] = { 0 } ;
   int maxPrice = 0 ;
   int overallMaxPrice = 0 ;

   scanf("%d" , &n ) ;

   for ( i = 0 ; i < n ; i++ ) {

      scanf("%d" ,&price[i] ) ;
   }


   for ( i = 0 ; i < n ; i++ ) {


      maxPrice = price[i] ;

      for ( j = 1 ; j <=  (i+ 1) / 2 ; j++ ) { 


         if ( maxPrice <  ( max[j-1]  + max[ (i - j ) ] )) {
            maxPrice = ( max[j-1]  + max[ (i - j ) ] ) ;   
         }
      }

      max[i] = maxPrice ;

      if ( overallMaxPrice < max[i] ) {
         overallMaxPrice = max[i] ;
      } 
   } 

   printf("Max price of rod: %d\n" , overallMaxPrice ) ;

   return 0;
}
