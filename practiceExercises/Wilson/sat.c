// CS1010 AY2012/3 Semester 1
// PE1 Ex1: sat.c
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Description:

#include <stdio.h>

int computePercentile (int, int, int);
float computeIQscore (int, int, int);

int main(void) {

	int verbal, math, writing ; // user's input

	printf("Enter scores: ");

	scanf("%d %d %d", &verbal, &math, &writing);

	printf("The SAT score is in the %d percentile.\n", computePercentile(verbal, math, writing));

	printf("The IQ score is %0.2f\n", computeIQscore(verbal, math, writing));

	if ((verbal>600 && math>600 && writing>600) || computeIQscore(verbal, math, writing)>=120)
		printf("Wow, this is amazing!\n");

	return 0;

}

int computePercentile (int verbal, int math, int writing) {
	int percentile; 
	int total = verbal + math + writing;


	if (total >= 2200) {
		percentile = 99;
	}else if (total >= 2000) {
		percentile = 95;
	}else if (total >= 1500) {
		percentile = 50;
	}else {
		percentile = 10;
	}

	return percentile;
}

float computeIQscore (int verbal, int math, int writing) {
	float iq = (0.095 * math) + (0.003 * verbal) + 50.241;


	return iq;
}