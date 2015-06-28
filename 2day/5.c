#include<stdio.h>


int main(int argc, const char *argv[])
{
	int time,weeks,day;
	printf("please input days!\n");
	scanf("%d",&time);
	weeks=time/7;
	day=time%7;
	printf("%ddays are %d weeks,%d days\n",time,weeks,day);
	return 0;
}
