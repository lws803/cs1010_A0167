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
	//printf("%s\n",keyword);
	createAlphabet(keyword, alphabet);
	printf("%s\n",alphabet);
	encrypt(message, alphabet, result);

	printf("Encrypted message: %s\n", result);

	return 0;
}

void simplify(char keyword[]){
    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
    char temp[MAX_LENGTH+1] = {NULL};
    int i,j,counter = 0;
    int len = strlen(keyword);
    for (i=0;i<len;i++){
        for (j=0;j<26;j++){
            if (keyword[i] == alphabet[j]){
                alphabet[j] = '0';
                temp[counter++] = keyword[i];
            }
        }
    }
    strcpy(keyword,temp);
}

void createAlphabet(char keyword[], char alphabet[]){
    char i;
    int j;
    int inalpha = 0;
    int counter = strlen(keyword);
    strncpy(alphabet,keyword,counter);

    for (i='a';i<='z';i++){
        inalpha = 0;
        for (j=0;j<strlen(keyword);j++){
            if (i==keyword[j])
                inalpha = 1;
        }
        if (!inalpha)
            alphabet[counter++] = i;
    }
    alphabet[counter] = '\0';
}

void encrypt(char message[], char alphabet[], char result[]){
    int i,j;
    int len=strlen(message);
    int counter = 0;
    int temp;

    for (i=0;i<len;i++){
        if (isalpha(message[i]) && isupper(message[i])){
            temp = (int)tolower(message[i]) - (int)'a';
            result[counter++] = toupper(alphabet[temp]);
        }
        else if (isalpha(message[i]) && islower(message[i])){
            temp = (int)message[i] - (int)'a';
            result[counter++] = tolower(alphabet[temp]);
        }
        else
            result[counter++] = message[i];
    }
    result[counter] = '\0';
}
