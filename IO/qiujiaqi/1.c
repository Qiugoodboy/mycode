#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
int main(int argc, const char *argv[])
{
	FILE * fp;
	int i;
	fp=fopen("2.c","w+");
	if(fp==NULL)
	{
		printf("%s\n",strerror(errno));
		exit(-1);
	}
	fprintf(fp,"helloworld!");
	i=fp->_IO_write_end-fp->_IO_write_base;
	printf("%d\n",i);
	return 0;
}
