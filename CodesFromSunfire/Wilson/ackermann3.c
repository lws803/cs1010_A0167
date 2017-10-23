// Ackermann's Function - Partial Recursive + Memoization
#include<stdio.h>
#define MAX 30
int ackermann(int x, int y);
int cacheAckermann(int x, int y);
int count = 0;
int indent = 0;
int memory[MAX][MAX];
int main(int argc, char **argv)
{
	int x,y;
	int i,j;
	if(argc!=3)
	{
		printf("\nUsage : %s <number1> <number2>\n",argv[0]);
		exit(0);
	}
	x=atoi(argv[1]);
	y=atoi(argv[2]);
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
			memory[i][j]=-1;
	printf("\nAckermann Function with inputs (%d,%d) is %d\n",x,y,cacheAckermann(x,y));
	printf("\nFunction called %d times.\n",count);
	/*
	printf("\nUncached memory : { ");
	for(i=0;i<x;i++)
		for(j=0;j<MAX;j++)
			if(memory[i][j]==-1)
				printf("(%d,%d),",i,j);
	printf("\b}\n");
	*/
}
int cacheAckermann(int x, int y)
{
	int i;
	//count++;
	if(x<0 || y<0 || x>=MAX || y>=MAX)
		return -1;
	//printf("\ncacheAckermann(%d,%d)... ",x,y);
	if(memory[x][y]==-1)
	{
		//printf("\nNo cache found yet for (%d,%d)",x,y);
		printf("\n");
		for(i=0;i<indent;i++)
			printf("-");
		indent++;
		memory[x][y]= ackermann(x,y);
		indent--;
		printf("\n");
		for(i=0;i<indent;i++)
			printf("-");
	}
	else
	{
		printf("\n");
		for(i=0;i<indent;i++)
			printf("-");
		printf("(%d,%d) - Cached",x,y);
		printf("\n");
		for(i=0;i<indent;i++)
			printf("-");
	}
	printf("Return (%d,%d) : %d",x,y,memory[x][y]);
	return memory[x][y];
}
int ackermann(int x, int y)
{
	count++;
	int ack;
	printf("Call : (%d,%d)",x,y);
	if(x<0 || y<0)
		return -1;
	while(x>0 && memory[x][y]==-1)
	{
		if(y==0)
		{
			printf("\n(%d,%d)->(%d,%d)",x,y,x-1,1);
			memory[x][y]=memory[x-1][1];
			x=x-1;
			y=1;
		}
		else
		{
			printf("\n(%d,%d)->(%d,(%d,%d))",x,y,x-1,x,y-1);
			ack=cacheAckermann(x,y-1);
			memory[x][y]=memory[x-1][ack];
			y=ack;
			x=x-1;
		}
	}
	printf("\n(%d,%d)->%d",x,y,y+1);
	memory[x][y]=y+1;
	return y+1;

}