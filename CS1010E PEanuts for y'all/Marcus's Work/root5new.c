#include <stdio.h>
#include <math.h>

double polynomial(double x , int c3 , int c2 , int c1 , int c0);
double fabs(double x) ;

int main(void) {

   int c3 , c2 , c1 , c0 ;
   double a , b ;
   double pa , pb ;
   double m ;
   double pm ;
   double diff ;
   double root , proot ;
   

   scanf("%d %d %d %d" , &c3 , &c2 , &c1 , &c0) ;
   scanf("%lf %lf" , &a , &b ) ;
   
   m = ( a + b ) / 2 ;

   pa = polynomial( a , c3 , c2 , c1 , c0 ) ;
   pb = polynomial( b , c3 , c2 , c1 , c0 ) ;
   pm = polynomial( m , c3 , c2 , c1 , c0 ) ;
   
   printf("a = %f; b = %f; m = %f; p(a) = %f; p(b) = %f; p(m) = %f\n" , a , b , m , pa , pb , pm ) ;

   diff = fabs( a - b ) ;
   
   while ( diff >= 0.0001 && pm != 0.000000 ) {
   
      if ( pm >= 0 ) {

         if ( pa >= 0 ) {
            a = m ;
         }

         else {
            b = m ;
         }
      }

      else if ( pm < 0 ) {
        if ( pa < 0 ) {
           a = m ;
        }

        else {
           b = m ;
       }
   
        }

   m = ( a + b ) / 2 ;

   pa = polynomial( a , c3 , c2 , c1 , c0 ) ;
   pb = polynomial( b , c3 , c2 , c1 , c0 ) ;
   pm = polynomial( m , c3 , c2 , c1 , c0 ) ;

   printf("a = %f; b = %f; m = %f; p(a) = %f; p(b) = %f; p(m) = %f\n" , a , b , m , pa , pb , pm ) ;

   diff = fabs( a - b ) ;

   } 

   root = ( a + b ) / 2 ;
   proot = polynomial( root , c3 , c2 , c1 , c0 ) ;

   printf("root = %f\n" , root) ;
   printf("p(root) = %f\n" , proot) ;

   return 0;
}

double polynomial(double x , int c3 , int c2 , int c1 , int c0) {
   
   double y ; 

   y = (( x * x * x ) * c3) + ((x * x) * c2) + ( x * c1 ) + c0 ; 

   return y  ;

}
