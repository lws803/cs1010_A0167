/**
 * CS1010 AY2017/8 Semester 1 Lab1 Ex2
 * box.c
 * <Type description of program here>
 * <LER WEI SHENG>
 * <C04>
 */


#include "stdio.h"
#include "math.h"

//This function calculates the surface area.
int surfaceArea(int length, int width, int height) {
	int x = length*height*2;
	int y = length*width*2;
	int z = width*height*2;

	return x+z+y;
}

//This function calculates the diagonal line. 
double diagonalLine(double length_d, double width_d, double height_d){

	double c = sqrt(pow(length_d, 2)+pow(width_d, 2));

	double diagonal = sqrt(pow(c, 2)+pow(height_d, 2));

	return diagonal;
}

int main(void)
{
	int length, width, height;

	printf("Enter length: ");
	scanf("%d", &length);
	printf("Enter width: ");
	scanf("%d", &width);
	printf("Enter height: ");
	scanf("%d", &height);


	double length_d = length;
	double width_d = width;
	double height_d = height;

	printf("Surface area = %d\n", surfaceArea(length, width, height));
	printf("Diagonal = %1.2lf\n", diagonalLine(length_d, width_d, height_d));

	return 0;
}


