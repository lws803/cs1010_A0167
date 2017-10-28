// Find a pair that would sum up to a number (in a sorted arr) 

#include <stdio.h>
#define MAX 1000

int find_pair (int [], int, int, int*);
int enter_array (int []);

int main () {
	int arr[MAX], sum, count = 0;
	int size = enter_array(arr);

	printf ("Enter sum to find: ");
	scanf ("%d", &sum);

	if (find_pair(arr, size, sum, &count)) {
		printf("Found, %d runs \n", count);
	}else {
		printf("Not found, %d runs\n", count);
	}

}


int enter_array (int arr[]) {
	int size, i; 
	printf ("Enter size: ");
	scanf ("%d", &size);

	printf("Enter sorted array: \n");
	for (i = 0; i < size; i++) {
		scanf ("%d", &arr[i]);
	}
	return size;
}

/** 
 * Precond: array needs to be sorted 
*/

int find_pair (int arr[], int size, int sum, int *count) {
	int i = 0, d = size - 1, runs = 0;

	while (i != d) {
		runs++;
		*count = runs;
		if (arr[i] + arr[d] > sum) {
			// Too big
			d--;
		}else if (arr[i] + arr[d] == sum) {
			return 1;
		}else {
			// Too small
			i++;
		}
	}
	return 0;
}