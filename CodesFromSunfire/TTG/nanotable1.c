/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex1
 * nanotable1.c
 * This program will initialise a list for the purpose of storing student ID and score and ranks them appropriately.
 * It will allow input and output of data
 * Tan Tze Guang
 * C06
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define MAX_COMMAND_LENGTH 100
#define MAX_STUDENTS 100
#define SCORE_ROW 2

/* Function prototypes */
void print_help();
int sumArr(int arr[][2],int);
int aveArr(int arr[][2],int);
void sortArr(int arr[][2],int);

int main(void){
	
	// The string for input command, do not modify...
	char input[MAX_COMMAND_LENGTH];
	int lastID=0; 	// Keeps track of the last ID and also validates the number of IDs input into the array.
	int sum,ave; 
	int scores[MAX_STUDENTS][SCORE_ROW];

	// print welcome information
	printf("Welcome to Nanotable!\n");
	printf("Type \"help\" for more information...\n");
	while (1) {
		printf("Waiting for command...\n");
		scanf("%s", input);
			
		if (strcmp(input,"help") == 0) {
			print_help();
		} 
		
		else if (strcmp(input,"exit") == 0){
		    printf("See you!\n");
		    break;
		} 
		
		else if (strcmp(input,"sum") == 0) {
			if (lastID==0)	/* Need to determine whether the table is empty...*/ {
				printf("The table is empty\n");
			} 
			else {
				sum = sumArr(scores,lastID);
				printf("The sum of score is %d\n", sum);
			}
		} 
		
		else if (strcmp(input,"ave") == 0) {
			if (lastID==0) {
				printf("The table is empty\n");
			} 
			else {
				ave = aveArr(scores,lastID);
				printf("The average of score is %d\n", ave);
			}
		}
		
		else if (strcmp(input,"insert") == 0) {
			printf("Please input the student's ID...\n");
			scanf("%d",&scores[lastID][0]);
			printf("Please input the student's score...\n");
			scanf("%d",&scores[lastID][1]);
			
			lastID++;
		} 
		
		else if (strcmp(input,"init") == 0) {
			lastID = 0;
			printf("Initializing table...\n");
		} 
		
		else if (strcmp(input,"rank") == 0) {
			if (lastID==0) {        
				printf("The table is empty\n");
			} 
			else {
				sortArr(scores,lastID);
				int ranking;
				do {
					printf("Please input the rank (1 - %d)...\n",lastID);
					scanf("%d",&ranking);
					if (ranking>lastID || ranking < 1){
						printf("Invalid rank: %d\n",ranking);
					}
				} while (ranking>lastID || ranking < 1);
				
				printf("ID: %d, Score: %d\n",scores[ranking-1][0],scores[ranking-1][1]);
			}
		} 
		
		else {
		  printf("No such command: %s, please input command again!\n", input);
		}
	}
	return 0;
}

// This function prints the help information
void print_help() {
	printf("Commands available: insert, init, sum, ave, rank, help, exit\n");
}
// This function sums all the scores in the array and returns the sum to the function that calls it.
//Precond: num > 0
int sumArr(int arr[][2],int num){
	int sum = 0;
	int i;
	for (i=0;i<num;i++){
		sum += arr[i][1];
	}
	return sum;
}

// This function sums all the scores in the array and returns the average.
//Precond: num > 0
int aveArr(int arr[][2],int num){
	int sum = sumArr(arr,num); // using my own function to simplify code
	int ave;
	double temp = sum/(double)num;
	int det = (int)(temp*10)%10; // to get the remainder of the ave to decide whether to round up or down.
	if (det>=5){
		ave = ceil(temp);
	}
	else{
		ave = floor(temp);
	}
	return (int)ave;
}

// This function sorts the array of scores based on the score.
// If there are same scores, it will sort by ID.
//Precond: num > 0
void sortArr(int arr[][2],int num){
	int i,j,temp,temp2;  
    for (i = 0; i < num; i++) {  
		for (j = 0; j < (num - i - 1); j++) {  
			if (arr[j][1] > arr[j+1][1]) {
				temp = arr[j][1];
				temp2 = arr[j][0];
				arr[j][1] = arr[j+1][1];
				arr[j][0] = arr[j+1][0];
				arr[j+1][1] = temp;
				arr[j+1][0] = temp2;
	        }        
			else if((arr[j][1] == arr[j+1][1]) && arr[j][0] > arr[j+1][0]){
				temp = arr[j][1];
				temp2 = arr[j][0];
				arr[j][1] = arr[j+1][1];
				arr[j][0] = arr[j+1][0];
				arr[j+1][1] = temp;
				arr[j+1][0] = temp2;
			}
        }  
	}
}