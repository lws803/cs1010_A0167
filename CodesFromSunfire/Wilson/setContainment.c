// setContainment.c
// Program to check if a set is contained in another.
// This is an incomplete program given to students.
#include <stdio.h>

void scanArray(int [], int);
void printArray(int [], int);
int isSubset(int [], int, int [], int);

int main(void) {
	int arrayA[4], sizeA = 4, arrayB[7], sizeB = 7;

	printf("1st array:\n");
	scanArray(arrayA, sizeA);
	printf("2nd array:\n");
	scanArray(arrayB, sizeB);

	if (isSubset(arrayA, 4, arrayB, 7))
		printf("arrayA[0..3] is a subset of arrayB[0..6]\n");
	else
		printf("arrayA[0..3] is not a subset of arrayB[0..6]\n");

	if (isSubset(arrayA, 4, arrayB, 6))
		printf("arrayA[0..3] is a subset of arrayB[0..5]\n");
	else
		printf("arrayA[0..3] is not a subset of arrayB[0..5]\n");

	return 0;
}

// To read values into arr
void scanArray(int arr[], int size) {
	int i;

	printf("Enter %d values: ", size);
	for (i=0; i<size; i++) {
		scanf("%d", &arr[i]);
	}
}

// To print values of arr
void printArray(int arr[], int size) 
{
	int i;

	// To print all values on one line
	for (i=0; i<size; i++) 
		printf("%d ", arr[i]);

	printf("\n");
}

int isSubset(int arrA[], int sizeA, int arrB[], int sizeB) {
	int i, d, count = 0;
	for (i = 0; i < sizeA; i++) {
		for (d = 0; d < sizeB; d++) {
			if (arrA[i] == arrB[d]) {
				count++;
			}
		}
	}

	// Only subset if all elements in A is present in B 
	if (count == sizeA) {
		return 1;
	}

	return 0;
}
