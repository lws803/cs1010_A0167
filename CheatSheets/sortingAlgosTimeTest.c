#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 16000

int bubbleSort (int[], int);
int insertionSort (int[], int);
int selectionSort (int[], int);
int enhancedBubble (int[], int);
int shakerSort(int[], int);
int insertionSortV2(int[],int);
void merge (int [], int [], int [], int , int ); 
int mergeSort (int [], int );

int main () {
	int choice;
	int arr1[1000], arr2[2000], arr4[4000], arr8[8000], arr16[16000];

	printf("1: bubblesort, 2: insertion sort, 3: selection sort, 4: Enhanced bubblesort, 5: Shaker sort, 6: Insertion sort v2, 7: Merge sort\n");

	printf("What sort you want?: ");
	scanf("%d", &choice);

	switch(choice) {
		case 1: 
		printf("Bubble sort selected\n");
		printf("size 1000 : %d \n", bubbleSort(arr1, 1000));
		printf("size 2000 : %d \n", bubbleSort(arr2, 2000));
		printf("size 4000 : %d \n", bubbleSort(arr4, 4000));
		printf("size 8000 : %d \n", bubbleSort(arr8, 8000));
		printf("size 16000 : %d \n", bubbleSort(arr16, 16000));
		printf("-----Best case: O(n), worst case: O(n^2)-----\n");
		break;
		case 2: 
		printf("Insertion sort selected\n");
		printf("size 1000 : %d \n", insertionSort(arr1, 1000));
		printf("size 2000 : %d \n", insertionSort(arr2, 2000));
		printf("size 4000 : %d \n", insertionSort(arr4, 4000));
		printf("size 8000 : %d \n", insertionSort(arr8, 8000));
		printf("size 16000 : %d \n", insertionSort(arr16, 16000));
		printf("-----Best case: O(n), worst case: O(n^2)-----\n");
		break;
		case 3: 
		printf("Selection sort selected\n");
		printf("size 1000 : %d \n", selectionSort(arr1, 1000));
		printf("size 2000 : %d \n", selectionSort(arr2, 2000));
		printf("size 4000 : %d \n", selectionSort(arr4, 4000));
		printf("size 8000 : %d \n", selectionSort(arr8, 8000));
		printf("size 16000 : %d \n", selectionSort(arr16, 16000));
		printf("-----Best case: O(n^2), worst case: O(n^2)-----\n");
		break;
		case 4:
		printf("Bubble sort selected\n");
		printf("size 1000 : %d \n", enhancedBubble(arr1, 1000));
		printf("size 2000 : %d \n", enhancedBubble(arr2, 2000));
		printf("size 4000 : %d \n", enhancedBubble(arr4, 4000));
		printf("size 8000 : %d \n", enhancedBubble(arr8, 8000));
		printf("size 16000 : %d \n", enhancedBubble(arr16, 16000));
		printf("-----Best case: O(n), worst case: O(n^2)-----\n");
		break;
		case 5:
		printf("Shaker sort selected\n");
		printf("size 1000 : %d \n", shakerSort(arr1, 1000));
		printf("size 2000 : %d \n", shakerSort(arr2, 2000));
		printf("size 4000 : %d \n", shakerSort(arr4, 4000));
		printf("size 8000 : %d \n", shakerSort(arr8, 8000));
		printf("size 16000 : %d \n", shakerSort(arr16, 16000));
		printf("-----Best case: O(n), worst case: O(n^2)-----\n"); 
		break;
		case 6: 
		printf("Insertion sort V2 selected\n");
		printf("size 1000 : %d \n", selectionSort(arr1, 1000));
		printf("size 2000 : %d \n", selectionSort(arr2, 2000));
		printf("size 4000 : %d \n", selectionSort(arr4, 4000));
		printf("size 8000 : %d \n", selectionSort(arr8, 8000));
		printf("size 16000 : %d \n", selectionSort(arr16, 16000));
		printf("-----Best case: O(n), worst case: O(n^2)-----\n");
		break;
		case 7: 
		printf("Merge sort selected\n");
		printf("size 1000 : %d \n", mergeSort(arr1, 1000));
		printf("size 2000 : %d \n", mergeSort(arr2, 2000));
		printf("size 4000 : %d \n", mergeSort(arr4, 4000));
		printf("size 8000 : %d \n", mergeSort(arr8, 8000));
		printf("size 16000 : %d \n", mergeSort(arr16, 16000));
		printf("-----O(log(n))-----\n");
		break;
		default:
		printf("Bubble sort selected\n");
		printf("size 1000 : %d \n", bubbleSort(arr1, 1000));
		printf("size 2000 : %d \n", bubbleSort(arr2, 2000));
		printf("size 4000 : %d \n", bubbleSort(arr4, 4000));
		printf("size 8000 : %d \n", bubbleSort(arr8, 8000));
		printf("size 16000 : %d \n", bubbleSort(arr16, 16000));
		printf("-----Best case: O(n), worst case: O(n^2)-----\n");
	}

	return 0;
}


