#include <stdio.h>


void swap (int * , int * );
void printArr (int *);

int main () {
	// Show that variable != pointer 
	int a = 123;
	printf("a: %d, a_pointer: %p\n", a, &a);

	// Pointer variable 
	// To init a pointer, we use '*' 
	// To assign a pointer with memory address we dont need '*'
	// To assign val to the pointer, we need to use '*'

	int b = 1234; 
	int *b_pointer; 

	b_pointer = &b;

	printf("%d\n", *b_pointer); // Equivalent of printing b directly

	// Creating of pointer variable without assigning it 
	/*
	Doesnt work 
	int *c_pointer;
	printf("%d\n", *c_pointer);
	*/

	int *p;
	int c = 123; 
	p = &c;
	*p += 1;

	printf("c: %d, pointer_p: %d\n", c, *p); 
	// We can see that c has also been incremented. This shows that pointer is not mutually exclusive
	// Neither does it create a new int or is seperate from c

	int x = 8, y = 10;
	int *p1, *p2, *p3;

	p1 = &x;
	p2 = &y;

	// Pointer variable can be assigned with another pointer variable 
	p3 = p2;

	printf("%d\n", *p3);

	int *ap;
	ap = &a;

	// What happens when you increment a pointer? 

	printf("%p %p %p\n", ap, ++ap, (ap += 3)); // ap is incremented by 4 bytes, compare the addresses (eg. 2c + 4 = 30)
	// when ap += 3 (we're jumping 12 bytes forward)

	// Common error 
	/* 

	int *n;
	*n = 123; - this is illegal, can't just assign values to a pointer 

	*/ 


	swap (&a, &b);
	printf("%d %d\n", a, b);
	// Now a and b have both been affected 
	// To allow the function to modify the values outside the function 


	// Works for assigning arrays too and the calling it using another pointer function 
	int arr[5] = {1,2,3,4,5};
	int *arr_ptr = arr;

	printArr(arr_ptr);

}


// Pointer functions!

// Pointer swaps in a function, we're passing the address of the two variables instead of the variable value 
void swap (int *ptr1, int *ptr2) {
	int temp;
	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
// Do not use pointer functions when you have no need for it 
// Note that pointer functions would affect the original value from the previous function itself 

void printArr (int *ptr) {
	int i;
	for (i = 0; i < 5; i++){
		printf("%d\n", ptr[i]);
	}
}
