#include <stdio.h>

int main(void) {

   int c3 , c2 , c1 , c0 ;
   double xL , xH ;

   scanf("%d %d %d %d" , &c3 , &c2 , &c1 , &c0 ) ;
   scanf("%lf %lf" , &xL , &xH ) ;

   printf("%d %d %d %d\n" , c3 , c2 , c1 , c0 ) ;
   printf("xL = %f; xH = %f\n" , xL , xH) ;

   return 0;
}
