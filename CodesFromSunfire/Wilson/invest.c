/**
 * CS1010 AY2017/8 Semester 1 Lab1 Ex1
 * invest.c
 * This program calculates the final amount given principal amount,
 * interest rate, and number of years, based on compound interest.
 * <LER WEI SHENG>
 * <C04>
 */


#include <stdio.h>
#include <math.h>

int main()
{
	float moneyEarned;
	int principal, rate, numYears;

	printf("Enter principal amount: ");
	scanf("%d", &principal);
	printf("Enter interest rate   : ");
	scanf("%d", &rate);
	printf("Enter number of years : ");
	scanf("%d", &numYears);

	float principal_f = principal;
	float rate_f = rate;
	float rateYears_f = rateYears;

	float rateYears = powf((rate_f/100.0), (numYears+1));
	moneyEarned = (principal_f*(1- rateYears_f)/(1-(rate_f/100)));

	printf("Amount = $%1.2f \n", moneyEarned);
	return 0;
}
