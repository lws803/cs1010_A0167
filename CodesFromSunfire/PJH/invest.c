/**
* CS1010 AY2017/8 Semester 1 Lab1 Ex1
* invest.c
* This program calculates the final amount given principal amount,
* interest rate, and number of years, based on compound interest.
* <Park Junhyuk>
* <C06>
*/

#include <stdio.h> /*printf, scanf definitions */
#include <math.h> /* to use pow(x,y) function */
int main(void) {
	int principal,rate,numYears; // input //

	printf("Enter principal amount: ");
	scanf("%d",&principal); //get principal//

	printf("Enter interest rate   : ");
	scanf("%d",&rate); // get interest rate//

	printf("Enter number of years : ");
	scanf("%d",&numYears); //get number of years//

	float amount; //output//
	amount=(principal * (1-pow(((float)rate/100),(numYears+1))))/(1-(float)rate/100); // (float) used to change the respective variables to float//
	printf("Amount = $%.2f\n",amount); // Display the calculated final amount //

	return 0;
}

