#include <stdio.h>

int scanBoard( int board[12][12] ) ;
int search( int board[12][12] , int *startX , int *startY ) ;
void computeLength( int board[12][12] , int i , int j , int *lengthMax , int digit , int *startX , int *startY ) ;
int checkRight( int board[12][12] , int i , int j , int digit ) ;
int checkDiagonal( int board[12][12] , int i , int j , int digit ) ;
int checkDown( int board[12][12] , int i , int j , int digit ) ;

int main(void) {
	int board[12][12] ;
	int startX = 0 , startY = 0 ;

	printf("Length of longest sequence = %d\n" , search( board , &startX , &startY ) ) ;

	if ( (search( board , &startX , &startY ) ) > 0 ) {
		printf("Start at (%d,%d)\n" , startX , startY ) ;
	} 

	else {
		printf("No such sequence\n") ;
	}

   return 0;
}

int scanBoard( int board[12][12] ) {
	int i , j ;
	int digit ;

	for ( i = 0 ; i < 12 ; i++ ) {
		for ( j = 0 ; j < 12 ; j++ ) {
			scanf("%d" , &board[i][j] ) ;
		}
	}
	scanf("%d" , &digit ) ;
	return digit ;
}

int search( int board[12][12] , int *startX , int *startY ) {
	int i , j , digit , lengthMax = 0 ;
	int startx , starty ;

	digit = scanBoard( board ) ;

	for ( i = 0 ; i < 12 ; i++ ) {
		for ( j = 0 ; j <= i ; j++ ) {
			if ( board[i][j] == digit || board[j][i] == digit ) {
				computeLength( board , i , j , &lengthMax , digit , &startx , &starty ) ;
			}
		}
	}

	*startX = startx ;
	*startY = starty ;

	return lengthMax ;
}

void computeLength( int board[12][12] , int i , int j , int *lengthMax , int digit , int *startx , int *starty) {
	int length = 0 ;

	if ( board[i][j] == digit ) {
		length += 1 ;		

		if ( board[i][j+1] == digit ) {
			length += checkRight( board , i , j+1 , digit ) ;

			if( length > *lengthMax ) {
				*lengthMax = length ;
				*startx = i ;
				*starty = j ;
			}

			length = 1 ;
		}

		if ( board[i+1][j+1] == digit ) {
			length += checkDiagonal( board , i+1 , j+1 , digit ) ;

			if( length > *lengthMax ) {
				*lengthMax = length ;
				*startx = i ;
				*starty = j ;				
			}

			length = 1 ;			
		}

		if ( board[i+1][j] == digit ) {
			length += checkDown( board , i+1 , j , digit ) ;

			if( length > *lengthMax ) {
				*lengthMax = length ;
				*startx = i ;
				*starty = j ;				
			}

			length = 1 ;			
		}		
	}

	length = 0 ;

	if ( board[j][i] == digit ) {
		length += 1 ;

		if ( board[j][i+1] == digit ) {
			length += checkRight( board , j , i+1 , digit ) ;

			if( length > *lengthMax ) {
				*lengthMax = length ;
				*startx = j ;
				*starty = i ;				
			}

			length = 1 ;			
		}

		if ( board[j+1][i+1] == digit ) {
			length += checkDiagonal( board , j+1 , i+1 , digit ) ;

			if( length > *lengthMax ) {
				*lengthMax = length ;
				*startx = j ;
				*starty = i ;					
			}

			length = 1 ;			
		}

		if ( board[j+1][i] == digit ) {
			length += checkDown( board , j+1 , i , digit ) ;

			if( length > *lengthMax ) {
				*lengthMax = length ;
				*startx = j ;
				*starty = i ;					
			}

			length = 1 ;			
		}		
	}	
	return ;
}

int checkRight( int board[12][12] , int i , int j , int digit ) {
	int length = 0 ;

	if ( board[i][j] == digit ) {
		length += 1 ;
		length += checkRight( board , i , j+1 , digit ) ;
	}

	return length ;
}

int checkDiagonal( int board[12][12] , int i , int j , int digit ) {
	int length = 0 ;

	if ( board[i][j] == digit ) {
		length += 1 ;
		length += checkDiagonal( board , i+1 , j+1 , digit ) ;
	}

	return length ;
}

int checkDown( int board[12][12] , int i , int j , int digit ) {
	int length = 0 ;	

	if ( board[i][j] == digit ) {
		length += 1 ;
		length += checkDown( board , i+1 , j , digit ) ;
	}

	return length ;
}
