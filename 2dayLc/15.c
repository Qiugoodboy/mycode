#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void sort(char **tmp);

int main(int argc, const char *argv[])
{
	char * ptr[4];
	int i;

	for(i=0;i<4;i++)
		ptr[i]=(char *)malloc(20*sizeof(char));
	for(i=0;i<4;i++)
		scanf("%s",ptr[i]);

	sort(ptr);

	printf("\n");



	return 0;
}

void sort(char ** tmp)
{
	int i,flag,j;
	char *ptr;
	char *str;
	for(j=0;j<4;j++)
	{
	str=tmp[j];
	flag=j;
	for(i=j;i<4;i++)
	{
		if(strcmp(tmp[i],str))
		{
			str=tmp[i];
			flag=i;
		}
	}
	ptr=tmp[flag];
	tmp[flag]=tmp[j];
	tmp[j]=ptr;
	}
	printf("%s\n",tmp[2]);
	printf("%s\n",tmp[1]);
	printf("%s\n",tmp[0]);

}
