#include <stdio.h>

int main(void){
	int arr[] = {32,43,65,432,45,64,21,54};
	int size = 8;
	int i,j,temp;
	
	for (i=0;i<size;i++){
		temp = arr[i];
		j = i-1;
		while ((j>=0) && (temp<arr[j])){
			arr[j+1] = arr[j];		// Only does one assignment each time it looks for the space for the element.
			j--;
		}
		arr[j+1] = temp; 			// Once it finds the location then assign. FASTER than doing swapping as swapping does 3 actions each time.
	}
	for (i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}