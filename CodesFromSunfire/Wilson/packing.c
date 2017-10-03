/**
 * CS1010 AY2017/8 Semester 1 Lab1 Ex3
 * packing.c
 * <Fill in a description of this program>
 * <LER WEI SHENG>
 * <C04>
 */


#include <stdio.h>


int slabVertical (int height_slab, int width_slab, int width_container, int height_container){
    int slabCount = (width_container/width_slab)*(height_container/height_slab);


    //Extra - to slot in mixed
    int remainingHeight_c = height_container - (height_container/height_slab)*height_slab;
    slabCount += (remainingHeight_c/width_slab)*(width_container/height_slab);

	return slabCount;
}



int slabHorizontal (int height_slab, int width_slab, int width_container, int height_container){
    int slabCount = (height_container/width_slab)*(width_container/height_slab);

    //Extra - to slot in mixed
    int remainingWidth_c = width_container - (width_container/height_slab)*height_slab;
    slabCount += (remainingWidth_c/width_slab)*(height_container/height_slab);

	return slabCount;
}



int main() {
	int height_slab = 0;
	int width_slab = 0;
	int width_container = 0;
	int height_container = 0;

	int max_slabs;


	printf("Enter dimension of tray: ");
	scanf("%d %d", &height_container, &width_container);
	printf("Enter dimension of slab: ");
	scanf("%d %d", &height_slab, &width_slab);
	
	int verticalCount = slabVertical(height_slab, width_slab, width_container, height_container);
	int horizontalCount = slabHorizontal(height_slab, width_slab, width_container, height_container);

	if (verticalCount>horizontalCount){
		max_slabs = verticalCount;
	}else{
		max_slabs = horizontalCount;
	}

	printf("Maximum number of slabs = %d\n", max_slabs);


	return 0;
}

