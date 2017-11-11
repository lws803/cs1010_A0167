// BFS
#include "stdio.h"
#define MAX 100

int get_matrix (int arr[][MAX], int size); 
void bfs (int [][MAX], int , int [], int , int [], int *);
int pop (int arr[], int atIndex, int size) ;
int insert (int [], int , int , int );
int visited_func (int [], int , int ); 

int main(int argc, char const *argv[])
{
	
	int queue[MAX], queue_size = 0, visited[MAX], visited_size = 0;
	int arr[MAX][MAX];
	int size = get_matrix(arr, size); 
	printf("Enter first element to queue: ");
	scanf("%d", &queue[0]);
	queue_size = 1;

	bfs (arr, size, queue, queue_size, visited, &visited_size);

	int i;
	printf("Elements visited: \n");
	for (i = 0; i < visited_size; i++) {
		printf("%d ", visited[i]);
	}
	printf("\n");

	return 0;
}

int get_matrix (int arr[][MAX], int size) {
	int i ,d;
	printf("Enter size: ");
	scanf ("%d", &size);
	printf("Enter matrix: \n");
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			scanf ("%d", &arr[i][d]);
		}
	}
	return size;
}

void bfs (int arr[][MAX], int size, int queue[], int queue_size, int visited[], int *size_visited) {
	int visited_size = 0;
	while (queue_size > 0) {
		// visited 
		/**
		// Visual representation of what the queue looks like 
		for (int i = 0; i < queue_size; i++) {
			printf("%d ", queue[i]);
		}
		printf("\n");
		*/ 
		int target = queue[0], d;
		queue_size = pop (queue, 0, queue_size);
		visited_size = insert(visited, target, visited_size, visited_size); // marking it as visited

		
		for (d = 0; d < size; d++) {
			if (arr[target][d] == 1 && !visited_func(visited, d, visited_size) && !visited_func(queue, d, queue_size)) {
				queue_size = insert (queue, d, queue_size, queue_size); // insert at the back to queue
			}
		}
	}
	*size_visited = visited_size;
}

int pop (int arr[], int atIndex, int size) {
    int i;
    for (i = atIndex; i < size; i++) {
        arr[i] = arr[i+1];
    }
    size--;
    return size;
}

int insert (int arr[], int element, int atIndex, int size) {
    int i;
    for (i = size-1; i >= atIndex; i--) {
        arr[i+1] = arr[i];
    }
    arr[atIndex] = element;
    size++;
    return size;
}

int visited_func (int arr[], int target, int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (arr[i] == target) {
			return 1;
		}
	}
	return 0;
}