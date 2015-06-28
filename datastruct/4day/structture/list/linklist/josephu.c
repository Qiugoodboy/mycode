#include "linklist.h"
int main(int argc, const char *argv[])
{
	link_plist l;
	int n,ret;
	//创建单向循环链表
	printf("pls input game num:");
	scanf("%d",&n);
	josephu_create(&l, n);
	josephu_show(l);
#if 1
	//数n出局
	printf("pls input num:");
	scanf("%d",&n);
	ret = josephu(l, n);
	printf("last people:%d\n",ret);
#endif
	return 0;
}

int josephu(link_plist l, int n)
{
	link_plist p = l,q;
	int i;

	while(p->next != p)
	{
	//把p移动到删除的前一个位置
		for(i = 0; i < n-2; i++)
			p = p->next;
	//删除元素
		q = p->next;
		p->next = q->next;
		printf("%d\t",q->data);
		free(q);
	//p移到下一个位置
		p = p->next;
	}
	printf("\n");

	return p->data;
}

void josephu_show(link_plist l)
{
	link_plist p = l;
	
	while(p->next != l)
	{
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("%d\t",p->data);
	printf("\n");

}

void josephu_create(link_plist *l, int num)
{
	link_plist new,p;
	int i;

	for(i = 1; i <= num; i++)
	{
		if(1 == i)
		{
			(*l) = (link_plist) malloc(sizeof(link_list));
			if(NULL == new)
			{
				printf("josephu create filed!!\n");
				exit(1);
			}
			(*l)->data = i;
			(*l)->next = (*l);
			
			p = *l;
		}
		else
		{
			new = (link_plist) malloc(sizeof(link_list));
			if(NULL == new)
			{
				printf("josephu create filed!!\n");
				exit(1);
			}
			new->data = i;

			//插入到表尾
			new->next = p->next;
			p->next = new;

			p = p->next;
		}
	}
}
