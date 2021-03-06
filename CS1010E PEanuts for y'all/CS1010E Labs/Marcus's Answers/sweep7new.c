#include <stdio.h>
#include <stdbool.h> 
#define ROW 16 
#define COL 30

void scanBoard( int board[][COL] , int m , int n ) ;
void printBoard( int board[][COL], int m , int n ) ;
int countNeighbour( int board[][COL] , int r , int c , int m , int n ) ;
bool isValid( int r , int c , int m , int n , int board[][COL] ) ;
bool allCleared( int board[][COL] , int m , int n , int r , int c ) ;
void clearNeighbours( int board[][COL] , int r , int c , int m , int n ) ;
void playGame( int board[][COL] , int m , int n ) ;

int main(void) {
   int board[ROW][COL] = {{0}} ;
   int m , n ; 
   scanf("%d %d" , &m , &n ) ;
   scanBoard( board , m , n ) ;
   playGame( board , m , n ) ; 
   
   return 0;
}
void playGame( int board[][COL] , int m , int n ) {
   int r , c ;
   bool Valid = false , Cleared = false ;
   
      scanf("%d %d" , &r , &c ) ;
      Valid = isValid( r , c , m , n , board ) ;
      if( Valid == true && board[r][c] !=9) {
         board[r][c] = countNeighbour( board , r , c , m , n ) ;
         if( board[r][c] == 0 ) {
            clearNeighbours( board , r , c , m , n ) ;
         }
         Cleared = allCleared( board , m , n , r , c ) ;
     }

     else if ( r >= 0 && r < m && c >= 0 && c < n && board[r][c]!=9) {
      Cleared = false ;
     }
     else {
         Cleared = true ;
     }
    if ( Cleared == true ) {
     printBoard( board , m , n ) ;
     }

     else {
      playGame( board , m , n ) ;
     }
return ;
}
void clearNeighbours( int board[][COL] , int r , int c , int m , int n ) {
   bool Valid = false ;
   int i , j ;

   for ( i = r-1 ; i <= r+1 ; i++ ) {
      for ( j = c-1 ; j <= c+1 ; j++ ) {
         Valid = isValid( i , j , m , n , board ) ;
         if (Valid == true ) {
         board[i][j] = countNeighbour( board , i , j , m , n ) ;
         if ( board[i][j] == 0 ) {
            clearNeighbours( board, i , j , m , n ) ;
         }
     }
     }
   }
   return ;
}
bool allCleared( int board[][COL] , int m , int n, int r , int c ){
   int i , j ;

   if ( board[r][c] == 9 ) {
      return true ;
   }
   for ( i = 0 ; i < m ; i ++ ) {
      for ( j = 0 ; j < n ; j++ ) {
         if ( board[i][j] == -1 ) {
            return false ;
         }
      }
   }
   return true ;
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

int countNeighbour( int board[][COL] , int r , int c , int m , int n ) {
   int i , j ;
   int count = 0 ;
   bool Valid = false ;

   if ( board[r][c] != 9 ) {
      for ( i = r - 1 ; i <= r+1 ; i++ ) {
         for ( j = c - 1 ; j <= c+1 ; j++ ) {
            Valid = isValid( i , j , m , n , board ) ;
            if ( Valid == true && board[i][j] == 9 ) {
               count += 1 ;
            }
         }
      }
   }
   return count ;
}

bool isValid( int r , int c , int m , int n , int board[][COL] ) {
   if ( r >= 0 && r < m && c >= 0 && c < n &&( board[r][c] == -1 || board[r][c] == 9 ) ) {
      return true ;
   }

   return false ;
}



