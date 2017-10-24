// count_string.c
// Count the number of times a search string appears in a text.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LENGTH_SEARCH 15
#define LENGTH_LINE 80

int count_substr(char [], char [], char);
int count_substr_not_sensitive (char [], char [], char);
void reinit (char []);

int main(void) {	
	char str[LENGTH_SEARCH + 1], str_backup[LENGTH_SEARCH + 1]; 
	char line[LENGTH_LINE + 1]; 
	char sensitivity;
	int len, count;

	printf("Enter search string with <= %d characters: ", LENGTH_SEARCH);
	fgets(str, LENGTH_SEARCH+1, stdin);
	len = strlen(str); 
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
	printf("search string: \"%s\"\n", str);
	strcpy(str_backup, str); 

	printf("Search with case-sensitive ('y' or 'n')? ");
	scanf("%c%*c", &sensitivity);
	if (sensitivity == 'y')
		printf("Case-sensitivity is on.\n");
	else
		printf("Case-sensitivity is off.\n");

	count = 0;
	printf("Enter lines of text, each with <= %d characters,\n", LENGTH_LINE);
	printf("and end with an empty line.\n");

	while (1) {
		fgets(line, LENGTH_LINE+1, stdin);
		len = strlen(line); 
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		len = strlen(line); 
		printf("Line entered: \"%s\"\n", line);

		if (len == 0) 
			break;

		if (sensitivity == 'n') {
			count += count_substr_not_sensitive(line, str, sensitivity);
		}else {
			count += count_substr(line, str, sensitivity);
		}
	}

	printf("Number of times \"%s\" appears: %d\n", str_backup, count);
	return 0;	
}

// Count the number of times str occurs in line, 
// depending on case-sensitivity.
int count_substr(char line[], char str[], char sensitivity) {
	int count = 0, i, index = 0;
	char saved_string[LENGTH_LINE + 1];

	for (i = 0; line[i] != '\0'; i++) {
		saved_string[index++] = line[i];
		if (strstr(saved_string, str) != NULL) {
			count++;
			reinit(saved_string);
			index = 0;
		}
	}

	return count;
}

int count_substr_not_sensitive (char line[], char str[], char sensitivity) {
	int count = 0, i, index = 0;
	char saved_string[LENGTH_LINE + 1], converted_line[LENGTH_LINE + 1];

	// Convert all to upper case: 
	for (i = 0; line[i] != '\0'; i++) {
		converted_line[i] = toupper(line[i]);
	}

	// End off the line 
	converted_line[i] = '\0';

	for (i = 0; str[i] != '\0'; i++) {
		str[i] = toupper(str[i]);
	}

	for (i = 0; line[i] != '\0'; i++) {
		saved_string[index++] = converted_line[i];
		if (strstr(saved_string, str) != NULL) {
			count++;
			reinit(saved_string);
			index = 0;
		}
	}

	return count;
}

void reinit (char str[]) {
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		str[i] = '\0';
	}
}