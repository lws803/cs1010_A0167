#include <stdio.h>
#define ROW 16 
#define COL 30

void scanBoard( int board[][COL] , int m , int n ) ;
void printBoard( int board[][COL], int m , int n ) ;
int countNeighbour( int board[][COL] , int r , int c ) ;

int main(void) {
   int board[ROW][COL] = {{0}} ;
   int m , n , r , c ; 

   scanf("%d %d" , &m , &n ) ;
   scanBoard( board , m , n ) ;
   scanf("%d %d" , &r , &c ) ;
   if(board[r][c]!=9){
   board[r][c] = countNeighbour( board , r , c ) ;
}
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
         else if ( board[i][j] == -1 ){
            printf(".") ;
         }

         else {
            printf("%d" , board[i][j] ) ;
      }
      }
      printf("\n") ;
      }
   return ;
}

int countNeighbour( int board[][COL] , int r , int c ) {
   int i , j ;
   int count = 0 ;

   if ( board[r][c] != 9 ) {
      for ( i = r - 1 ; i <= r+1 ; i++ ) {
         for ( j = c - 1 ; j <= c+1 ; j++ ) {
            if ( board[i][j] == 9 ) {
               count += 1 ;
            }
         }
      }
   }
   return count ;
}



