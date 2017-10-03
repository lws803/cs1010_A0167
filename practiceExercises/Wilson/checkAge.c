// validate.c
// To read age from user, until the 
// age entered is valid (1 - 100).
#include <stdio.h>

int checkAge(int);

int main(void) {    
	int age, counter = 0;


	do {
		counter++;
		printf("Enter age: ");
		scanf("%d", &age);
		if (checkAge(age)){
			printf("Your age is %d.\n", age);
			printf("Number of attempts = %d\n", counter);
		}
	} while(checkAge(age) == 0);

	return 0;
}


int checkAge (int age) {
	int boolean = 0;
	if (age <= 100 && age >= 1) {
		boolean = 1;
	}

	return boolean;
}