// CS1010 AY2014/5 Semester 1
// PE2 Ex1: ngram.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 101

int main(void) {
	char text[MAX_SIZE], result[3];
	int option, unigramFreq, bigramFreq;
	int length;

	printf("Enter text: ");

	fgets(text,MAX_SIZE,stdin);
	length = strlen(text);
	if (text[length-1] == '\n') text[length-1] = '\0';

	printf("Enter option: ");
	scanf("%d",&option);

	switch(option){
		case 1:
		unigramFreq = mostFrequentUnigram(text,result);
		printf("Most frequent unigram: %s\n", result);
		printf("Frequency: %d\n", unigramFreq);
		break;

		case 2:
		bigramFreq = mostFrequentBigram(text,result);
		printf("Most frequent bigram: %s\n", result);
		printf("Frequency: %d\n", bigramFreq);
	}
	return 0;
}

int mostFrequentUnigram(char word[],char result[]){
	int arr[127] = {0};
	int length = strlen(word);
	int i,largest = 0;

	for (i=0;i<length;i++){
		arr[word[i]]++;	
	}
	for (i=0;i<127;i++){
		//printf("%d",arr[i]);
		if (arr[i] > largest){
			largest = arr[i];
			result[0] = (char)i;
			result[1] = '\0';
		}
	}
	return largest;
}


int mostFrequentBigram(char word[],char result[]){
	int arr[128][128] = {{0}};
	int length = strlen(word);
	int i,j,largest = 0;

	for (i=0;i<length-2;i++){
		arr[word[i]][word[i+1]]++;	
	}
	for (i=0;i<127;i++){
		for (j=0;j<127;j++){
			//printf("%d",arr[i]);
			if (arr[i][j] > largest){
				largest = arr[i][j];
				result[0] = (char)i;
				result[1] = (char)j;
				result[2] = '\0';
			}
		}
	}
	return largest;
}


