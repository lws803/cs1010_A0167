/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex1
 * candles.c
 * <A programme to calculate the total number of candles burnt given the number of candles(n) and the number of residue wax needed to make a candle(k)>
 * <Park Junhyuk>
 * <C06>
 */

#include <stdio.h>

int count_candle (int,int); 

int main(void) {

	int n,k,total_burnt;
	printf("Enter number of candles and \n");
	printf("number of residuals to make a new candle: ");
	scanf("%d" "%d",&n,&k);
	total_burnt = count_candle (n,k); 
	printf("Total candles burnt = %d\n",total_burnt);

	return 0;
}

int count_candle (int n , int k) { //function that counts the number of total candles burnt 

	int remain,new,total;
	total = 0;
	if (n<k) { // no new candles are produced 
		total = n;
	} 
	else {
		while (n>0){ //while loop is used to count the number of burnt candles until no/new candles remains
			new = n/k;
			remain = n%k;
			total= total + new*k;
			n = remain + new;
			if (n<k) {
				total += n;
				n=0; // n must be 0 to exit the while loop
			}
		}
	}
	return total;
}


//
