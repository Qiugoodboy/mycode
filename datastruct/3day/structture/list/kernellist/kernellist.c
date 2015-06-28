#include "kernellist.h"
int main(int argc, const char *argv[])
{
	int num,ret;
	kernel_plist l;

	kernellist_init(&l);

	printf("pls input list len:");
	scanf("%d",&num);
	//创建表
	kernellist_create(l,num);
	kernellist_show(l);
#if 1
	//奇升序偶降序
	kernellist_sort(l);
	kernellist_show(l);
#endif
	return 0;
}

#if 1

void kernellist_sort(kernel_plist l)
{
	struct list_head *p,*q,*k;
	kernel_plist h;

	if(list_empty(&l->list))
		return ;
	//找插入基准
	k = l->list.prev;
	p = l->list.next;

	while(p != k)
	{
		h = list_entry(p, kernel_list, list);
		if(h->data%2 == 0)
		{
			//删除偶数q
			q = p;
			p = p->next;
			
			list_del(q);

			//把q插入到k后面
			list_add(q,k);
		}else
			p = p->next;
	}
}
#endif

void kernellist_show(kernel_plist l)
{
	kernel_plist pos;
	
	list_for_each_entry(pos, &l->list, list)
		printf("%d\t",pos->data);
	printf("\n");
}


void kernellist_create(kernel_plist l, int n)
{
	int i,num;
	kernel_plist new;//,p;
	//	p = l;

	for( i = 1; i <= n; i++)
	{
		//创建新的节点，赋值
		new = (kernel_plist) malloc(sizeof(kernel_list));
		if(NULL == new)
		{
			printf("kernellist create failed!!\n");
			exit(1);
		}
		new->data = i;
		//插入到表尾
		list_add_tail(&new->list, &l->list);
	}
}

void kernellist_init(kernel_plist *l)
{
	(*l) = (kernel_plist)malloc(sizeof(kernel_list));
	if(NULL == (*l))
	{
		printf("kernellist malloc failed!!\n");
		exit(1);
	}

	INIT_LIST_HEAD(&(*l)->list);
}
