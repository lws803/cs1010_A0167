#include <stdio.h>

typedef struct {
	int x , y ;
} Point ;

int main(void) {
	Point prey , PRED ;
	Point preyMove ;
	int i ;

	scanf("%d %d" , &(prey.x) , &(prey.y) ) ;
	scanf("%d %d" , &(PRED.x) , &(PRED.y) ) ;

	printf("prey(%d,%d)\n" , (prey.x) , (prey.y) ) ;
	printf("PRED(%d,%d)\n" , (PRED.x) , (PRED.y) ) ;

	for ( i=0 ; i < 10 ; i++ ) {

		scanf("%d %d" , &(preyMove.x) , &(preyMove.y) ) ;

		(prey.x) += (preyMove.x) ;
		(prey.y) += (preyMove.y) ;

		printf("prey(%d,%d)\n" , (prey.x) , (prey.y) ) ;

		if ( (PRED.y) != 0 ) {

			(PRED.y) -= 1 ;

		}

		printf("PRED(%d,%d)\n" , (PRED.x) , (PRED.y) ) ;

	}

   return 0;
}
