#include "stdio.h"
#include "string.h"


void reverse (char [], int , int );
void swapSubString (char [], int , int );


int main(int argc, char const *argv[])
{

	char str[10] = "Hamburger";
	char str2[12] = "Programming";
	reverse(str2, 3, 7);
	swapSubString(str, 3, 6);
	printf("%s\n", str2);
	printf("%s\n", str);
	
	return 0;
}

void reverse (char str[], int start, int end) {
	if (start > end) {
		return;
	}

	char temp = str[start];
	str[start] = str[end];
	str[end] = temp;

	reverse(str, start+1, end-1);
}

void swapSubString (char str[], int len_a, int len_b) {
	// Reverse the entire thing first
	reverse(str, 0, strlen(str)-1);
	// Reverse the first portion properly
	reverse(str, 0, len_b-1);
	// Reverse the second portion properly
	reverse(str, len_b, strlen(str)-1);
}