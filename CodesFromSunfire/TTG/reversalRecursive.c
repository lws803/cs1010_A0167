#include <stdio.h>
#define MAX 10
int main(){
	int arr[MAX] = {0,1,2,3,4,5,6,7,8,9};
	int i=0;
	int j = reversal(arr,-1,MAX);
	for (i=0;i<MAX;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void reversal(int arr[],int i, int j){
    int temp;
	if (i<j){
        reversal(arr,++i,--j);
        temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	else
		return;
}

void reverse(int arr[],int size){
	if (size <= 1)
		return;
	else{
		int temp = arr[0];
		arr[0] = arr[size-1];
		arr[size-1] = temp;
		reverse[++arr[],size-2];
	}
}