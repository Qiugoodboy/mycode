#include<stdio.h>

int main(int argc, const char *argv[])
{
	if(argc!=3)
	{
		printf("please input right commond!");
		exit(0);
	}

	int fd_r,fd_w;
	fd_r=open(argv[1],O_RDONLY);
	fd_w=open(argv[2],O_WRITE|O_CREAT|O_TRUNC,0664);

	return 0;
}
