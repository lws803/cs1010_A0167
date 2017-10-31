// CS1010 AY2013/4 Semester 1
// PE2 Ex1: compatible.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Given two names, strike off matching letters in the names,
// find the number of remaining letters in the names, and 
// determines if the names are compatible.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Name has at most 35 characters
#define MAXLEN 36

// Fill in your function prototypes below

void readName (char []);
int match (char [], char [], int *, int *);

int main(void) {
	char name1[MAXLEN], name2[MAXLEN];
	int remain1,   // number of remaining characters in name1 
	    remain2;   // and name2 after matching

	printf("Enter 2 names below:\n"); // given, do not remove/change this line
	readName(name1);                  // given, do not remove/change this line
	readName(name2);                  // given, do not remove/change this line

	int compatibility = match (name1, name2, &remain1, &remain2); 


	printf("Number of letters remaining in 1st name = %d\n", remain1);
	printf("Number of letters remaining in 2nd name = %d\n", remain2);

	if (compatibility) {
		printf("The names are compatible.\n");
	}else {
		printf("The names are not compatible.\n");
	}
	return 0;
}

// To students: You must write the function's description here. [1 mark]
// readName() function


// To students: You must write the function's description here. [1 mark]
// match() function

void readName (char name[]) {
	fgets (name, 36, stdin);
	int i;
	for (i = 0; name[i] != '\0'; i++) {
		if (name[i] == '\n') {
			name[i] = '\0';
		}
	}
}

int match (char name1[], char name2[], int *name1_len, int *name2_len) {
	int i,d;
	for (i = 0; name1[i] != '\0'; i++) {
		for (d = 0; name2[d] != '\0'; d++) {
			if (toupper(name1[i]) == toupper(name2[d]) && name1[i] != ' ' && name2[d] != ' '){
				name1[i] = ' ';
				name2[d] = ' ';
			}
		}
	}
	char newName1[MAXLEN] = "\0", newName2[MAXLEN] = "\0";
	const char s[2] = " ";
	char *token;
	token = strtok (name1, s);

	while (token != NULL) {
		strcat (newName1, token);
		token = strtok (NULL, s);
	}
	
	token = strtok (name2, s);

	while (token != NULL) {
		strcat (newName2, token);
		token = strtok (NULL, s);
	} 

	// Returns the remaining length 
	*name1_len = strlen (newName1);
	*name2_len = strlen (newName2);
	

	// Check compatibility 
	if (*name1_len%2 == *name2_len%2) {
		return 1;
	}
	return 0;
}
