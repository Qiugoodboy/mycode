#include<stdio.h>

void swap(char *p1,char *p2,int size);


int main(int argc, const char *argv[])
{
	char a[5]="1234";
	char b[5]="4321";
	swap(a,b,5);
	printf("%s\n",a);
	printf("%s\n",b);
	return 0;
}


void swap(char *p1,char *p2,int size)
{
	int i;
	char tmp;
	for(i=0;i<size;i++)
	{
		tmp=p1[i];
		p1[i]=p2[i];
		p2[i]=tmp;
	}

}
