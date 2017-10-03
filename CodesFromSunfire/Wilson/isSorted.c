#include <stdio.h>


int isSorted (int[], int);

int main () {
	int i;
	int arr[7] = {2,6,1,7,8,4,10};
	int arr2[7] = {1,2,3,4,5,6,7};


	printf("-----arr-----\n");
	for (i = 0; i<7; i++) {
		printf("%d ", arr[i]);
	}
	printf("\narr isSorted: %d\n", isSorted(arr, 7));

	printf("-----arr2-----\n");
	for (i = 0; i<7; i++) {
		printf("%d ", arr2[i]);
	}
	printf("\narr2 isSorted: %d\n", isSorted(arr2, 7));

}


int isSorted (int arr[], int size) {
	int i;

	for (i = 0; i< size - 1; i++) {
		if (arr[i] > arr[i+1]) {
			return 0;
		}
	}
	return 1;
}
