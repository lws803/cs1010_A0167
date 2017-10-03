//Single struct test

#include <stdio.h>
#include <string.h>

struct testStruct
{
	char message[12];
	int index;
}test;



int main(void)
{

	printf("Enter name: \n");
	gets(test.message);
	printf("Enter indexNo: \n");
	scanf("%d", &test.index);

	printf("---------------Printing---------------\n");
	printf("%s\n", test.message);
	printf("%d\n", test.index);
	return 0;
}