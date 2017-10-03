/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex1
 * candles.c
 * <Fill in a description of this program>
 * <LER WEI SHENG>
 * <C04>
 */

#include <stdio.h>

int candles_burnt(int, int);

int main(void) {
	int n, k ;

	printf("Enter number of candles and \n");
	printf("number of residuals to make a new candle: ");
	scanf("%d %d", &n, &k);
	printf("Total candles burnt = %d\n", candles_burnt(n ,k));

	return 0;
}

//This function calculates the total number of candles burnt
int candles_burnt (int n, int k) {
	int total = 0;
	int residueCollected = 0;
	while (n) {
		n -= 1;
		residueCollected += 1;
		total += 1;

		if (residueCollected == k) {
			n +=1;
			residueCollected =0;
		}
	}

	return total;
}

