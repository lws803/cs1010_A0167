#include <stdio.h>

void findThirds ( double xL , double xH , double *x1 , double *x2 ) ;
double polynomial ( double x , int c3 , int c2 , int c1 , int c0 ) ;

int main(void) {

   int c3 , c2 , c1 , c0 ;
   double xL , xH ;
   double x1 = 0.0  , x2 = 0.0 ;
   double px1 , px2 ;

   scanf("%d %d %d %d" , &c3 , &c2 , &c1 , &c0 ) ;
   scanf("%lf %lf" , &xL , &xH ) ;

   findThirds ( xL , xH , &x1 , &x2 ) ;
   
   px1 = polynomial ( x1 , c3 , c2 , c1 , c0 ) ;
   px2 = polynomial ( x2 , c3 , c2 , c1 , c0 ) ;

   printf("xL = %f; xH = %f; x1 = %f; x2 = %f; p(x1) = %f; p(x2) = %f\n" ,xL,xH,x1,x2,px1,px2);
   
   return 0;
}

void findThirds ( double xL , double xH , double *x1 , double *x2 ) {
   double third ;

   third = ( (xH - xL) / 3 ) ;
   
   *x1 = xL + third ;
   *x2 = xH - third ;

   return ;

}

double polynomial ( double x , int c3 , int c2 , int c1 , int c0 ) {
   double y ;

   y = ( x * x * x * c3 ) + ( x * x * c2 ) + ( x * c1 ) + c0 ;

   return y ;
}





