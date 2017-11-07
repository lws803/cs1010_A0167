/**
 * CS1010 AY2017/8 Semester 1 Lab6 Ex1
 * prerequisites.c
 * < This program reads a positive integer indicating the number of modules, and a list of module codes. 
 * The program also reads a particular module code and if that module code exists, it displays all the 
 * prerequisites of that module in the same order as the entry of module codes. >
 * <Tan Tze Guang>
 * <C06>
 */

// Add the preprocessor include statements below

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_MOD  10
#define MAX_LEN  7

int scanModules(char [][MAX_LEN]);
int computePrereq(char [][MAX_LEN], int, char [], char [][MAX_LEN]);
void printPrereq(char [][MAX_LEN], int, char []);

// Note: the main() function is given below. You are NOT to modify it.
int main(void) {
	int 	numModules, numPrereq;
	char	codes[MAX_MOD][MAX_LEN],         // the list of modules codes
			target[MAX_LEN],                 // the target module
			prerequisites[MAX_MOD][MAX_LEN]; // prerequisites of the target module

	numModules = scanModules(codes);

	printf("Choose a module: ");
	scanf("%s", target);

	numPrereq = computePrereq(codes, numModules, target, prerequisites);

	printPrereq(prerequisites, numPrereq, target);

	return 0;
}

// Print the prerequisites
// This function is given. You are NOT to modify it.
void printPrereq(char prerequisites[][MAX_LEN], int numPrereq, char target[]) {
	int i;

	if (numPrereq == -1) {
		printf("No such module %s\n", target);
	}
	else if (numPrereq == 0) {
		printf("No prerequisites for %s\n", target);
	}
	else {
		printf("Prerequisites for %s:", target);
		for (i = 0; i < numPrereq; i++){
			printf(" %s", prerequisites[i]);
		}
		printf("\n");
	}
}

// 	This function will ask the user how many modules he wants and prompts the user to input the module codes into the program.
//	It will then be stored in an array for use in the main program, and also return the number of modules in the list.
int scanModules(char codes[][MAX_LEN]){
	int i,numMods,length;
	char code[MAX_LEN];
	printf("Enter number of modules: ");
	scanf("%d",&numMods);
	
	printf("Enter %d modules:\n",numMods);
	for (i=0;i<numMods;i++){
		scanf("%s",codes[i]);
	}
	return numMods;
}

//	This function computes the number of prerequisites there is for the given module, after checking that the target module exists in the list.
// 	It will also append the module to the prerequisites array if it finds that it indeed is a prerequisite.
//	Precond: nummods > 0;
int computePrereq(char codes[][MAX_LEN], int numMods, char target[], char prerequisites[][MAX_LEN]){
	int prereq = 0;
	int word,i;
	int isPrereq = 0;
	int found = 0;
	
	for (word=0;word<numMods;word++){				// check if the module exists in the array.
		if (!strcmp(codes[word],target)){
			found = 1;
		}
	}
	if (found){
		for (word=0;word<numMods;word++){			// The module exists
			isPrereq = 1;
			if (!strcmp(codes[word],target)){
				continue;
			}
			for (i=0;i<MAX_LEN;i++){
				switch(i){
					case 0: case 1:
					if (codes[word][i] != target[i]) isPrereq = 0; break;

					case 2: 
					if (codes[word][i] >= target[i]) isPrereq = 0; break;
					
					case 3: case 4: case 5:
					if (codes[word][i] > target[i]) isPrereq = 0; break;

				}
			}
			if(isPrereq){							// append the found prerequisite in to the array.
				strcpy(prerequisites[prereq++],codes[word]);
			}
		}
	}
	else
		return -1;
	return prereq;
}