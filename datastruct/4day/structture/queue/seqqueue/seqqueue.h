#ifndef __SEQQUEUE_H_
#define __SEQQUEUE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10
typedef int datatype;

typedef struct seqqueue{
	datatype data[MAXSIZE];
	int front,rear;
}seq_queue,*seq_pqueue;

extern void seqqueue_init(seq_pqueue *q);
extern void seqqueue_in(seq_pqueue q,int num);
extern bool seqqueue_is_full(seq_pqueue q);
extern int seqqueue_out(seq_pqueue q, int *num);
extern void seqqueue_show(seq_pqueue q);
#endif
