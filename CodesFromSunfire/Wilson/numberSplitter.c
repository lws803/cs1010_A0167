#include "stdio.h"


void disectNum(int inputNum) {
	while(inputNum){
		printf("%d\n", inputNum%10);
		inputNum /= 10;
	}
}




int main(void)
{
	int inputNum;
	printf("Enter a number to be split up: ");
	scanf("%d", &inputNum);
	disectNum(inputNum);
	return 0;
}