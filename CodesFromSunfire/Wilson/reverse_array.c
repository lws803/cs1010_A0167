#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15


int reverse (int [], int, int);
void print (int [], int);

int main () {
	srand(time(NULL));
	int i, size;
	int arr[MAX] = {0};
	printf ("Enter size (max 15): ");
	scanf ("%d", &size);

	// Randomise 
	for (i = 0; i < size; i++) {
		int n = rand()%100;
		arr[i] = n;
		printf ("%d ", n);
	}	
	printf ("\n");

	reverse (arr, size, size-1);

	print (arr, size);


}

int reverse (int arr[], int size, int pointer) {
	// Termination 
	if (pointer == (size - 1)/2) {
		return 0;
	}else {
		// swap 
		int t = arr[pointer];
		arr[pointer] = arr[size - 1 - pointer];
		arr[size - 1 - pointer] = t;

		return reverse (arr, size, --pointer);
	}
}

void print (int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf ("%d ", arr[i]);
	}
	printf ("\n");
}
