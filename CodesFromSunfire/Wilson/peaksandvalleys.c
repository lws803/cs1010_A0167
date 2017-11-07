// Peaks and valleys shit 

#include <stdio.h>
#include <stdlib.h>
#define MAX_ROW 12 
#define MAX_COL 12

void read_map (int [][MAX_COL], int *, int *); 
void print_map (int [][MAX_COL], int , int ) ;
int scan_neighbours_pns (int [][MAX_COL], int, int , int , int ); 
void peaks_and_valleys (int [][MAX_COL], int [][MAX_COL], int, int , int *, int *); 
void hike_trail (int [][MAX_COL], int [][MAX_COL], int, int); 
void flood_fill (int [][MAX_COL], int [][MAX_COL], int, int, int, int); 

int main(void) {
	int nopeaks, novalleys;
	int row, col;
	int map[MAX_ROW][MAX_COL], hike[MAX_ROW][MAX_COL], pns[MAX_ROW][MAX_COL];

	read_map (map, &row, &col);

	peaks_and_valleys (map, pns, row, col, &nopeaks, &novalleys);

	printf("No. of peaks and valleys: %d & %d\n", nopeaks, novalleys);
	printf("Peaks and valleys map\n");
	print_map (pns, row, col);

	printf("Hike trail: \n");
	hike_trail(map, hike, row, col);
	print_map (hike, row, col);


	return 0;
}


void read_map (int map[][MAX_COL], int *row, int *col) {
	int rows, cols;
	printf("Enter rows and cols: ");
	scanf ("%d %d", &rows, &cols);

	*row = rows;
	*col = cols;

	printf("Enter map: \n");
	for (int i = 0; i < rows; i++) {
		for (int d = 0; d < cols; d++) {
			scanf ("%d", &map[i][d]);
		}
	}
}

void print_map (int source[][MAX_COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int d = 0; d < col; d++) {
			printf("%d ", source[i][d]);
		}
		printf("\n");
	}
}



void peaks_and_valleys (int map[][MAX_COL], int pns[][MAX_COL], int row, int col, int *nopeaks, int *novalleys) {
	int valleys = 0, peaks = 0;
	// Init the pns map 
	for (int i = 0; i < row; i++) {
		for (int d = 0; d < col; d++) {
			pns[i][d] = 0;
		}
	}

	for (int i = 1; i < row-1; i++) {
		for (int d = 1; d < col-1; d++) {
			pns[i][d] = scan_neighbours_pns(map, d, i, row, col);
		}
	}

	for (int i = 0; i < row; i++) {
		for (int d = 0; d < col; d++) {
			if (pns[i][d] == 2) {
				valleys++;
			}
			if (pns[i][d] == 1) {
				peaks++;
			}
		}
	}
	*nopeaks = peaks;
	*novalleys = valleys;
}


void hike_trail (int map[][MAX_COL], int hike[][MAX_COL], int row, int col) {
	int i, d;
	// Init
	for (i = 0; i < row; i++) {
		for (d = 0; d < col; d++) {
			hike[i][d] = 0;
		}
	}

	// Drop the seed 
	flood_fill (map, hike, row, col, 0, 0);

}

void flood_fill (int map[][MAX_COL], int hike[][MAX_COL], int row, int col, int x, int y) {
	hike[y][x] = 1;
	if (y+1 < row && abs(map[y+1][x] - map[y][x]) < 3 && hike[y+1][x] != 1) {
		flood_fill (map, hike, row, col, x, y+1);
	}
	if (y-1 >= 0 && abs(map[y-1][x] - map[y][x]) < 3 && hike[y-1][x] != 1) {
		flood_fill (map, hike, row, col, x, y-1);
	}
	if (x+1 < col && abs(map[y][x+1] - map[y][x]) < 3 && hike[y][x+1] != 1) {
		flood_fill (map, hike, row, col, x+1, y);
	}
	if (x-1 >= 0 && abs(map[y][x-1] - map[y][x]) < 3 && hike[y][x-1] != 1) {
		flood_fill (map, hike, row, col, x-1, y);
	}
}

/**
int scan_neighbours (int source[][MAX_COL], int row, int col, int x, int y) {
	int i, d;
	for (i = -1; y+i < row && y+i >= 0 && i < 2; i++) {
		for (d = -1; x+d < col && x+d >= 0 && d < 2; d++) {
			if (i == y && d == x) {
				// position is at original coords
			}else {
				if (source[y+i][x+d] == 1) {
					// Continuation detected
					return 1;
				}
			}
		}
	}
	return 0;
}

int scan_neighbours_less_two (int source[][MAX_COL], int row, int col, int x, int y, int target) {
	int i, d;
	for (i = -1; y+i < row && y+i >= 0 && i < 2; i++) {
		for (d = -1; x+d < col && x+d >= 0 && d < 2; d++) {
			if (i == y && d == x) {
			}else {
				if (abs(source[y+i][x+d] - target) < 3) {
					return 1;
				}
			}
		}
	}
	return 0;
}
DEPRECATED - iterative method really does not work 
*/

int scan_neighbours_pns (int map[][MAX_COL], int x, int y, int row, int col) {
	// if valley return 2, if peak return 1 
	int i, d, count_valley = 0 ,count_peak = 0 ;
	for (i = -1; y+i < row && y+i >= 0 && i < 2; i++) {
		for (d = -1; x+d < col && x+d >= 0 && d < 2; d++) {
			if (i == y && d == x) {
				// position is at original coords
			}else {
				if (map[y+i][x+d] < map[y][x]) {
					count_peak++;
				}
				if (map[y+i][x+d] > map[y][x]) {
					count_valley++;
				}
			}
		}
	}

	if (count_valley == 8) {
		return 2;
	}

	if (count_peak == 8) {
		return 1;
	}
	return 0;
}