#include<stdio.h>

int sub(int x,int y)
{
	return x-y;
}
int mul(int x,int y)
{
	return x*y;
}
int div(int x,int y)
{
	return x/y;
}
int add(int x,int y)
{
	return x+y;
}
int inter(int x,int y,int (*p)(int ,int))
{
	return p(x,y);
}
int main(int argc, const char *argv[])
{
	int value;
	value=inter(3,4,sub);
	printf("%d\n",value);
	return 0;
}
