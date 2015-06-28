#include<stdio.h>

int main(int argc, const char *argv[])
{
	char *p;
	int n=0x12345678;
	p=(char *)(&n);
	printf("%p,%x\n",p,*p++);
	return 0;
}
