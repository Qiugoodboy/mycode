#include<stdio.h>
#include<strings.h>
#include<string.h>
#include<stdlib.h>
#define PERROR(ptr,str) \
if(ptr==NULL)\
{\
	perror(str);\
	exit(1);\
}

int main(int argc, const char *argv[])
{
	int i;
	FILE *fp;
	char buf[100]={'a','b','\n','a','b','\n','\0'};

//	bzero(buf,sizeof(buf));

	fp=fopen("1.c","w+");
	PERROR(fp,"fopen");
//	fgets(buf,100,stdin);
	fputs(buf,fp);
	fclose(fp);


	return 0;
}
