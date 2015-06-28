#ifndef __DOUBLELINK_H_
#define __DOUBLELINK_H_

typedef struct doublelink
{
	struct doublelink *front,*next;
	int num;
}doublelink_t,*doublelink_p;

extern void link_create_head(doublelink_p *l);
extern void link_init(doublelink_p l);
extern void link_sort(doublelink_p l);
extern void link_show(doublelink_p l);
#endif
