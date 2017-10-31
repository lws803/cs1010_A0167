#include <stdio.h>

typedef struct {
	int x , y ;
} Point ;

int main(void) {
	Point prey , PRED ;

	scanf("%d %d" , &(prey.x) , &(prey.y) ) ;
	scanf("%d %d" , &(PRED.x) , &(PRED.y) ) ;

	printf("prey(%d,%d)\n" , (prey.x) , (prey.y) ) ;
	printf("PRED(%d,%d)\n" , (PRED.x) , (PRED.y) ) ;

   return 0;
}
