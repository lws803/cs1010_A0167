#include <stdio.h>
#define MAX_ROW 100
#define MAX_COL 100

int main(){
	int row, col, level, i, j;
	int land[MAX_ROW][MAX_COL];
	
	printf("Enter dimensions of the land: ");
	scanf("%d %d",&row,&col);
	
	printf("Enter elevations: \n");
	
	for(i=0;i<row;i++) 
		for(j=0;j<col;j++) 
			scanf("%d",&land[i][j]);
	
	printf("Enter flood level: ");	
	scanf("%d",&level);
	
	printf("Number of robots to be rescued: \n") // Incomplete
	
	return 0;
}