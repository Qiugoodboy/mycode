#include<stdio.h>

int main(int argc, const char *argv[])
{
	int j;
	int a[2][3]={};
	
	for(j=0;j<6;j++)
	{
		printf("%d\n",*(a[0]+j));
	}
	
		
	return 0;
}
