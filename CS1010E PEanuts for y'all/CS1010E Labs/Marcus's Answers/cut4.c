#include <stdio.h>

int main(void) {

   int n ;
   int price[100] = { 0 } ;
   int i , j ;
   int max[100] = { 0 } ;
   int maxPrice = 0 ;

   scanf("%d" , &n ) ;

   for ( i = 0 ; i < n ; i++ ) {

      scanf("%d" ,&price[i] ) ;
   }

   printf("Length: %d\n" , n ) ;

   for ( i = 0 ; i < n ; i++ ) {

      printf("Price of length %d: %d\n" , i+1 , price[i] ) ;
      
      maxPrice = price[i] ;

      for ( j = 1 ; j <=  (i+ 1) / 2 ; j++ ) { 
         
         printf("[%d,%d]" , j , (i+1)-j ) ; 
         printf(" = %d\n" , ( max[j-1]  + max[ (i - j ) ] ) ) ;
        
        if ( maxPrice <  ( max[j-1]  + max[ (i - j ) ] )) {
          maxPrice = ( max[j-1]  + max[ (i - j ) ] ) ;   
      }
   }
      
      max[i] = maxPrice ;
      printf("Max price of length %d: %d\n" , i+1 , max[i] ) ;
  } 

   return 0;
}
