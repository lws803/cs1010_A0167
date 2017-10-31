/**
* CS1010 AY2017/8 Semester 1 Lab1 Ex2
* box.c
* <Programme to compute the surface area and the length of the diagonal of the box>
* <Park Junhyuk>
* <C06>
*/

#include <stdio.h> 
#include <math.h> // needed as sqrt is used // 


int compute_surface_area (int x, int y, int z); //a function to calculate the surface area of a box// 
double compute_diagonal (double x, double y, double z); // a function to calculate the diagonal of a box//

int main(void) {
	int length, width, height; // declare variables//
		
	printf("Enter length: ");
	scanf("%d" , &length);  //for users to input the data//

	printf("Enter width : ");
	scanf("%d" , &width);
		
	printf("Enter height: ");
	scanf("%d" , &height);

	int surfacearea = compute_surface_area (length, width, height); //here, programme goes into the first function//
	double diagonal= compute_diagonal (length, width, height);// here, programme goes into the second function//

	printf("Surface area = %d\n", surfacearea); // print the calculated answer from the first function//
	printf("Diagonal = %.2f\n", diagonal);//print the calculated answer from the second function//		

	return 0;
}

int compute_surface_area (int x, int y, int z) { //x,y,z takes the value of length,width , height respectively in int form  from the main function//

	int surface_area;
	surface_area= (2*x*y)+(2*x*z)+(2*y*z);
	return surface_area; //the calculated value is returned to the main function//
}

double compute_diagonal (double x, double y, double z) { //x,y,z takes the value of length, width,height respectively in double form from the main function//

	double base_diagonal, diagonal;
	base_diagonal = sqrt(pow(x,2) + pow(y,2));
	diagonal = sqrt(pow(base_diagonal,2) + pow(z,2));

	return diagonal; //the calculated value is returned to the main function//
}

