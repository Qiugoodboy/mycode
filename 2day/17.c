#include<stdio.h>

int gcd(int max,int min);

int main(int argc, const char *argv[])
{
	int x,y,temp,z;
	scanf("%d,%d",&x,&y);
	if(y>x)
	{
		temp=y;
		y=x;
		x=temp;
	}
	z=gcd(x,y);
	printf("%d\n",z);
	return 0;
}
int gcd(int max,int min)
{
	int buf[100],i=1,value;
	buf[0]=max%min;


	if(buf[0]==0)
	{
		value=min;
		goto home;
	}

	buf[1]=min%buf[0];

	if(buf[1]==0)
	{
		value=buf[0];
		goto home;
	}

	do{
		i++;
		buf[i]=buf[i-2]%buf[i-1];
	}while(buf[i]!=0);

	value=buf[i-1];
home:	return value;
}
