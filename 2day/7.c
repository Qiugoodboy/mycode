#include<stdio.h>

int main(int argc, const char *argv[])
{
	char value;
	int i,x,y,z,h;

	printf("please input value!!\n");
	scanf("%c",&value);
	i=value-64;
	for(y=0;y<i;y++)
	{
		for(x=0;x<i-y-1;x++)
			printf(" ");
		for(z=0;z<y+1;z++)
		{
			printf("%c",('A'+z));
		}
		for(h=1;h<y+1;h++)
		{
			printf("%c",'A'+z-h-1);	
		}
			printf("\n");

	}
	return 0;
}

