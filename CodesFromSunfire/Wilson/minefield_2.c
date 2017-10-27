// CS1010 AY2015/6 Semester 2 PE2 Ex1
//
// minefield.c
//
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#define MAX_SIZE 10

int readField(int [][MAX_SIZE]);
void printField(int [][MAX_SIZE], int);
void detonate (int [][MAX_SIZE], int [][MAX_SIZE], int, int *, int *);
void bloom (int [][MAX_SIZE], int, int, int, int);

int main(void) {
	int field[MAX_SIZE][MAX_SIZE], aftermath[MAX_SIZE][MAX_SIZE];
	int size;
	int safe_area = 0, max_dmg = 0;
	
	size = readField(field);
	
	detonate (field, aftermath, size, &safe_area, &max_dmg);

	printf("Aftermath: \n");
	printField(aftermath, size);
		
	printf("Maximum damage: %d\n", max_dmg); // Incomplete
	printf("Number of safe areas: %d\n", safe_area); // Incomplete

	return 0;
}

// Read in a minefield
// Do NOT modify this function!
int readField(int field[][MAX_SIZE]) {
	int i,j, size;
	
	printf("Enter size: \n");
	scanf("%d", &size);
	
	printf("Enter minefield: \n");
	for (i=0; i<size; i++)
		for (j=0; j<size; j++)
			scanf("%d", &field[i][j]);
		
	return size;
}

// Print a minefield
// Do NOT modify this function!
void printField(int field[][MAX_SIZE], int size) {
	int i,j;
	
	for (i=0; i<size; i++){
		for (j=0; j<size; j++)
			printf("%d ", field[i][j]);
		printf("\n");
	}
}

/**
 * Places the damages in aftermath array
 * Precond: None
*/
void bloom (int aftermath[][MAX_SIZE], int size, int x, int y, int power) {
	int i, d;
	// Traverse upwards
	for (i = y - 1; i >= 0 && i > y - power; i--) {	
		aftermath[i][x] += 1;
	}
	// Traverse downwards
	for (i = y + 1; i < size && i < y + power; i++) {
		aftermath[i][x] += 1;
	}
	// Traverse left 
	for (i = x - 1; i >= 0 && i > x - power; i--) {
		aftermath[y][i] += 1;
	}
	// Traverse right
	for (i = x + 1; i < size && i < x + power; i++) {
		aftermath[y][i] += 1;
	}
	aftermath[y][x] += 1;
}

/**
 * Detonates the bombs and calls bloom to place the damages 
 * Precond: None
*/
void detonate (int matrix[][MAX_SIZE],int aftermath[][MAX_SIZE], int size, int *safe_areas, int *dmg) {
	int i, d; 
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			bloom (aftermath, size, d, i, matrix[i][d]);
		}
	}
	int count = 0, max = 0;
	for (i = 0; i < size; i ++) {
		for (d = 0; d < size; d++) {
			if (aftermath[i][d] == 0) {
				count++;
			}else {
				if (aftermath[i][d] > max) {
					max = aftermath[i][d];
				}
			}
		}
	}
	*safe_areas = count;
	*dmg = max;
}
