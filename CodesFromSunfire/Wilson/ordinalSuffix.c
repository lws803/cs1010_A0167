// Suffix.c
// This program reads a positive integer and 
// prints the value with the correct ordinal suffix.
#include <stdio.h>

void printSuffix(int);

int main(void) {    
	int value;

	printf("Enter value: ");
	scanf("%d", &value);

	printf("%d", value);
	printSuffix(value);

	return 0;
}

// This function prints the corresponding 
// ordinal suffix for value.
void printSuffix(int value) {

	int suffix = value%100;

	if (suffix < 20 && suffix > 10) {
		printf("th\n");

	}else {
		switch (value%10) {
			case 1: 
			printf("st\n");
			break;
			case 2: 
			printf("nd\n");
			break;
			case 3: 
			printf("rd\n");
			break;
			default: 
			printf("th\n");
		}
	}

}
