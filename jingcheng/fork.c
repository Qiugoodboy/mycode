#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, const char *argv[])
{
	pid_t ret;
	ret=fork();
	int value=1;
	if(-1==ret)
	{
		perror("fork");
		exit(-1);
	}
	if(0==ret)
	{
		value++;
		int a=2;
		printf("I'm father fork! the value=%d\n",value);
	}
	else
	{
		value++;
		printf("i'm son fork and my pid is %d !the value =%d\n",ret,value);
	}
		return 0;
}
