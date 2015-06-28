#include<stdio.h>

int main(void)
{
	char str[3]="66";
	int i,num=0,sum=0;

	for(i=0;i<2;i++)
	{
		num=str[1]-'0';
		sum=sum*10+num;
	}
	printf("%d\n",sum);
}

