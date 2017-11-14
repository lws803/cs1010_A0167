#include "stdio.h"
#define MAX 11 

struct coords_t{
	int x;
	int y;
	struct coords_t *p;
};

void scan_maze (char [][MAX]); 
void print_maze (char [][MAX]) ; 
void bfs (char [][MAX], struct coords_t [], struct coords_t [], int * , int *, struct coords_t) ; 
int pop (struct coords_t [], int ) ; 
int push (struct coords_t [], struct coords_t , int ); 
int contains(struct coords_t [], int , int , int ) ; 
void scan_neighbours (char [][MAX], struct coords_t [], struct coords_t [], int *, int *, struct coords_t ); 
void traverse (char [][MAX], struct coords_t [], int *, struct coords_t ) ; 
void start_end_scan (struct coords_t *, char [][MAX]) ; 

int main(int argc, char const *argv[])
{
	struct coords_t start;
	char maze[MAX][MAX];
	int open_sized = 0, closed_size = 0;
	struct coords_t open[MAX*MAX], closed[MAX*MAX];

	scan_maze(maze);
	printf("Maze input: \n");
	print_maze(maze);

	start_end_scan (&start, maze);

	bfs(maze, open, closed, &open_sized, &closed_size, start);

	traverse (maze, closed, &closed_size, start);

	print_maze(maze);
	return 0;
}


void scan_maze (char maze[][MAX]) {
	int i;
	for (i = 0; i < MAX; i++) {
		scanf("%s", maze[i]);
	}
}

void print_maze (char maze[][MAX]) {
	int i,d;
	for (i = 0; i < MAX; i++) {
		for (d = 0; d < MAX; d++) {
			printf ("%c", maze[i][d]);
		}
		printf("\n");
	}
}

void start_end_scan (struct coords_t *start, char maze[][MAX]) {
	int i, d;
	for (i = 0; i < MAX; i++) {
		for (d = 0; d < MAX; d++) {
			if (maze[i][d] == 's') {
				start-> x = d;
				start-> y = i;
			}
			
		}
	}
}

void traverse (char maze[][MAX], struct coords_t closed[], int *closed_size, struct coords_t start) {
	int i;
	struct coords_t trace;
	for (i = 0; i < *closed_size; i++) {
		// Shd be the last element of closed 
		if (maze[closed[i].y][closed[i].x] == 'e') {
			trace = closed[i];
		}
	}
	for (i = 0; i < *closed_size; i++) {
		maze[closed[i].y][closed[i].x] = '*';
	}
	
	// TODO: Add the ability to traceback, gotta fix the linked list of coords_t
}

void bfs (char maze[][MAX], struct coords_t open[], struct coords_t closed[], int *open_sized, int *closed_size, struct coords_t start) {
	int i, d;
	*open_sized = push(open, start, *open_sized);
	while (*open_sized > 0) {
		struct coords_t current = open[0];
		*closed_size = push (closed, current, *closed_size); 
		*open_sized = pop (open, *open_sized);

		scan_neighbours (maze, open, closed, open_sized, closed_size, current);
	}	

}

void scan_neighbours (char maze[][MAX], struct coords_t open[], struct coords_t closed[], int *open_sized, int *closed_size, struct coords_t current) {
	int x = current.x, y = current.y;
	// Pushes the new coords into open 
	if (y+1 < MAX && maze[y+1][x] != '@' && !contains(open, *open_sized, x, y+1) && !contains(closed, *closed_size, x, y+1)) {
		struct coords_t element;
		element.x = x;
		element.y = y+1;
		element.p = &current;
		*open_sized = push(open, element, *open_sized);
	}
	if (y-1 >= 0 && maze[y-1][x] != '@' && !contains(open, *open_sized, x, y-1) && !contains(closed, *closed_size, x, y-1)) {
		struct coords_t element;
		element.x = x;
		element.y = y-1;
		element.p = &current;
		*open_sized = push(open, element, *open_sized);
	}
	if (x+1 < MAX && maze[y][x+1] != '@' && !contains(open, *open_sized, x+1, y) && !contains(closed, *closed_size, x+1, y)) {
		struct coords_t element;
		element.x = x+1;
		element.y = y;
		element.p = &current;
		*open_sized = push(open, element, *open_sized);
	}
	if (x-1 >= 0 && maze[y][x-1] != '@' && !contains(open, *open_sized, x-1, y) && !contains(closed, *closed_size, x-1, y)) {
		struct coords_t element;
		element.x = x-1;
		element.y = y;
		element.p = &current;
		*open_sized = push(open, element, *open_sized);
	}

}

int pop (struct coords_t arr[], int size) {
    int i;
    for (i = 0; i < size - 1; i++) {
        arr[i] = arr[i+1];
    }
    size--;
    return size;
}

// Push it in the tail
int push (struct coords_t arr[], struct coords_t element, int size) {
    arr[size] = element;
    size++;
    return size;
}

int contains(struct coords_t arr[], int size, int x, int y) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i].x == x && arr[i].y == y) {
            return 1;
        }
    }
    return 0;
}