#include "stdio.h"


int numberSplitter (int);

int main(int argc, char const *argv[]) {
	int a , b , c;

	printf("Enter 3 positive integers: ");
	scanf("%d %d %d", &a, &b, &c);

	printf("The integers are %d, %d and %d\n", a, b, c);
	if (numberSplitter(c) > numberSplitter (b) && numberSplitter(b) > numberSplitter(a) ){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	
	return 0;
}

int numberSplitter (int x) {
	int i = 0, number;
	while (x) {
		if (i == 2) {
			number = x%10;
		}
		x /= 10;
		i++;
	}

	return number;
}