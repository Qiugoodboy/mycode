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
	int sockfd;
	struct sockaddr_in servaddr,clienaddr;
	char buf[BUFSIZE];
	int peerlen;

	if(argc<3)
	{
		printf("Usage :%s <ip> <port>!\n",argv[0]);
		exit(-1);
	}
	//创建套接字
	if((sockfd=socket(AF_INET,SOCK_DGRAM,0))==-1)
	{
		perror("socket");
		exit(-1);
	}

	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(atoi(argv[2]));
	servaddr.sin_addr.s_addr=inet_addr(argv[1]);
	//绑定地址
	if(bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))==-1)
	{
		perror("bind");
		exit(-1);
	}

	printf("bind success!\n");
	peerlen=sizeof(clienaddr);

	while(1)
	{
		if(recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&servaddr,&peerlen)<0)
		{
			perror("recvfrom");
			exit(-1);
		}

		printf("recv:%s\n",buf);

		strcpy(buf,"welcome server");

		sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&servaddr,peerlen);
	}
	return 0;
}
