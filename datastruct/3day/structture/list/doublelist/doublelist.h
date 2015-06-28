#ifndef __DOUBLELIST_H_
#define __DOUBLELIST_H_

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

//#define MAXSIZE 10

typedef struct doublelist{
	datatype data;
	struct doublelist *front,*next;
}double_list,*double_plist;


extern void doublelist_show(double_plist l);
extern void doublelist_init(double_plist *l);
extern void doublelist_create(double_plist l, int n);
extern void doublelist_sort(double_plist l);
extern void doublelist_del(double_plist l,int num);

#endif
