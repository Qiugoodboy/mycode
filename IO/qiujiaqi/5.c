#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, const char *argv[])
{
	FILE *fpr,*fpw1,*fpw2;
	char buf[100];

	bzero(buf,sizeof(buf));
	fpr=fopen("1.txt","r");
	if(fpr==NULL)
	{
		perror("1.txt");
		exit(-1);
	}

	fpw1=fopen("2.txt","w");
	if(fpw1==NULL)
	{
		perror("2.txt");
		exit(-1);
	}

	fpw2=fopen("3.txt","w");
	if(fpw2==NULL)
	{
		perror("3.txt");
		exit(-1);
	}

	
	fread(buf,sizeof(buf),1,fpr);
	fwrite(buf,sizeof(buf),1,fpw1);
	fseek(fpr,strlen(buf),SEEK_SET);
	fwrite(buf,sizeof(buf),1,fpw2);

	fclose(fpr);
	fclose(fpw1);
	fclose(fpw2);

	return 0;
}
