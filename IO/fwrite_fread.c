#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<string.h>

#define PERROR(ptr,str)\
if(ptr==NULL)\
{\
	perror(str);\
	exit(1);\
}

typedef struct student 
{
	char name[10];
	char age[2];
}student_t;

int main(int argc, const char *argv[])
{
	student_t stu[10];
	int count=(argc-1)/2,i;
	FILE *fp;
	bzero(&stu,sizeof(stu));
	fp=fopen("1.c","r+");
		PERROR(fp,"fopen");

	for(i=0;i<count;i++)
	{
		strcpy(stu[i].name,argv[i*2+1]);
		strcpy(stu[i].age,argv[i*2+2]);
	}
	for(i=0;i<count;i++)
	{
	fwrite(&stu[i],sizeof(student_t),1,fp);
	fputs("\n",fp);
	}

	fread(&stu,sizeof(student_t),count,stdout);

	fclose(fp);
	return 0;
}











