#include <stdio.h>

int get_magic(int);

int main(void){
	int num1,num2;
	
	printf("Enter 1st value: ");
	scanf("%d",&num1);
	num2 = get_magic(num1);
	printf("Magic number = %d\n",num2);
	
	printf("Enter 2nd value: ");
	scanf("%d",&num1);
	num2 = get_magic(num1);
	printf("Magic number = %d\n",num2);
	
	return 0;
}

int get_magic(int num){
	int sum = 0,magic;
	sum += temp % 10;
	sum += (temp % 1000)/100;
	sum += (temp % 100000)/10000;
	
	magic = sum%10;
	return magic;
}