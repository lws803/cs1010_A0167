//Pointers experiment

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int var = 6;
	int *ptr;
	ptr = &var;

	printf("This is a pointer value print %d\n", *ptr);
	printf("This is pointer address print from ptr %p\n", ptr);
	printf("This is a var address print %p\n", &var);

	return 0;
}