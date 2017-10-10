/**
 * rabbit.c 
 * A rabbit can jump at most 50 centimetres. It needs to cross a
 * river, with rocks positioned in a straight line in the river.
 * The program computes the minimum number of jumps for the rabbit
 * to cross to the other side of the river.
 */

#include <stdio.h>

int countJumps(int [], int);
void readRocks (int [], int);

int main(void) {
	int num_rocks, rocks[20] = {0};            // including opposite bank

	printf("Enter number of rocks: ");
	scanf("%d", &num_rocks);
	readRocks(rocks, num_rocks);

	printf("%d\n", countJumps(rocks, num_rocks));

	return 0;
}

// Counts the minimum number of jumps the rabbit needs
// to take to get to the other side of the river.
// Precond: size > 0
int countJumps(int rocks[], int size) {
	int jumps = 0, i = 0, currentPos = 0, d;

	while (currentPos < rocks[size-1]) {
		if (rocks[i] - currentPos > 50) {
			return -1;
		}

		for (d = i + 1; d < size && rocks[d] - currentPos <= 50; d++);

		i = --d;
		currentPos = rocks[d];
		jumps++;
	}
	

	return jumps; // this is just a stub; replace it with the correct value
}

void readRocks (int rocks[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		scanf("%d", &rocks[i]);
	}
}