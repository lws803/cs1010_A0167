#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 21

int isPalindrome(char[]);

int main(void){
	char str[MAX];

	printf("Enter input: ");
	fgets(str,21,stdin);
	if(isPalindrome(str))
		printf("This is a palindrome.\n");
	else
		printf("THis is not a palindrome.\n");
}

int isPalindrome(char str[]){
	int length = strlen(str);
	int i,j,isPalin = 1;
	for (i=0,j=length-2;i<j && isPalin;i++,j--){
		if (toupper(str[i]) != toupper(str[j]))
			isPalin = 0;
	}
	if (isPalin)
		return 1;
	return 0;
}
