#include <stdio.h>
#include <math.h>

double gridToGraph( int i , double low , double high , int n );
int graphToGrid(double x, double low, double high, int n);
double polynomial(double x, int c3, int c2, int c1, int c0);
void findMinMax(int c3, int c2, int c1, int c0, double *yl, double *yh, double xl, double xh);
void plotGraph(int c3, int c2, int c1, int c0, double xl, double xh , double yl, double yh , int xAxisRow , int yAxisColumn) ;

int main(void) {

	int c3 , c2 , c1 , c0 ;
	double xl , xh , yl = 0.000000 , yh = 0.000000;
	int n = 60 ;
	int i ;
	double xValue , prevxValue , yValue , prevyValue ;

	int xAxisRow = 20 , yAxisColumn = 0 ;

	scanf("%d %d %d %d" , &c3 , &c2 , &c1 , &c0 ) ;
	scanf("%lf %lf" , &xl , &xh) ;

	if ( (xl > 0 && xh > 0) || (xl < 0 && xh < 0) ) {
		printf("Domain: [%f,%f];" , xl , xh ) ;
	}

	else for ( i = 0 ; i <= n-1  ; i++) {
		
		xValue = gridToGraph( i , xl , xh , n ) ;

		if ( xValue < 0 && xValue > -0.000001 || xValue == 0.000000) {
			xValue = 0.000000 ;

			printf("Domain: [%f,%f];" , xl , xh ) ;
			
			yAxisColumn = i + 1 ;

			i = n ;
		}

		if ( xValue > 0.000000) {

			if ( fabs(prevxValue) >= xValue ) {
				printf("Domain: [%f,%f];" , xl , xh ) ;
			
				yAxisColumn = i + 1;
			
				i = n;
			}

			else {
				printf("Domain: [%f,%f];" , xl , xh ) ;
				
				yAxisColumn = i ;

				i = n ;
			}

		}

		prevxValue = xValue ;

	} 

	findMinMax( c3 , c2 , c1 , c0 , &yl , &yh , xl , xh );

	n = 20 ;

	if ( (yl > 0.1 && yh > 0) || (yl < 0 && yh < -0.001300) ) {

		xAxisRow = 0 ;

		printf(" Range: [%f,%f]\n" , yl , yh) ;
	}

	else for ( i = 0 ; i <= n+2  ; i++) {
		
		yValue = gridToGraph( i , yl , yh , n ) ;

		if ( yValue < 0 && yValue > -0.001300 || yValue == 0.000000) {
			yValue = 0.000000 ;

			printf(" Range: [%f,%f]\n" , yl , yh ) ;
			
			xAxisRow = i + 1;

			i = n+2 ;
		}

		if ( yValue > 0.000000) {

			if ( fabs(prevyValue) >= yValue ) {
				printf(" Range: [%f,%f]\n" , yl , yh ) ;
				
				xAxisRow = i + 1;

				i = n+2 ;
			}

			else if ( i == 0) {
				
				xAxisRow = i + 1 ;
			}

			else {
				printf(" Range: [%f,%f]\n" , yl , yh ) ;
				
				xAxisRow = i  ;

				i = n+2 ;
			}

		}

		prevyValue = yValue ;

	} 

	plotGraph(c3 , c2 , c1 , c0 , xl , xh , yl , yh , xAxisRow , yAxisColumn );

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

double polynomial(double x, int c3, int c2, int c1, int c0){
	double y ;

	y = (c3 * x * x * x ) + (c2 * x * x) + (c1 * x) + c0 ;

	return y ;
}

void findMinMax(int c3, int c2, int c1, int c0, double *yl, double *yh, double xl, double xh){
	double min  , max ;
	double diff ;
	int i ;
	double y ;

	min =  polynomial( xl , c3 , c2 , c1 , c0 ) ;
	max =  polynomial( xh , c3 , c2 , c1 , c0 ) ;


	diff = ( xh - xl ) / 59  ;

	for ( i = 0 ; i <= 59 ; i++ ){
		y = polynomial( (xl + (i * diff )) , c3 , c2 , c1 , c0 ) ;

		if ( y < min ){
			min = y ;
		}

		if ( y > max ){
			max = y ;
		}
	}

	*yl = min ;
	*yh = max ;
}

void plotGraph(int c3, int c2, int c1, int c0, double xl, double xh , double yl, double yh , int xAxisRow , int yAxisColumn) {
	int i, j ;
	double xGraph , yGraph ;
	int yGrid ;

	for ( i = 20 ; i > 0 ; i-- ) {

		for ( j = 1 ; j <= 60 ; j++) {

			xGraph = gridToGraph ( j -1 , xl , xh , 60 ) ;
			yGraph = polynomial ( xGraph , c3 , c2 , c1 , c0 ) ;
			yGrid = graphToGrid ( yGraph , yl , yh , 20 ) ;

			if ( yGrid + 1 == i ) {
				printf("x") ;
			}

			else if ( i == xAxisRow && j == yAxisColumn) {
				printf("+") ;
			}

			else if( i == xAxisRow) {
				printf("-") ;
			}

			else if ( j == yAxisColumn ) {
				printf("|") ;
			}

			else {
				printf(" ") ;
			}


		}

		printf("\n") ;
	}

}