#include "seqlist.h"
int main(int argc, const char *argv[])
{
	int num,ret;
	seq_plist l;

	seqlist_init(&l);

	while(1)
	{
		printf("pls input num:");
		ret = scanf("%d",&num);
		if(1 == ret)
		{
			if(num > 0)
				seqlist_insert(l,num);
#if 1
			else 
				seqlist_del(l,-num);
#endif
		}else 
			break;
		seqlist_show(l);
	}
	return 0;
}
bool seqlist_is_empty(seq_plist l)
{
	if(l->last == -1)
		return true;
	else 
		return false;
}

void seqlist_del(seq_plist l,int num)
{
	int i;
	if(seqlist_is_empty(l))
		return;

	//找到这个元素的位置
	for(i = 0; i <= l->last; i++)
	{
		if(l->data[i] == num)
			break;
	}

	//删除元素
	if(i <= l->last)
	{
		for(; i <= l->last-1; i++)
			l->data[i] = l->data[i+1];
		l->last--;
	}
	
}

void seqlist_show(seq_plist l)
{
	int i;
	for(i = 0; i <= l->last; i++)
	{
		printf("%d\t",l->data[i]);
	}
	printf("\n");
}

bool seqlist_is_full(seq_plist l)
{
	if(l->last == MAXSIZE - 1)
		return true;
	else
		return false;
}

void seqlist_insert(seq_plist l, int num)
{
	int i,j;

	if(seqlist_is_full(l))
		return;

	//找到插入的位置
	for(i = 0; l->data[i] < num && i <= l->last; i++);

	//移动元素
	for(j = l->last; j >= i; j--)
	{
		l->data[j+1] = l->data[j]; 
	}


	//插入元素
	l->last++;
	l->data[i] = num;
}

void seqlist_init(seq_plist *l)
{
	(*l) = (seq_plist)malloc(sizeof(seq_list));
	if(NULL == (*l))
	{
		printf("seqlist malloc failed!!\n");
		exit(1);
	}

	(*l)->last = -1;
}
