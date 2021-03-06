#ifndef __linkQUEUE_H_
#define __linkQUEUE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10

typedef struct btreenode * datatype_q;

typedef struct linkqueuenode{
	datatype_q data;
	struct linkqueuenode* next;
}link_queuenode,*link_pqueuenode;

typedef struct linkqueue{
	link_pqueuenode front,rear;
}link_queue,*link_pqueue;

extern void linkqueue_init(link_pqueue *q);
extern void linkqueue_in(link_pqueue q,datatype_q num);
extern bool linkqueue_is_full(link_pqueue q);
extern int linkqueue_out(link_pqueue q, datatype_q* num);
extern void linkqueue_show(link_pqueue q);
extern bool linkqueue_is_empty(link_pqueue q);
#endif
