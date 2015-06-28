#include "hash.h"
#define N 11
#define M 13
int main(int argc, const char *argv[])
{
	hash_ptbl hp;
	int a[N] = {23,34,14,38,46,16,68,15,07,31,26};
	int m,ret,key;

	//计算hash长度
	m = ceil(N/0.75);

	//初始化hash表
	hash_tbl_init(m,&hp);

	//创建hash表
	hash_tbl_create(a,N,hp);

	//查找hash表
#if 1
	while(1)
	{
		printf("pls input key:");
		ret = scanf("%d",&key);
		if(ret == 1)
		{
			ret = hash_tbl_search(hp,key);
			if(ret >= 0)
			{
				printf("key: %d is in %d\n",key,ret);
			}else
				printf("key is not find!!'\n");
		}
		else
			break;
	}
#endif
	return 0;
}
hash_tbl_search(hash_ptbl hp,int key)
{
	int val,flag = 0;
	link_pnode p;

	//计算位置
	val = key%M;

#if 0
	//线性探查法查找数据
	while(hp->data[val] != key && flag <= hp->len)
	{
		val++;
		flag++;
	}
#else 
	p = hp->data[val];
	while(p != NULL)
	{
		if(p->data == key)
			break;

		p = p->next;
	}

	if(p != NULL)
		return val;
	else 
		return -1;

#endif
	
	//获取数据
	if(flag > hp->len)
		return -1;
	else 
		return val;
}

void hash_tbl_show(hash_ptbl hp)
{
	int i;
	link_pnode p;

#if 0
	for(i = 0; i < hp->len; i++)
	{
		printf("hp->data[%d] = %d\n",i,hp->data[i]);
	}
	printf("*************************\n");
#else
	for(i = 0; i < hp->len; i++)
	{
		p = hp->data[i];
		printf("hp->data[%d]",i);
		while(p !=NULL)
		{
			printf("---> %d",p->data);
			p = p->next;
		}
		printf("\n");
	}
	printf("*************************\n");
#endif
}

void hash_tbl_create(int *a, int n, hash_ptbl hp)
{
	int i,val;
	link_pnode new;
	
	for(i = 0; i < n; i++)
	{
 		//保留余数法计算地址
		val = a[i]%M;
#if 0
		//线性探查发处理冲突
		while(hp->data[val] != -1)
			val++;
		//保存数据
		hp->data[val] = a[i];
#else 
		//新建节点
		new = (link_pnode) malloc(sizeof(link_node));
		if(NULL == new)
		{
			printf("new malloc failed!\n");
			exit(1);
		}
		new->data = a[i];

		//插入元素
		new->next = hp->data[val];
		hp->data[val] = new;

#endif
		hash_tbl_show(hp);
		sleep(1);
	}
}


void hash_tbl_init(int m,hash_ptbl *hp)
{
	int i;

	(*hp) = (hash_ptbl)malloc(sizeof(hash_tbl));
	if(NULL == *hp)
	{
		printf("hash_tbl_init failed\n");
		exit(1);
	}
	
	(*hp)->len = m;

	(*hp)->data = (link_pnode*) malloc(sizeof(link_pnode) * m);
	if(NULL == (*hp)->data)
	{
		printf("hash_tbl_init failed\n");
		exit(1);
	}

#if 0 
	for(i = 0; i < m; i++)
		(*hp)->data[i] = -1;
#else 
	for(i = 0; i < m; i++)
		(*hp)->data[i] = NULL;
#endif

}
