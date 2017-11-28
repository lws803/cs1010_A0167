#include "stdio.h"

int main(int argc, char const *argv[])
{
	int arr[7] = {1,6,10,11,14,20,22};

	int target = 30;
	int start = 0, end = 6, mid;
	int count = 0;
	while (start <= end) { // Common mistake, we need to have start <= end
		count++;
		mid = (start+end)/2;
		if (arr[mid] == target) break;

		if (arr[mid] > target) {
			end = mid - 1; // Note that we need to ignore mid by adjust end to be one element less than mid
		}
		if (arr[mid] < target) {
			start = mid + 1; // or more than mid for start 
		}
	}
	printf("%d\n", count);
	return 0;
}