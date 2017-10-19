#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


#define MAX 1000

int generate_SE (char [MAX][MAX], int , char [MAX], int, int);
void display (char [MAX][MAX], int);
int generate_north (char [MAX][MAX], int, char [MAX], int, int);
int generate_south (char [MAX][MAX], int, char [MAX], int, int);
int generate_east (char [MAX][MAX], int, char [MAX], int, int);
int generate_west (char [MAX][MAX], int, char [MAX], int, int);
int generate_general (char [MAX][MAX], int, char [MAX], int, int, int);
void fill (char [MAX][MAX], int);
void write(char [MAX][MAX], int);
void write_ans_sheet(char [MAX][MAX], int);

int main () {
	char word[MAX]; 
	char matrix[MAX][MAX];
	srand(time(NULL));

	int size, x = arc4random_uniform(size-1) + 0, y = arc4random_uniform(size-1) + 0, Case = arc4random_uniform(8)+1;

	printf("Enter size of word search: ");
	scanf("%d", &size);

	// Init the word search
	int i, d;
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			matrix[i][d] = '-';
		}
	}

	// Generate the word search	
	// Keeps the prog running as long as user does not press ctrl-D
	// Precond: Only key in upper case letters if you want the answers to be harder to find :) 
	printf("Enter word: ");
	int totalsum = 0;
	while(scanf("%s", word) != EOF) {
		int length = strlen(word);
		if (length > size || length < 3) {
			printf("Word exceeding board or fewer than 3\n");
			printf("Enter word: ");
			continue;
		}
		totalsum += length;
		float density = (float)totalsum/(size*size);
		printf("Density: %f\n", density);
		while (!generate_general(matrix, size, word, x, y, Case) && density < 0.6) {
			// Determines the number of cases that can be randomly generated 
			//Case = rand()%8+1;
			Case = arc4random_uniform(8)+1;
			x = arc4random_uniform(size-1) + 0;
			y = arc4random_uniform(size-1) + 0;
		}

		if (density >= 0.6) {
			printf("Too many words... generating word_search\n");
			break;
		}
		printf("Enter word: ");
	}
	
	printf("\n-------VISIBLE ANSWERS-------\n");
	display(matrix, size);
	write_ans_sheet(matrix, size);

	fill(matrix, size);
	printf("\n-------INVISIBLE ANSWERS-------\n");
	display(matrix, size);


	// Write to file 
	write(matrix, size);

	return 0;
}

void display (char matrix[MAX][MAX], int size) {
	int i, d;
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			printf("%c ", matrix[i][d]);
		}
		printf("\n");
	}
}

void write(char matrix[MAX][MAX], int size) {
	int i, d;
	FILE *f = fopen("word_search.txt", "w");
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			fprintf(f, "%c ", matrix[i][d]);
		}
		fprintf(f, "\n");
	}
	fclose(f);
}

void write_ans_sheet(char matrix[MAX][MAX], int size) {
	int i, d;
	FILE *f = fopen("word_search_ans.txt", "w");
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			fprintf(f, "%c ", matrix[i][d]);
		}
		fprintf(f, "\n");
	}
	fclose(f);
}


void fill (char matrix[MAX][MAX], int size) {
	int i, d;
	for (i = 0; i < size; i++) {
		for (d= 0; d < size; d++) {
			char randomletter = 'A' + (rand() % 26);
			if (matrix[i][d] == '-') {
				matrix[i][d] = randomletter;
			}	
		}
	}
}

int generate_general (char matrix[MAX][MAX], int size, char word[MAX], int x, int y, int Case) {
	int boolean = 0;
	switch(Case) {
		case 1: case 5: case 6: 
		boolean = generate_south(matrix, size, word, x, y);
		break;
		case 2:
		boolean = generate_SE(matrix, size, word, x, y);
		break;
		case 3: case 4:
		boolean = generate_east(matrix, size, word, x, y);
		break;
		default:
		boolean = generate_east(matrix, size, word, x, y);
	}

	return boolean;
}

// Generators 
int generate_north (char matrix[MAX][MAX], int size, char word[MAX], int x, int y) {
	int i, d, index;
	// Check path first
	int length = strlen(word);
	// return 0 when it exceeds the board
	if (y - length < 0) {
		return 0;
	}
	// Check for overlaps 
	for (i = x, d = y, index = 0; index < length; d--, index++) {
		if (matrix[d][i] == '-' || matrix[d][i] == word[index]) {
			// continue
		}else {
			return 0;
		}
	}
	// Commit to placing the characters 
	for (i = x, d = y, index = 0; index < length; d--, index++) {
		matrix[d][i] = word[index];
	}
	return 1;
}

int generate_south (char matrix[MAX][MAX], int size, char word[MAX], int x, int y) {
	int i, d, index;
	// Check path first
	int length = strlen(word);
	// return 0 when it exceeds the board
	if (y + length < size) {
		return 0;
	}
	// Check for overlaps 
	for (i = x, d = y, index = 0; index < length; d++, index++) {
		if (matrix[d][i] == '-' || matrix[d][i] == word[index]) {
			// continue
		}else {
			return 0;
		}
	}
	// Commit to placing the characters 
	for (i = x, d = y, index = 0; index < length; d++, index++) {
		matrix[d][i] = word[index];
	}
	return 1;
}

int generate_east (char matrix[MAX][MAX], int size, char word[MAX], int x, int y) {
	int i, d, index;
	// Check path first
	int length = strlen(word);
	// return 0 when it exceeds the board
	if (x + length < size) {
		return 0;
	}
	// Check for overlaps 
	for (i = x, d = y, index = 0; index < length; i++, index++) {
		if (matrix[d][i] == '-' || matrix[d][i] == word[index]) {
			// continue
		}else {
			return 0;
		}
	}
	// Commit to placing the characters 
	for (i = x, d = y, index = 0; index < length; i++, index++) {
		matrix[d][i] = word[index];
	}
	return 1;
}

int generate_west (char matrix[MAX][MAX], int size, char word[MAX], int x, int y) {
	int i, d, index;
	// Check path first
	int length = strlen(word);
	// return 0 when it exceeds the board
	if (x - length >= 0) {
		return 0;
	}
	// Check for overlaps 
	for (i = x, d = y, index = 0; index < length; i--, index++) {
		if (matrix[d][i] == '-' || matrix[d][i] == word[index]) {
			// continue
		}else {
			return 0;
		}
	}
	// Commit to placing the characters 
	for (i = x, d = y, index = 0; index < length; i--, index++) {
		matrix[d][i] = word[index];
	}
	return 1;
}

int generate_SE (char matrix[MAX][MAX], int size, char word[MAX], int x, int y) {
	int i, d, index;
	// Check path first
	int length = strlen(word);
	// return 0 when it exceeds the board
	if (x + length > size || y + length > size) {
		return 0;
	}
	// Check for overlaps 
	for (i = x, d = y, index = 0; index < length; i++, d++, index++) {
		if (matrix[d][i] == '-' || matrix[d][i] == word[index]) {
			// continue
		}else {
			return 0;
		}
	}
	// Commit to placing the characters 
	for (i = x, d = y, index = 0; index < length; i++, d++, index++) {
		matrix[d][i] = word[index];
	}
	return 1;
} 

