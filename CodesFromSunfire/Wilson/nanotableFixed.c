/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex1
 * nanotable1.c
 * <Type your program description here>
 * <Ler Wei Sheng>
 * <C04>
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define MAX_COMMAND_LENGTH 100


/* Function prototypes */
void print_help();
int insertTable (int[][2], int);
int sumArray (int[][2], int);
int ave(int, int);
void rank(int[][2], int);
int insert (int [][2], int, int, int, int);

int main (void) {

	// The string for input command, do not modify...
	char input[MAX_COMMAND_LENGTH];

	int arr[MAX_COMMAND_LENGTH][2] = {{0,0}}, count = 0, i;

  	// TO BE IMPLEMENTED
  	// How to represent the table and other information...

	// print welcome information
  	printf("Welcome to Nanotable!\n");
  	printf("Type \"help\" for more information...\n");

  	while (TRUE) {
    	printf("Waiting for command...\n");
    	scanf("%s", input);
		
    if (strcmp(input,"help") == 0) {
  		print_help();
    } else if (strcmp(input,"exit") == 0){
      	printf("See you!\n");
      	break;
    } 
    else if (strcmp(input,"sum") == 0) {
    	
      	if (count == 0) {
			printf("The table is empty\n");

      	} else {
        	printf("The sum of score is %d\n", sumArray(arr, count));
      	}


    } else if (strcmp(input,"ave") == 0) {
      	if (count == 0) {
			printf("The table is empty\n");
      	} else {

      		printf("The average of score is %d\n", ave(sumArray(arr, count), count));
      	}
    } 
    else if (strcmp(input,"insert") == 0) {
	    count = insertTable(arr, count);

    } 
    else if (strcmp(input,"init") == 0) {
    	for (i = 0; i <= count; i++) {
    		arr[i][0] = 0;
    		arr[i][1] = 0;
    	}

    	count = 0 ;
    	printf ("Initializing table...\n");
    } 
    else if (strcmp(input,"rank") == 0) {
    	if (count == 0) {        
			printf("The table is empty\n");
      	} 
      	else {
      		rank(arr, count);
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

/*
Inserts new entries 
Precond: no negative scores plox 
*/

int insertTable (int arr[][2], int size) {

  int id, score, i = 0;

	printf("Please input the student's ID...\n");
  scanf("%d", &id);
  printf("Please input the student's score...\n");
  scanf("%d", &score);


  for (i = 0; i < size; i++){
      if (arr[i][1] > score) {
        size = insert(arr, id, score, i, size);
        break;
      } 
    }
  if (i == size) {
    arr[size][0] = id;
    arr[size][1] = score;
    size++;
  }

  return size;
}


/*
Obtains the sum of scores
Precond: none
*/

int sumArray (int arr[][2], int size) {
	int sum = 0, i;
	for (i = 0; i < size; i++) {
        sum += arr[i][1];
    }
    return sum;
}

/*
Obtains the average of the sum of scores
Precond: none
*/

int ave(int sum, int size) {
  float sum_f = sum;
  int ave;

  if ((sum_f/size) - (sum/size) >= 0.5) {
    ave = sum/size + 1;
  }else{
    ave = sum/size;
  }

	return ave;
}

/* 
Sort and print the rank
Precond: none	
*/
void rank(int arr[][2], int size) {
	int rank;

	do {
		printf("Please input the rank (1 - %d)...\n", size);
		scanf("%d", &rank);

		if (rank > size) {
			printf("Invalid rank: %d\n", rank);
		}
	}while (rank > size || rank == 0);
		//printf("ID: %d, Score: %d\n", sortedArray[rank-1][0], sortedArray[rank-1][1]);
    printf("ID: %d, Score: %d\n", arr[rank-1][0], arr[rank-1][1]);

}

// This function inserts an element into the array and shifts everything right of it forward.

int insert (int arr[][2], int element, int element2, int atIndex, int size) {
    int i;
    for (i = size-1; i >= atIndex; i--) {
        arr[i+1][0] = arr[i][0];
        arr[i+1][1] = arr[i][1];
    }
    arr[atIndex][0] = element;
    arr[atIndex][1] = element2;

    size++;
    return size;
}
