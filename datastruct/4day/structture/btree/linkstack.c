#include "linkstack.h"
#if 0
int main(int argc, const char *argv[])
{
	int num,ret;
	link_pstack s;

	linkstack_init(&s);

	while(1)
	{
		printf("pls input num:");
		ret = scanf("%d",&num);
		if(1 == ret)
		{
			linkstack_push(&s, num);
			linkstack_show(s);
		}else 
		{
			ret = linkstack_pop(&s, &num);
			if(ret == -1)
				printf("stack is emtyp!\n");
			else
			{
				linkstack_show(s);
				printf("pop num is:%d\n",num);
			}
			while(getchar() != '\n');
		}
	}
	return 0;
}
#endif

bool linkstack_is_empty(link_pstack s)
{
	if(s == NULL)
		return true;
	else 
		return false;
}

int linkstack_pop(link_pstack *s,datatype *num)
{
	link_pstack p;

	if(linkstack_is_empty(*s))
		return -1;

	//出栈
	p = (*s);
	(*s) = (*s)->next;
	*num = p->data;
	free(p);

	return 0;
}


void linkstack_push(link_pstack *s, datatype num)
{
	link_pstack new;

	//创建节点
	new = (link_pstack)malloc(sizeof(link_stack));
	if(NULL == new)
	{
		printf("linkstack push failed!\n");
		exit(1);
	}
	new->data = num;

	//插入数据
	new->next = (*s);
	(*s) = new;
	}

void linkstack_init(link_pstack *s)
{
	(*s) = NULL;
}

