#include <stdio.h>

int compute_percentile(int, int, int);
double compute_iqscore(int, int);

int main (void) {
	int verbal, maths, writing, percent;
	double iq;
	printf("Enter scores: ");
	scanf("%d %d %d",&verbal, &maths, &writing);
	
	percent = compute_percentile(verbal, maths, writing);
	iq = compute_iqscore(verbal,maths);

	printf("The SAT score is in the %d percentile.\nThe IQ score is %.2lf\n",percent,iq);
	if ((maths > 600 && verbal > 600 && writing > 600) || iq >= 120)
		printf ("Wow, this is amazing!\n");
		return 0;
}



int compute_percentile(int verbal, int maths, int writing){
	int total;
	total = verbal + maths + writing;
	if (total >= 2200)
		return 99;
	if (total >= 2000)
		return 95;
	if (total >= 1500)
		return 50;
	else
		return 10;
} 

double compute_iqscore(int verbal, int maths){
	double iq;
	iq = (0.095 * maths) + (0.003 * verbal) + 50.241 ;
	return iq;
}

 
