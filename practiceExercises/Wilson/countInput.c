// countInputs.c
// To count the number of input values user entered.
#include <stdio.h>

int main(void) {

	int counter = 0, value;    
	printf("Enter integers, terminate with ctrl-d\n");

    
    while (scanf("%d", &value) == 1){
    	counter++;
    };

    printf("Number of values entered = %d\n", counter);


    return 0;
}
