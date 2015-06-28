#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

typedef struct student
{
	char name [10];
	int age;
	int class;
}student_t;

int main(int argc, const char *argv[])
{
	student_t buf[10];
	student_t *p;
	FILE *fp;
	fp=open(argv[1],"r");
	if(fp==NULL)
	{
		perror("fopen");
		exit(-1);
	}

	while()	

	return 0;
}
