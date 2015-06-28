#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define BUFFER_SIZE 512


struct message
{
	long msg_type;
	int port;
	char user[BUFFER_SIZE];
};

int main(int argc, const char *argv[])
{
	int qid,length;
	key_t key;
	struct message msg,msg1;

	length=sizeof(msg.port)+sizeof(msg.user);

	if((key=ftok(".",'a'))==-1)
	{
		perror("ftok");
		exit(1);
	}
	
	if((qid=msgget(key,IPC_CREAT|0666))==-1)
	{
		perror("msgget");
		exit(1);
	}
	printf("Open queue %d\n",qid);

		if(msgrcv(qid,(void *)&msg,length,0,0)<0)
		{
			perror("msgrcv");
			exit(1);
		}
		printf("The message from process %ld :port :%d, user: %s\n",msg.msg_type,msg.port,msg.user);

		if(msgrcv(qid,(void *)&msg1,length,0,0)<0)
		{
			perror("msgrcv");
			exit(1);
		}
		printf("The message from process %ld :port :%d, user: %s\n",msg1.msg_type,msg1.port,msg1.user);
	if(msgctl(qid,IPC_RMID,NULL)<0)
	{
		perror("msgctl");
		exit(1);
	}
	exit(0);
	return 0;
}
