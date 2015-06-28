#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<strings.h>
#include<string.h>

#define OFFSET 10240
#define BUFSIZE 1024

int main(int argc, const char *argv[])
{
	int fd_r,fd_w,ret_r,ret_w;
	char buf[1500];


	bzero(buf,sizeof(buf));

	if((fd_r=open(argv[1],O_RDONLY))==-1)
	{
		perror("open_r");
		exit(-1);
	}

	if((fd_w=open(argv[2],O_WRONLY|O_TRUNC|O_CREAT,0664))==-1)
	{
		perror("open_w");
		exit(-1);
	}

	lseek(fd_r,-OFFSET,SEEK_END);

	while((ret_r=read(fd_r,buf,BUFSIZE))>0)
	{
		write(fd_w,buf,strlen(buf));
		bzero(buf,sizeof(buf));
	}

	close(fd_r);
	close(fd_w);


	return 0;
}
