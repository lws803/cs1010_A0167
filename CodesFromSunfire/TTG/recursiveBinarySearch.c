#include <stdio.h>

int recursive_binary_search(int[],int,int,int);

int main(void){
	int arr[] = {23,45,67,89,10034,20043,60000};
	int size = 7;
	int toFind = 23;
	int pos = recursive_binary_search(arr,toFind,0,size-1);
	
	printf("The integer %d is found at position %d of the array\n",toFind,pos);
}

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