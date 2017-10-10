// More useful algos


// To multiply mtxA and mtxB to obtain mtxC
void prodMatrix(float mtxA[][MAX_COL], float mtxB[][MAX_COL], 
		float mtxC[][MAX_COL], int mtxA_row_size, 
		int mtxA_col_size, int mtxB_col_size) {

	int row, col, row2;
	// Row stepper for mtx A
	for (row = 0; row < mtxA_row_size; row++){
		// Col stepper for mtx B
		for (col = 0; col < mtxB_col_size; col++) {
			// Multiplier 
			float sum = 0;
			for (row2 = 0; row2 < mtxA_col_size; row2++){
				sum += mtxA[row][row2] * mtxB[row2][col];
			}
			mtxC[row][col] = sum;
		}
	}

}

// Sub sequences - find the sub sequence with the largest sum 
void sum_subsequence(int arr[], int size, int ans[]) {
	int first_run = 1;
	// fill in the code
	int c, i, sum, d;
	// Subsequence 
	for (c = 1; c <= size; c++) {
		// Starting positions 
		for (i = 0; i < c; i++) {
			sum = 0;
			// Summing up loop
			for (d = i; d < size; d+= c) {
				sum += arr[d];
				
			}
			if (sum > ans[0] && !first_run) {
				ans[0] = sum;
				ans[1] = c;
				ans[2] = i;
			}else if (first_run){
				ans[0] = sum;
				ans[1] = c;
				ans[2] = i;
				first_run = 0;
			}
		}
	}
}

// Using coordinates system to check for valid path within a 2D array maze char path is a series of directions
// keyed in by the user 
int isValid(int maze[][SIZE], char path[]) {
	int pathlen, i;
	int x = 0, y = 0;

	pathlen = strlen(path);


	for (i = 0; path[i] != '\0'; i++){
		switch (path[i]){
			case 'N':
			y -= 1;
			break;
			case 'S':
			y += 1;
			break;
			case 'E':
			x += 1;
			break;
			case 'W':
			x -= 1;
			break;
		}
		if (!checker(maze, x, y)){
			return 0;
		}
	}
	return 1; // this is a stub
}

int checker(int maze[][SIZE], int x, int y) {
	if (x > SIZE - 1 || x < 0){
		return 0;
	}
	else if (y > SIZE - 1 || y < 0){
		return 0;
	}
	else if (maze[y][x] == 0){
		return 0;
	}

	return 1;
}

// Search for a pattern (of fixed dimensions) within a 2D array (of fixed dimensions)
int searchFunc(char minefield[][MAX], char search[][3]){
	int c, d, count = 0;;

	for (c = 0; c < MAX - 2; c++){
		for (d = 0; d < MAX - 3; d++) {
			if (minefield[c][d] == search[0][0] && minefield[c][d+1] == search[0][1] && minefield[c][d+2] == search[0][2]){
				if (minefield[c+1][d] == search[1][0] && minefield[c+1][d+1] == search[1][1] && minefield[c+1][d+2] == search[1][2]){
					count++;
				}
			}
		}
	}

	return count;
}


// Check if an array is sorted in ascending order
int isSorted (int arr[], int size) {
	int i;

	for (i = 0; i< size - 1; i++) {
		if (arr[i] > arr[i+1]) {
			return 0;
		}
	}
	return 1;
}


// Check if an array contains a number/ element (this is the same algo in the swift_ports)
int contains (int arr[], int number, int i) {

	while (arr[i] != '\0') {
		if (arr[i] == number) {
			return 1;
		}
		i++; 
	}

	return 0;
}


