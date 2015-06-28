#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char *argv[])
{
	FILE *fp;	
	time_t t;
	struct tm *pt;
	char buf[50];
	int i;
	bzero(buf,sizeof(buf));

	fp=fopen("time.txt","a+");
	if(fp==NULL)
	{
		perror("fopen");
		exit(-1);
	}
	while(1)
	{
	sleep(1);
	time(&t);
	pt = localtime(&t);
	sprintf(buf,"%d,%d-%d-%d %d:%d:%d",i,pt->tm_year+1900,pt->tm_mon+1,pt->tm_mon+1,pt->tm_mday,pt->tm_hour,pt->tm_min,pt->tm_sec);

	}
	return 0;
}
