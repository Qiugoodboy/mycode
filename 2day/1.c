#include<stdio.h>
int main(void)
{
	float i=1;
	float n;

	printf("watch out!Here come a bunch of fraction!\n");
	while(i<30)
	{
		n=1/i;
		printf("%f\n",n);
		i++;
	}
	printf("That's all,folks!\n");
	return ;
}
