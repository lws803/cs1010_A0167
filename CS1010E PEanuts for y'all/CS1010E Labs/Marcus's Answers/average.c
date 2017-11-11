#include <stdio.h>

int main(void) {
	double arr[10] = {4,9,-7,5,-8,-3,0,8,-9,2} ;
	int n ;
	int i , j ;
	double sum = 0, average ;

	printf("Enter n: ") ;
	scanf("%d" , &n ) ;
	printf("The %d-moving average is:\n" , n ) ;

	for ( i = 0 ; i < 11 - n ; i++ ) {
		for ( j = i ; j < i + n ; j++ ) {
			sum += arr[j] ;
		}

		average = sum / n ;
		printf("%f\n" , average ) ;
		sum = 0 ;
	}

	

   return 0;
}
