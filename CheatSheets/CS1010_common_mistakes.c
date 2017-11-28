This document shows all possible errors when tracing an algorithm in CS1010 questions.

if (-50 < i < -30) 		//will still compile.-Wall will complain. it will process from left to right.)
is the same as			//it does the same when there is an assignment operator in the condition.
if ((-50 < i) < -30)
= if ((1 < -30)
= if (0)

---------------------------------------------------------------------------------------------------------------------------
for ( ; i < 12 ; )		//will still compile, acts like a while loop instead
	i++; 

---------------------------------------------------------------------------------------------------------------------------
for (i=0, i <5, i++);	//due to the ';' token at the end, will not process the next line.
    printf(“%d”,i);     //will compile and print only the last value of the iteration of i.

---------------------------------------------------------------------------------------------------------------------------
double a=1.5, b=1.55
if (a=b)				//the assignment will lead to the side effect of 'if (1.55)' which is TRUE.
    printf(”a and b are equal”)
else
    printf(”a and b are not equal”)

---------------------------------------------------------------------------------------------------------------------------
double a=1.5, b=0
if (a=b)				//the assignment will lead to the side effect of 'if (0)' which is FALSE.
    printf(”a and b are equal”)
else
    printf(”a and b are not equal”)

---------------------------------------------------------------------------------------------------------------------------
// To test the use of crappy operator styles
void operatorTest () {
    int x;
    printf("%d\n", x=10); // From this we can infer that x=10 just defaults and registers as 10
    // OUTPUT: 10
    printf("%d\n", x=0);
    // OUTPUT: 0
    printf("%d\n", x=10>11);
    // OUTPUT: 0 because (x=10) gives 10 which is not more than 11 and thus returns 0 (FALSE)
    printf("%d\n", y<(-1<3));
    // OUTPUT: 1 whatever goes in the bracket will be processed first before left to right precedence is applied.
}
---------------------------------------------------------------------------------------------------------------------------
// Cant use % with real numbers 

x % 1.0 // Illegal 
x % 5 // Legal
---------------------------------------------------------------------------------------------------------------------------
i = (int)'A';
switch (i){
	case 'A': printf("%d\n",i);		//will print all of the statements due to no "break;" statement
	case 'B': printf("%d\n",i);		//fall through and prints this statement too
	case 'C': printf("%d\n",i);		//fall through and prints this statement too
}

---------------------------------------------------------------------------------------------------------------------------
int x=8,y=6,z=2;	
x /= y %= z 		//will compile. will give runtime error due to dividing zero.

---------------------------------------------------------------------------------------------------------------------------
for (i=0; i < n; i = i*2)	//will result in infinite loop due to "i = 0"
	count++;	
	
---------------------------------------------------------------------------------------------------------------------------
int Continue = 5; 	//is a valid initialisation statement. continue is a reserved term. not Continue.

---------------------------------------------------------------------------------------------------------------------------
int 20cents_digit; 	//not a valid initialisation, first character cannot be a digit. '_' is allowed as the first character.

---------------------------------------------------------------------------------------------------------------------------
int x=3,y=5,z;
z = ++(x+y);		//will not compile. lvalue required as increment operand.

---------------------------------------------------------------------------------------------------------------------------
sum -= --x - y 		//there is an invisible parenthesis around ( x - y )
is the same as
x = x - 1; sum = sum - x + y;
---------------------------------------------------------------------------------------------------------------------------
Weird multi operators: 

a+-b is read as a + -b
a-+b. Is read a - +b
a---b is a-- - b
a+++b is a++ + b

---------------------------------------------------------------------------------------------------------------------------

Initialising arrays
	int arr[5] = {} == {0,0,0,0,0}
		is the same as int arr[5] = {0}

	int arr[5] //will reserve 5 memory spaces to put integers. will not allocate any values to them.
	arr[][5]
		need to define the number of columns for multidimensional arrays.
	
---------------------------------------------------------------------------------------------------------------------------
STUFF to rectify
arrays
	what happens when they print beyond the array limit - undefined
	initialising arrays
	

void multiDimensionalArrayTest () {
    /*
     case 1:
     when we allocate more columns than we declare
     
     case 2:
     when we allocate only the row but not the column
     
     case 3:
     when we allocate only the column but called more rows than the ones we've declared
     */
    
    int arr[][4] = {{1, 2, 3}};
    int i, k;
    for (i = 0; i < 3; i++) {
        for (k = 0; k < 4; k++) {
            printf("%d\t", arr[i][k]);
        }
        printf("\n");
    }
}

OUTPUT
1 2 3 0
UNDEFINED UNDEFINED UNDEFINED UNDEFINED
UNDEFINED UNDEFINED UNDEFINED UNDEFINED

void multiDimensionalArrayTest () {
    /*
     case 1:
     when we allocate more columns than we declare
     
     case 2:
     when we allocate only the row but not the column
     
     case 3:
     when we allocate only the column but called more rows than the ones we've declared
     */
    
    int arr[][4] = {{0}};
    int i, k;
    for (i = 0; i < 3; i++) {
        for (k = 0; k < 4; k++) {
            printf("%d\t", arr[i][k]);
        }
        printf("\n");
    }
}
OUTPUT 
0 0 0 0 
0 0 0 0 
0 0 0 0

// Interesting case 

int i, j;
    int A[4][4] = {{1,2,3}}; // This is fine because we've defined the size of the multidim array

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", A[i][j]);
        }
    printf("\n");
}

