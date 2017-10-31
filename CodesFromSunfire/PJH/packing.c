/**
 * CS1010 AY2017/8 Semester 1 Lab1 Ex3
 * packing.c
 * <computing the maximum possible number of slabs that could be packed onto the tray>
 * <Park Junhyuk>
 * <C06>
 */

#include <stdio.h>


int compute_max_slabs(int length1,int length2,int breadth1,int breadth2);//function prototype//

int main (void) {

	int max_slabs,length1,length2,breadth1,breadth2; //declares the variables//

	printf("Enter dimension of tray: ");
	scanf("%d %d",&length1, &breadth1); //takes the value from the user//

	printf("Enter dimension of slab: ");
	scanf("%d %d", &length2, &breadth2); //takes the value from the user//

	max_slabs = compute_max_slabs (length1, length2, breadth1, breadth2); //equate variable max_slabs to the calculated returned data from the compute_max_slabs function//

	printf("Maximum number of slabs = %d\n", max_slabs);

	return 0;
}

int compute_max_slabs(int length1,int length2,int breadth1,int breadth2) {//function to calculate the maximum number of slabs that could be packed onto the tray//
	int slabs_vertical, slabs_horizontal, maximum; //define variables used in the function//
	slabs_vertical = (length1/breadth2)*(breadth1/length2); //maximum number of slabs when slabs are fitted in vertically//
	slabs_horizontal= (length1/length2)*(breadth1/breadth2);//maximum number of slabs when slabs are fitted in horizontally//
	if (slabs_vertical >slabs_horizontal) {
		maximum=slabs_vertical;}
	else {
		maximum = slabs_horizontal;}

	return maximum; } // return the calculated max value to the main function// 





