#include "stdio.h"
#include "string.h"

// CS1010 FINALS AY15/16 Qn 12

#define MAX 1000

int match (char str[], char pat[]); 

int main(int argc, char const *argv[])
{
	char str[MAX] = "3E4A1K";
	char pat[MAX] = "AEEEKAAA";
	char pat2[MAX] = "AEEEKAAAC";

	printf("%d\n", match (str, pat));
	printf("%d\n", match(str, pat2));
	return 0;
}

int match (char str[], char pat[]) {
	int len = 0; 
	for (int i = 0; str[i] != '\0'; i++) {
		int count;
		if (i % 2 == 0) {
			count = str[i] - '0';
			len += str[i] - '0';

		}else {
			int verify = 0;
			for (int d = 0; pat[d] != '\0'; d++) {
				if (pat[d] == str[i]) {
					verify++;
				}
			}
			if (verify != count) {
				return 0;
			}
		}
	}

	if (len != strlen(pat)) {
		return 0;
	}
	return 1;
}