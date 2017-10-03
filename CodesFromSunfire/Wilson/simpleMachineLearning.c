#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <unistd.h>
#include <limits.h>


int myRand(int low, int high) {
   srand(time(NULL));

   return rand() % (high - low + 1) + low;
}


int guesser(int inputNum) {

	//int highGuess = INT_MAX/2;
	//int lowGuess = INT_MIN/2;
	int highGuess, lowGuess;
	int myGuess;
	int correctGuess;
	int repeat, numberOfRepeats =0; 

	printf("Input lowest guess: ");
	scanf("%d", &lowGuess);
	printf("Input highest guess: ");
	scanf("%d", &highGuess);

	while (inputNum != correctGuess) {
		myGuess = myRand(lowGuess, highGuess);

		if (myGuess<inputNum && myGuess>lowGuess) {
			repeat = lowGuess = myGuess +1;

            printf("My guess is: %d higher\n", myGuess);
		}else if (myGuess>inputNum && myGuess<highGuess) {
			repeat = highGuess = myGuess -1;

            printf("My guess is: %d lower\n", myGuess);
		}else if (inputNum == myGuess) {
			correctGuess = myGuess;
		}else if (myGuess == repeat) {
			//To make sure that the machine doesn't stall...
			printf("High guess: %d Low guess: %d\n", highGuess, lowGuess);
			if (numberOfRepeats > 3) {
				printf("Resetting...\n");
				numberOfRepeats =0;
				highGuess +=1;
				lowGuess -=1;
				//sleep(2);
			}else{
				printf("Repeated guess!\n");
				numberOfRepeats++;
				sleep(1);
			}

		}else{
			printf("Struggling...\n");
			numberOfRepeats =0;
			highGuess +=1;
			lowGuess -=1;
			sleep(2);
		}
		//sleep(1);
	}

	return correctGuess;
}



int main(int argc, char const *argv[])
{
	int inputNumber;
	printf("Enter a number to guess: ");
	scanf("%d", &inputNumber);
	printf("Success!: %d\n", guesser(inputNumber));
	return 0;
}
