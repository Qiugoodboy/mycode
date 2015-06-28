#include<stdio.h>
#include"linklist.h"
#include<stdlib.h>
int main(int argc, const char *argv[])
{
	int num;
	printf("please input size of link:");
	scanf("%d",&num);
	link_p p;
	/*创建链表头*/
	creat_link_head(&p);
	/*插入链表*/
	insert_link(p,num);
	/*显示链表*/
	show_link(p);
	/*倒序*/
	sort_link(p);
	//显示链表
	show_link(p);
	return 0;
}

void creat_link_head(link_p *l)
{
	(*l)=(link_p)malloc(sizeof(link_t));
	(*l)->next=NULL;
}

void insert_link(link_p l,int n)
{
	int i,value;
	link_p q,p;
	p=l;
	for(i=0;i<n;i++)
	{
		printf("please input num:");
		scanf("%d",&value);
		q=(link_p)malloc(sizeof(link_t));
		q->num=value;
		q->next=p->next;
		p->next=q;
		p=p->next;
	}
}

void show_link(link_p l)
{
	link_p q;
	q=l->next;
	while(q!=NULL)
	{
		printf("%d\t",q->num);
		q=q->next;
	}
	printf("\n");
}
void sort_link(link_p l)
{
	link_p p,q;
	p=l->next;
	l->next=NULL;
	while(p!=NULL)
	{
	q=p;
	p=p->next;
	q->next=l->next;
	l->next=q;
	}
}
