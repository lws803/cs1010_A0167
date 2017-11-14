#include "stdio.h"
#define MAX 1000
#define MERGE_MAX 2000

void print_arr (int [], int ); 
void read_files (int [], int [], int *, int *) ;
int merge (int [], int [], int , int , int []) ;
void insertionSort (int [], int ) ; 

int main(int argc, char const *argv[])
{
	int arr1[MAX], arr2[MAX], arr3[MERGE_MAX];
	int size1, size2, size3; 

	read_files(arr1, arr2, &size1, &size2);
	size3 = merge(arr1, arr2, size1, size2, arr3);
	print_arr (arr3, size3);
	return 0;
}


int merge (int arr1[], int arr2[], int size, int size2, int arr3[]) {
	int i, new_size = size+size2, index = 0; 
	char str[50];
	FILE *outfile;
	for (i = 0; i < size; i++) {
		arr3[index++] = arr1[i];
	}
	for (i = 0; i < size2; i++) {
		arr3[index++] = arr2[i];
	}
	insertionSort(arr3, new_size);
	printf("Enter output file for merged list: ");
	scanf("%s", str);
	outfile = fopen (str, "w");
	fprintf(outfile, "%d\n", new_size);
	for (i = 0; i < new_size; i++) {
		fprintf(outfile, "%d\n", arr3[i]);
	}
	return new_size;
}


void read_files (int arr1[], int arr2[], int *size1, int *size2) {
	FILE *infile;
	char str[50];
	int i;

	printf("Enter input file for 1st list: ");
	scanf ("%s", str);
	if ((infile = fopen(str, "r")) == NULL) {
		printf("File does not exist\n");
		return;
	}
	fscanf(infile, "%d", size1);
	for (i = 0; i < *size1; i++) {
		fscanf(infile, "%d", &arr1[i]); // Note that calling fscanf here again wont start from the top!
	}
	fclose (infile);

	printf("Enter input file for 2nd list: ");
	scanf ("%s", str);

	if ((infile = fopen(str, "r")) == NULL) {
		printf("File does not exist\n");
		return;
	}
	fscanf(infile, "%d", size2);
	for (i = 0; i < *size2; i++) {
		fscanf(infile, "%d", &arr2[i]); // Note that calling fscanf here again wont start from the top!
	}
	fclose (infile);
}

void print_arr (int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void insertionSort (int arr[], int n) {
	int d, c, t;
	for (c = 0; c < n; c++){
		d = c;
		while (d > 0 && arr[d] < arr[d-1]){
			t = arr[d];
			arr[d] = arr[d-1];
			arr[d-1] = t;

			d--;
		}
	}
}