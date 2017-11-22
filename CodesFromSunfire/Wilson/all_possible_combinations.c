#include "stdio.h"


void subset(int [], int [], int , int , int , int ); 
void printsubset(int [], int , int );

int main(int argc, char const *argv[])
{
	int i;
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	for (i = 1; i < 11; i++) {
		printsubset(arr, 10, i);
	}
	return 0;
}


void subset(int arr[], int data[], int start, int end, int index, int r)
{
    int j, i;
    if (index == r) {
        for (j = 0; j < r; j++)
            printf("%d ", data[j]);
        printf("\n");
        // Add any operations here to process data (subset)
        return;
    }
    for (i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        subset(arr, data, i+1, end, index+1, r);
    }
}
 
void printsubset(int arr[], int n, int r)
{
    int data[r];
    subset(arr, data, 0, n - 1, 0, r);
}