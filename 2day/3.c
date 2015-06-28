#include<stdio.h>
int main(int argc, const char *argv[])
{
	int a,b,c,d;
	a=10;
	b=a++;
	c=++a;
	d=10*a++;
	printf("b,c,d:%d,%d,%d",b,c,d);
	return 0;
}
