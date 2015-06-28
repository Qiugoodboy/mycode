#include "linkstack.h"
#define N 8
int main(int argc, const char *argv[])
{
	int num;
	link_pstack s;
	
	linkstack_init(&s);
	printf("pls input ten num:");	
	scanf("%d",&num);

	while(num%N)
	{
		linkstack_push(&s, num%N);
		num = num/8;
	}

	//linkstack_show(s);
	while(!linkstack_is_empty(s))
	{
		linkstack_pop(&s, &num);
		printf("%d",num);
	}
	printf("\n");

	return 0;
}
