/**
 * CS1010 AY2017/8 Semester 1 Lab6 Ex1
 * prerequisites.c
 * <This is NUSMODS?>
 * <LER WEI SHENG>
 * <C04>
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_MOD  10
#define MAX_LEN  7

int scanModules(char [][MAX_LEN]);
int computePrereq(char [][MAX_LEN], int, char [], char [][MAX_LEN]);
void printPrereq(char [][MAX_LEN], int, char []);
int check_digits (char [], char []);

// Note: the main() function is given below. You are NOT to modify it.
int main(void) {
	int numModules, numPrereq;
	char codes[MAX_MOD][MAX_LEN],         // the list of modules codes
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

/**
 * Precond: Modules keyed in must be in correct format
 * This function allows user to key in all respective modules. 
*/

int scanModules (char codes[][MAX_LEN]) {
	int size; 
	printf("Enter number of modules:");
	scanf ("%d", &size);
	int i;
	printf("Enter %d modules: \n", size);
	for ( i = 0; i < size; i++) {
		scanf("%s", codes[i]);
	}
	return size;
}

/**
 * Precond: None
 * This function finds out if there are any perequisites based on the conditions given. 
*/

int computePrereq(char codes[][MAX_LEN], int size, char target[], char prerequisites[][MAX_LEN]) {
	// First two characters same, first digit of module A is less than B, the other three digits are not greater
	char digits[4];
	int i, count = 0;
	for (i = 0; i < size; i++) {
		// Check for same character
		if (codes[i][0] == target[0] && codes[i][1] == target[1]) {
			// Check if first digit of module A is lesser than B
			if ((codes[i][2] - '0') < (target[2] - '0')) {
				if (check_digits(codes[i], target)) {
					strcpy (prerequisites[count++], codes[i]);
				}
			}
		}
	}
	int check = 0;
	for (i = 0; i < size; i++) {
		if (strcmp(codes[i], target) == 0) {
			check++;
		}
	}
	if (check < 1) {
		return -1;
	}
	return count;
}

/**
 * Precond: none
 * This function checks the remaining digits and returns if they are all lesser than target. 
*/

int check_digits (char target[], char source[]) {
	int i;
	for (i = 2; i <= 5; i++) {
		if (target[i] > source[i]) {
			return 0;
		}
	}
	return 1;
}