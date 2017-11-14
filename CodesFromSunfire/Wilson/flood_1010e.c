#include "stdio.h"
#include "ctype.h"
#define MAX 10 

int read (char [][MAX]);
void flood (char [][MAX], int, int, int); 
void print_array (char [][MAX]);
void count_area (char [][MAX], int*, int *); 
int search_surrounding (char [MAX][MAX], int, int); 

int main () {
	char arr [MAX][MAX];
	int flood_level = read(arr);
	int i, d, perimeter, area;

	for (i = 0; i < MAX; i+= 9) {
		for (d = 0; d < MAX; d++) {
			if (arr[i][d] - '0' <= flood_level) {
				flood (arr, flood_level, d, i);
			} 
		}
	}
	for (i = 0; i < MAX; i+= 9) {
		for (d = 0; d < MAX; d++) {
			if (arr[d][i] - '0' <= flood_level) {
				flood (arr, flood_level, i, d);
			} 
		}
	}
	count_area (arr, &area, &perimeter);
	printf("Flooded city: \n");
	print_array(arr);
	printf("area = %d perimeter = %d\n", area, perimeter);

}

int read (char arr[][MAX]) {
	int i, d, flood;
	printf("Enter flood level: ");
	scanf ("%d", &flood);
	for (i = 0; i < MAX; i++) {
		for (d = 0; d < MAX; d++) {
			scanf (" %c", &arr[i][d]);
		}
	}
	return flood;
}

void flood (char arr[][MAX], int flood_level, int x, int y) {
	arr[y][x] = '*';
	if (y + 1 < MAX && arr[y+1][x] - '0' <= flood_level && arr[y+1][x] != '*') {
		flood (arr, flood_level, x, y+1);
	}	
	if (x + 1 < MAX && arr[y][x+1] - '0' <= flood_level && arr[y][x+1] != '*') {
		flood(arr, flood_level, x+1, y);
	}
	if (x - 1 >= 0 && arr[y][x-1] - '0' <= flood_level && arr[y][x-1] != '*') {
		flood(arr, flood_level, x-1, y);
	}
	if (y - 1 >= 0 && arr[y-1][x] - '0' <= flood_level && arr[y-1][x] != '*') {
		flood(arr, flood_level, x, y-1);
	}
}

void print_array (char arr[][MAX]) {
	int i, d;
	for (i = 0; i < MAX; i++) {
		for (d = 0; d < MAX; d++) {
			printf("%c", arr[i][d]);
		}
		printf("\n");
	}
}

void count_area (char arr[][MAX], int *area , int *perimeter) {
	int i, d, count = 0, param = 0; 
	for (i = 0 ; i < MAX; i++) {
		for (d = 0; d < MAX; d++) {
			if (arr[i][d] != '*') {
				count++;
				param += search_surrounding(arr, d, i);
			}
		}
	}
	*area = count;
	*perimeter = param;
}

int search_surrounding (char arr[MAX][MAX], int x, int y) {
	int i, d, count = 0;
	if (arr[y][x+1] == '*' || x+1 >= MAX) count++;
	if (arr[y][x-1] == '*' || x-1 < 0) count++;
	if (arr[y+1][x] == '*' || y+1 >= MAX) count++;
	if (arr[y-1][x] == '*' || y-1 < 0) count++;
	return count;
}