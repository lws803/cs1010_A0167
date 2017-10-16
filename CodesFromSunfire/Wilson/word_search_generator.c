#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define MAX 50

int generate_SE (char [MAX][MAX], int , char [MAX], int, int);
int word_len (char [MAX]);
void display (char [MAX][MAX], int);


int main () {
	char word[MAX]; 
	char matrix[MAX][MAX];
	int size, x, y;

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
	// TODO: Work on a random coords generator that continues to try until generate SE returns 1
	printf("Enter word: ");
	scanf("%s", word);
	printf("Enter coordinates x and y: ");
	scanf("%d %d", &x, &y);
	generate_SE(matrix, size, word, x, y);
	display(matrix, size);

	printf("Enter second word: ");
	scanf("%s", word);
	printf("Enter coordinates x and y: ");
	scanf("%d %d", &x, &y);
	generate_SE(matrix, size, word, x, y);


	display(matrix, size);
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

int generate_SE (char matrix[MAX][MAX], int size, char word[MAX], int x, int y) {
	int i, d, index;
	// Check path first
	int length = word_len(word);
	for (i = x, d = y, index = 0; i < x + length && i < size && d < size; i++, d++, index++) {
		if ((matrix[d][i] == '-' && x + length < size) || (matrix[d][i] == word[index] && x + length < size)) {
			// continue
		}else {
			return 0;
		}
	}
	// Commit to placing the characters 
	for (i = x, d = y, index = 0; i < x + length && i < size && d < size; i++, d++, index++) {
		matrix[d][i] = word[index];
	}
	return 1;
} 

int word_len (char word[MAX]) {
	int i;
	for (i = 0; word[i] != '\0'; i++);
	return i;
}