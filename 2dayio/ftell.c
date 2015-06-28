#include<stdio.h>
#include<stdlib.h>

int main(int argc, const char *argv[])
{
	FILE *fp;
	if(argc!=2)
	{
		printf("Usage:please rightly input argument!\n");
		return -1;
	}

	if((fp=fopen(argv[1],"r+"))==NULL)
	{
		perror("fopen");
		exit(-1);
	}

	fseek(fp,0,SEEK_END);

	printf("the size of %s is %ld\n",argv[1],ftell(fp));

	return 0;
}
