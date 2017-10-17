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
char str[20] = "Hello world";

printf("%lu\n", strlen(str)); // Outputs 11, number of letters including whitespace 