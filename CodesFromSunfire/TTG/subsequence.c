/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex2
 * subsequence.c
 * This program reads in a list of integers and find the
 * k-interval subsequence with the largest sum.
 * Tan Tze Guang
 * C06
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

//   This function reads the list of integers and evaluates each subsequence sum.
//   during the process of evaluating the sum, it will determine the greatest sum and store the value in the following manner:
//   where 	ans[0] = maximum sum of solution subsequence
//   		ans[1] = interval k of the solution subsequence
//   		ans[2] = start position of the solution subsequence
//   Precond: arr[] not empty, size > 0
void sum_subsequence(int arr[], int size, int ans[]) {
	int firstRun = 1;				//Used to assign the ans value to something that we can compare with. Not undefined.
	int sum;
	int i,j,q;
	
	for (i=1;i <= size;i++){		//loop through interval number
		for(j=0;j<i;j++){			//loop through the array for the new starting position
			sum=0;
			for (q=j;q<size;q+=i){
				if (q < size){		//loop through to get sum
					sum = sum + arr[q];
				}
			}
			if (sum > ans[0] && !firstRun){
				ans[0] = sum;
				ans[1] = i;
				ans[2] = j;
			}
			else if (firstRun){
				ans[0] = sum;
				ans[1] = i;
				ans[2] = j;
				firstRun = 0;
			}
		}
	}
}