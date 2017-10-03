/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex2
 * subsequence.c
 * This program reads in a list of integers and find the
 * k-interval subsequence with the largest sum.
 * <Ler Wei Sheng>
 * <C04>
 */

#include <stdio.h>

int scan_list(int []);
void sum_subsequence(int [], int, int []);

int main(void) {
	int list[10], size; // array and actual number of elements entered
	int answers[3];     // stores the required answers

	size = scan_list(list); 

	sum_subsequence(list, size, answers);

	printf("Max sum %d of %d-interval subsequence starting at position %d.\n",
			answers[0], answers[1], answers[2]);

	return 0;
}

// Read in elements for the array arr and returns the 
// number of elements read.
// Postcond: i > 0
int scan_list(int arr[]) {
	int num, i;

	printf("Enter number of elements: ");
	scanf("%d", &num);
	printf("Enter %d element%s: ", num, (num>1)?"s":"");
	for (i=0; i<num; i++) {
		scanf("%d", &arr[i]);
	}

	return num;
}

// Write a description for this function below
// Adds the numbers in each sub sequence and compares them to see which is bigger
// Then report back the ans with the highest sum 
//   ans[0] = maximum sum of solution subsequence
//   ans[1] = interval k of the solution subsequence
//   ans[2] = start position of the solution subsequence
void sum_subsequence(int arr[], int size, int ans[]) {
	int first_run = 1;
	// fill in the code
	int c, i, sum, d;
	// Subsequence 
	for (c = 1; c <= size; c++) {
		// Starting positions 
		for (i = 0; i < c; i++) {
			sum = 0;
			// Summing up loop
			for (d = i; d < size; d+= c) {
				sum += arr[d];
				
			}
			if (sum > ans[0] && !first_run) {
				ans[0] = sum;
				ans[1] = c;
				ans[2] = i;
			}else if (first_run){
				ans[0] = sum;
				ans[1] = c;
				ans[2] = i;
				first_run = 0;
			}
		}
		
	}
}
