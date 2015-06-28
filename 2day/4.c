#include<stdio.h>

float cube(float);

int main(int argc, const char *argv[])
{
	float input,output;

	printf("please input value!!\n");
	scanf("%f",&input);
	output=cube(input);
	printf("the cube of this value is %.3f\n",output);
	return 0;
}
float cube(float value)
{
	int i;
	float sum=1.0;

	for(i=0;i<3;i++)
	{
		sum=sum*value;
	}
	return sum;
}

