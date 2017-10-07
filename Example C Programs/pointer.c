#include <stdio.h>

int main(void) {
   
   int i1 , i2;
   int *p1 , *p2 ; 

   i1 = 5 ;
   p1 = &i1 ; 
   i2 = (*p1)/2 + 10 ;
   p2 = p1;

   printf ( " %d %d %d %d %d %d " , i1 , i2 , *p1 , p1 , *p2 , p2 ) ;

   return 0;
}
