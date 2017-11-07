// tiles_skeleton.c
#include <stdio.h>
#define MAX_TILES 20

// Define tile_t below
typedef struct{
	int length;
	int width;
	float price;
} tile_t;

int scan_tiles(tile_t []);
float difference(tile_t [], int);

int main(void) {
	tile_t tiles[MAX_TILES];
	int num_tiles;

	num_tiles = scan_tiles(tiles);

	printf("Largest difference = $%.2f\n",difference(tiles, num_tiles));

	return 0;
}

// To read tiles' data into array tiles
// Return the number of tiles read
int scan_tiles(tile_t tiles[]) {
	int num_tiles,i;
	tile_t newTile;

	printf("Enter number of tiles: ");
	scanf("%d",&num_tiles);
	printf("Enter data for %d tiles:\n",num_tiles);
	for (i=0;i<num_tiles;i++){
		scanf("%d %d %f",&newTile.length,&newTile.width,&newTile.price);
		tiles[i] = newTile;
	}

	return num_tiles;
}

// Return the difference in cost between
// the cheapest tile and the most expensive tile.
float difference(tile_t tiles[], int size) {
    int i,first;
	float highest=0,lowest,difference,price;
	for (i=0;i<size;i++){
		price = tiles[i].length * tiles[i].width * tiles[i].price;
		if (first){
			 highest = price;
			 lowest = price;
			 first = 0;
		}
		else{
			if (highest < price) highest = price;
			if (lowest > price) lowest = price;
		}
	}
	difference = highest - lowest;
	return difference;
}

