// CS1010 AY2017/8 Semester 1
// PE2 Ex1: carnum.c
// Name: Park Junhyuk
// Matriculation number: A0170638B
// plab account-id: plab0460
// Discussion group: c06
// Description: finding out whether the carnum is valid and what type of car it is

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 8

int isValidChecksum(char [], int*);
char genChecksum(char []);

int main(void) {
	char regNo[MAX_LENGTH + 1];
	int type , valid;

	printf("Enter car reg no: ");
	scanf("%s", regNo);


	valid = isValidChecksum(regNo,&type);

	if (type == 1)
		printf ("Car is a taxi\n");
	if (type == 2)
		printf ("Car is a rental car\n");
	if (type == 3)
		printf ("Car is a goods vehicle\n");
	if (type == 4)
		printf ("Car is a private car\n");


	if (valid == 0)
		printf("Invalid registration number\n");
	if (valid == 1)
		printf("Valid registration number\n");


	return 0;
}

//precond: regNo is not empty
//funtion that takes in the reg no string anda returns 1 if the registration number is valid and 0 otherwise
//also gives type its value, using pointers

int isValidChecksum(char regNo[MAX_LENGTH + 1], int *type){
	int dif,len,i,j,x;
	char checksum;

	len = strlen(regNo);
	dif = 8 - len;
	if (dif>0){
//fill the string, insert 0 and push over.
    for (x=7;x>dif+2;x--) {
        regNo[x] = regNo[x-dif];
        regNo[x-dif] = '0';
        }
	}

	if (regNo[0] != 'S')
		return 0;

	if ( regNo[1]== 'A' || regNo[1] == 'E' || regNo[1]== 'I' ||regNo[1]== 'O' ||regNo[1]== 'U')
        return 0;

	if (regNo[1] == 'H')
		*type = 1;
	else if (regNo[1] == 'Z')
		*type = 2;
	else if (regNo[1] == 'G')
		*type = 3;
	else
		*type = 4;

	checksum = genChecksum(regNo);

	if (regNo[7] != checksum)
		return 0;

	return 1;

}

//precond: regNo is not empty
// function that takes in the reg no string and returns the checksum number to isValidChecksum()

char genChecksum(char regNo[MAX_LENGTH + 1]) {

	int remainder ,x1, x2 ,i;
	char letter;
	char alpha [20] = "AZYXUTSRPMLKJHGEDCB";

	x1 = regNo[1] - 64;
	x2 = regNo[2] - 64;

	remainder = (x1*9 + x2*4 + (regNo[3]-48)*5 +  (regNo[4]-48)*4 +  (regNo[5]-48)*3 +  (regNo[6]-48)*2)%19;

	for (i = 0 ; i<19 ; i++){
		if (i  == remainder) {
			letter = alpha[i];
		}
	}


	return letter;
}
