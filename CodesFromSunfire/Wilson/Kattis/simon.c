#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_LENGTH 100
#define N 1000

int read_instructions (char instructions[][MAX_LENGTH+1]);
void print_instructions (char instructions[][MAX_LENGTH+1], int n);

int main(int argc, char const *argv[])
{
	char instructions[N][MAX_LENGTH+1];
	int size;
	size = read_instructions (instructions);
	print_instructions(instructions, size);


	return 0;
}


int read_instructions (char instructions[][MAX_LENGTH+1]) {
	int size, i;
	scanf("%d", &size);
	for (i = 0; i < size + 1; i++) {
		fgets(instructions[i], MAX_LENGTH, stdin);
		instructions[i][strlen(instructions[i])-1] = '\0';
	}
	return size + 1; // because fgets took the new line as instructions[0]
}

void print_instructions (char instructions[][MAX_LENGTH+1], int n) {
	int i;
	const char s[2] = " ";

	for (i = 1; i < n; i++) {
		char *token;
    	token = strtok(instructions[i], s);
   		int count = 0;
   		char str[MAX_LENGTH] = "\0";
   		char step[MAX_LENGTH+1] = "\0";
   		int flag = 1;
   		while( token != NULL ) {
   			if (count < 2) {
   				strcat(str, token);
   				strcat(str, " ");
   			}
   			count++;

   			if (count == 2 && strcmp(str, "Simon says ") != 0) {
   				flag = 0;
   				break;
   			}else if (count > 2){
   				strcat(step, token);
   				strcat(step, " ");
   			}
   			token = strtok(NULL, s);
   		}
   		if (flag) {
   			step[strlen(step) - 1] = '\0';
   			printf("%s\n", step);
   		}
	}
}