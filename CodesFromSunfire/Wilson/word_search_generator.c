#include <stdio.h>
#define MAX 50

void generate_SE (char [MAX][MAX], int , char [MAX], int, int);
int word_len (char [MAX]);
void display (char [MAX][MAX], int);


int main () {
	char word[MAX]; 
	char matrix[MAX][MAX];
	int size;

	printf("Enter size of word search: ");
	scanf("%d", &size);

	printf("Enter word: ");
	scanf("%s", word);

	// Init the word search
	int i, d;
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			matrix[i][d] = '-';
		}
	}

	// Generate the word search
	generate_SE(matrix, size, word, 0, 0);

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

void generate_SE (char matrix[MAX][MAX], int size, char word[MAX], int x, int y) {
	int i, d, index = 0;
	for (i = x; i < x + word_len(word) && x + i < size && y < size; i++) {
		matrix[y++][i] = word[index++];
	}
} 

int word_len (char word[MAX]) {
	int i;
	for (i = 0; word[i] != '\0'; i++);
	return i;
}