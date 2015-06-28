#include<stdio.h>

void recur(int a[],int k);

int main(int argc, const char *argv[])
{
	int buf[5]={1,2,3,4,5};
	recur(buf,5);
	
	printf("%d\n%d\n%d\n%d\n%d\n",buf[0],buf[1],buf[2],buf[3],buf[4]);
	return 0;
}

void recur(int a[],int k)
{
	int tmp;
	if(k>1)
	{	
		recur(a+1,k-2);
		tmp=a[0];
		a[0]=a[k-1];
		a[k-1]=tmp;
	}
}
