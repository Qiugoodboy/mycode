#include<stdio.h>

int main(int argc, const char *argv[])
{
	float fahrenheit,centigrade;

	printf("please input fahrenheit\n");
	scanf("%f",&fahrenheit);
	
	centigrade=5*(fahrenheit-32)/9;
	printf("the centigrade %.2f\n",centigrade);
	return 0;
}
