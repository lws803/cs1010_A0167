/**
 * box.c 
 * This program calculates the surface area of a box, and the
 * length of the diagonal connecting two vertices farthest apart.
 */

#include <stdio.h>
#include <math.h>
void compute_surface_area_and_diagonal(int, int, int,int*,double*);

int main(void) {
	int length, width, height, area;
	double diagonal;

	printf("Enter length: ");
	scanf("%d", &length);

	printf("Enter height: ");
	scanf("%d", &height);
	
	printf("Enter width: ");
	scanf("%d", &width);

	compute_surface_area_and_diagonal(length, width, height,&area,&diagonal);
	printf("Surface area = %d\n", area);
	printf("Diagonal = %.2f\n", diagonal);

	return 0;
}

// Compute the surface area of a box
// Precond: length>0, width>0, height>0
void compute_surface_area_and_diagonal (int length, int width, int height,int *area,double *diagonal) {
	*area = (2 * ((length * width) + (width * height) + (length * height)));
	*diagonal = sqrt((length * length) + (width * width) + (height * height));
}

// Compute the length of diagonal of a box between two vertices
// that are farthest apart.
// Precond: length>0, width>0, height>0
/* double compute_diagonal(int length, int width, int height) {
	return sqrt((length * length) + (width * width) + (height * height));
} */