/**
	Pros: Good to use for small arrays
*/

int bubbleSort (int arr[], int n) {
	clock_t start, finish;

	start = clock();
	for (int c = 0; c < n; c++) {
		for (int d = 0; d < (n-c-1); d++) {
			if (arr[d] > arr[d+1]) {
				int t = arr[d+1];
				arr[d+1] = arr[d];
				arr[d] = t;
			}
		}
	}

	finish = clock();

	return (int)((finish - start));
}


/**
	Pros: Good to use for small arrays
*/

int insertionSort (int arr[], int n) {
	int d, c, t;
	clock_t start, finish;
	start = clock();
	for (c = 0; c < n; c++){
		d = c;
		while (d > 0 && arr[d] < arr[d-1]){
			t = arr[d];
			arr[d] = arr[d-1];
			arr[d-1] = t;

			d--;
		}
	}
	finish = clock();

	return (int)(finish - start);
}


/**
	Pros: Good to use for small arrays
*/

int selectionSort (int arr[], int n) {
	int i, smallestIndex, t;
	clock_t start, finish;

	start = clock();
	for (i = 0; i < n - 1; i++) {
		smallestIndex = i;
		int j;
		for (j = i; j < n; j++){
			// Searches for the position for the smallest element in the array
			if (arr[smallestIndex] > arr[j]){
				smallestIndex = j;
			}
		}
		// Swaps the smallest element with the element (i) you're currently on 
		t = arr[i];
		arr[i] = arr[smallestIndex];
		arr[smallestIndex] = t;
	}

	finish = clock();

	return (int)(finish - start);
}

int enhancedBubble (int arr[], int n) {
	int i, isNotSorted = 1, t;
	clock_t start, finish;
	
	start = clock();	
	for (i = 0; (i < n - 1) && isNotSorted; i++){	// IsNotSorted will cause the loop to break if there is no swaps occurring.
		int j;
		isNotSorted = 0;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j+1]){
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
				isNotSorted = 1;
			}
		}
	}

	finish = clock();

	return (int)(finish - start);
}


int shakerSort(int array[], int size) {
	clock_t start, finish;
	int swapped = 0;
	start = clock();	
    for (int i = 0; i < size/2; i++) {
    	swapped = 0;
        for (int j = i; j < size - i - 1; j++) { //one way
            if (array[j] < array[j+1]) {
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
                swapped = 1;
            }
        }
        for (int j = size - 2 - i; j > i; j--) { //and back
            if (array[j] > array[j-1]) {
                int tmp = array[j];
                array[j] = array[j-1];
                array[j-1] = tmp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
    finish = clock();

    return (int)(finish - start);
}

int insertionSortV2(int arr[],int size){
	clock_t start,finish;
	int i,j,temp;
	
	start = clock();
	for (i=0;i<size;i++){
		temp = arr[i];
		j = i-1;
		while ((j>=0) && (temp<arr[j])){
			arr[j+1] = arr[j];		// Only does one assignment each time it looks for the space for the element.
			j--;
		}
		arr[j+1] = temp; 			// Once it finds the location then assign. FASTER than doing swapping as swapping does 3 actions each time.
	}
	finish = clock();
	return (int)(finish-start);
}



/**
	Pros: Constant O(N log N)
	Cons: Not memory efficient and requires O(N) space
*/

// Due to the memory usage of this algo, it cannot be timed without causing a crash :(
int mergeSort (int arr[], int size) {
	clock_t start, finish;
	start = clock();
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
	finish = clock();
	return (int)(finish-start);
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
		// When they are both equal
		if (arrL[i] == arrR[j]) {
			arr[index++] = arrR[j++];
			arr[index++] = arrL[i++];
		}
	}
	// Settle the left overs 
	while (left_size - i) {
		arr[index++] = arrL[i++]; 
	}
	while (right_size - j) {
		arr[index++] = arrR[j++];
	}
}

