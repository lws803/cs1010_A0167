//NRIC check code 



#include <stdio.h>


char generateCode(int nric){
	int weights [7] = {2, 3, 4, 5, 6, 7, 2};
	char characters[11] = "ABCDEFGHIZJ";

	int totalSum = 0;
	int c = 0;
	while(nric)
	{
    	//printf("%d\n", nric % 10);
    	totalSum += ((nric%10)*weights[c]);
    	c++;
    	nric /= 10;
	}

	int remainder = totalSum%11;
	int remainderMinus = 11 - remainder;
	char returnCharacter;

	int i;
	for (i = 0; i < 11; i++)
	{
		if (i+1 == remainderMinus) {
			returnCharacter = characters[i];
		}
	}

	return returnCharacter;
}


int main()
{

	int nric;
	printf("Enter 7-digit NRIC number: ");
	scanf("%d", &nric);

	printf("Check code is %c\n", generateCode(nric));
	
	return 0;
}