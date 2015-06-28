#include<stdio.h>

struct S{
	int i;
	int *p;
};
int main(void)
{
	struct S s;
	int *p = &s.i;
	p[0] = 4;
	p[1] = 1;
	s.p = p;
//	s.p[1]=1;
	s.p[0] = 2;
	return 0;
}

