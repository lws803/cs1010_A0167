#include "stdio.h"
#define MAX 10

void merge (int [], int [], int [], int , int ); 
void mergeSort (int [], int ); 


int main(int argc, char const *argv[])
{
	int arr[MAX] = {0};
	int arrL[3] = {1,5,8};
	int arrR[3] = {3,7,9};
	int size = 6;

	printf("--------Testing of merge function--------\n");
	merge (arrL, arrR, arr, 3, 3);
	for (int i = 0; i < size; ++i)
	{
		printf("%d\n", arr[i]);
	}

	printf("--------Recursive merge sort--------\n");
	//int arr_test[MAX] = {5,6,2,7,3,9,10};
	int arr_test[MAX] = {7,8,3,1,4,4,10};
	int size2 = 7;
	mergeSort (arr_test, size2);
	for (int i = 0; i < size2; ++i)
	{
		printf("%d\n", arr_test[i]);
	}
	return 0;
}

void mergeSort (int arr[], int size) {
	int arrL[MAX] = {0};
	int arrR[MAX] = {0};
	int pivot = size/2;
	int i, d;
	if (size > 1) {
		
		for (i = 0; i < pivot; i++) {
			// Copy to left 
			arrL[i] = arr[i];
		}
		i = 0;
		for (d = pivot; d < size; d++) {
			// Copy to right
			arrR[i++] = arr[d];
		}
		mergeSort (arrL, pivot);
		mergeSort (arrR, i); // I used 'i' because it was post incremented earlier on
	}
	merge (arrL, arrR, arr, pivot, i);
}


void merge (int arrL[], int arrR[], int arr[], int left_size, int right_size) {
	int i = 0, j = 0, index = 0;
	while (i < left_size && j < right_size) {
		// Insert in increasing order 
		if (arrL[i] > arrR[j]) {
			arr[index++] = arrR[j++]; 
		}

		if (arrL[i] < arrR[j]) {
			arr[index++] = arrL[i++];
		}
		if (arrL[i] == arrR[j]) {
			arr[index++] = arrR[j++];
			arr[index++] = arrL[i++];
		}
	}
	// Settle the left overs 
	if (left_size - i) {
		arr[index++] = arrL[i]; 
	}
	if (right_size - j) {
		arr[index++] = arrR[j];
	}
}