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

	for(i = N; i > 0; i--)
	{
		for(j = 0; j < i-1; j++)
		{
			if(a[j] > a[j+1])
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
}

void show(int *a)
{
	int i;
	for(i = 0; i < 8; i++)
		printf("%d\t",a[i]);
	printf("\n");
}
