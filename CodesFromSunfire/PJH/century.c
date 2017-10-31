#include <stdio.h> 

int printCentury(int);
int printOrdinal(int);


int main (void) {
	int year,century,ordinal; 
	printf("Enter year: ");
	scanf("%d" ,&year);
	century = printCentury(year);
	ordinal = printOrdinal(century);
	if (ordinal == 1) 
 	printf("The year %d falls in the %dst century.\n",year,century);
	if (ordinal == 2)
	printf("The year %d falls in the %dnd century.\n",year,century);
	if (ordinal == 3)
	printf("The year %d falls in the %drd century.\n",year,century);
	if (ordinal == 4 )
	printf("The year %d falls in the %dth century.\n",year,century);

	return 0;
	}

int printCentury(int year){
	int i;
	i=year/100;
	return i+1;
}

int printOrdinal(int year) {
	if (year%100 == 11 || year%100 == 12 || year%100 == 13)
		return 4;
	else if (year%10 == 1 )
		return 1;
	else if (year%10 == 2)
		return 2;
	else if (year%10 == 3) 
		return 3;
	else 
		return 4;
}

	
	

