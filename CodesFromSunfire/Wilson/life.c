/**
 * CS1010 AY2017/8 Semester 1 Lab5 Ex3
 * Game of Life
 * <Ler Wei Sheng>
 * <C04>
 */

#include <stdio.h>

#define DIM_ROW 20
#define DIM_COL 20
#define DEAD    '-'
#define LIFE    'O'
#define MAX_GEN 5

int genesis(char[][DIM_COL+2]); 
void display(int, char[][DIM_COL+2]);
int check_all_neighbours (char [][DIM_COL+2], int, int);
int next_generation(char [][DIM_COL+2]);
void spawn_next_community (char [][DIM_COL+2], char [][DIM_COL+2]); 
int recurring_community (char [][DIM_COL+2], char [][DIM_COL+2]);
int still_alive (char [][DIM_COL+2]);

int main(void) {
	char board[DIM_ROW+2][DIM_COL+2]; // the community
	int  lives;                       // how many lives in community
	int  generation = 0;              // generation

	lives = genesis(board);
	// display(generation, board); // for checking


	generation = next_generation(board); 
	// Display the final generation
	display(generation, board); 

	return 0;
}

// To initialise the community with generation 0 from user's input, and
// return the number of life cells read.
// Sentinels are used here. Dead cells are padded around the actual
// community area.
int genesis(char community[][DIM_COL+2]) {
	int population = 0;
	int r, c; 

	// Fill left-most and right-most columns with dead cells.
	for (r=0; r < DIM_ROW + 2; r++)
		community[r][0] = community[r][DIM_COL + 1] = DEAD;

	// Fill top and bottom rows with dead cells.
	for (c=1; c < DIM_COL + 1; c++)
		community[0][c] = community[DIM_ROW + 1][c] = DEAD;

	// Fill the middle 20x20 area with input data
	for (r=1; r<=DIM_ROW; r++) {
		for (c=1; c<=DIM_COL; c++) {
			community[r][c] = fgetc(stdin);
			if (community[r][c] == LIFE)
				population++;
		}
		fgetc(stdin);  // to read the newline character
	}

	return population;
}

// To display the community
void display(int generation, char community[][DIM_COL+2]) {
	int r, c;

	printf("Generation %d:\n", generation);
	for (r=1; r <= DIM_ROW; r++) {
		for (c=1; c <= DIM_COL; c++) {
			printf("%c", community[r][c]);
		}
		printf("\n");
	}
}

// To generate next generation and
// return number of live cells in next generation.
// next_generation()

// Checking for neighbours are done horizontally, vertically and diagonally 

int next_generation(char community[][DIM_COL+2]) {
	int i, d, count = 0;
	char prevCommunity[DIM_COL+2][DIM_COL+2] = {{0}};

	// Generates the number of generations 
	while (!recurring_community(community, prevCommunity) && count < 5 && still_alive(community)) {
		for (i = 0; i < DIM_COL; i++) {
			for (d = 0; d < DIM_COL; d++) {
				prevCommunity[i][d] = community[i][d];
			}
		}
		spawn_next_community(community, prevCommunity);
		count++;
	}


	return count;
}


int check_all_neighbours (char community[][DIM_COL+2], int x, int y) {
	int neighbours = 0;
	int i;
	// scan top row 
	for (i = x-1; i <= x+1; i++) {
		if (community[y-1][i] == 'O') {
			neighbours++;
		}
	} 
	// scan bottom row
	for (i = x-1; i <= x+1; i++) {
		if (community[y+1][i] == 'O') {
			neighbours++;
		}
	}

	if (community[y][x-1] == 'O') {
		neighbours++;
	}
	if (community[y][x+1] == 'O') {
		neighbours++;
	}

	return neighbours;
}

void spawn_next_community (char community[][DIM_COL+2], char prevCommunity[][DIM_COL+2]) {
	int i, d;
	
	// Check and make changes to the new community according to prevCommunity
	for (i = 0; i < DIM_COL; i++) {
		for (d = 0; d < DIM_COL; d++) {
			if (community[i][d] != 'O') {
				int numNeighbours = check_all_neighbours(prevCommunity, d, i);
				if (numNeighbours == 3) {
					// Bring thou back to life 
					community[i][d] = 'O';
				}
			}
			// Found live cell 
			if (community[i][d] == 'O') {
				int numNeighbours = check_all_neighbours(prevCommunity, d, i);
				if (numNeighbours < 2 || numNeighbours > 3) {
					// loneliness or overcrowding
					community[i][d] = '-';
				}
			}

		}
	}
}

int recurring_community (char community[][DIM_COL+2], char prevCommunity[][DIM_COL+2]) {
	int i, d;
	for (i = 0; i < DIM_COL; i++) {
		for (d = 0; d < DIM_COL; d++) {
			if (community[i][d] != prevCommunity[i][d]) {
				return 0;
			}
		}
	}
	return 1;
}

int still_alive (char community[][DIM_COL+2]) {
	int i, d;
	for (i = 0; i < DIM_COL; i++) {
		for (d = 0; d < DIM_COL; d++) {
			if (community[i][d] == 'O') {
				return 1;
			}
		}
	}

	return 0;
}