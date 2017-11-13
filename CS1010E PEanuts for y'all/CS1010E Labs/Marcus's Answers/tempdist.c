#include <stdio.h>
#include <stdbool.h>

void makePlate( int plate[100][100] , int plateNew[100][100] , int n , int t ) ;
void printPlate( int plate[100][100] , int n , int *iteration) ;
void distribute( int plate[100][100] , int plateNew[100][100] , int n ) ;
int average( int plate[100][100] , int i , int j ) ;
bool checkPlate( int plate[100][100] , int plateNew[100][100] , int n , int *iteration ) ;

int main(void) {
	int plate[100][100] = {{0}} , plateNew[100][100] = {{0}} ;
	int n , t ;
	int iteration = 1 ;
	bool isSame = false ;

	printf("Enter n: ") ;
	scanf("%d" , &n ) ;
	printf("Enter t: ") ;
	scanf("%d" , &t ) ;

	makePlate( plate , plateNew , n , t ) ;
	/*printPlate( plate , n , &iteration ) ;*/

	while (isSame == false) {
		distribute( plate , plateNew , n ) ;
		/*printPlate( plateNew , n , &iteration ) ;*/
		isSame = checkPlate( plate , plateNew , n , &iteration ) ;
	}

	printf("Steady state iteration: %d\n" , iteration ) ;

   return 0;
}

void makePlate( int plate[100][100] ,int plateNew[100][100] , int n , int t ) {
	int i = 0 , j = 0 ;

	while ( j < n ) {
		plate[0][j] = t ;
		plate[n-1][j] = t ;
		j++ ;
	}

	while ( i < n ) {
		plate[i][0] = t ;
		plate[i][n-1] = t ;
		i++ ;
	}	

	for ( i = 0 ; i < n ; i++ ) {
		for ( j = 0 ; j < n ; j++ ) {
			plateNew[i][j] = plate[i][j] ;
		}
	}

	return ;
}

void printPlate( int plate[100][100] , int n , int *iteration ) {
	int i , j ;

	printf("Iteration: %d\n" , *iteration ) ;

	for ( i = 0 ; i < n ; i++ ) {
		for ( j = 0 ; j < n ; j++ ) {
			printf("%d " , plate[i][j] ) ;
		}
		printf("\n") ;
	}

	printf("\n") ;

	return ;
}

void distribute( int plate[100][100] , int plateNew[100][100] , int n ) {
	int i , j ;

	for ( i = 1 ; i < n - 1 ; i++ ) {
		for ( j = 1 ; j < n - 1 ; j ++ ) {
			plateNew[i][j] = average( plate , i , j ) ;
		}
	}

	return ;
}

int average( int plate[100][100] , int i , int j ) {
	int ave ;

	ave = ( ( plate[i-1][j] + plate[i][j+1] + plate[i+1][j] + plate[i][j-1] ) / 4 ) ;

	return ave ;
}

bool checkPlate( int plate[100][100] , int plateNew[100][100] , int n , int * iteration ) {
	int i , j ;

	for ( i = 0 ; i < n ; i++ ) {
		for ( j = 0 ; j < n ; j++ ) {
			if ( plate[i][j] != plateNew[i][j] ) {
				*iteration += 1 ;
				for ( i = 0 ; i < n ; i++ ) {
					for ( j = 0 ; j < n ; j++ ) {
						plate[i][j] = plateNew[i][j] ;
					}
				}
				return false ;
			}
		}
	}

	return true ;
}