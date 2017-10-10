/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex1
 * candles.c
 * This program calculates the number of candles that can be burnt given the initial number of candles
 * and the amount of residual wax that can be used to make a new candle. 
 * Tan Tze Guang
 * C06
 */

#include <stdio.h>

int count_candles(int,int);

int main(void) {
	int numberCandles, residualWaxAmount, totalCandlesBurnt;

	printf("Enter number of candles and \n");
	printf("number of residuals to make a new candle: ");
	scanf("%d %d",&numberCandles,&residualWaxAmount);

	totalCandlesBurnt = count_candles(numberCandles,residualWaxAmount);

	printf("Total candles burnt = %d\n",totalCandlesBurnt);

	return 0;
}

//This function calculates the number of candles that can be burnt
//given the number of initial candles n
//and the number of residual wax to make a new candle k
//Pre-condition: n > 0 , k > 0

int count_candles(int n, int k) {
	int total = 0;

	//Initialise a temp variable to store the number of candles that can be made from the residue.
	int residueCandles;
	//Initialise a temp variable to store the remaining candles after burning as many sets of k candles.
	int remainder;
	while (n > 0) {
		residueCandles = n / k;
		remainder = n % k;
		total = total + n - remainder;

		//if no new candles can be made from burning again then end the process
		if ((remainder + residueCandles) < k) {
			total = total + remainder + residueCandles;
			n = 0;
		}
		//else reassign n to have the remaining candles and continue
		else {
			n = remainder + residueCandles;
		}
	}			
	return total;
}
