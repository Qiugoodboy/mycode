#include<stdio.h>
#include<stdlib.h>

float my_power(float a,int b);

int main(int argc, const char *argv[])
{
	float value;
	value=my_power(3.14,-2);
	printf("%.6f\n",value);
	return 0;
}

float my_power(float a,int b)
{
	float sum=1;
	int i;
	if(b>0)
	{
		for(i=0;i<b;i++)
		{
		sum=sum*a;
		}
	}
	else if(b<0)
	{
		for(i=0;i<(abs(b));i++)
		{
			sum=sum*(1/a);
		}
	}
	else 
		sum=1;
	return sum;
}
