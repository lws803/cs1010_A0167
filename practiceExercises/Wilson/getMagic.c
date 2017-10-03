#include <stdio.h>


int get_magic(int inputNum) {
	int i =0;
	int c = 0;
	int sumOfNumbers = 0;
	while (inputNum) {
		switch (i) {
			case 0: case 2: case 4: 
			sumOfNumbers+= inputNum%10;
			break;
		}
		inputNum /= 10;
		i++;
	}
	return sumOfNumbers%10;
}


int main(void)
{
	int inputNum;
	printf("Enter 1st value: ");
	scanf("%d", &inputNum);
	if (inputNum<0 || inputNum>99999) {
		printf("Try again\n");
	}else{
		printf("Magic number = %d\n", get_magic(inputNum));
	}


	printf("Enter 2nd value: ");
	scanf("%d", &inputNum);
	if (inputNum<0 || inputNum>99999) {
		printf("Try again\n");
	}else{
		printf("Magic number = %d\n", get_magic(inputNum));
	}
	return 0;
}
