#include <stdio.h>
#include <stdbool.h>

void floodArray( int n , int map[][10] ) ;
void printArray( int n , int map[][10] ) ;
void copyArray ( int map[][10] , int mapOld[][10]) ;
bool checkArray( int map[][10] , int mapOld[][10])  ;

int main(void) {
   int n ;
   int map[10][10] ={{0}} ;
   int mapOld[10][10] = {{0}} ;
   int i , j ;
   bool isSame ;
   int flag = 0 ;

   scanf("%d" , &n) ;

   for ( i = 0 ; i < 10 ; i++ ) {

      for ( j = 0 ; j < 10 ; j++ ) {

         scanf("%d" ,&map[i][j] ) ;
      }
   }
   floodArray ( n , map ) ;

   while (flag == 0 ) {
      isSame = checkArray( map , mapOld ) ;
      if (isSame == false ) {
         copyArray( map , mapOld ) ;
      
      floodArray ( n , map ) ;
}
      else {
         printArray ( n , map ) ;
         flag = 1 ;
      }
   }
   return 0;
}

void floodArray (int n , int map[][10] ) {
   int i , j ;

   for ( i = 0 ; i < 10 ; i++ ) {

      for ( j = 0 ; j < 10 ; j++ ) {

         if ( i == 0 || j == 0 || i == 9 || j == 9 ) {
            if ( map[i][j] <=  n ) {
               map[i][j] = -1 ;
            }
         }

         else {

            if  (map[i-1][j] == -1 || map[i][j-1] == -1 || map[i+1][j] == -1 || map[i][j+1]== -1 ) {
               if ( map[i][j] <=  n ) {
                  map[i][j] = -1 ;
               }
            }

         }

      }

   }
   return ;
}

void printArray (int n ,int map[][10] ) {
   int i , j ;

   for ( i = 0 ; i < 10 ; i++ ) {

      for ( j = 0 ; j < 10 ; j++ ) {

            if ( map[i][j] == -1 ) {
               printf("*") ;
            }
            else {
               printf("%d" , map[i][j] ) ;
            }


      }

      printf("\n") ;

   }
   return ;
}

void copyArray ( int map[][10] , int mapOld[][10]) {
   int i , j ;

   for ( i = 0 ; i < 10 ; i++ ) {

      for ( j = 0 ; j < 10 ; j++ ) {
         mapOld[i][j] = map[i][j] ;

      }
   }
   return ;
}
bool checkArray( int map[][10] , int mapOld[][10])  {
   int i , j;
   int flag = 0 ;
   int old , new ;

   for ( i = 0 ; i < 10 ; i++ ) {

      for ( j = 0 ; j < 10 ; j++ ) {
         new = map[i][j] ;
         old = mapOld[i][j] ;

         if ( new != old ) {
            flag = 1;
            return false ;
         }
           }
      }
      if (flag == 0 ) {
         return true ;
      }
      else {
         return false ;
         } 
   }
