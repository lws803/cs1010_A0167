#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int checkDuplicates (int [], int);
int contains (int[] , int, int); 


int main () {
	int lower, upper, i, size = 0;
	srand (time(NULL));

	int array[1000] = {0};

	
	printf("Precond: range of numbers from 1 and above\n");
	printf ("Enter lower and upper: ");
	scanf("%d %d", &lower, &upper);

	printf ("Enter array size: ");
	scanf ("%d", &size);

	printf("---------Begin array printing---------\n");

	for (i = 0; i < size; i++ ){
		array[i] = rand()%upper + lower;
		printf("%d ", array[i]);
	}

	printf("\n---------End array printing---------\n");

	


	printf("Duplicates: %d\n", checkDuplicates(array, size));

}


//To calculate all duplicates in an array.
int checkDuplicates (int arr[], int size) {
	int i, j, count = 0;

	int checkArray[1000] = {0}, dupeCount = 0;

	for (i = 0; i < size - 1; i++) {
		if (contains(arr, arr[i], i+1)) {
			if (!contains(checkArray, arr[i], 0)) {
				checkArray[dupeCount] = arr[i];
				dupeCount++;
			}
		}
	}

	for (i = 0; i < dupeCount; i++) {
		printf("%d\n", checkArray[i]);
		for (j= 0; j < size; j++) {
			if (checkArray[i] == arr[j]) {
				count++;
			}
		}
	}

	return count;
}

//To check if an array contains a number 
int contains (int arr[], int number, int i) {

	while (arr[i] != '\0') {
		if (arr[i] == number) {
			return 1;
		}
		i++; 
	}

	return 0;
}

