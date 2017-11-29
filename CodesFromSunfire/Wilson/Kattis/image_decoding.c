#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#define MAX 1000

int decode (char [][MAX], int, char [][MAX]);
int read (char [][MAX], int *); 

int main(void)
{

	char pic[MAX][MAX], picOut[MAX][MAX];
	int size = 1;
	while (read(pic, &size)) {

		int status = decode (pic, size, picOut);

		for (int i = 0; i <= size; i++) {
			printf("%s", picOut[i]);
			printf("\n");
		}
		if (!status) {
			printf("Error decoding image");
		}
	}
	
	
	return 0;
}


int decode (char pic[][MAX], int size, char picOut[][MAX]) {
	int i;
	int numLines = 0, flag2 = 0, status = 1; 
	for (i = 1; i <= size; i++) {
		char start;
		int index = 0;
		int flag = 0;
		const char s[2] = " ";
		char *token;
		token = strtok(pic[i], s);
		while( token != NULL ) {
			if (!flag) {
				start = token[0];
				flag = 1;
			}else{
				for (int c = 0; c < atoi(token); c++) {
					picOut[i][index++] = start;
				}
				picOut[i][index] = '\0';
   				// To swap 
				if (start == '#') {
					start = '.';
				}else {
					start = '#';
				}
			}
			token = strtok(NULL, s);
		}
		if (!flag2) {
			numLines = index;
			flag2 = 1;
		}else if (flag2 && numLines != index) {
			status = 0;
		}
	}
	return status;
}


int read (char pic[][MAX], int *size) {
	scanf("%d", size); 
	for(int i = 0; i <= *size; i++) {
		fgets(pic[i], MAX, stdin);
		pic[i][strlen(pic[i])-1] = '\0';
	}
	return *size;
}