#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
int main(int argc, const char *argv[])
{
	FILE *fp;
	char buf[50];
	fp=fopen("4.txt","w+");
	if(fp==NULL)
	{
		perror("fopen");
		exit(-1);
	}

	bzero(buf,sizeof(buf));
	buf[0]='A';
	buf[1]='B';
	buf[2]='\n';
	buf[3]='\0';
	fputs(buf,fp);
	//while(1);
	return 0;
}
