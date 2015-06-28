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

	for(i = 1; i < N; i++)
	{
		tmp = a[i];
		for(j = i - 1; j >= 0; j--)
		{
			if(a[j] > tmp)
			{
				a[j+1] = a[j];
			}else 
				break;
		}
		a[j+1] = tmp;
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
