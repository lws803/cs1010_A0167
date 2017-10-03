#include <stdio.h>

int computeHappyNumbers(int, int);
int isHappy (int); 

int main () {
	int lower, upper, lower2, upper2;

	printf("Enter first range: ");
	scanf("%d %d", &lower, &upper);

	printf("Enter second range: ");
	scanf("%d %d", &lower2, &upper2);


	int happyNumbers1 = computeHappyNumbers(lower, upper);

	int happyNumbers2 = computeHappyNumbers (lower2, upper2);


	printf("The numbers of happy numbers in the two ranges are: %d %d\n", happyNumbers1, happyNumbers2);


	if (happyNumbers1 > happyNumbers2) {

		printf("There are more happy numbers in the first range.\n");
	}else if (happyNumbers1 < happyNumbers2){
		printf("There are more happy numbers in the second range.\n");
	}else{
		printf("The numbers of happy numbers in both ranges are the same.\n");
	}



}


int computeHappyNumbers(int lower, int upper) {
	int i, happyNumbers = 0;
	//Range iteration

	for (i = lower; i <= upper; i++) {
		if (isHappy(i)) {
			happyNumbers += 1;
		}

	}
	

	return happyNumbers;
}


int isHappy (int i) {
	int sum = i, boolean = 0;

	while (sum != 0 && sum != 1 && sum != 4 && sum != 16 && sum != 20 && sum != 37 && sum != 42 && sum != 58 && sum != 89 && sum != 145) {
		int internal = sum;
		sum = 0;
		while (internal > 0) {
			sum += (internal % 10) * (internal % 10);
			internal /= 10;
		}
	}

	if (sum == 1) {
		boolean = 1;
	}

	return boolean;

}


