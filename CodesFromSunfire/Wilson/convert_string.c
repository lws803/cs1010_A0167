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
		if (str[i] != ' ') {
			dest[count++] = str[i];
			dest[count++] = '*';
		}
	}
}