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
int calcPossibleRoutes(int , int , int , int [], int [] , int, int);

int main() {
	int distances[MAX_STATIONS];
	int fuels[MAX_STATIONS];
	int totalDist, numStation;
	int possibleRoute;

	readStations(distances, fuels, &totalDist, &numStation); 
	printStations(distances, fuels, totalDist, numStation); 

	possibleRoute = calcPossibleRoutes(100, totalDist, numStation, distances, fuels, 0, 0);
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

// Fill in description of function and brief explanation
int calcPossibleRoutes(int currentFuel, int targetDistance, int numStation, int distances[], int fuels[], int index, int distanceTravelled) {
	int d, routes = 0;	
	if (currentFuel < 0) {
		return 0;
	}


	if (currentFuel + distanceTravelled >= targetDistance) {
		routes++;
	}


	for (d = 1; index + d < numStation; d++) {
		int distance = distances[index + d] - distances[index];
		int fuelLeft = currentFuel - distance + fuels[index + d];
		routes += calcPossibleRoutes (fuelLeft, targetDistance, numStation, distances, fuels, index + d, distances[index]);
	}


	return routes;
	
}

