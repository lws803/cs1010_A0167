#include "stdio.h"


int main(int argc, char const *argv[])
{
	int a = 2;

	//This expression is invalid cause 3<a is a boolean which returns 0
	//then 0 ==0 returns 1 cause its true
	printf("%d\n", (3<a==0));
	//From this we can see associativity is left to right. 
	return 0;
}