OUTPUT
1 2 3 0 
0 0 0 0 
0 0 0 0 
0 0 0 0 
---------------------------------------------------------------------------------------------------------------------------
// Assignment of chunk of elements to an array
// This is illegal 

arr = {1,1,1};
// or 
arr[0] = {1,1,1};

// This applies for strings too 
// Which you'll have to use 
strcpy (arr, "test");
// And not 
arr = "test";
---------------------------------------------------------------------------------------------------------------------------
// Never do this: 
int size = 10; // Variable sized array
int arr[size][size] = {{0}}; // Won't compile, will give warning 

---------------------------------------------------------------------------------------------------------------------------
void charTest () {
    char c;
    
    while (c != 'n') {
        scanf(" %c", &c); // space added to keep new line from being registered as part of the char set.
        printf("%c\n", c);
    }
}
---------------------------------------------------------------------------------------------------------------------------
int main () {

    int i = 24;
    while (1) { // This occurence also works when its a conditional statement 
        int i = 11;
        printf("i = %d\n", i); // Output: will print 11. This is because the i initiated within while loop stays in while loop
    }

    printf("i = %d\n", i); // Output: will print 24 
}
---------------------------------------------------------------------------------------------------------------------------
// String functions 
// Delim: '-'
char str2[80] = "ore-wa-o-chin-chin-ga-daisuki-nandayo";
const s2[2] = '-'

char *token2;
token2 = strtok(str2, s2);
while( token2 != NULL ) {
    printf( "%s\n", token2 );
    
    token2 = strtok(NULL, s2); // If we remove this, then it will result in an infinite loop 
}

---------------------------------------------------------------------------------------------------------------------------
int main () {
    char str[1000] = "1 + 2 (6 x (3 + 4)) + 5";
    const char s[3] = "()";
    char *token;
   
    token = strtok(str, s);
    while( token != NULL ) {
        printf("%s\n", token);
        token = strtok(NULL, s);
    }
    return 0;
}
/**
Will output: 
1 + 2 
6 x 
3 + 4
 + 5
*/
---------------------------------------------------------------------------------------------------------------------------
char str[20] = "Hello world";

printf("%lu\n", strlen(str)); // Outputs 11, number of letters including whitespace 

---------------------------------------------------------------------------------------------------------------------------
char str[1000];

for (int i = 0; i < 3; i++) {
    str[i] = 'x';
}
// Output will print xxx&**&(^%^$%#)... this is because when we use for loops to append characters, it will not append '/0' for you. 
// Unlike 
scanf("%s", str);
// or 
char str2[10] = "Hello_world";

// Init a string: 
char str2[MAX_LENGTH+1]; // use +1 add the back to account for the NULL character

fgets (str2, MAX_LENGTH, stdin); // Then we can use MAX_LENGTH

---------------------------------------------------------------------------------------------------------------------------
// strcpy cant be used with pointer addresses 
char *fruit1 = "test", *fruit2 = "test2";
strcpy (fruit1, fruit2); // cant be done because fruit1 is not modifiable 
// When we declare a pointer variable to anything, it is not modifiable even though it appears like it might be. 

// Also strcpy cant work when a destination is smaller than the size we wish to copy in. 

---------------------------------------------------------------------------------------------------------------------------
char str1[MAX] = "HelloWorld", str2[MAX] = "Hello";
char *ptr = strstr (str1, str2); // Note that strstr will take everything after the substring (str2)

printf("%s\n", *ptr); // Will print HelloWorld.
---------------------------------------------------------------------------------------------------------------------------
int a = 10;
int* ptr = &a; // Will take the address of a 
*ptr = a // will not take the address of a, will take the value of a  
---------------------------------------------------------------------------------------------------------------------------
fgets (arr, 100, stdin);

