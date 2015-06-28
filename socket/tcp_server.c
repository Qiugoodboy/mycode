#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define BUFSIZE 128

int main(int argc, const char *argv[])
{
	int listenfd,connfd,peerlen,count,ret;
	char buf[BUFSIZE];
	struct sockaddr_in server_addr,client_addr;
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

	while(1)
	{
		if((connfd=accept(listenfd,(struct sockaddr *)&client_addr,&peerlen))==-1)
		{
			perror("accept");
			exit(-1);
		}
		printf( "have connect\n" );
		ret=fork();
		printf( "ret:%d\n" ,ret);
		if(ret<0)
		{
			perror("fork");
			exit(-1);
		}
		else if(ret==0)
		{
			printf("connect from address:%s port:%d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
			while(1)
			{
			count=recv(connfd,buf,7,0);
			if(count==0)
			{
				printf("close client!\n");
				exit(0);
			}
			printf("recv:%s",buf);
			if(send(connfd,buf,count,0)<0)
			{
				perror("send");
				exit(-1);
			}
			bzero(&buf,sizeof(buf));
			}
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
