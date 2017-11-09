#include <stdio.h>
#include <stdbool.h>

void floodArray( int n , int map[][10] ) ;
void printArray( int n , int map[][10] ) ;
void copyArray ( int map[][10] , int mapOld[][10]) ;
bool checkArray( int map[][10] , int mapOld[][10])  ;
int findArea( int map[][10] ) ;
int findPerimeter( int mapPerimeter[][12] ) ;
void transferArray( int map[][10] , int mapPerimeter[][12] ) ;

int main(void) {

   int n ;
   int map[10][10] ={{0}} ;
   int mapOld[10][10] = {{0}} ;
   int i , j ;
   bool isSame ;
   int flag = 0 ;
   int area , perimeter = 0 ;
   int mapPerimeter[12][12] = {{0}} ;

   for ( i = 0 ; i < 13 ; i++ ) {

      for ( j = 0 ; j < 13 ; j++ ) {
         mapPerimeter[i][j] = -1 ;

      }
   }

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

   transferArray( map , mapPerimeter ) ;

   area = findArea ( map ) ;
   perimeter = findPerimeter ( mapPerimeter ) ;

   printf("area = %d square units; perimeter = %d units\n" , area , perimeter ) ;

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

int findArea( int map[][10] ) {
   int i , j ;
   int area = 0 ;

  for ( i = 0 ; i < 10 ; i++ ) {

      for ( j = 0 ; j < 10 ; j++ ) {

         if( map[i][j] != -1 ) {
            area+= 1 ;
         }
      }
   }
   return area ;
}

int findPerimeter( int mapPerimeter[][12] ) {
   int i , j ;
   int perimeter = 0 ;

   for ( i = 0 ; i < 12 ; i++ ) {

      for ( j = 0 ; j < 12 ; j++ ) {
         
         if ( mapPerimeter[i][j] != -1 ) {

            if  (mapPerimeter[i-1][j] == -1 )  {
               perimeter += 1 ;
            }

               if (mapPerimeter[i][j-1] == -1 ) {
               perimeter += 1 ;
               }

               if (mapPerimeter[i+1][j] == -1 ) {
                perimeter += 1 ;
               }

                  if (mapPerimeter[i][j+1] == -1 ) {
                      perimeter += 1 ;
                  }
           

         }
      }
   }
   
   return perimeter ;
}

void transferArray( int map[][10] , int mapPerimeter[][12] ) {
   int i , j ;

   for ( i = 0 ; i < 10 ; i++ ) {

      for ( j = 0 ; j < 10 ; j++ ) {
            mapPerimeter[i+1][j+1] = map[i][j] ;
      }
   }
return ;
}