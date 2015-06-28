#ifndef __FLIGHT_H_
#define __FLIGHT_H_
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<strings.h>
typedef struct flight
{
	char number[18];//航班号
	char staddress[18];//起点站
	char arraddress[18];//终点站
	char date[12];//班期
	char type[8];//机型
	char stime[10];//起飞时间
	char atime[10];//到达时间
	int value;//票价
	struct flight * front,*next;
}flight_t,*flight_p;
extern void head_message(flight_p *d);
extern void flight_add(flight_p *d);
extern void flight_all_show(flight_p p);
extern void flight_serach(flight_p p,int num,char* buf);
extern void flight_check(flight_p p);
extern void load_message(flight_p *d);
#endif
