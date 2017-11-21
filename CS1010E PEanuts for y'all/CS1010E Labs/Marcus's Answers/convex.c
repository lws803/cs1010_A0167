#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int x , y ;
} Point ;

void scanArray( Point arr[] , int n ) ;
void printArray( Point arr[] , int n ) ;
bool checkRight( Point arr[] , int i ) ;

int main(void) {
	int n , i ;
	Point arr[10] ;
	bool isRight = true ;

	printf("Enter number of vertices: ") ;
	scanf("%d" , &n ) ;
	scanArray( arr , n ) ;

	for ( i = 1 ; i <= n && isRight == true ; i++ ) {
		isRight = checkRight( arr , i ) ;
	}

	if ( isRight == true ) {
		printf("YES\n") ;
	}

	else {
		printf("NO\n") ;
	}

   return 0;
}

void scanArray( Point arr[] , int n ) {
	int i ;

	for ( i = 1 ; i <= n ; i++ ) {
		scanf("%d %d" , &arr[i].x , &arr[i].y ) ;
	}

	arr[0].x = arr[n].x ;
	arr[0].y = arr[n].y ;
	arr[n+1].x = arr[1].x ;
	arr[n+1].y = arr[1].y ;

	return ;
}

void printArray( Point arr[] , int n ) {
	int i ;

	for ( i = 0 ; i <= n+1 ; i++ ) {
		printf("%d,%d\n" , arr[i].x , arr[i].y );
	}
	return ;
}

bool checkRight( Point arr[] , int i ) {
	int a , b , c , value ;
	int ax , ay , bx , by , cx , cy ;

	a = i - 1 ;
	b = i ;
	c = i + 1 ;

	ax = arr[a].x ;
	ay = arr[a].y ;
	bx = arr[b].x ;
	by = arr[b].y ;
	cx = arr[c].x ;
	cy = arr[c].y ;		

	value = ( ax * ( by - cy ) ) - ( ay * ( bx - cx )) + ( ( bx * cy ) - (by * cx)) ;

	if ( value >= 0 ) {
		return false ;
	}

	else {
		return true ;
	}
}
