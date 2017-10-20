// transpose.c

#include <stdio.h>
#include <string.h>


#define MAX_ROWS 10      // maximum number of rows
#define MAX_COLS 10     // maximum number of columns 
#define MAX_LENGTH 100   // maximum number of characters in the message & result

int encrypt(int, int, char [], char []);
int decrypt(int, int, char [], char []);


int main(void) {
	char message[MAX_LENGTH], result[MAX_LENGTH];
	int setting, row, col;
	printf("Enter 1 for encryption, 2 for decryption: ");
	scanf("%d", &setting);
	printf("Enter dimensions of a 2D array: ");
	scanf("%d %d", &row, &col);
	printf("Enter message: ");

	scanf("%s", message);

	if (setting == 1) {

		if (encrypt(row, col, message, result)) {
			printf("Encrypted message: %s\n", result);
		}else{
			printf("Encryption failed.\n");
		}

	}else {
		if (decrypt(row, col, message, result)) {
			printf("Decrypted message: %s\n", result);
		}else{
			printf("Decryption failed.\n");
		}
	}

	return 0;
}

// Encrypt a message based on transposition algorithm
int encrypt(int rows, int cols, char message[], char result[]){
	char matrix[MAX_ROWS][MAX_COLS];
	int index = 0, i, d, word_len = strlen(message); 

	// For encryption, we need to ensure that the message can fit nicely in the number of spaces
	if (strlen(message) > cols*rows) {
		return 0;
	}

	for (i = 0; i < rows; i++) {
		for (d = 0; d < cols; d++) {
			if (index >= word_len) {
				matrix[i][d] = '@';
			}else{
				matrix [i][d] = message[index++];
			}
		}
	}
	index = 0;
	for (i = 0; i < cols; i++) {
		for (d = 0; d < rows; d++) {
			result[index++] = matrix[d][i];
		}
	}
	// Need to add this to ensure that there is a null character behind the actual string
	result[index] = '\0';
	return 1;
}
// TODO: Add in fail cases 
// Decrypt a message based on transposition algorithm
int decrypt(int rows, int cols, char message[], char result[]){
	char matrix[MAX_ROWS][MAX_COLS];
	int index = 0, i, d, word_len = strlen(message); 

	// For Decryption, we need to ensure that length of message is the same as the number of slots in this matrix 
	if (strlen(message) != cols*rows) {
		return 0;
	}

	for (i = 0; i < rows; i++) {
		for (d = 0; d < cols; d++) {
			matrix[i][d] = message[index++];
		}
	}
	index = 0;
	for (i = 0; i < cols; i++) {
		for (d = 0; d < rows; d++) {
			if (matrix[d][i] == '@') {
				return 1;
			}else {
				result[index++] = matrix[d][i];
			}
		}
	}

	return 1; 
}
