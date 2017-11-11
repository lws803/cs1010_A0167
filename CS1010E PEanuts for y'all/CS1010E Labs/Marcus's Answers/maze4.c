#include <stdio.h>
#include <string.h> 

void generateMaze( char maze[][30] ) ;
void printMaze( char maze[][30] ) ;
void findPosOfS( char maze[][30] , int *startX , int *startY ) ;
void moveEast( char maze[][30] , int startX , int startY ) ;
void moveNorth( char maze[][30] , int startX , int startY ) ;
void moveWest( char maze[][30] , int startX , int startY ) ;
void moveSouth( char maze[][30] , int startX , int startY ) ;

int main(void) {
	char maze[30][30] = {{0}} ;
	int startX = 0 , startY = 0 ;

	generateMaze( maze ) ;
	findPosOfS( maze , &startX , &startY ) ;
	printf("start = (%d,%d)\n" , startX , startY) ;
	moveEast( maze , startX , startY ) ;
	printMaze( maze ) ;

   return 0;
}

void generateMaze( char maze[][30] ) {
	int i = 0;

	scanf("%s" , maze[i] ) ;
	while ( maze[i][0] != 0 ) {
		i++ ;
		scanf("%s" , maze[i] ) ;
	}

	return ;
}

void printMaze( char maze[][30] ) {
	int i , j ;

	for ( i = 0 ; maze[i][0] != 0 ; i++ ) {
		for ( j = 0 ; maze[i][j] != 0 ; j++ ) {
			printf("%c" , maze[i][j] ) ;
		}
		printf("\n") ;
	}
	
	return ;
}

void findPosOfS( char maze[][30] , int *startX , int *startY ) {
	int i , j ;

	for ( i = 0 ; maze[i][0] != 0 ; i++ ) {
		for ( j = 0 ; maze[i][j] != 0 ; j++ ) {
			if ( maze[i][j] == 's' ) {
				*startX = i ;
				*startY = j ;

				return ;
			}
		}
	}	
}

void moveEast( char maze[][30] , int startX , int startY ) {
	int i = startX , j = startY ;

	if ( maze[i-1][j] == '.' || maze[i-1][j] == 'e' ) {
		moveNorth( maze , startX , startY ) ;
	}

	else if ( maze[i][j] == '.' || maze[i][j] == 'e' || maze[i][j] == 's' ) {
		maze[i][j] = '1' ;
		moveEast( maze , startX , startY + 1) ;
	}
	
	return ;
}

void moveNorth( char maze[][30] , int startX , int startY ) {
	int i = startX , j = startY ;

	if ( maze[i][j-1] == '.' || maze[i][j-1] == 'e') {
		moveWest( maze , startX , startY ) ;
	}

	else if ( maze[i][j] == '.' || maze[i][j] == 'e') {
		maze[i][j] = '1' ;
		moveNorth( maze , startX - 1 , startY ) ;
	}
	
	return ;

}
void moveWest( char maze[][30] , int startX , int startY ) {
	int i = startX , j = startY ;

	if ( maze[i+1][j] == '.' || maze[i+1][j] == 'e' ) {
		moveSouth( maze , startX , startY ) ;
	}

	else if ( maze[i][j] == '.' || maze[i][j] == 'e' ) {
		maze[i][j] = '1' ;
		moveWest( maze , startX , startY - 1) ;
	}
	
	return ;

}
void moveSouth( char maze[][30] , int startX , int startY ) {
	int i = startX , j = startY ;

	if ( maze[i][j+1] == '.' || maze[i][j+1] == 'e') {
		moveEast( maze , startX , startY ) ;
	}

	else if ( maze[i][j] == '.' || maze[i][j] == 'e' ) {
		maze[i][j] = '1' ;
		moveSouth( maze , startX + 1 , startY ) ;
	}
	
	return ;

}