#include <stdio.h>
#include <stdbool.h>

void numToArray( int n , int num[] ) ;
void sortArrayAsc( int num[] ) ;
void reverseArray( int num[] , int numRev[] ) ;
void arrayDiff( int num[] , int numRev[] , int diff[] ) ;
void printArray( int diff[] ) ;
bool checkArray( int diff[] , int diffOld[] ) ;
void copyArray( int diff[] , int diffOld[] ) ;

int main(void) {

	int num[4] = {0} ;
	int numRev[4] = {0} ;
	int diff[4] = {0} ;
	int diffOld[4] = {0} ;
	int n ;
	bool isSame = false ;

	printf("Enter number: ") ;
	scanf("%d" , &n ) ;
	numToArray( n , num ) ;
	
	while( isSame == false ) {		
		sortArrayAsc( num ) ;	
		reverseArray( num , numRev ) ;
		arrayDiff( num , numRev , diff ) ;
		printArray( diff ) ;
		isSame = checkArray( diff , diffOld ) ;
		copyArray( diff , diffOld ) ;
		copyArray( diff , num ) ;

}

   return 0;
}

void numToArray( int n , int num[] ) {
	int i ;

	for ( i = 0 ; i < 4 ; i++ ) {
		num[i] = n % 10 ;
		n /= 10 ;
	}
	return ;
}

void sortArrayAsc( int num[] ) {
	int i , j , temp ;

	for ( j = 1 ; j <=3 ; j++ ) {
	for ( i = 0 ; i < 4 ; i++ ) {
		if ( num[i] > num[i+1] ) {
			temp = num[i] ;
			num[i] = num[i+1] ;
			num[i+1] = temp ;
		}
	}
}
	return ;
}

void reverseArray ( int num[] , int numRev[] ) {
   int i ;

   for ( i = 0 ; i < 4 ; i++ ) {
    	numRev[i] = num[3-i];    
   }
   return ;
}

void arrayDiff( int num[] , int numRev[] , int diff[] ) {
	int i ;
	int flag = 1 ;

	for ( i = 0 ; i < 4 ; i++ ) {
		diff[i] = numRev[i] - num[i] ;
	}

	while ( flag == 1 ) {
		flag = 0 ;

		for ( i = 0 ; i < 4 ; i++ ){
			if ( diff[i] < 0) {
				diff[i-1] -= 1 ;
				diff[i] += 10 ;
				flag = 1 ;
			}
		}	
	}
	
	return ;
}

void printArray( int diff[] )  {
	int i ;

	for ( i = 0 ; i < 4 ; i++ ) {
		printf("%d" , diff[i] ) ;
	}
	printf("\n") ;
	return ;
}

bool checkArray( int diff[] , int diffOld[] ) {
	int i ;

	for ( i = 0 ; i < 4 ; i++ ) {
		if ( diff[i] != diffOld[i] ) {
			return false ;
		}
	}

	return true ;
}

void copyArray( int diff[] , int diffOld[] ) {
	int i ;

	for ( i = 0 ; i < 4 ; i++ ) {
		diffOld[i] = diff[i] ;
	}

	return ;
}