#include "linklist.h"
int main(int argc, const char *argv[])
{
	int num,ret;
	link_plist l;

	linklist_init(&l);

	printf("pls input list len:");
	scanf("%d",&num);
	//创建表
	linklist_create(l,num);
	linklist_show(l);
#if 1
	//倒序
	linklist_sort(l);
	linklist_show(l);
#endif
	return 0;
}

#if 1
bool linklist_is_empty(link_plist l)
{
	if(l->next == NULL)
		return true;
	else 
		return false;
}
#endif

void linklist_sort(link_plist l)
{
	link_plist p,q;

	if(linklist_is_empty(l))
		return ;

	//设定头结点
	p = l->next;
	l->next = NULL;

	while(p != NULL)
	{
		//删除p指向节点
		q = p;
		p = p->next;
		
		//把删除的节点插入到表头
		q->next = l->next;
		l->next = q;
	}
}

void linklist_show(link_plist l)
{
	link_plist p = l->next;

	while(NULL != p)
	{
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("\n");
}


void linklist_create(link_plist l, int n)
{
	int i,num;
	link_plist new,p;
	p = l;

	for( i =0; i < n; i++)
	{
		printf("pls input num：");
		scanf("%d",&num);
		//创建新的节点，赋值
		new = (link_plist) malloc(sizeof(link_list));
		if(NULL == new)
		{
			printf("linklist create failed!!\n");
			exit(1);
		}
		new->data = num;
		//插入表尾
		new->next = p->next;
		p->next = new;

		p = p->next;
	}
}

void linklist_init(link_plist *l)
{
	(*l) = (link_plist)malloc(sizeof(link_list));
	if(NULL == (*l))
	{
		printf("linklist malloc failed!!\n");
		exit(1);
	}

	(*l)->next = NULL;
}
