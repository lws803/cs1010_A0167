// CS1010 AY2016/7 Semester 1
// PE2 Ex1: spy.c
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Description:

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_SIZE 26
#define MAX_LENGTH 80

void createAlphabet(char [], char []);
void encrypt(char [], char[], char []);
void simplify(char []);

// Do NOT change the main function!
int main(void) {
	char keyword[MAX_LENGTH+1], alphabet[ALPHABET_SIZE+1], message[MAX_LENGTH+1], result[MAX_LENGTH+1];
	
    printf("Enter keyword: ");
    scanf("%s", keyword);
	
	printf("Enter message: ");
    scanf("%s", message);

	simplify(keyword);
	createAlphabet(keyword, alphabet);	
	encrypt(message, alphabet, result);
	
	printf("Encrypted message: %s\n", result);

	return 0;
}

void simplify(char keyword[]){
}

void createAlphabet(char keyword[], char alphabet[]){
}

void encrypt(char message[], char alphabet[], char result[]){
}