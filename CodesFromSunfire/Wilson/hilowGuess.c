//Binary search simplified 

#include <stdio.h>


int main () {

	int high = 200000000, low = 0, guess = 3, myGuess; 

	printf("Enter number to guess: ");
	scanf("%d", &guess);

	while (myGuess != guess) {
		myGuess = (high - low)/2 + low;

		if (myGuess > guess) {
			printf("High guess: %d\n", myGuess);
			high = myGuess;
		}else {
			printf("Low guess: %d\n", myGuess);
			low = myGuess;
		}
	}

	printf("My guess: %d\n", myGuess);

}


