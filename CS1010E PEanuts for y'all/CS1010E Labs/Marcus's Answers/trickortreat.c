#include <stdio.h>

void generateMap( int map[100][100] , int n ) ;
int max( int up , int left) ;
void move( int map[100][100] , int n ) ;
void printMap( int map[100][100] , int n ) ;

int main(void) {
	int map[100][100] = {{0}} ;
	int n ; 

	printf("Enter n: ") ;
	scanf("%d" , &n ) ;
	generateMap( map , n ) ;
	move( map , n ) ;

	printf("Maximum: %d\n" , map[n][n] ) ;

   return 0;
}

void generateMap( int map[100][100] , int n ) {
	int i , j ;

	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) {
			scanf("%d" , &map[i][j]) ;
		}
	}

	return ;
}

int max( int up , int left) {
	int n ;

	n = up ;
	if ( left > up ) {
		n = left ;
	}

	return n ;
}

void move( int map[100][100] , int n ) {
	int i , j , sum ;

	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= n ; j++ ) {
			sum = max( map[i-1][j] , map[i][j-1] ) ;
			map[i][j] += sum ;
			/*printMap( map , n ) ;*/

		}
	}
	return ;
}

void printMap( int map[100][100] , int n ) {
	int i , j ;

	for ( i = 0 ; i <= n ; i++ ) {
		for ( j = 0 ; j <= n ; j++ ) {
			printf("%d " , map[i][j]) ;
		}
		printf("\n") ;
	}

	printf("\n") ;

	return ;

}
