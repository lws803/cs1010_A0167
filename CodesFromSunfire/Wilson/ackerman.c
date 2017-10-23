// Ackermann's Function - Full Recursive
#include<stdio.h>
#include<stdlib.h>
int ackermann(int x, int y);
int count = 0, indent = 0;
int main(int argc, char **argv)
{
	int x,y;
	if(argc!=3)
	{
		printf("\nUsage : %s <number1> <number2>\n",argv[0]);
		exit(0);
	}
	x=atoi(argv[1]);
	y=atoi(argv[2]);
	printf("\nAckermann Function with inputs (%d,%d) is %d\n",x,y,ackermann(x,y));
	printf("\nFunction called %d times.\n",count);
}
int ackermann(int x, int y)
{
	count++;
	if(x<0 || y<0)
		return -1;
	if(x==0)
		return y+1;
	if(y==0)
		return ackermann(x-1,1);
	return ackermann(x-1,ackermann(x,y-1));
}