#include "seqstack.h"
int main(int argc, const char *argv[])
{
	int num,ret;
	seq_pstack s;

	seqstack_init(&s);

	while(1)
	{
		printf("pls input num:");
		ret = scanf("%d",&num);
		if(1 == ret)
		{
			seqstack_push(s, num);
			seqstack_show(s);
		}else 
		{
			ret = seqstack_pop(s, &num);
			if(ret == -1)
				printf("stack is emtyp!\n");
			else
			{
				seqstack_show(s);
				printf("pop num is:%d\n",num);
			}
			while(getchar() != '\n');
		}
	}
	return 0;
}

bool seqstack_is_empty(seq_pstack s)
{
	if(s->top == -1)
		return true;
	else 
		return false;
}

int seqstack_pop(seq_pstack s,int *num)
{
	int i;
	if(seqstack_is_empty(s))
		return -1;

	//出栈
	*num = s->data[s->top];
	s->top--;
	return 0;
}

void seqstack_show(seq_pstack s)
{
	int i;
	for(i = 0; i <= s->top; i++)
	{
		printf("%d\t",s->data[i]);
	}
	printf("\n");
}

bool seqstack_is_full(seq_pstack s)
{
	if(s->top == MAXSIZE - 1)
		return true;
	else
		return false;
}

void seqstack_push(seq_pstack s, int num)
{
	int i,j;

	if(seqstack_is_full(s))
		return;

	//插入数据
	s->top++;
	s->data[s->top] = num;
}

void seqstack_init(seq_pstack *s)
{
	(*s) = (seq_pstack)malloc(sizeof(seq_stack));
	if(NULL == (*s))
	{
		printf("seqstack malloc failed!!\n");
		exit(1);
	}

	(*s)->top = -1;
}

