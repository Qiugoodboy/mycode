#include <stdio.h>
#include <time.h>

int main(int argc, const char *argv[])
{
	time_t t;
	struct tm *pt;

	time(&t);

	pt = gmtime(&t);

	printf("year:%d\n", pt->tm_year+1900);
	printf("month:%d\n", pt->tm_mon+1);
	printf("day:%d\n", pt->tm_mday);
	printf("%d:%d:%d\n", pt->tm_hour, pt->tm_min, pt->tm_sec);
	
	return 0;
}
