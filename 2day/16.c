#include<stdio.h>

int main(int argc, const char *argv[])
{
	int i,j=0,n,z;
	int buf[100];
	scanf("%d",&i);
	do{
		buf[j]=i%16;
		i=i/16;
		j++;
	}while(i!=0);
	j-=1;
	for(;j>=0;j--)
	{
		if(buf[j]>9 && buf[j]<16)
		{
			if(j==0)
			{
			printf("%c\n",buf[j]+87);
			continue;
			}
			else
			{
			printf("%c",buf[j]+87);
			continue;
			}
		}
		if(j==0)
			printf("%d\n",buf[j]);
		else
			printf("%d",buf[j]);
	}
	return 0;
}
