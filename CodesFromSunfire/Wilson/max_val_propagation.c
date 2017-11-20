#include "stdio.h"

void maxPush (int[], int, int, int); 

int maxPull (int arr[], int size, int index, int length); 



int main(int argc, char const *argv[])
{
	int arr[10] = {7,3,8,5,7,10,9,12,6,5};
	int arr2[10] = {11,3,5,8,19,7,10,12,6,9};

	maxPush (arr, 10, 3, 7);
	maxPull (arr2, 10, 0, 4);

	int i;
	for (i = 0; i < 10; i++) 
		printf ("%d ", arr[i]);
	printf("\n");

	for (i = 0; i < 10; i++) 
		printf ("%d ", arr2[i]);
	printf("\n");
	return 0;
}

void maxPush (int arr[], int size, int index, int length) {
	if (index + 1 < size && length > 0) {
		if (arr[index+1] < arr[index]) {
			arr[index+1] = arr[index];
		}
		maxPush (arr, size, index+1, length-1);
	}
}

int maxPull (int arr[], int size, int index, int length) {
	if (length > 1 && index < size) {
		int next = maxPull (arr, size, index+1, length-1);
		if (next > arr[index]) {
			arr[index] = next;
		}
	}
	return arr[index];
}