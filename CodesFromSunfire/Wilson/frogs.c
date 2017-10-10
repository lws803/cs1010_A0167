/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex3
 * frogs.c
 * <Frogs crossing a bridge>
 * <Ler Wei Sheng>
 * <C04>
 */
#include <stdio.h>

int jump(int, int, int[]);
void printBridge(int, int[]);
int checkGameState(int, int[]);
int checkGameState_possibleMoves (int, int[]);

int main(void) {

	int bridge[1000];
	int i;
	int lengthOfBridge;
	int position;

	int numMoves = 0;

	printf("Please enter the length of the bridge: ");
	scanf("%d", &lengthOfBridge);

 	for (i=0; i<lengthOfBridge; i++) {
		int frogType;

		printf("Please insert frogs at position %d: ", i);
		scanf("%d", &frogType);

		bridge[i] = frogType;
	}

	printf("Input completed\n");
	printBridge(lengthOfBridge, bridge);

	printf("Please start moving the frogs\n");

	while(!checkGameState(lengthOfBridge, bridge)) {
		printf("Move the frog at position: ");
		scanf("%d", &position);

		if (jump(position, lengthOfBridge, bridge)) {
			numMoves++;
			printBridge(lengthOfBridge, bridge);
		}else{
			printf("Invalid move!\n");
		}

	}

	if (checkGameState(lengthOfBridge, bridge) == 2) {
		printf("Oh no! It seems like the two clans of frogs are stuck!\n");

	}else if (checkGameState(lengthOfBridge, bridge) == 1) {
		printf("Congratulations! The frogs took %d jumps to cross the bridge!\n", numMoves);
	}


	return 0;
}

//This function is provided for you
/**
 * Prints out the current state on the bridge
 * @param size (int) represents the size of bridge
 * @param bridge[] contains the current state of the bridge
 **/
void printBridge(int size, int bridge[]) {

	int i;
	printf("Position: ");
	for (i=0; i<size; i++) {
		printf("%2d ", i);
	}
	printf("\n");

	printf("Bridge:   ");
	for (i=0; i<size; i++) {
		printf("%2d ", bridge[i]);
	}
	printf("\n");
}

/* 
This function moves the frogs and gives an invalid return if the move cannot be done
*/


int jump (int position, int len, int arr[]) {
	int t;
	if (arr[position] == 1) {
		if (arr[position + 1] == 0) {
			t = arr[position + 1];
			arr[position + 1] = arr[position];
			arr[position] = t;
		}else if (arr[position + 2] == 0) {
			t = arr[position + 2];
			arr[position + 2] = arr[position];
			arr[position] = t;
		}else {
			return 0;
		}
	}else if (arr[position] == -1) {
		if (arr[position - 1] == 0) {
			t = arr[position - 1];
			arr[position - 1] = arr[position];
			arr[position] = t;
		}else if (arr[position - 2] == 0) {
			t = arr[position - 2];
			arr[position - 2] = arr[position];
			arr[position] = t;
		}else {
			return 0;
		}
	}else if (arr[position] == 0) {
		return 0;
	}
	return 1;
}

/* 
This function checks to see if the game can still continue. If checkstate is 0, 
game can still continue. 

if check state is 1, game succeeds 

if check state is 2, game is stuck.
precond: none 
*/

int checkGameState (int len, int arr[]) {
	int i, gamestate = 1;

	for (i = 0; i < len-1; i++) {
		if (arr[i] > arr[i+1]) {
			gamestate = 0;
		}
	}

	// Pinpoint '0' and find anymore possible moves 
	for (i = 0; i < len-1; i++) {
		if (arr[i] == 0) {
			if ((arr[i+1] != -1 && arr[i+2] != -1) && (arr[i-1] != 1 && arr[i-2] != 1)){
				if (gamestate == 0) {
					gamestate = 2;
				}
			}
		}
	}

	

	return gamestate;
}


// Another method of checking stuck state 
// 1 means got possible moves, 0 means no possible moves
int checkGameState_possibleMoves (int len, int arr[]) {
	int arr2[1000], i, d;
	// Brute force and check for all possible moves 

	// First copy the old array into the new array 
	for (i = 0; i < len; i++){
		arr2[i] = arr[i];
	}

	for (d = 0; d <= len && !jump(d, len, arr2); d++) {
		// If all attempts have failed
		if (d == len) {
			return 0;
		}
	}

	return 1;
}
