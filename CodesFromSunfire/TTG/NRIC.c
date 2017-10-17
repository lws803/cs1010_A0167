#include <stdio.h>
#include <math.h>

char generateCode(int);

int main(void){
	int NRIC,checkCode;
	printf("Enter 7-digit NRIC number: ");
	scanf("%d",&NRIC);
	
	checkCode = generateCode(NRIC);
	
	printf("Check code is %c\n",checkCode);
}

char generateCode(int nric){
	int i,temp,sum=0,remainder,check = 11,checkCode;
	for (i=0;i<7;i++){
		temp = nric%10;
		nric /= 10;
		
		if (i==6)
			sum += (2 * temp);
		else
			sum += (i+2)*temp;
	}
	remainder = sum % 11;
	check -= remainder;
	switch(check){
		case 1: checkCode = 'A'; break;
		case 2: checkCode = 'B'; break;
		case 3: checkCode = 'C'; break;
		case 4: checkCode = 'D'; break;
		case 5: checkCode = 'E'; break;
		case 6: checkCode = 'F'; break;
		case 7: checkCode = 'G'; break;
		case 8: checkCode = 'H'; break;
		case 9: checkCode = 'I'; break;
		case 10: checkCode = 'Z'; break;
		case 11: checkCode = 'J';
	}
	return checkCode;
}