#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<string.h>

int main(int argc, const char *argv[])
{
	FILE * fp_r,*fp_w;
	char buf[1024];
	bzero(buf,sizeof(buf));

	if(argc!=3)
	{
		printf("Usage:please rightly input argument!\n");
		return -1;
	}
	if((fp_r=fopen(argv[1],"r+"))==NULL)
	{
		perror("fp_r");
		exit(-1);
	}

	if((fp_w=fopen(argv[2],"w+"))==NULL)
	{
		perror("fp_w");
		exit(-1);
	}

	while(fgets(buf,sizeof(buf),fp_r)!=NULL)
	{
		fputs(buf,fp_w);
		bzero(buf,sizeof(buf));
	}
	return 0;
}
