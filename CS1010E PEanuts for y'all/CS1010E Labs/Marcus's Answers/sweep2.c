#include <stdio.h>
#define ROW 16 
#define COL 30

void scanBoard( int board[][COL] , int m , int n ) ;
void printBoard( int board[][COL], int m , int n ) ;

int main(void) {
   int board[ROW][COL] = {{0}} ;
   int m , n ; 

   scanf("%d %d" , &m , &n ) ;

   scanBoard( board , m , n ) ;
   printBoard( board , m , n ) ;

   return 0;
}

void scanBoard( int board[][COL] , int m , int n ) {
   int i , j ;

   for ( i = 0 ; i < m ; i++ ) {
      for ( j = 0 ; j < n ; j++ ) {
         scanf("%d" , &board[i][j] ) ;
      }
   }
   return ;
}

void printBoard( int board[][COL] , int m , int n ) {
   int i , j ;

   for ( i = 0 ; i < m ; i++ ) {
      for ( j = 0 ; j < n ; j++ ) {
         if ( board[i][j] == 9 ) {
            printf("*") ;
         } 
         else{
            printf(".") ;
         }
      }
      printf("\n") ;
   }
   return ;
}



