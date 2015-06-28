#include "btree.h"
int main(int argc, const char *argv[])
{
	btree_pnode b;

	printf("pls input btree:");
	btree_create(&b);

	printf("先序非递归遍历");
	btree_pre_order_t(b);
	printf("\n");
	printf("先序遍历");
	btree_pre_order(b);
	printf("\n");

	printf("中序遍历");
	btree_mid_order(b);
	printf("\n");

	printf("后序遍历");
	btree_post_order(b);
	printf("\n");

	printf("层次遍历");
	btree_level_order(b);
	printf("\n");

	return 0;
}


void btree_level_order(btree_pnode t)
{
	link_pqueue q;

	linkqueue_init(&q);
	while(t != NULL || !linkqueue_is_empty(q))
	{
		printf("%c",t->data);
		if(t->lchild != NULL)
			linkqueue_in(q, t->lchild);

		if(t->rchild != NULL)
			linkqueue_in(q, t->rchild);

		if(linkqueue_is_empty(q))
			break;
		else
		{
			linkqueue_out(q, &t);
		}
	}
}

void btree_pre_order_t(btree_pnode t)
{
	link_pstack s;

	linkstack_init(&s);

	while(t != NULL || !linkstack_is_empty(s))
	{
		while(t != NULL)
		{
			printf("%c",t->data);
			linkstack_push(&s, t);
			t = t->lchild;
		}

		if(linkstack_is_empty(s))
			break;
		else 
		{
			linkstack_pop(&s,&t);
			t = t->rchild;
		}
	}
}


void btree_pre_order(btree_pnode t)
{
	if( NULL != t)
	{
		printf("%c",t->data);
		btree_pre_order(t->lchild);
		btree_pre_order(t->rchild);
	}
}

void btree_mid_order(btree_pnode t)
{
	if( NULL != t)
	{
		btree_mid_order(t->lchild);
		printf("%c",t->data);
		btree_mid_order(t->rchild);
	}
}

void btree_post_order(btree_pnode t)
{
	if( NULL != t)
	{
		btree_post_order(t->lchild);
		btree_post_order(t->rchild);
		printf("%c",t->data);
	}
}

void btree_create(btree_pnode* t)
{
	char ch;

	scanf("%c",&ch);
	if(ch != '#')
	{
		(*t) = (btree_pnode)malloc(sizeof(btree_node));
		if(NULL == t)
		{
			printf("btree create failed!!\n");
			exit(1);
		}
		(*t)->data = ch;
		btree_create(&(*t)->lchild);
		btree_create(&(*t)->rchild);
	}else
	{
		(*t) = NULL;
	}
	return ;
}
