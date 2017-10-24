// Replace string with asterix's 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convert_string (char [20+1], char [1000]);


int main () {
	char str[20 + 1], dest[1000];
	fgets (str, 20, stdin);

	convert_string(str, dest);

	printf("%s\n", dest);	


}


void convert_string (char str[20+1], char dest[1000]) {
	int count = 0, i;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] != ' ' && str[i] != '\n') {
			dest[count++] = str[i];
			dest[count++] = '*';
		}
	}
	dest[--count] = '\0'; // To force a null at the end after the loop completes. 
	// --count was used to add the null character at the end to replace extra asterix.
}
