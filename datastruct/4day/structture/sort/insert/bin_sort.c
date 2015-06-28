#include<stdio.h>
#include <stdlib.h>
#define N 8
void show(int *a);
void insert_sort(int *a);
int main(int argc, const char *argv[])
{
	int a[] ={50,36,66,76,95,12,25,36};

	show(a);
	insert_sort(a);
	show(a);

	return 0;
}


void insert_sort(int *a)
{
	int i,j,tmp;
	int low,hight,mid;

	for(i = 1; i < N; i++)
	{
		low = 0; hight = i-1;
		tmp = a[i];
#if 0
		for(j = i - 1; j >= 0; j--)
		{
			if(a[j] > tmp)
			{
				a[j+1] = a[j];
			}else 
				break;
		}
		a[j+1] = tmp;
#else 
		//使用折半查找，查找插入的位置
		while(low <= hight)
		{
			mid = (low + hight)/2;
			if(a[mid] < tmp)
				low = mid + 1;
			else
				hight = mid -1;
		}
		
		//腾出位置
		for(j = i - 1; j >= low; j--)
			a[j+1] = a[j];

		a[low] = tmp;
#endif
		show(a);
	}
}

void show(int *a)
{
	int i;
	for(i = 0; i < 8; i++)
		printf("%d\t",a[i]);
	printf("\n");
}
