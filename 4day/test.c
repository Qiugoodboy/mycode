#include<stdio.h>

void other()
{
	static int a=2;
	a++;
	printf("a=%d\n",a);
}

int main(int argc, const char *argv[])
{
	int n;

	for(n=0;n<5;n++)
	{
		other();
	}
	return 0;
}

