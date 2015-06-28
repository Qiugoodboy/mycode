#ifndef __SEQLIST_H_
#define __SEQLIST_H_

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

typedef struct seqlist{
	datatype data[MAXSIZE];
	int last;
}seq_list,*seq_plist;


extern void seqlist_show(seq_plist l);
extern bool seqlist_is_full(seq_plist l);
extern void seqlist_insert(seq_plist l, int num);
extern void seqlist_init(seq_plist *l);
extern void seqlist_del(seq_plist l,int num);

#endif
