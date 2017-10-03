#include "stdio.h"

int top(int array[]){
	int i;
	for(i = 0; array[i] != '\0'; i++)
	;
	return array[--i];
}

int main()
{
	int array[1000] = {1, 3, 5, 8, 10, 6, 4, 3};
	printf("%d\n", top(array));

	return 0;
}