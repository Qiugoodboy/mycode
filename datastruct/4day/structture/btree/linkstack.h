#ifndef __linkstack_H_
#define __linkstack_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "btree.h"

#if 0
typedef struct student{
	int num;
	char name[20];
	int age;
	float score;
}datatype;
#endif

typedef struct btreenode *datatype;

#define MAXSIZE 10

typedef struct linkstack{
	datatype data;
	struct linkstack *next;
}link_stack,*link_pstack;


extern bool linkstack_is_full(link_pstack l);
extern void linkstack_init(link_pstack *l);
extern void linkstack_push(link_pstack *s, datatype num);
extern int linkstack_pop(link_pstack *s,datatype *num);
extern bool linkstack_is_empty(link_pstack s);

#endif
