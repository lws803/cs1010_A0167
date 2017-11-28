// We have to introduce digits to let the recursion functions count up
int recursion (int number) {
	int digits = 0; 
	if (number) {
		digits = recursion (number/10) + 1;
	}

	return digits;
}


// Precond: 1st number smaller than 2nd 
// In this case we do not need to add the numbers up, so no need to introduce a new variable 
int GCD (int num1, int num2) {
	if (num2 > 0) {
		return GCD(num2, num1%num2);
	}else{
		return num1;
	}
}

// This function rushes all the way to the back and then comapares one by one as it moves back up. 
int findLargest (int arr[], int size) {
	int largest = arr[size-1]; // We let largest be the current arr number first.
	if (size > 0) {
		int next = findLargest(arr, size-1); // Instead of starting from index 0, we moved all the way to the end first
		if (next > largest) {
			largest = next;
		}
	}
	return largest;
}

// Tower hopper question
int towerHop (int arr[], int i, int size) {
	// Exit cond
	if (i >= size) {
		return 1; // If the tower hopper hops out of the array size 
	}

	int possiblePaths = 0;

	for (int d = 1; d <= arr[i]; d++) {
		possiblePaths += towerHop (arr, i+d, size); // Try every possible paths starting from one step rom his current position
	}

	return possiblePaths;
}

// Recursive binary search
int recursive_binary_search(int arr[],int toFind,int start,int end){
    int mid = (start + end) / 2; 	// integer division
    if (start > end)
        return -1;  				// not found
    else if (arr[mid] == toFind) 	// if found
        return mid;
    else if (arr[mid] > toFind) 	// midpoint is greater than toFind, search lower half
        return recursive_binary_search(arr,toFind,start,mid-1);
    else 							// midpoint is  smaller than toFind, search upper half
        return recursive_binary_search(arr,toFind,mid+1,end);
}



// Flood fill algo, could've helped with PE2
void fill (char matrix[][MAX], int x, int y) {	
	matrix[y][x] = 'x';


	if (x+1 < MAX && matrix[y][x+1] != 'x')
		fill (matrix, x+1, y);
	if (x-1 >= 0 && matrix[y][x-1] != 'x')
		fill (matrix, x-1, y);
	if (y-1 >= 0 && matrix[y-1][x] != 'x')
		fill (matrix, x, y-1);
	if (y+1 < MAX && matrix[y+1][x] != 'x')
		fill (matrix, x, y+1);
}


// Permutation or possibility tree
// Can be applied to find number of possibilities or coupon questions

int header (int arr[], int size) {
	int i;
	int count = 0;
	for (i = 0; i < size; i++) {

		
		/**
		 * We can choose whether or not to do anything with the initial value here selected by the for loop before
		 * stepping.    
		*/


		// Start stepping from the index after the current one selected by the for loop.
		count += step (arr, i + 1, size);
	}
}

int step (int arr[], int index, int size) {
	// Terminations 
	if (NOT_GOOD) {
		// eg. -ve fuel, -ve money
		return -1;
	}
	if (VERY_GOOD) {
		// eg. reached destination, reached most optimum cash 
		return 1;
	}

	// Else we do not terminate first
	int count = 0; // Required to make sure that it returns something 

	for (i = index + 1; i < size; i++) { // To make sure that current index is not called again, we start from i = index + 1
		// Check ahead to make sure that the path is valid first 
		if (step (arr, i, size) != -1)
			count += step (arr, i, size);
	}

	return count; // Returns the number of possibilities 
}