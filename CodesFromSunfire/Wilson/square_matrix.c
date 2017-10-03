#include <stdio.h>
#define max 10


int upper_triangle (int[][max], int);
int diag_checker(int[][max], int);

int main () {
	int arr[max][max];
	int size;

	int arr2[][max] = {{2, -1, 3, 4, 1},{0, 7, 5, -2, 0},{0,0,6,0,4},{0,0,0,0,8},{0,0,0,0,2}};
	int size2 = 5;

	printf("Enter n: ");
	scanf("%d", &size);
	printf("Enter matrix: \n");
	int i, d;
	for (i = 0; i < size; i++){
		for (d = 0; d < size; d++){
			scanf("%d", &arr[i][d]);
		}
	}
	if (diag_checker(arr, size) && upper_triangle(arr, size)){
		printf("Matrix is a diagonal matrix\n");
	}else if (upper_triangle(arr, size)){
		
		printf("Matrix is an upper triangular matrix\n");
	}

	return 0;
}


int diag_checker(int arr[][max], int size) {
	int i, d, c = 1;
	for (i = 0; i < size; i++) {
		for (d = c; d < size; d++){
			if (arr[i][d] != 0){
				return 0;
			}
		}
		for (d = (c - 2); d >= 0; d-- ){
			if (arr[i][d] != 0) {
				return 0;
			}
		}
		c++;
	}
	return 1;
}

int upper_triangle (int arr[][max], int size) {
	
	int i, d, c = 0;
	for (i = 0; i < size; i++) {
		for (d = (c - 1); d >= 0; d-- ){
			if (arr[i][d] != 0) {
				return 0;
			}
		}
		c++;
	}
	return 1;
}

