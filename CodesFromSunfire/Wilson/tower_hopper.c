#include <stdio.h>

int towerHop (int [], int, int);
int main () {
	int arr[1000] = {0};
	int size; 
	printf ("Enter size: ");
	scanf ("%d", &size);
	printf ("Enter elements: \n");
	for (int i = 0; i < size; i++)
		scanf ("%d", &arr[i]);

	printf ("Possibilites: %d\n", towerHop(arr, 0, size));

}

int towerHop (int arr[], int i, int size) {
	// Exit cond
	if (i >= size) {
		return 1;
	}

	int possiblePaths = 0;

	for (int d = 1; d <= arr[i]; d++) {
		possiblePaths += towerHop (arr, i+d, size);
	}

	return possiblePaths;
}
