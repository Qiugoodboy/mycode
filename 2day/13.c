#include<stdio.h>
#include<string.h>

int main(int argc, const char *argv[])
{
	char a[10],b[10];
	char c[20];
	int i,j,x,temp;

	scanf("%s %s",a,b);
	
	i=strlen(a);
	j=strlen(b);

	for(x=0;x<i;x++)
	{
		c[x]=a[x];
		temp=x+1;
	}
	for(x=0;x<j;x++)
	{
		c[temp+x]=b[x];
	}
	c[temp+x]='\0';
	printf("%s\n",c);
	return 0;
}
