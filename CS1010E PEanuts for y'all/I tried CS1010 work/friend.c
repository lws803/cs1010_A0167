#include <stdio.h>
#define SIZE 10

void makeArray( int friendArr[][SIZE] , int n ) ;
void printArray( int friendArr[][SIZE] , int n ) ;
int leastTotalFriends( int friendArr[][SIZE] , int sum[] , int n ) ;
void iSolitude( int sum[] , int n , int least ) ;
void uFriend( int friendArr[][SIZE] , int n ) ;
void checkFriend( int friendArr[][SIZE] , int i , int j , int n ) ;


int main(void) {
	int friendArr[SIZE][SIZE] = {{0}} , sum[SIZE] = {0} ;
	int n , least ;

	printf("Read in the number of users: ") ;
	scanf("%d" , &n ) ;
	printf("There are %d users, indexed from 0 to %d.\n" , n , n - 1 ) ;
	makeArray( friendArr , n ) ;
	least = leastTotalFriends( friendArr , sum , n ) ;
	printf("The least number of friends found is %d\n" , least ) ;
	iSolitude( sum , n , least ) ;
	uFriend( friendArr , n ) ;

   return 0;
}

void makeArray( int friendArr[][SIZE] , int n ) {
	int pairs ;
	int i , j ;

	printf("Enter the number of pairs of direct friends: ") ;
	scanf("%d" , &pairs ) ;	

	while ( pairs > 0 ) {
		scanf("%d %d" , &i , & j ) ;
		friendArr[i][j] = 1 ;
		pairs-- ;
	}
	printArray( friendArr , n ) ;
	printf("The friendship matrix is: \n") ;

	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < n ; j++ ) {
			if ( i == j ) {
				friendArr[i][j] = 1 ;
			}

			if ( friendArr[i][j] == 1 ) {
				friendArr[j][i] = 1 ;
			}
		}
	}

	printArray( friendArr , n ) ;

	return ;
}

void printArray( int friendArr[][SIZE] , int n ) {
	int i , j ;

	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < n ; j++ ) {
			printf("%d " , friendArr[i][j] ) ;
		}
		printf("\n") ;
	}
	return ;	
}

int leastTotalFriends( int friendArr[][SIZE] , int sum[] , int n ) {
	int i , j , least ;

	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < n ; j++ ) {
			sum[i] += friendArr[i][j] ;
		}
	}	

	least = sum[0] ;

	for ( i = 0 ; i < n ; i++ ) {
		if ( sum[i] < least ) {
			least = sum[i] ;
		}
	}

	return least ;
}

void iSolitude( int sum[] , int n , int least ) {
	int i ;

	for ( i = 0 ; i < n ; i++ ) {
		if ( sum[i] == least ) {
			printf("User %d has the least number of friends\n" , i ) ;
		}
	}
	return ;
}

void uFriend( int friendArr[][SIZE] , int n ) {
	int i , j ;

	for ( i = 0 ; i < n ; i++ ) {
		for ( j = 0 ; j < n ; j++ ) {
			if ( friendArr[i][j] == 1 ) {
				checkFriend( friendArr , i , j , n ) ;
			}
		}
	}

	return ;

}

void checkFriend( int friendArr[][SIZE] , int i , int j , int n ) {
	int a = j + 1 ;

	for ( a ; a < n ; a++ ) {
		if ( friendArr[i][a] == 1 ) {
			if ( friendArr[j][a] == 0 ) {
				printf("(%d,%d) has a friend-of-friend relation.\n" , j , a ) ;
			}
		}
	}

	return ;
}
