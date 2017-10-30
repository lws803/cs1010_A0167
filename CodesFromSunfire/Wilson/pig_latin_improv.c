// pig_latin.c
#include <stdio.h>
#define MAX 80
#include <string.h>
#include <ctype.h>

void convert(char [], char []);
int checkVowel (char );

int main(void) {
	char sentence[MAX + 1], target[MAX + 1] = "\0";
	
	printf("Enter sentence: ");
	fgets (sentence, 81, stdin);


	convert (sentence, target);


	printf("\nConverted: %s\n", target);

	return 0;
}

// Convert src into pig-latin in dest
void convert(char src[], char dest[]) {
	const char s[2] = " ";
	char *token;
	token = strtok(src, s);

	while (token != NULL) {
		if (checkVowel(token[0])) {
			// Append way at the back
			char word[MAX] = "\0";
			strcat(word, token);
			strcat(word, "way ");
			strcat (dest, word);
		}else if (isalnum(token[0])) {
			char word[MAX] = "\0";
			int i, d;
			for (i = 0, d = 1; isalnum(token[d]); i++, d++) {
				word[i] = token[d]; 
			}
			word[i] = token[0];
			word[++i] = '\0';
			strcat (word, "ay ");
			strcat (dest, word);
		}
		token = strtok (NULL, s);
	}
}

int checkVowel (char target) {
	switch (target) {
		case 'a':
		return 1;
		case 'e':
		return 1;
		case 'i':
		return 1;
		case 'o':
		return 1;
		case 'u':
		return 1;
	}
	return 0;
}
