#include <stdio.h>

int main(void) {
   int n ;
   int map[10][10] ={ {0} } ;
   int i , j ;

   scanf("%d" , &n) ;

   printf("%d\n" , n ) ;
   
   for ( i = 0 ; i < 10 ; i++ ) {

      for ( j = 0 ; j < 10 ; j++ ) {

         scanf("%d" ,&map[i][j] ) ;
         printf("%d" , map[i][j] ) ;
      }
      printf("\n") ;
   }
   

   return 0;
}
