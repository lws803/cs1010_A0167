/********************************************************
 * CS1010 AY2017/8 Semester 1
 * PE1 Ex2: teetoo.c
 * Name: Ler Wei Sheng 
 * Student number: A0167342E
 * plab-id: 0038
 * Discussion group: C04
 * Description: 
 *
 ********************************************************/

#include <stdio.h>


int seesooVal (long long);

int teetooVal (long long);

int main(void) {
	long long num;
	

	printf("Enter a positive integer: ");
	scanf("%lli", &num);
	printf("%lli\n", num);


	printf ("%d\n", seesooVal(num));
	printf ("%d\n", teetooVal (num));	

	return 0;
}

/*
this function sums up all digits in num until num is a single digit
*/

int seesooVal (long long num) {
	
	while (num >= 10) {
		long long  n = num;
		long long sum = 0;

		while (n>0){
			sum += (n%10);
			n /= 10;
		}
		num = sum;
	}

	int sumInt = num;

	return sumInt;
}


/* 
precond: no negative numbers
this function finds the teetooVal by first checking where it should start
*/

int teetooVal (long long num) {
	int digitCount = 0;

	long long numForCount = num;

	while (numForCount > 0) {
		digitCount++;
		numForCount /= 10;
	}


	//Number splitter
	
	int first = digitCount%4, sum = 0;


	switch (first) {
		case 2: 
		sum += num %100;
		num /= 1000;
		break;
		case 3: 
		sum += num % 1000;
		num /= 10000;
		break;
		case 1: 
		sum += num % 10;
		num /= 100;
		break;
		default:
		sum += (num %10000)/10;
		num /= 10000;
	}


	while (num > 0) {
		sum += (num % 10000)/10;
		num /= 10000;
	}

	return sum;
}


