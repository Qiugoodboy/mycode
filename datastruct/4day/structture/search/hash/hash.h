#ifndef __HASH_H_
#define __HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef int datatype;

typedef struct linknode{
	datatype data;
	struct linknode *next;
}link_node,*link_pnode;

typedef struct hashtbl{
	link_pnode *data;
	int len;
}hash_tbl,*hash_ptbl;

extern void hash_tbl_create(int *a, int n, hash_ptbl hp);
extern void hash_tbl_show(hash_ptbl hp);
extern void hash_tbl_init(int m,hash_ptbl *hp);
extern int hash_tbl_search(hash_ptbl hp,int key);
#endif
