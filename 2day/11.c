#include<stdio.h>

int max(int a,int b,int c);
int main(int argc, const char *argv[])
{
	int i;
	i=max(32,45,37);
	printf("%d\n",i);
	return 0;
}
int max(int a,int b,int c)
{
	int temp;
	if(a>b)
		temp=a;
	else
		temp=b;
	if(c>temp)
		temp=c;
	return temp;
}
