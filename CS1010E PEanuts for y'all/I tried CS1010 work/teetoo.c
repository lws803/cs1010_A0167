#include <stdio.h>

#define SIZE 100 

int findSeesoo( long long n ) ;
int findTeetoo( long long n ) ;
int findNumOfDigits( long long n ) ;
int sumOfThrees( int arr[] ) ;
int sumOfArray( int sums[] , int j ) ;

int main(void) {
	long long n ;
	int seesoo , teetoo ;

	printf("Enter a positive integer: ") ;
	scanf("%lli" , &n ) ;
	printf("%lli\n" , n ) ;
	seesoo = findSeesoo( n ) ;
	teetoo = findTeetoo( n ) ;
	printf("%d\n" , seesoo ) ;
	printf("%d\n" , teetoo ) ;	

   return 0;
}

int findSeesoo( long long n ) {
	int seesoo = 0 ;

	while ( n > 0 ) {	
		seesoo += n%10 ;
		n /= 10 ;
	}

	if ( seesoo >= 10 ) {
		seesoo = findSeesoo( seesoo ) ;
	}

	return seesoo ;
}

int findTeetoo( long long n ) {
	int i , numOfDigits , teetoo ;
	int arr[SIZE] = {0} ;

	numOfDigits = findNumOfDigits( n ) ;

	for ( i = numOfDigits - 1 ; i >= 0 ; i-- ) {
		arr[i] = n%10 ;
		n /= 10 ;
	}

	teetoo = sumOfThrees( arr ) ;

	return teetoo ;
}

int findNumOfDigits( long long n ) {
	int num = 0 ;

	while ( n > 0 ) {	
		num += 1 ;
		n /= 10 ;
	}

	return num ;
}

int sumOfThrees( int arr[] ) {
	int sum = 0 , partSum = 0 , i , j , latest ;
	int sums[ SIZE/4 ] ;

	for ( i = 0 , j = 0 ; i < SIZE - 3 ; i += 4 , j++ ) {
		partSum = ( ( arr[i] * 100 ) + ( arr[i+1] * 10 ) + ( arr[i+2] ) ) ;
		sums[j] = partSum ;

		if ( partSum != 0 ) {
			latest = j ;
		}
	}

	sum = sumOfArray( sums , latest ) ;

	return sum ;
}

int sumOfArray( int sums[] , int j ) {
	int i , sum = 0 ;

	while ( sums[j] % 10 == 0 && sums[j] > 0 ) {
		sums[j] /= 10 ;
	}

	for ( i = 0 ; i < SIZE/4 ; i++ ) {
		sum += sums[i] ;
	}

	return sum ;
}
