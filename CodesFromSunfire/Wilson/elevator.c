/**
 * CS1010 AY2017/8 Semester 1 Lab6 Ex3
 * elevator.c
 * <Type a description of the program here>
 * <Type your name here>
 * <Type your discussion group here>
 */

#include <stdio.h>
#include <string.h>
#define CAPACITY 15
#define MAX_LEN 21
#define MAX_ELEVATORS 5

typedef struct { 
	int numExits;
	int current_passengers;
	int current_floor;	
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
	printf("Most used elevator: %d\n", mostUsedElevator(elevators, size) + 1);
	
	return 0;
}

void setupElevators(elevator_t elevators[], int size){
	int i;
	for (i = 0; i < size; i++) {
		elevators[i].numExits = 0;
		elevators[i].current_passengers = 0;
		elevators[i].current_floor = 1;
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
	int i, d;
	for (i = 0; i < size; i++) {
		for (d = 0; sequences[i][d] != '\0'; d++) {
			int floor = sequences[i][d] - '0';
			// TODO: Implement the goto floor function and test
			goToFloor(&elevators[i], floor);
		}
	}	
}

void goToFloor(elevator_t *elevator, int floor){
	if (elevator->current_floor > floor) {
		// Elevator going down 
		elevator->current_floor = floor;
		elevator->current_passengers -= floor;
		elevator->numExits += floor;

		if (elevator->current_passengers < floor) {
			elevator->numExits += elevator->current_passengers;
			elevator->current_passengers = 0;
		}
	}
	if (elevator->current_floor < floor) {
		// Elevator going up 
		elevator->current_floor = floor;
		elevator->current_passengers += floor;

		if (elevator->current_passengers > 15) {
			elevator->current_passengers = 15;
		}
	}
}

void printElevators(elevator_t elevators[], int size){
	int i;
	for (i = 0; i < size; i++) {
		printf("Elevator : %d\n", i+1); 
		printf("Floor: %d\n", elevators[i].current_floor);
		printf("Number of passengers: %d\n", elevators[i].current_passengers);
		printf("Usage: %d\n", elevators[i].numExits);
	}
}

int mostUsedElevator(elevator_t elevators[], int size){
	int i, mostUsed = elevators[0].numExits, mostUsedElevator = 0;
	for (i = 0; i < size; i++) {
		if (mostUsed < elevators[i].numExits) {
			mostUsedElevator = i;
			mostUsed = elevators[i].numExits;
		}
	}
	return mostUsedElevator;
}

