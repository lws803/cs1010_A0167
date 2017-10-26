// pig_latin.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 81


void convert(char [], char []);
int vowel_check (char);
void dump_words (char []);

int main(void) {
	char message[MAX+1], converted[MAX+1];
	printf("Enter sentence: ");
	fgets (message, MAX, stdin);

	convert (message, converted);
	// Converter here
	printf("\nConverted: %s\n", converted);

	return 0;
}

// Convert src into pig-latin in dest
void convert(char src[], char dest[]) {
	// All lower case 
	const char s[2] = " ";
	char *token;
	char word[MAX+1];
	token  = strtok (src, s);
	
	dump_words (dest);
	dump_words (word);

	while (token != NULL) {
		int count = 0, i;
		if (vowel_check(token[0]) == 0) {
			for (i = 1; token[i] != '\0' && token[i] != '\n'; i++) {
				word[count++] = token[i];
			}
			word[count] = token[0];
			strcat (word, "ay ");
			strcat (dest, word);
			dump_words (word);
		}else {
			for (i = 0; token[i] != '\0' && token[i] != '\n'; i++) {
				word[count++] = token[i];
			}
			strcat(word, "way ");
			strcat (dest, word);
		}
		dump_words (word);
		token = strtok (NULL, s);
	}
}

// Inits the array into all null characters 
void dump_words (char words[]) {
	int i;
	for (i = 0; i < (MAX + 1); i++) {
		words[i] = '\0';
	}
}

int vowel_check (char target) {
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
		case ' ':
		return -1;
		case '\0':
		return -1;
	}
	return 0;
}
