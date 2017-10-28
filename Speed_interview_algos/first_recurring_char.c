#include <stdio.h> 
#define MAX_ASCII 128 // 128 characters in an ascii table
#define MAX 1000

// O(n) time completion 

int find_first_recurring (char[], int []);
int main () {
	char arr[MAX];
	int hash_table[MAX_ASCII] = {0};
	
	printf ("Please enter characters: \n");
	scanf("%s", arr);
	
	int value = find_first_recurring(arr, hash_table); 

	if (value != -1) {
		printf ("Closest recurring character: %c\n", value);
	}else {
		printf ("No recurring char found\n");
	}


}

int find_first_recurring (char arr[], int hash_table[]) {
	int i;
	for (i = 0; arr[i] != '\0'; i++) {
		if (hash_table[arr[i]] == 1) {
			return arr[i];
		}
		hash_table[arr[i]] = 1;
	}
	return -1;
}
