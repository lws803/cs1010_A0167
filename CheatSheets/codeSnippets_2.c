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


// Checks if an array (A) is a subset of another (B)
int isSubset(int arrA[], int sizeA, int arrB[], int sizeB) {
	int i, d, count = 0;
	for (i = 0; i < sizeA; i++) {
		for (d = 0; d < sizeB; d++) {
			if (arrA[i] == arrB[d]) {
				count++;
			}
		}
	}

	// Only subset if all elements in A is present in B 
	if (count == sizeA) {
		return 1;
	}

	return 0;
}


// To print rank according to score. 
// Precond: Must specify max score, in this case its 100

void printRank (int arr[][2], int size, int rank) {

  int i, d, smallestElement = 100, comparisonIndex;

  for (i = 0; i < size ; i++) {
    // Find the smallest element 
    if (arr[i][1] < smallestElement) {
      smallestElement = arr[i][1];
    }
  }

  // To find the next smallest
  for (i = 1; i < rank; i++){
    int smallestDifference = 100;
    for (d = 0; d < size; d++){
      int difference = arr[d][1] - smallestElement;
      if (difference < smallestDifference && difference > 0) {
        smallestDifference = difference;
        comparisonIndex = d;
      }else if (difference == 0) {
        // Might be dupe or might be similar score, check ID and further eval 

      }
    }
    // Next smallest number 
    smallestElement = arr[comparisonIndex][1];
  }

  printf("ID: %d SCORE: %d\n", arr[comparisonIndex][0], smallestElement);

}

// To insert an element into an ordered array, <uses insert function from swift_ports.c>
// And returns the new size of the array.. 
// Precond: ID inputs must be in order 

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



// Trickling array 
// To insert an element at the top of the array and push the rest down backwards

void trickle (int arr[], int size, int index) {
	int i, element;
	element = arr[index];

	for (i = index; i < size-1; i++) {
		arr[i] = arr[i+1];
	}
	arr[size - 1] = element;
}


// Trace a multi-dimensional array for elements that chain diagonally rightwards 

int checkDiag (int arr[][MAX], int number, int startingX, int startingY) {
	int i, d, count = 0;
	for (i = startingX; i < DIM; i++) {
		if (board[startingY][i] == number) {
			count++;
			printf("%d\n", count);
		}else {
			break;
		}
		startingY++;
	}
	return count;
}

// Trace a multi-dimensional array for elements that chain horizontally forwards 

int checkHorizontal (int arr[][MAX], int number, int startingX, int startingY) {
	int i, count = 0;
	for (i = startingX; i < DIM; i++) {
		if (board[startingY][i] == number) {
			count++;
		}else {
			break;
		}

	}
	return count;
}

// Check neighbouring points of a single coordinate in a multi dimensional array 

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

// Check for neighbours in a specific direction and call the respective checkers to traverse in that direction 
void search_for_neighbours (char matrix[MAX][MAX], int size, char word[WORDSIZE], int x, int y) {
	// Found second character on North
	if (matrix[y-1][x] == word[1]) {
		if (search_north(matrix, size, word, x, y)) {
			printf("%d %d\n", x, y);
		}
	}
	// Found second char on south
	if (matrix[y+1][x] == word[1]) {
		if (search_south(matrix, size, word, x, y)) {
			printf("%d %d\n", x, y);
		}
	}

	// Found second char on east 
	if (matrix[y][x+1] == word[1]) {
		if (search_east(matrix, size, word, x, y)) {
			printf("%d %d\n", x, y);
		}
	}

	// Found second char on west
	if (matrix[y][x-1] == word[1]) {
		if (search_west(matrix, size, word, x, y)) {
			printf("%d %d\n", x, y);
		}
	} 

	// Found second char on NW 
	if (matrix[y-1][x-1] == word[1]) {
		if (search_north_west(matrix, size, word, x, y)) {
			printf("%d %d\n", x, y);
		}
	}

	// Found second char on NE
	if (matrix[y-1][x+1] == word[1]) {
		if (search_north_east(matrix, size, word, x, y)) {
			printf("%d %d\n", x, y);
		}
	}

	// Found second char on SE 
	if (matrix[y+1][x+1] == word[1]) {
		if (search_south_east(matrix, size, word, x, y)) {
			printf("%d %d\n", x, y);
		}
	}

	// Found second char on SW 
	if (matrix[y+1][x-1] == word[1]) {
		if (search_south_west(matrix, size, word, x, y)) {
			printf("%d %d\n", x, y);
		}
	}  
}

