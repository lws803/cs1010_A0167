// triangleCentroid.c
// This program computes the centroid (G) of a triangle
// given the coordinates of three vertices.
#include <stdio.h>
#include <math.h>

void centroid(float, float, float, float, float, float, float *, float *);

int main(void) {
	float x1, y1,    // coordinates of 1st vertex
				x2, y2,    // coordinates of 2nd vertex
				x3, y3,    // coordinates of 3rd vertex
				xG, yG;    // coordinates of centroid

	printf("Coordinates of 1st vertex: ");
	scanf("%f %f", &x1, &y1);
	printf("Coordinates of 2nd vertex: ");
	scanf("%f %f", &x2, &y2);
	printf("Coordinates of 3rd vertex: ");
	scanf("%f %f", &x3, &y3);
	centroid (x1, x2, x3, y1, y2, y3, &xG, &yG); 

	printf("Coordinates of centroid = (%.2f, %.2f)\n", xG, yG);

	return  0;
}

void centroid (float x1, float x2, float x3, float y1, float y2, float y3, float *x, float *y) {
	float a = sqrtf(powf((x3-x2),2) + powf((y3 - y2), 2));
	float b = sqrtf(powf((x1-x3),2) + powf((y1 - y3), 2));
	float c = sqrtf(powf((x1-x2),2) + powf((y1 - y2), 2));

	*x = (a*(x1) + (x2)*b + (x3)*c)/(a+b+c);
	*y = (a*(y1) + (y2)*b + (y3)*c)/(a+b+c);
}