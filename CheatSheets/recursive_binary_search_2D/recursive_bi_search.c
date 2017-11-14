#include "stdio.h"

void scan_arr (int [][6]); 
int search (int , int [][6], int , int , int, int); 

int main(int argc, char const *argv[])
{
	int arr[6][6];	

	scan_arr(arr);
	int num;
	scanf("%d", &num);

	printf ("%d\n", search (num, arr, 0, 0, 5, 5));

	return 0;
}

// Precond: The array must be sorted col wise and row wise
void scan_arr (int arr[][6]) {
	int i, d;
	for (i = 0; i < 6; i++) {
		for (d = 0; d < 6; d++) {
			scanf ("%d", &arr[i][d]);
		}
	}
}

int search (int target, int table[][6], int startX, int startY, int endX, int endY) {
	int midX = (startX+endX)/2, midY = (startY+endY)/2;
	if (startX > endX || startY > endY) {
		// Means end must decrease or start must increase 
		return 0;
	}
	if (target == table[midY][midX]) {
		return 1;
	}

	if (target < table[midY][midX]) 
		// Refer to the picture in the diagram. All search calls must have at least a decrease or an increase in the elements 
		return search(target, table, startX, startY, midX-1, endY) || search(target, table, midX, startY, endX, midY-1) || search(target, table, midX+1, midY, endX, midY);
	else 
		return search(target, table, midX, startY, endX, midY-1) || search(target, table, startX, midY+1, endX, endY) || search(target, table, midX+1, midY, endX, midY);
}