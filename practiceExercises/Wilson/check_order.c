// check_order.c 
// Repeatedly reads positive integer, until the input value 
// is zero, or the data are not in increasing order.

#include <stdio.h>

int main(void) {
	int a = 0, b;

	do {
		printf("Enter positive integer: ");
		b = a;
		scanf("%d", &a);

	}while (a>b && a > 0);


	if (a == 0) {
		printf("Data are in increasing order.\n");
	}else{
		printf("Data are not in increasing order.\n");
	}


	return 0;
}
