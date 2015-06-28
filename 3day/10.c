#include<stdio.h>

void copy(int x,int y,double (* p)[y],double (* pa)[y]);

int main(int argc, const char *argv[])
{
	int x,y;
	double n[3][3]={{1,2,3},{4,5,6},{7,8,9}};

	scanf("%d,%d", &x, &y);
	double h[x][y];

	copy(x,y,h,n);
	return 0;
}
void copy(int x,int y,double (* p)[y],double (* pa)[y])
{
	int mul,g;
	mul=x*y;
	for(g=0;g<mul;g++)
	{
		*(p[0]+g)=*(pa[0]+g);
		printf("%f\n",*(p[0]+g));
	}
}
