/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex2
 * square_free.c
 * <LER WEI SHENG>
 * <C04>
 * <Fill in a description of this program>
 */

#include <stdio.h>
#include <math.h> // optional, please remove if you are not using it

int number_of_numbers (int, int);

int main(void) {
	int lower1, upper1, lower2, upper2;
	int lowerWin, upperWin, winNumber;

	printf("Enter four positive integers: ");
	scanf("%d %d %d %d", &lower1, &upper1, &lower2, &upper2);

	if (number_of_numbers(lower1, upper1) > number_of_numbers(lower2, upper2)) {
		lowerWin = lower1;
		upperWin = upper1;
		winNumber = number_of_numbers(lower1, upper1);
		printf("Range [%d, %d] has more square-free numbers: %d\n", lowerWin, upperWin, winNumber);

	}else if (number_of_numbers(lower1, upper1) == number_of_numbers(lower2, upper2)) {
		winNumber = number_of_numbers(lower1, upper1);
		printf("Both ranges have the same number of square-free numbers: %d\n", winNumber);
	}
	else{
		lowerWin = lower2;
		upperWin = upper2;
		winNumber = number_of_numbers(lower2, upper2);			
		printf("Range [%d, %d] has more square-free numbers: %d\n", lowerWin, upperWin, winNumber);
	}
	return 0;
}



//obtains the number of square free numbers per set
int number_of_numbers (int lower, int upper) {
	int i, square_frees=0;
	for (i=lower; i<=upper; i++){
		int a=0;
		//a is the number of sucessful divides
		/*	
			loop will continue as long as counter^2 is lesser or equals to the number i
			and if not, it will continuously increment until the counter squared gets to a higher number.
		*/
		int counter = 2;
		while (counter*counter <= i) {
			if (i%(counter*counter)==0){
				a+=1;
				break;
			}
			counter++;
		}
		if (a==0) {
			square_frees+=1;
		}
	}
	return square_frees;
}	

