// validPath.c
#include <stdio.h>
#include <string.h>

#define SIZE 6     // size (number of rows and columns) of maze
#define WALL 0
#define CELL 1
#define MAX_PATHLEN 10

void readMaze(int [][SIZE], int);
int isValid(int [][SIZE], char []);
int checker(int [][SIZE], int, int);

int main(void) {
	int maze[SIZE][SIZE];
	char path[MAX_PATHLEN+1] = {0};

	readMaze(maze, SIZE); 

	printf("Enter path: ");
	scanf("%s", path);

	if (isValid(maze, path))
		printf("Path is valid.\n");
	else
		printf("Path is not valid.\n");

	return 0;
}

// Create the maze
void readMaze(int maze[][SIZE], int size) {
	int	r, c;

	printf("Enter maze:\n");
	for (r=0; r<size; r++)
		for (c=0; c<size; c++)
			scanf("%d", &maze[r][c]);
}

// Determine whether input path is valid in input maze
int isValid(int maze[][SIZE], char path[]) {
	int pathlen, i;
	int x = 0, y = 0;

	pathlen = strlen(path);


	for (i = 0; path[i] != '\0'; i++){
		switch (path[i]){
			case 'N':
			y -= 1;
			break;
			case 'S':
			y += 1;
			break;
			case 'E':
			x += 1;
			break;
			case 'W':
			x -= 1;
			break;
		}
		if (!checker(maze, x, y)){
			return 0;
		}
	}
	return 1; // this is a stub
}

int checker(int maze[][SIZE], int x, int y) {
	if (x > SIZE - 1 || x < 0){
		return 0;
	}
	else if (y > SIZE - 1 || y < 0){
		return 0;
	}
	else if (maze[y][x] == 0){
		return 0;
	}

	return 1;
}
