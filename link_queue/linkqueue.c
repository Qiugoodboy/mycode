#include"linkqueue.h"
int main(int argc, const char *argv[])
{
	manange_p m;
	link_queue_p q;
	int ret,num;
	queue_init(&m,&q);
	while(1)
	{
	printf("pls input num:");
	ret=scanf("%d",&num);
	if(1==ret)
	{
		queue_input(m,q,num);
		queue_show(m);
	}
	else
	{
		if(queue_isn_empty(m))
		{
			queue_output(m,q,&num);
			printf("the output num is %d\n",num);
			queue_show(m);
		}
		else
		{
			printf("the queue is empty\n");
		}
		while(getchar()!='\n');
	}
	}
	return 0;
}

void queue_init(manange_p *m,link_queue_p *q)
{
	(*m)=(manange_p)malloc(sizeof(manange_t));
	if(NULL==(*m))
	{
		printf("malloc error\n");
		exit(-1);
	}
	(*q)=(link_queue_p)malloc(sizeof(link_queue_t));
	if(NULL==(*q))
	{
		printf("malloc error\n");
		exit(-1);
	}
	(*q)->next=NULL;
	(*m)->front=(*q);
	(*m)->rear=(*q);
}

void queue_input(manange_p m,link_queue_p q,int num)
{
	link_queue_p new;
	new=(link_queue_p)malloc(sizeof(link_queue_t));
	if(NULL==new)
	{
		printf("malloc error\n");
		exit(-1);
	}
	new->data=num;
	new->next=m->rear->next;
	m->rear->next=new;
	m->rear=new;
}

void queue_output(manange_p m,link_queue_p q,int *num)
{
	link_queue_p p;
	p=m->front;
	(*num)=m->front->next->data;
	m->front=m->front->next;
	free(p);
}

bool queue_isn_empty(manange_p m)
{
	if(m->front!=m->rear)
		return true;
	else
		return false;
}

void queue_show(manange_p m)
{
	link_queue_p p;
	p=m->front->next;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
}







