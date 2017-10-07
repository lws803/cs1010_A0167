#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double bubbleSort (int[], int);

int main () {
	int choice;
	int arr1[1000], arr2[2000], arr4[4000], arr8[8000], arr16[16000];

	printf("1: bubblesort, 2: insertion sort, 3: selection sort\n");

	printf("What sort you want?: ");
	scanf("%d", &choice);

	switch(choice) {
		case 1: 
		printf("Bubble sort selected\n");
		printf("size 1000 : %lf \n", bubbleSort(arr1, 1000));
		printf("size 2000 : %lf \n", bubbleSort(arr2, 2000));
		printf("size 4000 : %lf \n", bubbleSort(arr4, 4000));
		printf("size 8000 : %lf \n", bubbleSort(arr8, 8000));
		printf("size 16000 : %lf \n", bubbleSort(arr16, 16000));
		break;
		default:
		printf("Bubble sort selected\n");
		printf("size 1000 : %lf \n", bubbleSort(arr1, 1000));
		printf("size 2000 : %lf \n", bubbleSort(arr2, 2000));
		printf("size 4000 : %lf \n", bubbleSort(arr4, 4000));
		printf("size 8000 : %lf \n", bubbleSort(arr8, 8000));
		printf("size 16000 : %lf \n", bubbleSort(arr16, 16000));
	}

	return 0;
}


// To determine sort time of a bubble sort Algo 

double bubbleSort (int arr[], int n) {
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

	return (double)((finish - start));
}
