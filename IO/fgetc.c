#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<string.h>
#define PERROR(ptr,str)\
if(ptr==NULL)\
{\
	perror(str);\
	exit(1);\
}
int main(int argc, const char *argv[])
{
	FILE *fp;
	int  buf[100],i;
	bzero(buf,sizeof(buf));
	fp=fopen("1.c","r+");
	PERROR(fp,"fopen");
	i=fgetc(fp);
	while(!(ferror(fp) || feof(fp)))
	{
		fputc(i,stdout);
		i=fgetc(fp);
	}

	return 0;
}
