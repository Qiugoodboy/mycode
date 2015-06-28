#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main(int argc, const char *argv[])
{
	FILE *fp;	
	time_t t;
	struct tm *pt;
	char buf[50];
	int i=0;
	bzero(buf,sizeof(buf));
	
	fp=fopen("4.txt","a+");
	if(fp==NULL)
	{
		perror("fopen");
		exit(-1);
	}
	//setlinebuf(fp);
	//printf("%d",fgetc(fp));
	while(1)
	{
	time(&t);
	pt =localtime(&t);
	sleep(1);
	sprintf(buf,"%d,%d-%d-%d %d:%d:%d",i,pt->tm_year+1900,pt->tm_mon+1,pt->tm_mday,pt->tm_hour,pt->tm_min,pt->tm_sec);
	fwrite(buf,strlen(buf),1,fp);
//	fflush(fp);
	fputc(10,fp);
	printf("%d\n",i);
	i++;
	}
	return 0;
}
