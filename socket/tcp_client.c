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
	int sock_client;
	struct sockaddr_in server_addr;
	char buf[BUFSIZE];

	if(argc<3)
	{
		printf("Usage:%s <ip> <port>\n",argv[0]);
		exit(-1);
	}

	if((sock_client=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket");
		exit(-1);
	}
	bzero(&server_addr,sizeof(server_addr));

	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr=inet_addr(argv[1]);


	if(connect(sock_client,(struct sockaddr *)&server_addr,sizeof(server_addr))==-1)
	{
		perror("connect");
		exit(-1);
	}
	while(1)
	{
		printf( "have connect\n" );
		if(recv(sock_client,buf,sizeof(buf),0)==0)
		{
			close(sock_client);
			exit(-1);
		}
		printf("%s",buf);
		bzero(buf,sizeof(buf));
		fgets(buf,sizeof(buf),stdin);
		/*if(atoi(buf)==1)
		{
			fgets(buf,sizeof(buf),stdin);
			send(sock_client,buf,sizeof(buf),0);
			fgets(buf,sizeof(buf),stdin);
			send(sock_client,buf,sizeof(buf),0);
		}*/
		if(strcmp(buf,"quit\n")==0)
		{
			perror("strcmp");
			exit(-1);
		}
		send(sock_client,buf,sizeof(buf),0);
		printf("%s",buf);
		bzero(buf,sizeof(buf));
	}
	close(sock_client);
	exit(0);
}
