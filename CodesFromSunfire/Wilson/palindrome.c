// palindrome.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define MAXLEN 20

int isPalindrome(char []);

int main(void) {
	char word[MAXLEN+1];

	printf("Enter word: ");
	scanf("%s", word);

	if (isPalindrome(word))
		printf("%s is a palindrome.\n", word);
	else
		printf("%s is not a palindrome.\n", word);

	return 0;
}

// Return 1 if str is a palindrome, otherwise return 0.
int isPalindrome(char str[]) {
	int i, d;
	int length = strlen(str);
	// Used to compare front and back concurrently with indexes i and d. 
	for (i = 0, d = length - 1; i < length/2; i++, d--) {
		if (toupper(str[i]) != toupper(str[d])) {
			return 0;
		}
	}

	return 1;
}
