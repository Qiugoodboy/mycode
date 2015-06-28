#include<stdio.h>
#define value 60
int main(void)
{
	int second,hour;
	int time=360;
	
	hour=time/60;
	second=time*60;

	printf("The second is %d\n",second);
	printf("The hour is %d\n",hour);
	
	return 0;
}
