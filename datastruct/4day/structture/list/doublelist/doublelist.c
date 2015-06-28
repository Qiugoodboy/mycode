#include "doublelist.h"
int main(int argc, const char *argv[])
{
	int num,ret;
	double_plist l;

	doublelist_init(&l);

	printf("pls input list len:");
	scanf("%d",&num);
	//创建表
	doublelist_create(l,num);
	doublelist_show(l);
#if 1
	//奇升序偶降序
	doublelist_sort(l);
	doublelist_show(l);
#endif
	return 0;
}

#if 1
bool doublelist_is_empty(double_plist l)
{
	if(l->next == l)
		return true;
	else 
		return false;
}

void doublelist_sort(double_plist l)
{
	double_plist p,q,k;

	if(doublelist_is_empty(l))
		return ;
#if 0

	//找插入基准
	k = l->front;
	p = l->next;

	while(p != k)
	{
		//找到偶数
		while(p->data%2 && p != k)
			p = p->next;

		if(p != k)
		{
			//删除偶数q
			q = p;
			p = p->next;
			
			q->front->next = q->next;
			q->next->front = q->front;

			//把q插入到k后面
			q->next = k->next;
			k->next = q;
			q->next->front = q;
			q->front = k;
		}
	}
#else
	//找插入基准
	k = l->front;
	p = l->next;

	while(p != k)
	{
		if(p->data%2 == 0)
		{
			//删除偶数q
			q = p;
			p = p->next;
			
			q->front->next = q->next;
			q->next->front = q->front;

			//把q插入到k后面
			q->next = k->next;
			k->next = q;
			q->next->front = q;
			q->front = k;
		}else
			p = p->next;
	}
#endif
}
#endif

void doublelist_show(double_plist l)
{
	double_plist p = l->next;

	while(l != p)
	{
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("\n");
}


void doublelist_create(double_plist l, int n)
{
	int i,num;
	double_plist new;//,p;
	//	p = l;

	for( i = 1; i <= n; i++)
	{
		//创建新的节点，赋值
		new = (double_plist) malloc(sizeof(double_list));
		if(NULL == new)
		{
			printf("doublelist create failed!!\n");
			exit(1);
		}
		new->data = i;
#if 0
		//插入表尾
		new->next = p->next;
		p->next = new;
		new->next->front = new;
		new->front = p;

		p = p->next;
#else 
		//插入到表头前面（插入表尾）
		new->front = l->front;
		new->next = l;
		l->front->next = new;
		l->front = new;
#endif
	}
}

void doublelist_init(double_plist *l)
{
	(*l) = (double_plist)malloc(sizeof(double_list));
	if(NULL == (*l))
	{
		printf("doublelist malloc failed!!\n");
		exit(1);
	}

	(*l)->next = (*l);
	(*l)->front = (*l);
}
