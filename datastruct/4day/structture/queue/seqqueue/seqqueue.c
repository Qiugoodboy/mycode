#include "seqqueue.h"
int main(int argc, const char *argv[])
{
	int num,ret;
	seq_pqueue q;

	seqqueue_init(&q);
	while(1)
	{
		printf("pls input in queue num:");
		ret = scanf("%d",&num);
		if(ret == 1)
		{
			seqqueue_in(q, num);
			seqqueue_show(q);
		}
		else{
			ret = seqqueue_out(q,&num);
			if(ret == -1)
			{
				printf("this queue is empty!\n");
			}else
			{
				seqqueue_show(q);
				printf("queue out:%d\n",num);
			}

			while(getchar() != '\n');
		}

	}
	return 0;
}

void seqqueue_show(seq_pqueue q)
{
	int i;
	for(i = (q->front + 1)%MAXSIZE; i != (q->rear + 1)%MAXSIZE; i = (i + 1)%MAXSIZE)
		printf("%d\t",q->data[i]);
	printf("\n");
}

bool seqqueue_is_empty(seq_pqueue q)
{
	if(q->front == q->rear)
		return true;
	else 
		return false;
}

int seqqueue_out(seq_pqueue q, int *num)
{
	if(seqqueue_is_empty(q))
		return -1;

	q->front = (q->front + 1)%MAXSIZE;
	*num = q->data[q->front];

	return 0;
}

bool seqqueue_is_full(seq_pqueue q)
{
	if(q->front == (q->rear + 1)%MAXSIZE)
		return true;
	else 
		return false;
}

void seqqueue_in(seq_pqueue q,int num)
{
	if(seqqueue_is_full(q))
		return;

	q->rear = (q->rear + 1)%MAXSIZE;
	q->data[q->rear] = num;
}

void seqqueue_init(seq_pqueue *q)
{
	(*q) = (seq_pqueue)malloc(sizeof(seq_queue));
	if(NULL == *q)
	{
		printf("queue malloc failed!!\n");
		exit(1);
	}
	(*q)->front = MAXSIZE - 1;
	(*q)->rear = MAXSIZE - 1;
}
