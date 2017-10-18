#include <stdio.h>
#include <math.h>

double gridToGraph( int i , double low , double high , int n );
int graphToGrid(double x, double low, double high, int n);

int main(void) {

	int c3 , c2 , c1 , c0 ;
	double xl , xh ;
	int n = 60 ;
	int i ;
	double xValue , prevxValue ;

	scanf("%d %d %d %d" , &c3 , &c2 , &c1 , &c0 ) ;
	scanf("%lf %lf" , &xl , &xh) ;

	printf("%d %d %d %d\nxl = %f; xh = %f\n" , c3 , c2 , c1 , c0 , xl , xh) ;


	if ( (xl > 0 && xh > 0) || (xl < 0 && xh < 0) ) {
		printf("y-axis is outside the plot\n") ;
	}

	else for ( i = 0 ; i <= n-1  ; i++) {
		
		xValue = gridToGraph( i , xl , xh , n ) ;

		if ( xValue < 0 && xValue > -0.000001 || xValue == 0.000000) {
			xValue = 0.000000 ;

			printf("y-axis is located at column %d\n" , i+1) ;
			printf("column %d is x = 0.000000\n" , i+1 ) ;
			i = n ;
		}

		if ( xValue > 0.000000) {

			if ( fabs(prevxValue) > xValue ) {
				printf("y-axis is located at column %d\n" , i+1) ;
				printf("column %d is x = %f\n" , i+1 , xValue ) ;
				i = n;
			}

			else {
				printf("y-axis is located at column %d\n" , i ) ;
				printf("column %d is x = %f\n" , i , prevxValue  ) ;
				i = n;
			}

		}

		prevxValue = xValue ;

	} 

   return 0;
}

double gridToGraph(int i ,double low , double high , int n){
	double diff ;
	double value ;

	diff = ( high - low ) / ( n - 1 ) ;

	value = low + ( i * diff ) ;

	return value ;

}

int graphToGrid(double x, double low, double high, int n){
	double diff ;
	double value ;
	int valueRounded ;

	diff = ( high - low ) / ( n - 1 ) ;

	value = (x - low) / diff ;

	valueRounded = rint(value) ;

	return valueRounded ;

}