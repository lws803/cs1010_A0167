#include "stdio.h"
#define MAX 1000
void scanBoard( int board[][MAX] , int  , int  );
void printBoard( int board[][MAX] , int  , int  ); 
int search_surrounding (int [][MAX], int , int , int , int ); 
void spread (int [][MAX], int , int , int , int ) ; 
int allCleared (int [][MAX], int , int); 
void playGame (int [][MAX], int, int); 

// Possible marcus's problem, Marcus's algo floods the entire board whereas the test case could only be expecting the following: 

/*
0 0 // when 0 0 is pushed 
000000000
121100000
*.*100000
...100011
....1111*
.*...*...
**.......
......***
*/


int main(int argc, char const *argv[])
{
   int map[MAX][MAX];
   int row, col;
   scanf("%d %d", &row, &col);

   scanBoard(map, row, col);
   printBoard(map, row, col);
   playGame (map, row, col);
   
   return 0;
}

void playGame (int arr[][MAX], int row, int col) {
   // Keep playing 
   int x, y;
   while (!allCleared(arr, row, col)) {
      scanf("%d %d" , &y, &x) ;
      if (arr[y][x] == 9 || y >= row || x >= col || y < 0 || x < 0) break;
      spread (arr, x, y, row, col);
   }
   printBoard (arr, row, col);
}

void scanBoard( int board[][MAX] , int m , int n) {
   int i , j ;
   for ( i = 0 ; i < m ; i++ ) {
      for ( j = 0 ; j < n ; j++ ) {
         scanf("%d" , &board[i][j] ) ;
      }
   }
   return ;
}

void printBoard( int board[][MAX] , int m , int n) {
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

int allCleared (int arr[][MAX], int row, int col) {
   int i, d;
   for (i = 0; i < row; i++) {
      for (d = 0; d < col; d++) {
         if (arr[i][d] == -1) return 0;
      }
   }
   return 1;
}

void spread (int arr[][MAX], int x, int y, int row, int col) {
  int bomb_count = search_surrounding (arr, x, y ,row, col);
  arr[y][x] = bomb_count;
  if (bomb_count == 0) {
    if (x+1 < col && arr[y][x+1] == -1)
      spread (arr, x+1, y, row, col);
    if (x-1 >= 0 && arr[y][x-1] == -1)
      spread (arr, x-1, y, row, col);
    if (y-1 >= 0 && arr[y-1][x] == -1)
      spread (arr, x, y-1, row, col);
    if (y+1 < row && arr[y+1][x] == -1)
      spread (arr, x, y+1, row, col);

    if (x+1 < col && y+1 < row && arr[y+1][x+1] == -1)
      spread (arr, x+1, y+1, row, col);
    if (x-1 >= 0 && y-1 < row && arr[y-1][x-1] == -1)
      spread (arr, x-1, y-1, row, col);
    if (y-1 >= 0 && x+1 < col && arr[y-1][x+1] == -1)
      spread (arr, x+1, y-1, row, col);
    if (y+1 < row && x-1 < col && arr[y+1][x-1] == -1)
      spread (arr, x-1, y+1, row, col);
  }
}

int search_surrounding (int arr[][MAX], int x, int y, int row, int col) {
  int i, d, count = 0;
  for (i = -1; i < 2; i++) {
    for (d = -1; d < 2; d++) {
      if (x+d < col && x+d >= 0 && y+d < row && x+d >= 0) {
        if (i == 0 && d == 0) {
        // position is at original coords
        }else if (arr[y+i][x+d] == 9){
          count++;
        }
      }
    }
  }
  return count;
}