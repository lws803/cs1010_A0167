// Graph maker - this graph maker converts your long chain of crappy graphs to a nice matrix representation
// Precond: All vertices must be converted to int numbers starting from 0 


#include "stdio.h"
#define MAX 100

void print_result (int[][MAX], int ); 
void get_edges (int [][MAX], int );
int get_vertices (int [][MAX]); 



int main(int argc, char const *argv[])
{
	int arr[MAX][MAX] = {0};
	int size = get_vertices (arr);

	get_edges(arr, size);
	print_result(arr, size);
	return 0;
}



int get_vertices (int arr[][MAX]) {
	int size;
	printf("Enter number of vertices: ");
	scanf ("%d", &size);
	return size;
}

void get_edges (int arr[][MAX], int size) {
	int i ,d;
	// init
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			arr[i][d] = 0;
		}
	}
	for (i = 0; i < size; i++) {
		int x, num; 
		printf("vertice: %d enter num edges: ", i);
		scanf ("%d", &num);
		printf("Enter edges: \n");
		for (x = 0; x < num; x++) {
			int edge;
			scanf ("%d", &edge);
			arr[i][edge] = 1;
			arr[edge][i] = 1;
		}	
	}
}

void print_result (int arr[][MAX], int size) {
	int i, d;
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			printf("%d ", arr[i][d]);
		}
		printf("\n");
	}
}
