#include<stdio.h>

char *get_memory(void)
{
	char p[]="hello world";
	return p;
}
int main(int argc, const char *argv[])
{
	char *str=NULL;
	str=get_memory();
	printf("%s\n",str);
	return 0;
}
