#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, const char *argv[])
{
	int ret;
	ret=fork();
	if(-1==ret)
	{
		perror("fork");
	}
	else if(0==ret)
	{
		sleep(5);
		exit(0);
	}
	else(ret>0)
	{
		while(!waitpid(ret,NULL,WNOHANG))
		{
			sleep(1);
			printf("not catch child process!\n");
		}
		printf("has catch child process %d",ret);
	}
	
	return 0;
}
