#include <stdio.h>
#include <string.h> 

void generateMaze( char maze[][30] ) ;
void printMaze( char maze[][30] ) ;

int main(void) {
	char maze[30][30] = {{0}} ;

	generateMaze( maze ) ;
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
