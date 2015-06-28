#include<stdio.h>
#include <stdlib.h>
#define N 8
void show(int *a);
void quick_sort(int *a, int i, int j);
int main(int argc, const char *argv[])
{
	int a[] ={50,36,66,76,95,12,25,36};

	show(a);
	quick_sort(a,0,N-1);
	show(a);

	return 0;
}


int quick_pass(int *a, int i, int j)
{
	int tmp;
	tmp = a[i];
	while(i < j)
	{
		while(a[j] >= tmp && i < j)
		{
			j--;
		}

		if(i < j)
			a[i] = a[j];

		while(a[i] <= tmp && i < j)
		{
			i++;
		}

		if(i < j)
			a[j] = a[i];
	}
	a[i] = tmp;
	return i;
}

void quick_sort(int *a, int i, int j)
{
	int mid;
	if(i < j)
	{
		show(a);
		//找基准
		mid = quick_pass(a,i,j);
		printf("mid = %d\n",mid);
		//快速排序
		quick_sort(a,i,mid-1);
		quick_sort(a,mid+1,j);
	}
}

void show(int *a)
{
	int i;
	for(i = 0; i < 8; i++)
		printf("%d\t",a[i]);
	printf("\n");
}
