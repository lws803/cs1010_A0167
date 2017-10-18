#include <stdio.h>
#include <math.h>

double gridToGraph( double low , double high , int n );

int main(void) {

	int c3 , c2 , c1 , c0 ;
	double xl , xh ;
	double interval ;
	int n = 60 ;
	int i ;

	scanf("%d %d %d %d" , &c3 , &c2 , &c1 , &c0 ) ;
	scanf("%lf %lf" , &xl , &xh) ;

	printf("%d %d %d %d\nxl = %f; xh = %f\n" , c3 , c2 , c1 , c0 , xl , xh) ;

	interval = gridToGraph( xl , xh , n ) ;


	for ( i = 1 ; i <= n  ; i++) {
		
		printf("%f\n" , xl ) ; 
		xl += interval ;

		if ( xl < 0 && xl > -0.000001) {
			xl = 0.000000 ;
			
		}
		

	} 

   return 0;
}

double gridToGraph(double low , double high , int n){
	double diff ;

	diff = ( high - low ) / ( n - 1 ) ;

	return diff ;

}
