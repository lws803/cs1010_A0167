// partition.c
#include <stdio.h>

void printArray(int [], int);
void scanArr(int [], int);
void trickle (int [], int, int);
void pivot (int [], int, int);

int main(void) {
	int size, arr[20], pivotVal;

	printf("Enter the number of elements: ");
	scanf("%d", &size);

	printf("Enter %d integers: ", size);
	scanArr(arr, size);

	printf("Enter pivot: ");
	scanf("%d", &pivotVal);
	pivot(arr, size, pivotVal);


	printArray(arr, size);

	return 0;
}

// Print array arr
void printArray(int arr[], int size) {
	int i;

	for (i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void scanArr(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}
}

void pivot (int arr[], int size, int pivot) {
	int i, d; 
	for (i = 0; i < size; i++) {
		if (arr[i] >= pivot) {
			trickle(arr, size, i);
		}
	}
}

// TODO: Create a new function to 'trickle' down elements from the top of the array

void trickle (int arr[], int size, int index) {
	int i, element;
	element = arr[index];

	for (i = index; i < size-1; i++) {
		arr[i] = arr[i+1];
	}
	arr[size - 1] = element;
}
