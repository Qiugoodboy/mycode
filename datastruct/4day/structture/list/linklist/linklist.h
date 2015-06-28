#ifndef __linkLIST_H_
#define __linkLIST_H_

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

typedef struct linklist{
	datatype data;
	struct linklist *next;
}link_list,*link_plist;


extern void linklist_show(link_plist l);
extern void linklist_init(link_plist *l);
extern void linklist_create(link_plist l, int n);
extern void linklist_sort(link_plist l);
extern void linklist_del(link_plist l,int num);
extern void josephu_create(link_plist *l, int num);
extern void josephu_show(link_plist l);

#endif