// Compass search algo  

void search_surrounding (int arr[MAX][MAX], int x, int y) {
	int i, d;
	for (i = -1; y+i < MAX && y+i >= 0 && i < 2; i++) {
		for (d = -1; x+d < MAX && x+d >= 0 && d < 2; d++) {
			if (i == 0 && d == 0) {
				// position is at original coords
			}else {
				printf("%d ", arr[y+i][x+d]);
			}
		}
	}
	printf("\n");
}

// Spiraled matrix - loop this in main and increment sequence after each function call 
// Keep looping as long as spiral returns 1; 

int spiral (int matrix[MAX][MAX], int size, int sequence) {
	int i, keep_spiral = 1;
	// Right
	for (i = sequence; i < size - (sequence + 1); i++) {
		printf("%d ", matrix[sequence][i]);
	}
	// Down 
	for (i = sequence; i < size - (sequence + 1); i++) {
		printf("%d ", matrix[i][size - (sequence + 1)]);
	}
	// Left 
	for (i = size - (sequence + 1); i > sequence; i--) {
		printf("%d ", matrix[size - (sequence + 1)][i]);
	}
	// Up 
	for (i = size - (sequence + 1); i > sequence  ; i--) {
		printf("%d ", matrix[i][sequence]);
	}
	if (sequence == size/2 && size%2 == 0) {
		keep_spiral = 0;
	}else if (sequence == size/2) {
		keep_spiral = 0;
		printf("%d ", matrix[size/2][size/2]);
	}

	return keep_spiral;
}

// Sum from any index in an array (in the shape of a circle)

int sum_circle (int arr[MAX_SLICES], int size, int index, int numSums) {
	int i, sum = 0, count = 0;
	for (i = index; count < numSums; i++) {
		sum += arr[i];
		count++;
		if (i == size - 1) {
			i = 0;
		}
	}
	return sum;
}

// Word Counting 
int word_count(char str[]) {
	int i, count = 0, word_count = 0;
	for (i = 0; str[i] != '\0'; i++) {
		if (isalpha(str[i])) {
			// Detection of normal words
			count = 1;
		}
		if ((count == 1 && str[i] == ' ')){
			// Last word can be tricky to recognise.
			// Detection of white spaces and any other weird characters or when the sentence ends. 
			word_count++;
			count = 0;
		}
	}
	if (count == 1) {
		word_count++;
	}
	return word_count;
}

// String tokenisation 
void tokenisation (char str[]) {
   const char s[2] = " ";
   char *token;
   
   /* get the first token */
   token = strtok(str, s);
   
   /* walk through other tokens */
   while( token != NULL ) {
   	printf("%s\n", token);
   	// Do fancy functions here, token is a string 
   	token = strtok(NULL, s);
   }
}

// Character insert at the back of string
void character_ins (char str[], char insert) {
	int i = strlen (str);
	str[i++] = insert;
	str[i] = '\0';
}


// Finding most frequent pairs of letters (bigram)

int mostFrequentBigram (char text[], char result[]) {
	int i, count = 0, d;
	for (i = 0; text[i] != '\0'; i++) {
		char str[2];
		int count2 = 0;
		if (text[i] != ' ' && text[i+1] != ' ' && text[i+1] != '\0') {
			str[0] = text[i];
			str[1] = text[i+1];

			for (d = i; text[d] != '\0'; d++) {
				if (str[0] == text[d] && str[1] == text[d+1]) {
					count2++;
				}
			}
		}

		if (count2 > count) {
			count = count2;
			result [0] = str[0];
			result [1] = str[1];
			// Tricky part, must always let the alphabet which comes first
		} else if (count2 == count && result[0] > str[0]) {	
			count = count2;
			result [0] = str[0];
			result [1] = str[1];
		}
	}
	
	result [2] = '\0';

	return count;
}

// Finding most frequently appearing alphabet - using a hash table

int mostFrequentUnigram (char text[], char result[]) {
	int hash_table [ASCII] = {0}, i;
	for (i = 0; text[i] != '\0'; i++) {
		if (isalpha(text[i])) {
			hash_table[text[i]] += 1;
		}
	}
	int frequency = 0, index = 0; 
	for (i = 0; i < ASCII; i++) {
		if (frequency < hash_table[i]) {
			frequency = hash_table[i];
			index = i;
		}
	}
	result[0] = index;
	result[1] = '\0';
	
	return frequency;
}
