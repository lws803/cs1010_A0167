#include <stdio.h>
#include <math.h>
#define DIGITS 3
#define BASE 16

int main(void) {
	char repre[16] = "0123456789ABCDEF";
	char compare[DIGITS] = "374";
	int sum = 0,power = DIGITS - 1;
	int i,j;
	
	for (i=0 ;i<DIGITS; i++){
		for (j=0; j<16;j++){
			if (repre[j] == compare[i]){
				sum = sum + (j * pow(BASE,power));
				power--;
				printf("%d ",sum);
				break;
			}
		}
	}
	printf("\n%d\n",sum);
}