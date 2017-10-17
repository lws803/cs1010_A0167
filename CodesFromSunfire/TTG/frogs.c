/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex3
 * frogs.c
 * This program creates a game of leap frogs on a bridge.
 * Tan Tze Guang
 * C06
 */
#include <stdio.h>

int jump(int, int, int[]);
void printBridge(int, int[]);
int checkGameState(int, int[]);
int search0(int[],int);

int main(void) {

	int bridge[1000];
	int i;
	int lengthOfBridge;
	int position;

	int numMoves = 0;
	int gameState;

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

	/** Insert your code below **/	
	while (!checkGameState(lengthOfBridge,bridge)){	// Checks the gamestate to determine if the game has ended.
		printf("Move the frog at position: ");
		scanf("%d",&position);
		if (jump(position,lengthOfBridge,bridge)){
			numMoves++;
			printBridge(lengthOfBridge,bridge);
		}
		else
			printf("Invalid move!\n");
	}
	gameState = checkGameState(lengthOfBridge,bridge);
	if (gameState==1){
		printf("Congratulations! The frogs took %d jumps to cross the bridge!\n",numMoves);
	}
	else {
		printf("Oh no! It seems like the two clans of frogs are stuck!\n");
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

//	Determine whether the game can continue.
//	gamestate 0:	Game can continue
//	gamestate 1:	Game ends as it has been completed
//	gamestate 2:	Game ends as there are no more moves left.
//	Precond: length > 0	
int checkGameState (int length, int arr[]) {
	int i, gameState = 1;
	for (i = 0; i < length-1; i++) {
		if (arr[i] > arr[i+1]) {
			gameState = 0;
		}
	}
	for (i = 0; i < length-1; i++) {
		if (arr[i] == 0) {
			if ((arr[i+1] != -1 && arr[i+2] != -1) && (arr[i-1] != 1 && arr[i-2] != 1)){
				if (gameState == 0) {
					gameState = 2;
				}
			}
		}
	}
	return gameState;
}

//Moves the frog if possible and returns the status of whether it managed to do any movement.
// 0 if there was no movement.
// 1 if there was.
//Precond: initial > 0, length > 0
int jump(int initial, int length, int arr[]){
	int temp;
	if (arr[initial] == 0){
		return 0;
	}
	else if(arr[initial]==1){		// Consider the frogs that move towards the right.
		if (arr[initial+1] == 0 && (initial+1)< length){	//Prevent the frogs from jumping off the bridge
			temp = arr[initial];
			arr[initial] = arr[initial+1];
			arr[initial+1] = temp;
		}
		else if (arr[initial+2]==0 && (initial+2)< length){
			temp = arr[initial];
			arr[initial] = arr[initial+2];
			arr[initial+2] = temp;
		}
		else
			return 0;
	}
	else if(arr[initial]==-1){		//Consider the frogs that move towards the left.
		if (arr[initial-1] == 0 && (initial-1)>=0){
			temp = arr[initial];
			arr[initial] = arr[initial-1];
			arr[initial-1] = temp;
		}
		else if (arr[initial-2]==0 && (initial-2)>=0){
			temp = arr[initial];
			arr[initial] = arr[initial-2];
			arr[initial-2] = temp;
		}
		else
			return 0;
	}
	return 1;
}