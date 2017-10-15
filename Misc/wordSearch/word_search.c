#include <stdio.h>
#define MAX 50
#define WORDSIZE 50

// http://tools.atozteacherstuff.com/word-search-maker/wordsearch.php - generate your word search here

void search(char [MAX][MAX], int , char [WORDSIZE]);
void scanBoard (char [MAX][MAX], int);
void search_for_neighbours (char [MAX][MAX], int, char [WORDSIZE], int, int);
int search_north (char [MAX][MAX], int, char [WORDSIZE], int, int);
int search_south (char [MAX][MAX], int, char [WORDSIZE], int, int);
int search_west (char [MAX][MAX], int, char [WORDSIZE], int, int);
int search_east (char [MAX][MAX], int, char [WORDSIZE], int, int);
int search_north_west (char [MAX][MAX], int, char [WORDSIZE], int, int);
int search_north_east (char [MAX][MAX], int, char [WORDSIZE], int, int);
int search_south_east (char [MAX][MAX], int, char [WORDSIZE], int, int);
int search_south_west (char [MAX][MAX], int, char [WORDSIZE], int, int);
int wordlen(char [WORDSIZE]);

int main () {
	char matrix[MAX][MAX], word[WORDSIZE];
	int size, word_length, i;


	printf("Please enter size: ");
	scanf("%d", &size);
	scanBoard(matrix, size);

	printf("Enter word: ");
	// Note: when scanning a string, dont need to use &word
	scanf("%s", word);
	printf("%s\n", word);
	search(matrix, size, word);
}

// Precond: only upper case characters
void scanBoard (char matrix[MAX][MAX], int size) {
	int i, d;
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			scanf(" %c", &matrix[i][d]);
		}
	}
}


void search(char matrix[MAX][MAX], int size, char word[WORDSIZE]) {
	// Search for first letter: 
	int i, d;
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			if (matrix[i][d] == word[0]) {
				search_for_neighbours(matrix, size, word, d, i);
			}
		}
	}

}

// Precond: words must be more than two letters long 

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

int search_north (char matrix[MAX][MAX], int size, char word[WORDSIZE], int x, int y) {
	int i, index = 2, count = 1;
	for (i = y-2; i >= 0 && word[index] != '\0'; i--) {
		if (matrix[i][x] != word[index++]) {
			return 0;
		}else{
			count++;
		}
	}
	if (count == wordlen(word)) {
		return 1;
	}else{
		return 0;
	}

}


int search_south (char matrix[MAX][MAX], int size, char word[WORDSIZE], int x, int y) {
	int i, index = 2, count = 1;
	for (i = y+2; i < size && word[index] != '\0'; i++) {
		if (matrix[i][x] != word[index++]) {
			return 0;
		}else{
			count++;
		}
	}
	if (count == wordlen(word)) {
		return 1;
	}else{
		return 0;
	}
}
int search_east (char matrix[MAX][MAX], int size, char word[WORDSIZE], int x, int y) {
	int i, index = 2, count = 1;
	for (i = x+2; i < size && word[index] != '\0'; i++) {
		if (matrix[y][i] != word[index++]) {
			return 0;
		}else{
			count++;
		}
	}
	if (count == wordlen(word)) {
		return 1;
	}else{
		return 0;
	}
}

int search_west (char matrix[MAX][MAX], int size, char word[WORDSIZE], int x, int y) {
	int i, index = 2, count = 1;
	for (i = x-2; i >= 0 && word[index] != '\0'; i--) {
		if (matrix[y][i] != word[index++]) {
			return 0;
		}else{
			count++;
		}
	}
	if (count == wordlen(word)) {
		return 1;
	}else{
		return 0;
	}
}

int search_north_west (char matrix[MAX][MAX], int size, char word[WORDSIZE], int x, int y) {
	int i, index = 2, count = 1;
	y--;
	for (i = x-2; i >= 0 && word[index] != '\0'; i--) {
		if (matrix[--y][i] != word[index++]) {
			return 0;
		}else{
			count++;
		}
	}
	if (count == wordlen(word)) {
		return 1;
	}else{
		return 0;
	}
}

int search_north_east (char matrix[MAX][MAX], int size, char word[WORDSIZE], int x, int y) {
	int i, index = 2, count = 1;
	y++;
	for (i = x+2; i < size && word[index] != '\0'; i++) {
		if (matrix[++y][i] != word[index++]) {
			return 0;
		}else{
			count++;
		}
	}
	if (count == wordlen(word)) {
		return 1;
	}else{
		return 0;
	}
}

int search_south_west (char matrix[MAX][MAX], int size, char word[WORDSIZE], int x, int y) {
	int i, index = 2, count = 1;
	y++;
	for (i = x-2; i >= 0 && word[index] != '\0'; i--) {
		if (matrix[++y][i] != word[index++]) {
			return 0;
		}else{
			count++;
		}
	}
	if (count == wordlen(word)) {
		return 1;
	}else{
		return 0;
	}
}

int search_south_east (char matrix[MAX][MAX], int size, char word[WORDSIZE], int x, int y) {
	int i, index = 2, count = 1;
	y++;
	for (i = x+2; i < size && word[index] != '\0'; i++) {
		if (matrix[++y][i] != word[index++]) {
			return 0;
		}else{
			count++;
		}
	}
	if (count == wordlen(word)) {
		return 1;
	}else{
		return 0;
	}
}

int wordlen(char word[WORDSIZE]) {
	int i;
	for (i = 0; word[i] != '\0'; i++);
	return --i;
}
