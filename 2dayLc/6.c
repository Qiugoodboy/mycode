#include<stdio.h>
#include<string.h>

void mystrcpy(char * p1 ,char * p2);

int main(int argc, const char *argv[])
{
	char a[20]="hahahahahaha";
	char b[20]="gagagagaga";
	mystrcpy(b,a);
	printf("%s\n",a);
	printf("%s\n",b);

	return 0;

}

void mystrcpy(char * p1 ,char * p2)
{

	while(*p2!=0)
		*p1++=*p2++;
		*p1='\0';
}
