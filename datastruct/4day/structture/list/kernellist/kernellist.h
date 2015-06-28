#ifndef __kernelLIST_H_
#define __kernelLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

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

typedef struct kernellist{
	datatype data;
	struct list_head list;
}kernel_list,*kernel_plist;


extern void kernellist_show(kernel_plist l);
extern void kernellist_init(kernel_plist *l);
extern void kernellist_create(kernel_plist l, int n);
extern void kernellist_sort(kernel_plist l);
extern void kernellist_del(kernel_plist l,int num);

#endif
