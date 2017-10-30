// CS1010 AY2014/5 Semester 1
// PE2 Ex1: ngram.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 101
#define ASCII 128

int mostFrequentUnigram (char [], char []);
int mostFrequentBigram (char [], char[]);

int main(void) {
	char text[MAX_SIZE], result[3];
	int option, unigramFreq, bigramFreq;


	printf("Enter text: ");
	fgets (text, 100, stdin);
	
	printf("Enter option: ");
	scanf ("%d", &option);

	if (option == 1) {
		unigramFreq = mostFrequentUnigram (text, result);
		printf("Most frequent unigram: %s\n", result);
		printf("Frequency: %d\n", unigramFreq);
	}else {	
		bigramFreq = mostFrequentBigram (text, result);
		printf("Most frequent bigram: %s\n", result);
		printf("Frequency: %d\n", bigramFreq);
	}




	

	return 0;
}

int mostFrequentUnigram (char text[], char result[]) {
	int hash_table [ASCII] = {0}, i;
	for (i = 0; text[i] != '\0'; i++) {
		if (isalpha(text[i])) {
			hash_table[text[i]] += 1;
		}
	}
	int frequency = 0, index = 0; 
	for (i = 0; i < ASCII; i++) {
		if (frequency < hash_table[i]) {
			frequency = hash_table[i];
			index = i;
		}
	}
	result[0] = index;
	result[1] = '\0';
	
	return frequency;
}


int mostFrequentBigram (char text[], char result[]) {
	int i, count = 0, d, hashtable_multi[ASCII][ASCII] = {{0}};
	// Init array 
	for (i = 0; i < ASCII; i++) {
		for (d = 0; d < ASCII; d++) {
			hashtable_multi[i][d] = 0;
		}
	}


	for (i = 0; text[i] != '\0'; i++) {
		char str[2];
		int count2 = 0;
		if (isalnum(text[i]) && isalnum(text[i+1])) {	
			hashtable_multi[text[i]][text[i+1]] += 1;
		}
	}

	for (i = 0; i < ASCII; i++) {
		for (d = 0; d < ASCII; d++) {
			if (hashtable_multi[i][d] > count) {
				result[0] = i;
				result[1] = d;
				count = hashtable_multi[i][d];
			}
		}
	}
	
	result [2] = '\0';

	return count;
}


