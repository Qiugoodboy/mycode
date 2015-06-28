#include<stdio.h>

int test(void);

int main(int argc, const char *argv[])
{
	int n,j;
	int n,j;


	for(n=0;n<5;n++)
	{
		j=test();		
	}

	printf("%d\n",j);
	
	return 0;
}

int test(void)
{
	static int i=0;
	i++;
	return i;
}
