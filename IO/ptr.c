#include<stdio.h>

int main(int argc, const char *argv[])
{
	FILE *p;
	char buf[1024];
	fread(buf,strlen(buf),1,stdin);
	p=fopen("test.c","w+");
	fwrite(buf,sizeof(buf),1,fp);
	return 0;
}
