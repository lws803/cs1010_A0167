/**
 * CS1010 AY2017/8 Semester 1 Lab6 Ex2
 * driver.c
 * This program calculate the possible routes given an array of gas stations available within distance.
 * <Type your name here>
 * <Type your discussion group here>
 */

#include <stdio.h>
#define MAX_STATIONS 20

void readStations(int [], int [], int *, int *);
void printStations(int [], int [], int, int);
int calcPossibleRoutes(int [], int [], int , int , int , int); 
int header(int [], int [], int , int ); 

int main() {
	int distances[MAX_STATIONS];
	int fuels[MAX_STATIONS];
	int totalDist, numStation;
	int possibleRoute;

	readStations(distances, fuels, &totalDist, &numStation); 
	printStations(distances, fuels, totalDist, numStation); 

	possibleRoute = header(distances, fuels, totalDist, numStation);
	printf("Possible number of routes = %d\n", possibleRoute);

	return 0;
}

// Read the gas stations' distances and available fuel 
// and return the total distance and number of gas stations read.
// Note: Do not change this function
void readStations(int distances[], int fuels[], int *totalDistPtr, int *numStationPtr) {
	int i;

	printf("Enter total distance: ");
	scanf("%d", totalDistPtr);

	printf("Enter number of gas stations: ");
	scanf("%d", numStationPtr);

	printf("Enter distance and amount of fuel for each gas station:\n");
	// gasStation Array will store in such way [dist0, fuel0, dist1, fuel1, dist2, fuel2, ...]
	for (i = 0; i < *numStationPtr; i++) {
		scanf("%d %d", &distances[i], &fuels[i]);
	}

}

// Print total distance and gas stations' distances and fuel
// Note: Do not change this function
void printStations(int distances[], int fuels[], int totalDist, int numStation) {
	int i;

	printf("Total distance = %d\n", totalDist);
	printf("Number of gas stations = %d\n", numStation);
	printf("Gas stations' distances: ");
	for (i = 0; i < numStation; i++) {
		printf("%4d ", distances[i]);
	}
	printf("\n");
	printf("Gas stations' fuel amt : ");
	for (i = 0; i < numStation; i++) {
		printf("%4d ", fuels[i]);
	}
	printf("\n");
}

int header(int distances[], int fuels[], int totalDist, int numStations) {
	int i, count = 0;
	int initialFuel = 100;
	for (i = 0; i < numStations; i++) {
		// Manipulates the index fed into calc possible routes 
		// Note that total dist will be affected and fuelLeft will be affected too
		count += calcPossibleRoutes (distances, fuels, totalDist - distances[i], numStations, initialFuel - distances[i], i);
	}

	// Handler to handle for when there are zero stations
	if (numStations == 0) {
		if (totalDist - initialFuel <= 0) {
			count++;
		}
	}

	return count;
}

int calcPossibleRoutes(int distances[], int fuels[], int totalDist, int numStations, int fuelLeft, int index) {
	int count = 0;
	// All the if statements are ranked according to priority, which is essential when dealing with recursion questions. 
	if (fuelLeft < 0) {
		return 0; // Returns 0 cause the route is not possible anyway, count on the previous call in the stack will just add with zero
	}

	int currentFuel = fuelLeft + fuels[index]; // top up 
	if (totalDist <= 0) {
		return 1; // Returns one immediately to prevent this route from going further 
	}

	if (totalDist - currentFuel <= 0) {
		count++; // For when it realises that it could also just travel all the way without meeting a station 
		// This wont be double counted, no worries 
	}

	int i;
	// Try out all possible stations starting from the initial index 
	for (i = index+1; i < numStations; i++) {
		int distanceTravelled = distances[i] - distances[index]; // Reference the previous distance and find out how much more travelled
		count += calcPossibleRoutes(distances, fuels, totalDist - distanceTravelled, numStations, currentFuel - distanceTravelled, i);
		// count += is very important to consider all possible routes 
	}
	
	return count;
}

