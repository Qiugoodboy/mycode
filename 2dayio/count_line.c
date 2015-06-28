#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

int main(int argc, const char *argv[])
{
	FILE * fp;
	char buf[1024];
	int count=0;
	bzero(buf,sizeof(buf));

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		perror("fopen");
		exit(-1);
	}

	while(fgets(buf,sizeof(buf),fp)!=NULL)
	{
		count++;
		bzero(buf,sizeof(buf));
	}
	printf("the %s have %d line\n",argv[1],count);


	return 0;
}
