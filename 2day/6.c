#include<stdio.h>

int main(int argc, const char *argv[])
{
	int value,x,y;

	printf("please input the value!!\n");
	scanf("%d",&value);

	for(x=1;x<value;x++)
	{
		for(y=2;y<x;y++)
		{
			if(x%y==0)
			{
				break;
			}
		}
		if(y==x || x==2)
		{
			printf("%d\n",x);
		}
		
	}

	return 0;
}
