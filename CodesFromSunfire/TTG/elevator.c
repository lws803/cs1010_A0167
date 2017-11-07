/**
 * CS1010 AY2017/8 Semester 1 Lab6 Ex3
 * elevator.c
 * <This program simulates a lift going up and down a building while calculating and keeping track of the elevators usage,passengers and floor.
	It will then determine the most used elevator out of all the elevators installed in the building.>
 * <Tan Tze Guang>
 * <C06>
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define CAPACITY 15
#define MAX_LEN 21
#define MAX_ELEVATORS 5

typedef struct { 
	int floor;
	int passengers;
	int usage;
} elevator_t;

void setupElevators(elevator_t [], int);
void readSequences(char [][MAX_LEN], int);
void runElevators(elevator_t [], char [][MAX_LEN], int);
void goToFloor(elevator_t *, int);
void printElevators(elevator_t [], int size);
int mostUsedElevator(elevator_t [], int);

// This function is given. You are NOT to modify it.
int main(void){
	int size;
	elevator_t elevators[MAX_ELEVATORS];
	char sequences[MAX_ELEVATORS][MAX_LEN];
	
	printf("Enter number of elevators: ");
	scanf("%d", &size);
	
	setupElevators(elevators, size);
	readSequences(sequences, size);
	
	runElevators(elevators, sequences, size);
	
	printElevators(elevators, size);
	printf("Most used elevator: %d\n", mostUsedElevator(elevators, size));
	
	return 0;
}

void setupElevators(elevator_t elevators[], int size){
	int i;
	for (i=0;i<size;i++){
		elevator_t new;			// Initialise all values
		new.floor = 0;
		new.passengers = 0;
		new.usage = 0;
		elevators[i] = new;
	}
}	

// Read in the sequences of floors the elevators go to.
// This function is given. You are NOT to modify it.
void readSequences(char sequences[][MAX_LEN], int size){
	int i;
	
	for (i = 0; i<size; i++){
		printf("Enter sequence for elevator %d: ", i+1);
		scanf("%s", sequences[i]);
	}
}

void runElevators(elevator_t elevators[], char sequences[][MAX_LEN], int size){
	int e,f;
	for (e=0;e<size;e++){
		for (f=0;isdigit(sequences[e][f]);f++){
			int newfloor = (int)(sequences[e][f] - '0');
			goToFloor(&elevators[e],newfloor);
		}
	}
}

//	This function will change the values of the number of passengers, usage and floor based on the next floor that the elevator is going to.
//	precond: floor >= 0;
void goToFloor(elevator_t *elevator, int floor){
	int change = floor;
	
	if (floor > elevator->floor){					// Elevator moving up the building
		elevator->floor = floor;
		if ((elevator->passengers + floor) > 15)
			change = 15 - elevator->passengers;
		elevator->passengers += change;	
	}
	else {
		elevator->floor = floor;
		if ((elevator->passengers - floor) < 0)
			change = elevator->passengers;
		elevator->passengers -= change;
		elevator->usage += change;	
	}
}

void printElevators(elevator_t elevators[], int size){
	int i;
	for (i=0;i<size;i++){
		
		printf("Elevator %d:\n",i+1); 
		printf("Floor: %d\n", elevators[i].floor);
		printf("Number of passengers: %d\n", elevators[i].passengers);
		printf("Usage: %d\n", elevators[i].usage);
	}
}

//	This function will do a linear search on the elevator_t array and find the elevator with the most usage.
//	precond: size > 0;
int mostUsedElevator(elevator_t elevators[], int size){
	int i;
	int mostUsed = -1;
	int first = 1;
	int highUsage = -1;
	int noPassengers = 0;
	for (i=0;i<size;i++){
		if (first){
			mostUsed = 0;
			highUsage = elevators[i].usage;
			noPassengers = elevators[i].passengers;
			first = 0;
		}
		else {
			if (highUsage == elevators[i].usage){					// Checks if the usage of the elevators are the same
				if (noPassengers < elevators[i].passengers){		// Compare the number of passengers
					mostUsed = i;
					highUsage = elevators[i].usage;
					noPassengers = elevators[i].passengers;			
				}
				else if (noPassengers == elevators[i].passengers){	
					if (mostUsed > i){								// Compare the elevator number of the number of passengers are the same
						mostUsed = i;
						highUsage = elevators[i].usage;
						noPassengers = elevators[i].passengers;			
					}
				}
			}
			if (highUsage < elevators[i].usage){
				mostUsed = i;
				highUsage = elevators[i].usage;
				noPassengers = elevators[i].passengers;
			}
		}
		
	}
	return mostUsed+1;
}

