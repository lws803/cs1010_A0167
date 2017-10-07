#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int bubbleSort (int[], int);
int insertionSort (int[], int);
int selectionSort (int[], int);
int enhancedBubble (int[], int);
int shakerSort(int[], int);

int main () {
	int choice;
	int arr1[1000], arr2[2000], arr4[4000], arr8[8000], arr16[16000];

	printf("1: bubblesort, 2: insertion sort, 3: selection sort, 4: Enhanced bubblesort, 5: Shaker sort\n");

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


// To determine sort time of a bubble sort Algo 

int bubbleSort (int arr[], int n) {
	clock_t start, finish;

	start = clock();
	for (int c = 0; c < n; c++) {
		for (int d = 0; d < (n-c-1); d++) {
			if (arr[d] > arr[d+1]) {
				int t = arr[d];
				arr[d] = arr[d+1];
				arr[d] = t;
			}
		}
	}

	finish = clock();

	return (int)((finish - start));
}

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
	for (i = 0; (i < n - 1) && isNotSorted; i++){
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