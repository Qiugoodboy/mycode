#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#if 0
int main(int argc, const char *argv[])
{
	FILE *fpr,*fpw;
	char buf[100];

	bzero(buf,sizeof(buf));
	fpr=fopen("1.txt","r");
	if(fpr==NULL)
	{
		perror("1.txt");
		exit(-1);
	}

	fpw=fopen("2.txt","w");
	if(fpw==NULL)
	{
		perror("2.txt");
		exit(-1);
	}

	fread(buf,sizeof(buf),1,fpr);

	fwrite(buf,sizeof(buf),1,fpw);


	return 0;
}
#else

int main(int argc, const char *argv[])
{
	FILE *fpr,*fpw;
	int i;

	fpr=fopen("1.txt","r");

	if(fpr==NULL)
	{
		perror("1.txt");
		exit(-1);
	}

	fpw=fopen("2.txt","w");

	if(fpr==NULL)
	{
		perror("1.txt");
		exit(-1);
	}
	i=fgetc(fpr);
	while(!(ferror(fpr)||feof(fpr)))
	{
		fputc(i,fpw);
		i=fgetc(fpr);
	}

	fclose(fpr);
	fclose(fpw);
	return 0;
}
#endif
