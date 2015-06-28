#ifndef __SEQstack_H_
#define __SEQstack_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#if 0
typedef struct student{
	int num;
	char name[20];
	int age;
	float score;
}datatype;
#endif

typedef int datatype;

#define MAXSIZE 10

typedef struct seqstack{
	datatype data[MAXSIZE];
	int top;
}seq_stack,*seq_pstack;


extern void seqstack_show(seq_pstack l);
extern bool seqstack_is_full(seq_pstack l);
extern void seqstack_init(seq_pstack *l);
extern void seqstack_push(seq_pstack s, int num);
extern int seqstack_pop(seq_pstack s,int *num);

#endif
