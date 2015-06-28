#include "linkqueue.h"
#if 0
int main(int argc, const char *argv[])
{
	int num,ret;
	link_pqueue q;

	linkqueue_init(&q);
	while(1)
	{
		printf("pls input in queue num:");
		ret = scanf("%d",&num);
		if(ret == 1)
		{
			linkqueue_in(q, num);
			linkqueue_show(q);
		}
		else{
			ret = linkqueue_out(q,&num);
			if(ret == -1)
			{
				printf("this queue is empty!\n");
			}else
			{
				linkqueue_show(q);
				printf("queue out:%d\n",num);
			}

			while(getchar() != '\n');
		}

	}
	return 0;
}
void linkqueue_show(link_pqueue q)
{
	link_pqueuenode p;

	for(p = q->front->next; p != NULL; p = p->next)
		printf("%d\t",p->data);
	printf("\n");
}

#endif
bool linkqueue_is_empty(link_pqueue q)
{
	if(q->front == q->rear)
		return true;
	else 
		return false;
}

int linkqueue_out(link_pqueue q, datatype_q*num)
{
	link_pqueuenode p;

	if(linkqueue_is_empty(q))
		return -1;

	p = q->front;
	q->front = p->next;
	free(p);
	(*num) = q->front->data;


	return 0;
}


void linkqueue_in(link_pqueue q,datatype_q num)
{
	link_pqueuenode new;

	new = (link_pqueuenode)malloc(sizeof(link_queuenode));
	if(NULL == new)
	{
		printf("queue in failed!!\n");
		exit(1);
	}
	new->data = num;
	
	new->next = NULL; //new->next = q->rear->next;
	q->rear->next = new;
	q->rear = new;	//q->rear = q->rear->next;


}

void linkqueue_init(link_pqueue *q)
{
	(*q) = (link_pqueue)malloc(sizeof(link_queue));
	if(NULL == *q)
	{
		printf("queue malloc failed!!\n");
		exit(1);
	}

	(*q)->front = (link_pqueuenode)malloc(sizeof(link_queuenode));
	if(NULL == (*q)->front)
	{
		printf("queue malloc failed!!\n");
		exit(1);
	}

	(*q)->front->next = NULL;
	(*q)->rear = (*q)->front;
}
