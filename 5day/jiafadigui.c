#include<stdio.h>

int add(int begin,int end)
{
	int ret=0;

	if(begin==end)
	{
		printf("%d\n",end);
		return end;
	}
	else
	{
		ret=begin+add(++begin,end);
		printf("%d\n",ret);
	}
		return ret;
}
int main(int argc, const char *argv[])
{
	int value;
	value=add(1,5);
	printf("%d\n",value);
	return 0;
}
