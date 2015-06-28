#include<stdio.h>
int main(int argc, const char *argv[])
{
	int a=12,n=5;
//	a+=a;     
//	a-=2;     
//	a*=2+3;   
//	a/=a+a;   
//	a%=(n%2);
	a+=a-=a*=a;
	printf("a=%d\n",a);
	return 0;
}
