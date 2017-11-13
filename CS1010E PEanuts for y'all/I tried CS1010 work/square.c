#include <stdio.h>
#include <stdbool.h>

void scanSquare( int square[9][9] , int sumSquare[10][10] , int n ) ;
bool checkDistinct( int square[9][9] , int table[81] , int n ) ;
void computeSum( int square[9][9] , int sumSquare[10][10] , int n ) ;
bool checkSemiMagic( int sumSquare[10][10] , int n ) ;
void printSquare( int sumSquare[10][10] , int n ) ;

int main(void) {
	int square[9][9] = {{0}} , sumSquare[10][10] = {{0}} , table[81] = {0} ;
	int n ;
	bool isDistinct , isSemiMagic = false ;

	printf("Enter size of square: " ) ;
	scanf("%d" , &n ) ;

	scanSquare( square , sumSquare , n ) ;
	isDistinct = checkDistinct( square , table , n ) ;

	if ( isDistinct == true ) {
		computeSum( square , sumSquare , n ) ;
		/*printSquare( sumSquare , n ) ;*/
		isSemiMagic = checkSemiMagic( sumSquare , n ) ;
	}

	if ( isSemiMagic == true ) {
		printf("It is a semi-magic square.\n") ;
	}

	else {
		printf("It is not a semi-magic square.\n") ;
	}

   return 0;
}

void scanSquare(int square[9][9] , int sumSquare[10][10] , int n ) {
	int i , j ;

	for ( i = 0 ; i < n ; i++ ) {
		for ( j = 0 ; j < n ; j++ ) {
			scanf("%d" , &square[i][j] ) ;
			sumSquare[i][j] = square[i][j] ;
		}
	}
	return ;
}

bool checkDistinct( int square[9][9] , int table[81] , int n ) {
	int i , j ;

	for ( i = 0 ; i < n ; i++ ) {
		for ( j = 0 ; j < n ; j++ ) {
			if ( table[square[i][j]] == 1 ) {
				return false ;
			}
			else {
				table[square[i][j]] = 1 ;
			}
		}
	}

	return true ;
}

void computeSum( int square[9][9] , int sumSquare[10][10] , int n ) {
	int i , j ;

	for ( i = 0 ; i < n ; i++ ) {
		j = 0 ;
		while ( j < n ) {
			sumSquare[i][n] += square[i][j] ;
			j++ ;
		}
	}

	for ( j = 0 ; j < n ; j++ ) {
		i = 0 ;
		while ( i < n ) {
			sumSquare[n][j] += square[i][j] ;
			i++ ;
		}
	}

	for ( i = 0 , j = 0 ; i < n ; i++ , j++ ) {
		sumSquare[n][n] += square[i][j] ;
	}	

	return ;
}

bool checkSemiMagic( int sumSquare[10][10] , int n ) {
	int i , j ;
	int sum ;

	sum = sumSquare[n][n] ;

	for ( i = 0 ; i < n ; i++ ) {
			if ( sumSquare[i][n] != sum ) {
				return false ;
			} 
		}

	for ( j = 0 ; j < n ; j++ ) {

			if ( sumSquare[n][j] != sum ) {
				return false ;
			}
		}

	return true ;

}

void printSquare( int sumSquare[10][10] , int n ) {
	int i , j ;

	for ( i = 0 ; i <= n ; i++ ) {
		for ( j = 0 ; j <= n ; j++ ) {	

			printf("%d " , sumSquare[i][j] ) ;
		}
		printf("\n") ;
	}
	return ;
}