// CS1010 AY2015/6 Semester 1
// PE2 Ex1: panel.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#define GRID_SIZE 5
#define MAX_LENGTH 30

void readGrid(int grid[][GRID_SIZE]);
void printGrid(int grid[][GRID_SIZE]);
int readSequence(int sequence[]);
void press (int [][GRID_SIZE], int [], int);
void press_grid (int[][GRID_SIZE], int , int );
int allOff (int [][GRID_SIZE], int *);



int main(void) {
	int grid[GRID_SIZE][GRID_SIZE], sequence[MAX_LENGTH], length;
	
	int lighted;
	readGrid(grid);

	length = readSequence(sequence);
	
	press(grid, sequence, length);

	if (allOff(grid, &lighted)) {
		printf("All panels are off.\n");
	}else {
		printf("Number of lighted panels: %d\n", lighted);
		printGrid(grid);
	}
	
	return 0;
}

// Read the initial state of a grid
void readGrid(int grid[][GRID_SIZE]) {
	int i,j;
	
	printf("Enter grid:\n");
	
	for (i=0; i<GRID_SIZE; i++)
		for (j=0; j<GRID_SIZE; j++)
			scanf("%d", &grid[i][j]);
}

// Print the current grid
void printGrid(int grid[][GRID_SIZE]) {
	int i,j;
	
	for (i=0; i<GRID_SIZE; i++){
		for (j=0; j<GRID_SIZE; j++)
			printf("%d ", grid[i][j]);
		printf("\n");
	}
}

// Read the sequence of panels to be pressed
int readSequence(int sequence[]) {
	int i,length;
	
	printf("Enter length of sequence: ");
	scanf("%d", &length);
	
	printf("Enter sequence of panels: ");

	for (i=0; i<length; i++)
		scanf("%d", &sequence[i]);
		
	return length;
}

void press_grid (int grid[][GRID_SIZE], int x, int y) {
	// North
	if (y - 1 >= 0) {
		if (!grid[y-1][x]) {
			grid[y-1][x] = 1;
		}else{
			grid[y-1][x] = 0;
		}
	}
	// South
	if (y+1 < GRID_SIZE) {
		if (!grid[y+1][x]) {
			grid[y+1][x] = 1;
		}else{
			grid[y+1][x] = 0;
		}
	}

	// East
	if (x + 1 < GRID_SIZE) {
		if (!grid[y][x+1]) {
			grid[y][x+1] = 1;
		}else{
			grid[y][x+1] = 0;
		}
	}

	// West
	if (x - 1 >= 0) {
		if (!grid[y][x-1]) {
			grid[y][x-1] = 1;
		}else {
			grid[y][x-1] = 0;
		}
	}

	// Centre
	if (!grid[y][x]) {
		grid[y][x] = 1;
	}else {
		grid[y][x] = 0;
	}
}


void press (int grid[][GRID_SIZE], int sequence[], int length) {
	int i;
	for (i = 0; i < length; i++) {
		int x = sequence[i], y = 0;
		if (sequence[i] > 4) {
			x = sequence[i] % 5;
			y = sequence[i]/5;
		}
		press_grid(grid, x, y);
	}
}

int allOff (int grid[][GRID_SIZE], int *lighted) {
	int i, d, lighted_panels = 0;
	for (i = 0; i < GRID_SIZE; i++) {
		for (d = 0; d < GRID_SIZE; d++) {
			if (grid[i][d]) 
				lighted_panels++;
		}
	}
	if (lighted_panels > 0) {
		*lighted = lighted_panels;
		return 0;
	}
	return 1;
}
