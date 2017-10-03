#include <stdio.h>

// CS1010 AY2011/2 Semester 1 
// PE1 Ex1: century.c
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Description:

void printOrdinal(int);

int main(void)
{
	int year; // user's input

	printf("Enter year: ");
	scanf("%d", &year);



	printf("The year %d falls in the %d", year, year/100 + 1 );
	printOrdinal(year);

	return 0;
}


void printOrdinal (int year) {
	 int century = year/100 + 1;

	 int suffix = century%100;

	 if (suffix < 14 && suffix > 10) {
	 	printf("th");
	 }else{
	 	switch(century%10){
	 		case 1: 
			 printf("st");
			 break;

			 case 2: 
			 printf("nd");
			 break;

			 case 3: 
			 printf("rd");
			 break;

			 default:
			 printf("th");
	 	}
	 }
	 printf(" century.\n");

}