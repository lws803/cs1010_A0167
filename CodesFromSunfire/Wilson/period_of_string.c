#include "stdio.h"
#include "string.h"

int period (char []); 

int main(int argc, char const *argv[])
{
	char str[100] = "abcdabcdabcd";


	printf("%d\n", period(str));

	return 0;
}


int period (char str[]) {
	int i;
	for (i = 1; i <= strlen(str); i++) {
		int count_2 = 0;
		for (int d = 0; d < i; d++) {
			int count = 0;
			for (int c = d; c < strlen(str); c += i) {
				if (str[d] != str[c])
					break;
				count++;
			}
			if (count == strlen(str)/i) {
				count_2++;
			}
		}
		if (count_2 == i) {
			return i;
		}
	}
	return -1;
}