#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX 1000

int generate_SE (char [MAX][MAX], int , char [MAX], int, int);
void display (char [MAX][MAX], int);
int generate_north (char [MAX][MAX], int, char [MAX], int, int);
int generate_south (char [MAX][MAX], int, char [MAX], int, int);
int generate_east (char [MAX][MAX], int, char [MAX], int, int);
int generate_west (char [MAX][MAX], int, char [MAX], int, int);
int generate_general (char [MAX][MAX], int, char [MAX], int, int, int);
void fill (char [MAX][MAX], int);
void write_to_file(char [MAX][MAX], int);
void write_ans_sheet(char [MAX][MAX], int);
void wordInput (char [MAX][MAX], int);
int remove_word (char [MAX][MAX], int , int );
int generate_general_no_diag (char [MAX][MAX], int , char [MAX], int , int , int);
int main () {
	char word[MAX]; 
	char matrix[MAX][MAX], words[MAX][MAX];
	int size, x = arc4random()%(size-1), y = arc4random()%(size-1), Case = arc4random()%10+1, num_words, total_sum = 0;

	printf("Enter size of word search: ");
	scanf("%d", &size);

	printf("Enter number of words: ");
	scanf("%d", &num_words);
	wordInput(words, num_words);


	// Init the word search
	int i, d;
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			matrix[i][d] = '-';
		}
	}

	// Calculate density and convert to upper case 
	for (i = 0; i < num_words; i++) {
		for (d = 0; words[i][d] != '\0'; d++) {
			words[i][d] = toupper(words[i][d]);
		}

		total_sum += strlen(words[i]);
	}

	printf("Density: %f\n", (float)total_sum/(size*size));



	for (i = 0; i < num_words; i++) {
		Case = arc4random()%9+1;
		x = (arc4random()%(size-1));
		y = (arc4random()%(size-1));
		if (!generate_general_no_diag(matrix, size, words[i], x, y, Case)) {
			int count = 0;
			while(count < 5 && !generate_general_no_diag(matrix, size, words[i], x, y, Case)) {
				count++;
			}
		}else {
			num_words = remove_word(words, i, num_words);
		} 
	}

	Case = arc4random()%10+1;
	x = (arc4random()%(size-1));
	y = (arc4random()%(size-1));

	for (i = 0; i < num_words; i++) {
		// Potential infinite loop
		while(!generate_general(matrix, size, words[i], x, y, Case)) {
			Case = arc4random()%10+1;
			x = (arc4random()%(size-1));
			y = (arc4random()%(size-1));
		}
	}
	
	printf("\n-------VISIBLE ANSWERS-------\n");
	display(matrix, size);
	write_ans_sheet(matrix, size);

	fill(matrix, size);
	printf("\n-------INVISIBLE ANSWERS-------\n");
	display(matrix, size);


	// Write to file 
	write_to_file(matrix, size);
	
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

void write_to_file(char matrix[MAX][MAX], int size) {
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

void wordInput (char words[MAX][MAX], int size) {
	int i, d;
	for (i = 0; i < size; i++) {
		scanf("%s", words[i]);
	}
}

int remove_word (char words[MAX][MAX], int atIndex, int size) {
    int i, d;
    for (i = atIndex; i < size; i++) {
    	for (d = 0; words[i][d] != '\0'; d++) {
    		words[i][d] = words[i+1][d];
    	}
    	words[i][d+1] = '\0';
    }
    size--;
    return size;
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
		case 1: case 2: case 3: case 4:
		boolean = generate_south(matrix, size, word, x, y);
		break;
		case 5: case 6: case 7: 
		boolean = generate_east(matrix, size, word, x, y);
		break;
		case 8:
		boolean = generate_SE(matrix, size, word, x, y);
		break;
		default:
		boolean = generate_east(matrix, size, word, x, y);
	}

	return boolean;
}

int generate_general_no_diag (char matrix[MAX][MAX], int size, char word[MAX], int x, int y, int Case) {
	int boolean = 0;
	switch(Case) {
		case 1: case 2: case 3: case 4:
		boolean = generate_south(matrix, size, word, x, y);
		break;
		case 5: case 6: case 7: 
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

