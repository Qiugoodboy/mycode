#ifndef __BTREE_H_
#define __BTREE_H_

#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"
#include "linkqueue.h"

typedef char datatype_t;

typedef struct btreenode{
	datatype_t data;
	struct btreenode *lchild,*rchild;
}btree_node,*btree_pnode;

extern void btree_pre_order(btree_pnode t);
extern void btree_create(btree_pnode* t);
extern void btree_mid_order(btree_pnode t);
extern void btree_post_order(btree_pnode t);
extern void btree_pre_order_t(btree_pnode t);
extern void btree_level_order(btree_pnode t);

#endif 
