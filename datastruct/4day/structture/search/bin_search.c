#include <stdio.h>
#include <stdlib.h>
#define N 12 
void show(int *a);
int bin_search(int *a, int key);
int main(int argc, const char *argv[])
{
	int a[N] = {03,12,18,20,32,55,60,68,80,86,90,100};
	int key,ret;

	show(a);

	while(1)
	{
		printf("pls input search key:");
		ret = scanf("%d",&key);
		if(ret == 1)
		{
			ret = bin_search(a,key);
			if(ret >= 0)
			{
				printf("key:%d is in %d\n",key,ret);
			}else
				printf("key is not find\n");
		}else
			break;
	}
	return 0;
}

void show(int *a)
{
	int i;
	for( i = 0; i < N; i++)
		printf("%d\t",a[i]);
	printf("\n");
}

int bin_search(int *a, int key)
{
	int low,hight,mid;

	low = 0;
	hight = N -1;
#if 0
	for(mid = (low + hight)/2; a[mid] == key && low <= hight; mid = (low + hight)/2);
	{
		if(a[mid] < key)
			low = mid + 1;
		else
			hight = mid - 1;
	}
#else
	for(mid = (low + hight)/2; low <= hight; mid = (low + hight)/2)
	{
		if(a[mid] == key)
			break;

		if(a[mid] < key)
			low = mid + 1;
		else
			hight = mid - 1;
	}
#endif
	if(a[mid] == key)
		return mid;
	else 
		return -1;

}
