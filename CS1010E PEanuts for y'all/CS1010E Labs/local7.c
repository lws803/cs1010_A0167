#include <stdio.h>

void findThirds ( double xL , double xH , double *x1 , double *x2 ) ;
double polynomial ( double x , int c3 , int c2 , int c1 , int c0 ) ;
double search ( int c3 , int c2 , int c1 , int c0 , double xL , double xH , int maxmin ) ;

int main(void) {

   int c3 , c2 , c1 , c0 ;
   double xL , xH ;
   double max , pmax ;
   int maxmin ;

   scanf("%d %d %d %d" , &c3 , &c2 , &c1 , &c0 ) ;
   scanf("%lf %lf" , &xL , &xH ) ;
   scanf("%d" , &maxmin ) ;
  
   max = search ( c3 , c2 , c1 , c0 , xL , xH , maxmin ) ;
   pmax = polynomial ( max , c3 , c2 , c1 , c0 ) ;
   
   if ( maxmin == 1 ) {
       printf("Local maximum point is (%f, %f)\n" , max , pmax ) ;
   }

   else if ( maxmin == -1 ) {
      printf("Local minimum point is (%f, %f)\n" , max , pmax ) ;
   }
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

double search ( int c3 , int c2 , int c1 , int c0 , double xL , double xH , int maxmin ) {
   int iter ;
   double replace ;
   double max ;
   double px1 , px2 ;
   double x1 = 0.0  , x2 = 0.0 ;
 
   for ( iter = 1 ;  xH - xL >= 0.0001 ; iter++ ) {
   
   findThirds ( xL , xH , &x1 , &x2 ) ;
   
   px1 = polynomial ( x1 , c3 , c2 , c1 , c0 ) ;
   px2 = polynomial ( x2 , c3 , c2 , c1 , c0 ) ;

   printf("iter = %d; xL = %f; xH = %f; x1 = %f; x2 = %f; p(x1) = %f; p(x2) = %f\n",iter ,xL,xH,x1,x2,px1,px2);
   
   replace = x1 ;

   if ( (maxmin * px1)  > ( maxmin *  px2 ) ) {
      replace = x2 ;
   }

   if ( replace == x1 ) {
      xL = x1 ;
   }

   else if ( replace == x2 ) {
      xH = x2 ;
   }

   }

   max = (xL + xH) / 2 ;

   return max ;
      

}





