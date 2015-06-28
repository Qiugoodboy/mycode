#include<stdio.h>

int main(int argc, const char *argv[])
{
	int i,j,n;
	int fib[100];

	scanf("%d",&n);
	fib[0]=1;
	fib[1]=1;
	if(n>1)
	{
	for(i=0;i<n;i++)
	{
		fib[i+2]=fib[i]+fib[i+1];
	}
	printf("%d\n",fib[i-1]);
	}
	else
		printf("%d\n",1);
	return 0;
}
