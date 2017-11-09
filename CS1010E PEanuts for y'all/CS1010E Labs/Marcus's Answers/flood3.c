#include <stdio.h>

int main(void) {
   int n ;
   int map[10][10] ={ {0} } ;
   int i , j ;

   scanf("%d" , &n) ;

   for ( i = 0 ; i < 10 ; i++ ) {

      for ( j = 0 ; j < 10 ; j++ ) {

         scanf("%d" ,&map[i][j] ) ;

         if ( i == 0 || j == 0 || i == 9 || j == 9 ) {
            if ( map[i][j] <=  n ) {
               map[i][j] = -1 ;
               printf("*") ;
            }
            else {
               printf("%d" , map[i][j] ) ;
            }
         } 

         else {

            if ( map[i-1][j] == -1 || map[i][j-1] == -1 ) {
               if ( map[i][j] <=  n ) {
                  map[i][j] = -1 ;
                  printf("*") ;
               }
               else {
                  printf("%d" , map[i][j] ) ;
               }
            }
             else {
                printf("%d" , map[i][j] ) ;
            
           }
           }

          }
      
         printf("\n") ;
      
}

      return 0;
   }
