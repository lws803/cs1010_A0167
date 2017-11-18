#include <stdio.h>
#define MAX_PIXELS 20

typedef struct {
	int r;
	int g;
	int b;
} pixel_c;

void numPixels (pixel_c [], int); 
pixel_c findSmallest (pixel_c [], int , int); 
int count_best_combi (pixel_c [], int, int , int , int , int ); 
int d_val (pixel_c , int, int, int, int , pixel_c); 
int find_best (pixel_c [], int, int, int, int, int); 
int subset(pixel_c [], pixel_c[], int, int, int, int, int, int, int, int ); 

int main(void) {
	int n,   // number of pixels
	    constA, constB, constC, constD;
	pixel_c pixels [MAX_PIXELS];
	scanf("%d %d %d %d %d", &n, &constA, &constB, &constC, &constD);
	numPixels (pixels, n);
	int best = find_best (pixels, n, constA, constB, constC, constD);

	printf("%d\n", best);
	return 0;
}

void numPixels (pixel_c pixels[], int size) {
	for (int i = 0; i < size; i++) {
		scanf("%d %d %d", &pixels[i].r, &pixels[i].g, &pixels[i].b);
	}
}

pixel_c findSmallest (pixel_c pixels[], int n, int index) {
	pixel_c smallest = pixels[index];
	int i;
	// Find minimum
	for (i = index; i < n; i++) {
		if (smallest.r > pixels[i].r) smallest.r = pixels[i].r;
		if (smallest.g > pixels[i].g) smallest.g = pixels[i].g;
		if (smallest.b > pixels[i].b) smallest.b  =pixels[i].b;
	}
	return smallest;
}

int d_val (pixel_c pixel, int A, int B, int C, int D, pixel_c smallest) {
	int d = A*(pixel.r - smallest.r) + B*(pixel.g-smallest.g) + C*(pixel.b-smallest.b);
	return d;
}

// This function stretches and tries to find the highest possible combination 
int find_best (pixel_c pixels[], int n, int A, int B, int C, int D) {
	pixel_c smallest = findSmallest(pixels, n, 0);
	pixel_c data[MAX_PIXELS];
	int i, d, count = 0;
	// Find the largest possible with the entire set itself 
	for (i = 0; i < n; i++) {
		int d_value = d_val(pixels[i], A, B, C, D, smallest);
		if (d_value <= D) {
			count++;
		}
	}
	while (subset(pixels, data, 0, n-1, 0, ++count, A, B, C, D));

	return --count;
}

// This function generates subsets of r and tries to push it further till r is equals to n. It returns the highest possible 
// Combination where d_value meets the conditions of constD. 
int subset(pixel_c arr[], pixel_c data[], int start, int end, int index, int r, int A, int B, int C, int D)
{
	// r = size of subset 
    int i;
    if (index == r) {
    	int count = 0;
    	pixel_c smallest = findSmallest (data, r, 0);
        for (i = 0; i < r; i++) {
        	int d_value = d_val (data[i], A, B, C, D, smallest);
        	if (d_value <= D) {
        		count++;
        	}
        }

        if (count == r) {
        	return 1;
        }
    }
    for (i = start; i <= end && end - i + 1 >= r - index; i++)
    {
    	int flag = 0;
        data[index] = arr[i];
        flag += subset(arr, data, i+1, end, index+1, r, A, B, C, D);
        if (flag > 0) {
        	return 1;
        }
    }
    return 0;
}
