#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc, const char *argv[])
{
	if(fork()==0)
	{
		if(execl("/bin/ps","ps","-aux",NULL)==-1)
		{
			perror("execl");
			exit(-1);
		}
	}
	return 0;
}
