// countWords.c
#include <stdio.h>
#include <ctype.h>
#define LENGTH 1000

int word_count(char []);

int main(void) {
	char sentence[LENGTH];

	printf("Enter a sentence with at most %d characters:\n", LENGTH);
	gets(sentence);
	printf("Sentence = %s\n", sentence); 
	
	printf("Word count = %d\n", word_count(sentence));

	return 0;
}

// Count the number of words in str
int word_count(char str[]) {
	int i, count = 0, word_count = 0;
	for (i = 0; str[i] != '\0'; i++) {
		if (isalpha(str[i])) {
			// Detection of normal words
			count = 1;
		}
		if ((count == 1 && str[i] == ' ')){
			// Last word can be tricky to recognise.
			// Detection of white spaces and any other weird characters or when the sentence ends. 
			word_count++;
			count = 0;
		}
	}

	if (count == 1) {
		word_count++;
	}


	return word_count;
}
