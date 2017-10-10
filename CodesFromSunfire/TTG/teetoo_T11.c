/********************************************************
 * CS1010 AY2017/8 Semester 1
 * PE1 Ex2: teetoo.c
 * Name: <name removed>
 * Student number: <remove>
 * plab-id: <remove>
 * Discussion group: T11 
 * Description: This program takes in a positive integer n, and prints out the 'seesoo' value and 'teetoo' value
 *
 ********************************************************/

#include <stdio.h>
#include <math.h>

int sum_digits(long long n);

int count_digits(long long n);

int compute_seesoo(long long n);

int compute_teetoo(long long n);

int main(void) {
	long long num;

	printf("Enter a positive integer: ");
	scanf("%lli", &num);
	printf("%lli\n", num);

	printf("%d\n", compute_seesoo(num));

	printf("%d\n", compute_teetoo(num));

	return 0;
}

//this function sums all the digits of an integer, n
//Precondition: n is positive
int sum_digits(long long n) {
	int sum = 0;
	while (n > 0) {
		sum += n%10; //add the last digit of n
		n /= 10; //remove the last digit of n
	}
	return sum;
}

//this function counts the number of digits of an integer, n
//Precondition: n is positive
int count_digits(long long n) {
	int count = 0;
	while (n > 0) {
		count++; 
		n /= 10; //remove the last digit
	}
	return count;
}

//this function returns the seesoo value of an integer n
//Precondition: n is positive
//Postcondition: output is the seesoo value which is an integer from 0 to 9 inclusive
int compute_seesoo(long long n) {
	while (n > 9) {
		n = sum_digits(n); //repeatedly sum digits until n<9 (1 digit)

		// Aaron's comment: This is a good decomposition strategy.
		//    The task of summing the digits of a number is delegated
		//    to another function sum_digits(n);
		//    This reduces the chance of careless mistake of not updating 
		//    the correct variable if everything is done in this function.
	}
	return n;
}

//this function returns the teetoo value of an integer n
//Precondition: n is positive
int compute_teetoo(long long n) {
	int last_width, digits, teetoo = 0; //digits is the number of digits of n
	digits = count_digits(n);

	//digits % 4 is the width of the last group of 3 when splitting n into groups of 3
	last_width = digits % 4;

	teetoo += n % (int) pow(10, last_width); //Add the last group to teetoo

	n /= (int) pow(10, last_width + 1); //remove the group from n and the separating digit also

	//now the number of digits of n should be a multiple of 4
	while (n > 0) {
		teetoo += n % 1000; //add the last 3 digits of n
		n /= 10000; //remove the last 4 digits of n
	}

	return teetoo;
}
