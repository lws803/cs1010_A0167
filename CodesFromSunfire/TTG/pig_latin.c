// pig_latin.c
#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 80

void convert(char [], char []);
int isVowel(char);

int main(void) {
    int length;
	char sentence[MAX_LENGTH+1] = {NULL};
	char converted[MAX_LENGTH+1] = {NULL};

	printf("Enter sentence: ");
	fgets(sentence,MAX_LENGTH+1,stdin);
	length = strlen(sentence);
	if (sentence[length-1] == '\n') sentence[length-1] = '\0';

	convert(sentence,converted);

	printf("\nConverted: %s\n", converted);

	return 0;
}

// Convert src into pig-latin in dest
void convert(char src[], char dest[]) {
	//break into individual words
	char s[2] = " ";
	char *token;
	int counter=0;
	int i;
	token = strtok(src,s);

	while (token != NULL){
        //printf("%d",counter);
		// Process each word.
		char temp = token[0];
		int length;
		if (isVowel(temp)){
            //printf("%c",temp);
			length = strlen(token);
			for (i=0;i<length;i++){
				dest[counter++] = token[i];
			}
			dest[counter++] = 'w';
			dest[counter++] = 'a';
			dest[counter++] = 'y';
		}
		else{
		    //printf("%c",temp);
			length = strlen(token);
			for (i=1;i<length;i++){
				dest[counter++] = token[i];
			}
			dest[counter++] = token[0];
			dest[counter++] = 'a';
			dest[counter++] = 'y';
		}
		dest[counter++] = ' ';
		token = strtok(NULL,s);
	}
}

int isVowel(char item){
	char strlist[5] = {'a','e','i','o','u'};
	int i;
	for (i=0;i<5;i++){
        //printf("%d",i);
		if (strlist[i] == item)
			return 1;
	}
	return 0;
}
