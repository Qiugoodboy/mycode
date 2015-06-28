#include<stdio.h>

int main(int argc, const char *argv[])
{
	int i,j;
	for(i=1;i<6;i++)
	{
		for(j=0;j<i;j++)
		{
			printf("$");
		}
		printf("\n");
	}
	return 0;
}
