#include <stdio.h>

typedef struct {
	int x , y ;
} Point ;

void TurnRight ( int *PREDMoveX , int *PREDMoveY ) ;

int main(void) {
	Point prey , PRED ;
	Point preyMove ;
	int i , PREDMoveX , PREDMoveY  ;

	scanf("%d %d" , &(prey.x) , &(prey.y) ) ;
	scanf("%d %d" , &(PRED.x) , &(PRED.y) ) ;

	printf("prey(%d,%d)\n" , (prey.x) , (prey.y) ) ;
	printf("PRED(%d,%d)\n" , (PRED.x) , (PRED.y) ) ;

	PREDMoveX =  0 ;
	PREDMoveY =  -1 ;

	for ( i=0 ; i < 10 ; i++ ) {
		
		scanf("%d %d" , &(preyMove.x) , &(preyMove.y) ) ;

		(prey.x) += (preyMove.x) ;
		(prey.y) += (preyMove.y) ;

		printf("prey(%d,%d)\n" , (prey.x) , (prey.y) ) ;

		/* UP (0,1) , RIGHT (1,0) , DOWN (0,-1) , LEFT (-1,0) */

		(PRED.x) += PREDMoveX ;
		(PRED.y) += PREDMoveY ;

		if ( (PRED.x) < 0 || (PRED.x) > 9 || (PRED.y) < 0 || (PRED.y) > 9 ) {

			(PRED.x) -= PREDMoveX ;
			(PRED.y) -= PREDMoveY ;

		}

		printf("PRED(%d,%d)\n" , (PRED.x) , (PRED.y) ) ;

		TurnRight ( &PREDMoveX , &PREDMoveY ) ;

	}

   return 0;
}

void TurnRight ( int *PREDMoveX , int *PREDMoveY ) {

	if ( *PREDMoveX == 0 && *PREDMoveY == 1 ) {
		*PREDMoveX = -1 ;
		*PREDMoveY = 0 ;

	}

	else if ( *PREDMoveX == -1 && *PREDMoveY == 0 ) {
		*PREDMoveX = 0 ;
		*PREDMoveY = -1 ;
		
	}

	else if ( *PREDMoveX == 0 && *PREDMoveY == -1 ) {
		*PREDMoveX = 1 ;
		*PREDMoveY = 0 ;
		
	}

	else if ( *PREDMoveX == 1 && *PREDMoveY == 0 ) {
		*PREDMoveX = 0 ;
		*PREDMoveY = 1 ;
		
	}

	return ;
}