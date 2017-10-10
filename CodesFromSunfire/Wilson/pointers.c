// pointers.c
// Exercise on using pointers.
#include <stdio.h>

int main(void) {
	int a, *a_ptr;
	float b, *b_ptr;

	printf("Enter an integer: ");
	scanf("%d", &a);
	printf("Enter a real number: ");
	scanf("%f", &b);

	a_ptr = &a;
	b_ptr = &b;

	// Segmentation fault caused when print before assigning the pointer variable to the correct variables 
	printf("Values entered are %d and %0.2f \n", *a_ptr, *b_ptr);

	while (*a_ptr < (*b_ptr)*(*b_ptr)) {
		// Note if we make an int_b we will be truncating b before multiplying instead of truncating a after multiplying
		*a_ptr *= *b_ptr;
	}

	printf("Final value of a = %d\n", *a_ptr);

	return 0;
}
