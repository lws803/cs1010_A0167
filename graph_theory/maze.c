// Maze solver - A* algorithm (Courtest of Marcus's lab question)
#include "stdio.h"
#include "string.h"
#include "math.h"
#define MAX 11

typedef struct 
{
	int x; 
	int y;
	double g_cost;
	double h_cost;
	int parent_x;
	int parent_y;
}coords_t;

void scan_maze (char [][MAX]);
void print_maze (char [][MAX]);
void start_end_scan (coords_t *, coords_t *, char [][MAX]); 
int insert (coords_t [], coords_t , int , int ); 
int pop (coords_t [], int , int, int ); 
void scan_neighbours (coords_t [], coords_t [], int *, int *, char [][MAX], coords_t , coords_t , coords_t );
int contains(coords_t [], int , int , int ) ; 
void pathfinder (coords_t [], coords_t [], coords_t , coords_t , int *, int *, char [][MAX]); 

int main(int argc, char const *argv[])
{
	coords_t open [MAX*MAX]; // Queue of nodes to visit 
	coords_t closed [MAX*MAX]; // Means visited nodes 
	coords_t start, end;

	int open_size = 0;
	int closed_size = 0;

	char maze[MAX][MAX];

	scan_maze(maze);

	printf("Maze input: \n");
	print_maze(maze);

	start_end_scan (&start, &end, maze);
	printf("start: %d %d end: %d %d\n", start.x, start.y, end.x, end.y);

	scan_neighbours (open, closed, &open_size, &closed_size, maze, start, start, end);
	//printf("%d\n", open_size);
	//printf("%lf %lf\n", open[0].g_cost, open[0].h_cost);

	pathfinder(open, closed, start, end, &open_size, &closed_size, maze);

	// Traceback
	int trace_x = end.x, trace_y = end.y; 
	maze[end.y][end.x] = '*';
	while (trace_x != start.x || trace_y != start.y) {
		// Continue tracing 
		int i; 
		for (i = 0; i < closed_size; i++) {
			if (closed[i].x == trace_x && closed[i].y == trace_y) {
				trace_x = closed[i].parent_x;
				trace_y = closed[i].parent_y;
				maze[trace_y][trace_x] = '*';
				break;
			}
		}
	}
	printf("Shortest path: \n");
	print_maze (maze);

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
double cartesian_count (int x, int y, int x_target, int y_target) {
	double difference_x = x - x_target;
	double difference_y = y - y_target;
	return sqrt (difference_x*difference_x + difference_y*difference_y);
}

void start_end_scan (coords_t *start, coords_t *end, char maze[][MAX]) {
	int i, d;
	for (i = 0; i < MAX; i++) {
		for (d = 0; d < MAX; d++) {
			if (maze[i][d] == 's') {
				start-> x = d;
				start-> y = i;
			}
			if (maze[i][d] == 'e') {
				end-> x = d;
				end-> y = i;
			}
		}
	}
}

void pathfinder (coords_t open[], coords_t closed[], coords_t start, coords_t end, int *open_size, int *closed_size, char maze[][MAX]) {
	// Can only travel 4 directions 
	while (*open_size > 0) {
		coords_t current = open[0];
		int i;
		for (i = 0; i < *open_size; i++) {
			if (current.h_cost + current.g_cost > open[i].h_cost + open[i].g_cost) {
				current = open[i]; // Set current to node with the lowest f_cost 

			}else if (current.h_cost + current.g_cost == open[i].h_cost + open[i].g_cost && 
				current.h_cost > open[i].h_cost) {
				// If they have the same f_cost 
				current = open[i];
			}
		}
		//printf("Open: %d %d\n", current.x, current.y);

		*closed_size = insert (closed, current, *closed_size, *closed_size);
		*open_size = pop (open, current.x, current.y , *open_size);


		if (current.x == end.x && current.y == end.y) {
			return; // Path has been found 
		}
		scan_neighbours(open, closed, open_size, closed_size, maze, current, start, end);
	}

}

void scan_neighbours (coords_t open[], coords_t closed[], int *open_size, int *closed_size, char maze[][MAX], 
	coords_t current, coords_t start, coords_t end) {
	// TODO: Finish up the scanning for shortest path 
	int y = current.y, x = current.x;
	if (y+1 < MAX) {
		if (!contains(open, *open_size, x, y+1) && !contains (closed, *closed_size, x, y+1) && maze[y+1][x] != '@') {
			coords_t neighbour = {x, y+1, cartesian_count(x, y+1, start.x, start.y), cartesian_count(x, y+1, end.x, end.y)};
			neighbour.parent_x = current.x; // Make sure they remember their parent 
			neighbour.parent_y = current.y;
			*open_size = insert(open, neighbour, *open_size, *open_size);
		}
	}
	if (y-1 >= 0) {
		if (!contains(open, *open_size, x, y-1) && !contains (closed, *closed_size, x, y-1) && maze[y-1][x] != '@') {
			coords_t neighbour = {x, y-1, cartesian_count(x, y-1, start.x, start.y), cartesian_count(x, y-1, end.x, end.y)};
			neighbour.parent_x = current.x;
			neighbour.parent_y = current.y;
			*open_size = insert(open, neighbour, *open_size, *open_size);
		}
	}
	if (x-1 >= 0) {
		if (!contains(open, *open_size, x-1, y) && !contains (closed, *closed_size, x-1, y) && maze[y][x-1] != '@') {
			coords_t neighbour = {x-1, y, cartesian_count(x-1, y, start.x, start.y), cartesian_count(x-1, y, end.x, end.y)};
			neighbour.parent_x = current.x;
			neighbour.parent_y = current.y;
			*open_size = insert(open, neighbour, *open_size, *open_size);
		}
	}
	if (x+1 < MAX) {
		if (!contains(open, *open_size, x+1, y) && !contains (closed, *closed_size, x+1, y) && maze[y][x+1] != '@') {
			coords_t neighbour = {x+1, y, cartesian_count(x+1, y, start.x, start.y), cartesian_count(x+1, y, end.x, end.y)};
			neighbour.parent_x = current.x;
			neighbour.parent_y = current.y;
			*open_size = insert(open, neighbour, *open_size, *open_size);
		}
	}
}

int contains(coords_t arr[], int size, int x, int y) {
	int i;
	for (i = 0; i < size; i++) {
		if (arr[i].y == y && arr[i].x == x) {
			return 1;
		}
	}
	return 0;
}

int insert (coords_t arr[], coords_t element, int atIndex, int size) {
    int i;
    for (i = size-1; i >= atIndex; i--) {
        arr[i+1] = arr[i];
    }
    arr[atIndex] = element;
    size++;
    return size;
}

// To pop an element from a specified index

int pop (coords_t arr[], int x, int y, int size) {
    int i, atIndex;
    // To search
    for (i = 0; i < size; i++) {
    	if (arr[i].x == x && arr[i].y == y) {
    		atIndex = i;
    	}
    }
    // Then pop 
    for (i = atIndex; i < size; i++) {
        arr[i] = arr[i+1];
    }
    size--;
    return size;
}
