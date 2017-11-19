// From CS1010 Finals 

#include "stdio.h"

int determinant (int [][10], int ); 
int readMtx (int [10][10]); 


int main(int argc, char const *argv[])
{
	int mtx[10][10];
	int size = readMtx(mtx);

	printf("%d\n", determinant(mtx, size));

	return 0;
}


int readMtx (int mtx[10][10]) {
	int size;
	scanf ("%d", &size);
	for (int i = 0; i < size; i++) {
		for (int d = 0; d < size; d++) {
			scanf("%d", &mtx[i][d]);
		}
	}
	return size;
}


int determinant (int mtx[][10], int size) {
	int sum = 0;
	if (size > 2) {
		int i, d, c;
		for (c = 0; c < size; c++) {
			printf("%d\n", mtx[0][c]);
			int arr[10][10] = {{0}}; // do not use a variable size arr eg. arr[size][size] even for this situation
			for (i = 1; i < size; i++) {
				int index = 0;
				for (d = 0; d < size; d++) {
					if (d != c) {
						arr[i-1][index++] = mtx[i][d];
					}
				}
			}
			if (c%2) {
				sum -= determinant(arr, size-1)*mtx[0][c];
			}else{
				sum += determinant(arr, size-1)*mtx[0][c];
			} 
		}
	}else {
		return mtx[0][0]*mtx[1][1] - mtx[0][1]*mtx[1][0];
	}
	return sum;
}