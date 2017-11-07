/*CS1010 AY2017/8 Semester 1 Lab6 Ex1
 * prerequisites.c
 * <program that gives you the prerequisite of the module you type in>
 * <ParkJunhyuk>
 * <C06>
 */


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_MOD  10
#define MAX_LEN  7

int scanModules(char [][MAX_LEN]);
int computePrereq(char [][MAX_LEN], int, char [], char [][MAX_LEN]);
void printPrereq(char [][MAX_LEN], int, char []);


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
//function that scans the modules input from the user
//precond: number > 0
int scanModules(char arr[][MAX_LEN]){
	int number,i;
	printf("Enter number of modules: ");
	scanf("%d" ,&number);
	printf("Enter %d modules:\n", number);
	for (i=0; i<number; i++){
		scanf("%s", arr[i]);
	}
	return number;
}
//it is a function that returns the number of prerequisite or returns -1 when the the target module is not inside the list of modules
//precond: input is not empty , number > 0

int computePrereq(char input[][MAX_LEN], int number, char target [], char pre[][MAX_LEN]){

	int i,z=0, a,count=0,selection=1;

	for (i=0; i<number; i++){
		if((strcmp(input[i],target))== 0)
			selection = 0;
    }

	if (!selection) {

        for(i=0; i<number; i++){
            count =0;
			if ((input[i][0] == target[0]) && (input[i][1] == target[1])){
				if (input[i][2] < target[2]){
					for(a=3; a<6;a++){
						if (input[i][a] <= target[a])
							count++;
                    }
					if (count == 3){
                        strcpy(pre[z],input[i]);
						z++;
                    }
                }
            }
        }
    }
	else
		return -1;

	if (z == 0){
		return 0;
	}
	else if (z > 0){
		return z;
    }

}




