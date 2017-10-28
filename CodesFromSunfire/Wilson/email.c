// CS1010 AY2015/6 Semester 1
// PE2 Ex2: email.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 51

int checkEmail (char[]);

int main(void){
	char email[MAX_LENGTH];
	
	printf("Enter email address: ");
	scanf("%s", email);
	

	switch (checkEmail (email)) {
		case 0:
		printf("This email address is not valid.\n");
		break;
		case 1:
		printf("This email address is valid but not friendly.\n");
		break;
		case 2:
		printf("This email address is valid and friendly.\n");
		break;
	}
	
	return 0;
}

/**
 * This function checks if an email is valid
 * Precond: Must be in lower case
*/

int checkEmail (char email[]) {
	int isDomain = 0, isFriendly = 2;
	// Tokenise and split to two - local & domain 
	const char s[2] = "@";
	char *token;

	token = strtok (email, s);
	
	while (token != NULL) {
		// Checking thru local 
		if (!isDomain) {
			isDomain = 1;
			// Checks local length 
			if (strlen(token) < 3 || strlen(token) > 21) {
				return 0;
			}
			int i;
			for (i = 0; token[i] != '\0'; i++) {
				if (!isalnum(token[i]) && token[i] != '.') {
					return 0;
				}
			}

			if (token[0] == 'e' || token[0] == 'a') {
				int i;
				for (i = 1; token[i] != '\0'; i++) {
					if (!isdigit(token[i])) {
						break;
					}
				}
				if (i > 7) {
					isFriendly = 1;
				}
			}else if (isdigit(token[0])) {
				return 0;
			}

		}else {
			// Checking thru domain 
			// Checks using strcmp 			
			if (strcmp (token, "u.nus.edu")) {
				return 0;
			}
		}
		token = strtok (NULL, s);
	}
	return isFriendly; // 1 means not friendly but valid, 2 means friendly  
} 
