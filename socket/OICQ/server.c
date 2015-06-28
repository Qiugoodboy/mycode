#include"tcp_server.h"
#define BUFSIZE 128
#define MAXSIZE 128
int main(int argc, const char *argv[])
{
	length=sizeof(convdata_t);
	char buf[BUFSIZE],passwd[BUFSIZE],user[BUFSIZE],item[BUFSIZE],*ptr;
	FILE *fp;
	int listenfd,connfd,peerlen,ret,test;
	struct sockaddr_in server_addr,client_addr;
	clidata_p Link;
	if((listenfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket_server");
		exit(-1);
	}

	if(argc<3)
	{
		printf("Usage:%s <ip> <port>\n",argv[0]);
		exit(0);
	}

	bzero(&server_addr,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons((short)atoi(argv[2]));
	server_addr.sin_addr.s_addr=inet_addr(argv[1]);

	if(bind(listenfd,(struct sockaddr *)&server_addr,sizeof(server_addr))<0)
	{
		perror("bind");
		exit(-1);
	}

	if(listen(listenfd,10)==-1)
	{
		perror("listen");
		exit(-1);
	}

	printf("Listening...\n");

	peerlen=sizeof(client_addr);

	if((fp=fopen("data.txt","r+"))<0)
	{
		perror("fopen");
		exit(-1);
	}
	while(1)
	{
		key_t key;
		int qid;
		convdata_t msg;
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
		
		if(msgrcv(qid,(void *)&msg,length,0,0)<0)
		{
			perror("msgrcv");
			exit(1);
		}

		insert(&Link,msg);
		show(&Link);
		if((connfd=accept(listenfd,(struct sockaddr *)&client_addr,&peerlen))==-1)
		{
			perror("accept");
			exit(-1);
		}
		ret=fork();
		if(ret<0)
		{
			perror("fork");
			exit(-1);
		}
		else if(ret==0)
		{
			int qid;
			key_t key;
			convdata_t conv;
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
			printf("connect from address:%s port:%d\n",inet_ntoa\
					(client_addr.sin_addr),ntohs(client_addr.sin_port));
			send(connfd,"1\tzhuce\n2\tlogin\n>",18,0);
			if(recv(connfd,buf,sizeof(buf),0)<0)
			{
				perror("recv");
				exit(-1);
			}
			if(atoi(buf)==1)
			{
				send(connfd,"zhuce\nuser>",12,0);
				recv(connfd,user,sizeof(user),0);
				send(connfd,"passwd>",8,0);
				recv(connfd,passwd,sizeof(passwd),0);
				fseek(fp,0,SEEK_END);
				fprintf(fp,"%s%s",user,passwd);
				send(connfd,"zhuce succecc!",15,0);	
			}
			else if(atoi(buf)==2)
			{
				send(connfd,"user>",6,0);
				recv(connfd,buf,sizeof(buf),0);
				ptr=buf;
				while(*(ptr++)!='\n');
				*(ptr-1)='\0';
				printf("user is %s\n",buf);
				while(fscanf(fp,"%s\n%s\n",user,passwd)!=-1)
				{
					printf("user :%s\n",user);
					printf("passwd :%s\n",passwd);
					if(strcmp(user,buf)==0)
					{
						bzero(buf,sizeof(buf));
						send(connfd,"passwd>",9,0);
						if(recv(connfd,buf,sizeof(buf),0)<0)
						{
							perror("recv");
							exit(-1);
						}
						ptr=buf;
						while(*(ptr++)!='\n');
						*(ptr-1)='\0';
						if(strcmp(buf,passwd)==0)
						{
							send(connfd,"login succecc!",16,0);
							conv.addr=client_addr.sin_addr;
							conv.port=client_addr.sin_port;
							conv.msg_type=getpid();
							strcpy(conv.user,user);
							if(msgsnd(qid,&conv,length,0)==-1)
							{
								perror("msgsnd");
								exit(1);
							}
							break;
						}
						else
						{
							send(connfd,"login error!",15,0);
							close(connfd);
							exit(-1);
						}
					}
					else
					{
						send(connfd,"again\nuser>",12,0);
						recv(connfd,user,sizeof(user),0);
					}
				}

			}
			fseek(fp,0,SEEK_SET);
			send(connfd,"no this user...",16,0);
			close(connfd);
			exit(-1);
		}
		else
		{
			close(connfd);
		}

	}

	close(connfd);

	exit(0);
	return 0;
}
void insert(clidata_p *ptr,convdata_t conv)
{
	
	if(flag==0)
	{
		(*ptr)=(clidata_p)malloc(sizeof(clidata_t));
		if((*ptr)==NULL)
		{
			perror("malloc");
			exit(-1);
		}
		printf("first\n");
		(*ptr)->addr=conv.addr;
		(*ptr)->port=conv.port;
		(*ptr)->user=conv.user;
		(*ptr)->pre=(*ptr);
		(*ptr)->next=(*ptr);
		flag=1;
	}
	else if(1==flag)
	{
		clidata_p p;
		p=(clidata_p)malloc(sizeof(clidata_t));
		if(p==NULL)
		{
			perror("malloc");
			exit(-1);
		}
		p->addr=conv.addr;
		p->port=conv.port;
		p->user=conv.user;
		p->pre=(*ptr)->pre;
		(*ptr)->pre->next=p;
		p->next=(*ptr);
		(*ptr)->pre=p;
		printf("second\n");
	}
}
//bool search(char *user_t,clidata_p *ptr,clidata_p *ret)
//{
//	clidata_p val;
//	val=(*ptr);
//	while(val->next!=(*ptr))
//	{
//		if(strcmp(val->user,user_t)==0)
//		{
//			ret=&val;
//			return true;//返回true搜索成功
//		}
//		else
//		{
//			val=val->next;
//		}
//	}
//	if(strcmp(val->user,user_t)==0)
//	{
//		ret=&val;
//		return true;
//	}
//	return false;//返回false表示搜索失败
//}

void show(clidata_p * ptr)
{
	clidata_p p;
	p=(*ptr);
	while(p->next!=(*ptr))
	{
		printf("ipaddr :%s,port :%d\n",inet_ntoa(p->addr),ntohs(p->port));
		p=p->next;
	}
	printf("ipaddr :%s,port :%d\n",inet_ntoa(p->addr),ntohs(p->port));
}
//bool delete(chidata_p *ptr,char *user)
//{
//	clidata_p val,ret;
//	val=(*ptr);
//	while(val->next!=(*ptr))
//	{
//		if(strcmp(val->user,user_t)==0)
//		{
//			ret=val;
//			val->pre->next=val->next;
//			val->next->pre=val->pre;
//			free(ret);
//		return true;
//		}
//		else
//		{
//			val=val->next;
//		}
//	}
//	if(strcmp(val->user,user_t)==0)
//	{
//		ret=val;
//		val->pre->next=val->next;
//		val->next->pre=val->pre;
//		free(ret);
//		return true;
//	}
//	return false;//返回false表示搜索失败
//}
