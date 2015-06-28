#ifndef __TCP_SERVER_H_
#define __TCP_SERVER_H_
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/msg.h>
#include<sys/ipc.h>
int flag=0;
#define USER_SIZE 50
typedef struct clidata
{	struct in_addr addr;
	char * user;
	unsigned short int port;
	struct clidata * pre,*next;
}clidata_t,*clidata_p;

typedef struct convdata
{
	long msg_type;
	struct in_addr addr;
	char user[USER_SIZE];
	unsigned short int port;
}convdata_t;
extern void insert(clidata_p *ptr,convdata_t conv);
int length;
//extern bool search(char *user_t,\
//	clidata_p *ptr,clidata_p *ret);
//extern bool delete(chidata_p \
//		*ptr,char *user);
extern void show(clidata_p * ptr);
#endif
