#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, const char *argv[])
{
	pid_t pid,fd;
	int i,count;
	pid=fork();
	char buf[100]="has pass 1 second!";
	//count=strlen(buf)+1;
	//buf[count]='\n';
	//buf[count+1]='\0';
	if(pid<0)
	{
		perror("fork");
		exit(-1);
	}
	else if(pid>0)
	{
		exit(0);
	}

	setsid();
	chdir("/tmp");
	umask(0);
	for(i=0;i<getdtablesize();i++)
	{
		close(i);
	}

	fd=open("daemon.log",O_WRONLY|O_CREAT|O_TRUNC,0666);
	if(fd<0)
	{
		perror("open");
		exit(-1);
	}
	while(1)
	{
		sleep(1);
		write(fd,buf,strlen(buf));
		write(fd,"\n",1);	
	}
	return 0;
}
