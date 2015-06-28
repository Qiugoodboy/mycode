#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, const char *argv[])
{
	pid_t pd1,pd2;

	pd1=fork();
	if(pd1<0)
	{
		perror("fork");
		exit(-1);
	}
	else if(pd1>0)
	{
		pd2=fork();
		if(pd2<0)
		{
			perror("fork");
			exit(-1);
		}
		else if (pd2>0)
		{
			waitpid(pd2,NULL,0);
		}
		else
		{
			execlp("ls","ls","-l",NULL);
		}
		while(!waitpid(pd1,NULL,WNOHANG))
		{
			sleep(1);
			printf("no catch child 1..\n");
		}
		printf("has catch child\n");
	}
	else
	{
		sleep(5);
		exit(-1);
	}
	return 0;
}
