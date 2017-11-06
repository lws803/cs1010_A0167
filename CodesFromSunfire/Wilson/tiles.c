#include <stdio.h>
#include <math.h>

typedef struct {
	int len; 
	int width;
	float price;
}tile_t;


float difference (tile_t [], int);
int scan_tiles (tile_t []);


int main(int argc, char const *argv[]) {
	tile_t tiles[20];
	int size;
	size = scan_tiles(tiles);

	printf("Largest difference = %0.2f\n", difference(tiles, size));


	return 0;
}

int scan_tiles (tile_t tiles[]) {
	int size;
	printf("Enter number of tiles: ");
	scanf ("%d", &size);
	printf("Enter data for %d tiles: \n", size);

	for (int i = 0; i < size; i++) {
		scanf ("%d %d %f", &tiles[i].len, &tiles[i].width, &tiles[i].price);
	}
	return size;
}


float difference (tile_t tiles[], int size) {
	float tileA_price = tiles[0].price * tiles[0].len * tiles[0].width;
	float tileB_price = tiles[1].price * tiles[1].len * tiles[1].width;
	float greatestDiff = fabs(tileA_price - tileB_price);

	for (int i = 0; i < size; i++) {
		for (int d = 0; d < size; d++) {
			float tile1_price = tiles[i].price * tiles[i].len * tiles[i].width;
			float tile2_price = tiles[d].price * tiles[d].len * tiles[d].width;

			if (fabs(tile1_price - tile2_price) > greatestDiff) {
				greatestDiff = fabs(tile1_price - tile2_price);
			}
		}
	}
	return greatestDiff;
}