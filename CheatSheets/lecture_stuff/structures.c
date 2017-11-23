#include <stdio.h> 
#include <string.h>

// struct 
typedef struct  {
	int a;
	char b[10];
} box_t;

typedef struct {
	box_t box;
	int a;
} nested_t;


nested_t add_1 (nested_t);
box_t search (box_t []);
void swap (box_t[]);

int main () {
	// Structure to hold multiple data types with a single unique identifier (index)
	box_t box[5]; // array of type: box_t

	int i;
	for (i = 0; i < 5; i++) {
		box[i].a = i; // To access the field, use . operator 
		strcpy(box[i].b, "Hello world");
	}

	for (i = 0; i < 5; i++) {
		printf ("a: %d b: %s\n", box[i].a, box[i].b);
	}
	
	box_t box2[5];

	for (i = 0; i < 5; i++) {
		box2[i] = box[i]; // To copy contents of box 1 to box 2 
	}

	/**
	 For non array structs, we can just let box2 = box, assuming they are non-
	 array structs. 
	*/

	printf("-----Nested structs-----\n");
	// Accessing struct within struct 
	nested_t nested;
	nested.box.a = 6;
	printf ("nested.box.a: %d\n", nested.box.a);

	
	printf("-----Parsing structs as func parameters-----\n");

	printf ("nested.box.a: %d\n", add_1(nested).box.a); // add_1(nested) is of type nested_t

	// Search thru box to find 
	
	printf("-----Searching for index 3-----\n");

	printf ("%d\n", search(box).a);

	/**
	 Using pointers with structs
	 player_ptr -> name is the same as (*player_ptr).name
	*/


	printf("-----Swapping box[5]-----\n");
	// swap box[5]

	swap (box);

	for (i = 0; i < 5; i++) {
		printf ("%d ", box[i].a);
	}
	printf ("\n");
}


// Parsing structs to functions: 
nested_t add_1 (nested_t target) {
	target.box.a += 1; // Adds one to the target before returning it 
	return target;
}

// Linear search thru a struct array 
box_t search (box_t input[]) {
	box_t fail;
	fail.a = -1;
	int i;
	for (i = 0; i < 5; i++) {
		if (input[i].a == 3) { // search params 
			return input[i];
		}
	}
	//return NULL;
	return fail;
}

void swap (box_t input[]) {
	// Reverse the array
	for (int i = 0; i < 5/2; i++) {
		box_t t = input[i];
		input[i] = input[5 - 1 - i];
		input[5 - 1 - i] = t;
	}
}
