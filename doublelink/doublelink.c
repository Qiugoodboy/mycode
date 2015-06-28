#include<stdio.h>
#include"doublelink.h"
#include<stdlib.h>
#include<stdio.h>


int main(int argc, const char *argv[])
{
	doublelink_p dl;
	link_create_head(&dl);
	link_init(dl);
	link_sort(dl);
	link_show(dl);
	return 0;
}

void link_create_head(doublelink_p * l)
{
	(*l)=(doublelink_p)malloc(sizeof(doublelink_t));
	if((*l)==NULL)
	{
		printf("malloc error\n");
		exit(1);
	}
	(*l)->next=(*l);
	(*l)->front=(*l);
}

void link_init(doublelink_p l)
{
	doublelink_p new,q;
	int i;
	q=l;
	for(i=1;i<=10;i++)
	{
		new=(doublelink_p)malloc(sizeof(doublelink_t));
		if(new==NULL)
		{
			printf("malloc error!\n");
			exit(1);
		}
		new->num=i;
		new->next=q->next;
		new->front=q;
		q->next->front=new;
		q->next=new;
		q=q->next;
		new->next->front=new;
	}
}


void link_show(doublelink_p l)
{
	doublelink_p p;
	p=l->next;
	while(p->next!=l)
	{
		printf("%d\t",p->num);
		p=p->next;
	}
	printf("%d\t",p->num);
printf("\n");
}

void link_sort(doublelink_p l)
{
	doublelink_p p,q,tmp;
	int i;
	tmp=l->next;
	q=l->next;
	while(q->num!=10)
		q=q->next;
	while(tmp->num!=10)
	{
		if(tmp->num%2==0)
		{
			p=tmp;
			tmp=tmp->next;
			p->front->next=p->next;
			p->next->front=p->front;
			p->next=q->next;
			p->front=q;
			p->next->front=p;
			p->front->next=p;
		}
		else
			tmp=tmp->next;
	}
}







