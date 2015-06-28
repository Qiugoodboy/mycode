#include<stdio.h>

int fac(int i)
{
	int j;
	j=i;
	if(i==0||i==1)
		return 1;
	else
		j=fac(j-1)*i;
		return j;
}
int main(int argc, const char *argv[])
{
	int value;
	value=fac(5);
	printf("%d\n",value);
	return 0;
}
