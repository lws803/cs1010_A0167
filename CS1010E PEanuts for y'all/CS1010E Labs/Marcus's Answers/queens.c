#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

void scanBoard( char board[][SIZE] , int n ) ;
void printBoard( char board[][SIZE] , int n ) ;
void lookForQ( char board[][SIZE] , int n ) ;
bool willAttack( char board[][SIZE] , int n , int i , int j ) ;
bool attack( char board[][SIZE] , int n , int i , int j , int a , int b ) ;

int main(void) {
	char board[SIZE][SIZE] ;
	int n ;

	printf("Enter n: ") ;
	scanf("%d" , &n ) ;

	scanBoard( board , n ) ;
	lookForQ( board , n ) ;

   return 0;
}

void scanBoard( char board[][SIZE] , int n ) {
	int i , j ;

	for ( i = 0 ; i < n ; i++ ) {
			scanf("%s" , &board[i] ) ;
		}
	
	return ;
}

void printBoard( char board[][SIZE] , int n ) {
	int i , j ;

	for ( i = 0 ; i < n ; i++ ) {
		for ( j = 0 ; j < n ; j++ ) {
			printf("%c" , board[i][j] ) ;
		}
		printf("\n") ;
	}
	return ;
}

void lookForQ( char board[][SIZE] , int n ) {
	int i , j ;
	bool canAttack ;

	for ( i = 0 ; i < n ; i++ ) {
		for ( j = 0 ; j < n ; j++ ) {
			if (board[i][j] == 'Q') { 
				/*printf("[%d,%d]\n" , i , j ) ;*/
				canAttack = willAttack( board , n ,i , j ) ;
				if ( canAttack == true ) {
					printf("Attacking\n");
					return ;
				}
			}
		}
	}

	printf("Not attacking\n") ;
	return ;
}

bool willAttack( char board[][SIZE] , int n , int i , int j ) {
	bool canAttack ;
	int a = 0 , b = 1 ;
	/* Attack East first*/
	canAttack = attack( board , n , i , j , a , b ) ;
	/* Then attack South */
	if ( canAttack == false ) {
		a = 1 ;
		b = 0 ;
		canAttack = attack( board , n , i , j , a , b ) ;
	}
	/* Then attack SW */
	if ( canAttack == false ) {
		a = 1 ;
		b = -1 ;
		canAttack = attack( board , n , i , j , a , b ) ;
	}
	/* Then attack SE */
	if ( canAttack == false ) {
		a = 1 ;
		b = 1 ;
		canAttack = attack( board , n , i , j , a , b ) ;
	}
	return canAttack ;
}

bool attack( char board[][SIZE] , int n , int i , int j , int a , int b ) {
	bool canAttack ;
	i += a ;
	j += b ;

	if ( i >= 0 && j >= 0 && i < n && j < n ) {
		if ( board[i][j] == 'Q') {
			return true ;
		}

		else { 
			canAttack = attack( board , n , i , j , a , b ) ;
			return canAttack ;
		}
	}
	
	else {
		return false ;
	}
}