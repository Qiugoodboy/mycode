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
	int i,j,tmp,d;

	//shell分组
	for(d = N/2; d > 0; d = d/2)
	{
		//直接插入排序
		for(i = d; i < N; i = i++)
		//for(i = d; i < N; i = i + d)
		{
			tmp = a[i];
			for(j = i - d; j >= 0; j = j - d)
			{
				if(a[j] > tmp)
				{
					a[j+d] = a[j];
				}else 
					break;
			}
			a[j+d] = tmp;
		}
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
