#include "stdio.h"

void maxPush (int[], int, int, int); 



int main(int argc, char const *argv[])
{
	int arr[10] = {7,3,8,5,7,10,9,12,6,5};
	maxPush (arr, 10, 3, 7);

	int i;
	for (i = 0; i < 10; i++) 
		printf ("%d ", arr[i]);
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