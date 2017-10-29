#include <stdio.h>

void print (int[][20], int);
int fill (int [][20], int);

int main () {
	int n;
	int arr[20][20];
	
	printf ("Enter n: ");
	scanf ("%d", &n);
	fill (arr, n);
	print (arr, n);
}

int fill (int arr[][20], int n) {
	int i;
	// Termination
	if (n == 1) {
		arr[0][0] = 1;
		return 0;
	}	
	// Traverse southwards
	for (i = 0; i < n; i++) {
		arr[i][n-1] = n;
	} 
	// Traverse west
	for (i = n - 1; i >= 0; i--) {
		arr[n-1][i] = n;
	} 

	return fill (arr, --n);	

}

void print (int arr[][20], int n) {
	int i, d;
	for (i = 0; i < n; i++) {
		for (d = 0; d < n; d++) {
			printf ("%2d ", arr[i][d]);
		}
		printf ("\n");
	}
}
