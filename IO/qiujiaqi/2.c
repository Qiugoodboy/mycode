#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
int main(int argc, const char *argv[])
{
	int i;
	fprintf(stdout,"hello\n");
	i=stdout->_IO_buf_end-stdout->_IO_buf_base;
	printf("%d\n",i);
	return 0;
}
