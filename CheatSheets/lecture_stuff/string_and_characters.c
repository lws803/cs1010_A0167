#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	// Introduction 
	char ch str[20], s1[20], s2[20];

	// We can increment characters 
	ch++;

	// We can compare characters 
	if ('A' <  'B') {
		printf("success\n");
	}
	// Output: Success

	// To get a char from stdin
	ch = getchar();
	// To print the character out to stdout
	putchar(ch)


	// Check out some ctype.h functions 
	int a = isspace(' '); // isspace is a boolean
	int b = isspace('	'); // isspace is a boolean
	// returns a = 1, b = 1;

	// Cannot put multiple characters inside one quote 
	ch = 'test';

	// Cannot use string in a switch statement - use strcmp or atoi to find the string value first

	// String contains one extra null character at the back. So always create one with a size bigger by 1 unit****

	// Read string from stdin (two types)
	fgets(str, size, stdin); // it can read whitespace or newline characters (will only stop with ctrl-D)
	/* vs */
	scanf("%s", str); // it can only read till before a whitespace or newline 


	len = strlen(str); // gets the length of string (not including new line or whitespace )

	if (str[len-1] == '\n'); // To determine if the last character is a newline character 


	// To convert all characters to uppercased
	toupper(str);
	// To convert to lower 
	tolower(str);


	char str_2[4] = "omai" // Will not know how to terminate as there is no null character, only four characters 
	// The program cant add more characters behind this 

	strcat() // String concatenation 
	strcmp() // String compare 

	strcpy(s1, s2) // copies the string including null character into string 2



	// To demo that namePtr is pointing to a different address if you let namePtr = "Lee Hsu"
	char name[12] = "Chan Tan";  
	char *namePtr = "Chan Tan";  

	printf("name = %s\n", name);
	printf("namePtr = %s\n", namePtr);
	printf("Address of 1st array location for name = %p\n", name);
	printf("Address of 1st array location for namePtr = %p\n", namePtr);

	strcpy(name, "Lee Hsu");
	namePtr = "Lee Hsu";

	printf("name = %s\n", name);
	printf("namePtr = %s\n", namePtr);
	printf("Address of 1st array location for name = %p\n", name);
	printf("Address of 1st array location for namePtr = %p\n", namePtr);


	strtok(str, delim); // To extract words out of an entire string and place it into tokens using a delimiter 

	// Why pass a null pointer to strtok? 


	return 0;
}