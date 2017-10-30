// CS1010 AY2015/6 Semester 2 PE2 Ex1
//
// minefield.c
//
// Name:
// Matriculation number:
// plab-id:
// Discussion group:
// Description:

#include <stdio.h>
#define MAX_SIZE 10

int readField(int [][MAX_SIZE]);
void printField(int [][MAX_SIZE], int);
void detonate(int [][MAX_SIZE],int [][MAX_SIZE],int *, int *, int);
void explode(int [][MAX_SIZE],int,int,int,int);

int main(void) {
	int field[MAX_SIZE][MAX_SIZE] = {{0}}, aftermath[MAX_SIZE][MAX_SIZE] = {{0}};
	int size;
	int maxDamage=0,safeArea=0;

	size = readField(field);
	detonate(field,aftermath,&maxDamage,&safeArea,size);

	printf("Aftermath: \n");
	printField(aftermath, size);

	printf("Maximum damage: %d\n",maxDamage); // Incomplete
	printf("Number of safe areas: %d\n",safeArea); // Incomplete

	return 0;
}

// Read in a minefield
// Do NOT modify this function!
int readField(int field[][MAX_SIZE]) {
	int i,j, size;

	printf("Enter size: \n");
	scanf("%d", &size);

	printf("Enter minefield: \n");
	for (i=0; i<size; i++)
		for (j=0; j<size; j++)
			scanf("%d", &field[i][j]);

	return size;
}

// Print a minefield
// Do NOT modify this function!
void printField(int field[][MAX_SIZE], int size) {
	int i,j;

	for (i=0; i<size; i++){
		for (j=0; j<size; j++)
			printf("%d ", field[i][j]);
		printf("\n");
	}
}

void detonate(int field[][MAX_SIZE],int aftermath[][MAX_SIZE],int *damage, int *safe, int size){
    int i,j;
    for (i=0;i<size;i++){
        for (j=0;j<size;j++){
            if (field[i][j] > 0){
                explode(aftermath,i,j,field[i][j],size);
            }
        }
    }
    for (i=0;i<size;i++){
        for (j=0;j<size;j++){
            if (aftermath[i][j] > 0){
                if (aftermath[i][j] > *damage)
                    *damage = aftermath[i][j];
            }
            else if (aftermath[i][j] == 0){
                *safe += 1;
            }
        }
    }
}

void explode(int aftermath[][MAX_SIZE],int x, int y, int power,int size){
    int i;
    int dist = power-1;
    if (power == 1){
        aftermath[x][y]++;
        return;
    }

    //scan vertical
    for (i=x-dist;i<=x+dist;i++){
        if (i >= 0 && i <size)
            aftermath[i][y]++;
    }
    //scan horizontal
    for (i=y-dist;i<=y+dist;i++){
        if (i >= 0 && i <size)
            aftermath[x][i]++;
    }
    aftermath[x][y]--;
}
