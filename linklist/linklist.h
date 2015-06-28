#ifndef __LINKLIST_H_
#define __LINKLIST_H_

typedef struct link
{
	int num;
	struct link * next;
}link_t,*link_p;

extern void creat_link_head(link_p *l);
extern void insert_link(link_p l,int n);
void show_link(link_p l);
void sort_link(link_p l);

#endif