// fgets actually records down the new line before ending off. so use for loop with '\n' instead. 
for (i = 0; arr[i] != '\n'; i++) {
    // Your code here 
}

// Or remove it early on using: 
for (int i = 0; word[i] != '\0'; i++) {
    if (word[i] == '\n') {
        word[i] = '\0'; // To replace the newline with null char
    }
}

---------------------------------------------------------------------------------------------------------------------------
// strcat relies heavily on null character "\0"
// Helloworld\0 + test == Helloworldtest\0

//Some tricks to settle this: 
char word[MAX] = "\0"; // to make the first character a null character 

// Not needed for fgets as it works like strcpy where characters are copied straight and replaced starting from word[0]

---------------------------------------------------------------------------------------------------------------------------
typedef struct {
    int a;
}s_t;
// When scanning into a struct, 

s_t s;
scanf ("%d", &s.a) 
scanf ("%d", &(s.a))
// Are valid 

scanf ("%d", (&s).a) // Invalid - (&s) means memory address of s and it does not contain a. 
scanf ("%d", s.&a) // Invalid - use of undeclared identifier 

---------------------------------------------------------------------------------------------------------------------------
typedef struct {
    int a;
}test_t;

// When parsing a struct from int main to another function 
int main() {
    test_t test;
    func(test);
    printf ("%d\n", test.a);
    // Print test.a will not hold any value. - it usually prints 0
}

void func (test_t test) {
    test.a = 10;
}

/* instead what we should do is */
int main() {
    test_t test;
    func(&test);

    // Print test.a will non hold any value.  
}

void func (test_t *test) {
    test->a = 10;
    // Take note we use an arrow here instead to reference the item inside the struct
}
---------------------------------------------------------------------------------------------------------------------------
// Assigning values to a struct 

typedef struct {
    int a;
    int b;
    int c;
}test_t;

test_t t = {1,2}; // This is legal even tho we did not assign c; 
// c would be zero in this case, it would be treated like a regular array
---------------------------------------------------------------------------------------------------------------------------
fscanf(infile, "%d", size1);
    for (i = 0; i < *size1; i++) {
        fscanf(infile, "%d", &arr1[i]); // Note that calling fscanf here again wont start from the top of the file!
}
---------------------------------------------------------------------------------------------------------------------------
// To scan a file with multiple numbers without scanning last line twice** (EOF problem)
    while (fscanf(infile, "%d", &num) == 1) {
        printf("%d\n", num);
        // Process whatever you wish with num here. 
    }
---------------------------------------------------------------------------------------------------------------------------
int recursive_binary(int arr[], int start, int end, int target) {
    int mid = (end + start)/2 ;
    if (arr[mid] == target) {
        return mid;
    }
    if (start > end) {
        return -1;
    }
    if (arr[mid] > target) {
        return recursive_binary (arr, start, mid - 1, target); 
        // Usually confuse this for mid + 1 or just mid. 
        // The reason why we use mid - 1 is to account for the rounding up of integers 
    }else {
        return recursive_binary (arr, mid + 1, end, target);
    }
    return -1;
}
---------------------------------------------------------------------------------------------------------------------------
void randomFunction (int *max, int arr[]) {
    max = &arr[0]; // Will not be parsed back to the main func or anywhere outside of this function 
    *max = arr[0]; // Use this instead 
}


int main(int argc, char const *argv[])
{
    int arr[3] = {1,2,3};
    int *p = arr;
    printf("%d\n", *p); // prints 1 

    printf("%d\n", ++*p); // prints 2 
    // This shows that every element in the array is side by side (memory address)

    return 0;
}
---------------------------------------------------------------------------------------------------------------------------
// As long as srand() is called once before rand() is called, the sequence of random numbers generated does not change everytime 
srand(); // srand shd be assigned to take an argument that changes, in that case time(NULL) would be best 
srand(time(NULL));
printf ("%d", rand());
---------------------------------------------------------------------------------------------------------------------------
// Order of recursion 
// *Pre-processing 
void mystery (int length) {
    printf("%d\n", length);
    if (length > 0) {
        mystery (length - 1);
    }
}
// Outputs: 10,9,8,7...
/* vs */ 
// *Post-processing
void mystery (int length) {
    if (length > 0) {
        mystery (length - 1);
    }
    printf("%d\n", length); 
}
// Outputs: 0,1,2,3,4...

/**
 Simple concept but commonly applied to manipulating arrays or numbers. 
 Postprocessing commonly used chiong to the last case and then slowly move back up to base case.
 Pre-processing commonly used when we need to rely on the changes made. Eg. passing down values/ flood fill 
*/
---------------------------------------------------------------------------------------------------------------------------