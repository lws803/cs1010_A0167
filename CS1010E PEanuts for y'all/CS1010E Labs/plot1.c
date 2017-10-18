#include <stdio.h>

int main(void) {

	int c3 , c2 , c1 , c0 ;
	double xl , xh ;

	scanf("%d %d %d %d" , &c3 , &c2 , &c1 , &c0 ) ;
	scanf("%lf %lf" , &xl , &xh) ;

	printf("%d %d %d %d\nxl = %f; xh = %f\n" , c3 , c2 , c1 , c0 , xl , xh) ;

   return 0;
}
