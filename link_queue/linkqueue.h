#ifndef __LINKQUEUE_H_
#define __LINKQUEUE_H_
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct link_queue
{
	int data;
	struct link_queue *next;
}link_queue_t,*link_queue_p;

typedef struct manange
{
	link_queue_p front,rear;
}manange_t,*manange_p;
extern void queue_init(manange_p *m,link_queue_p *q);
extern void queue_input(manange_p m,link_queue_p q,int num);
extern void queue_output(manange_p m,link_queue_p q,int *num);
extern bool queue_isn_empty(manange_p m);
extern void queue_show(manange_p m);
#endif
