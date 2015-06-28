#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, const char *argv[])
{
	if(execlp("ps","ps","-aux",NULL)==-1)
	{
		perror("execlp");
		exit(-1);
	}
	return 0;
}
