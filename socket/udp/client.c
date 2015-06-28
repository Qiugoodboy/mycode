
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
	char buf[BUFSIZE]="hello server!";
	int sockfd;
	struct sockaddr_in servaddr;

	if(argc<3)
	{
		printf("Usage : <ip><port>\n");
		exit(-1);
	}
	//创建套接字
	if((sockfd=socket(AF_INET,SOCK_DGRAM,0))==-1)
	{
		perror("socket");
		exit(-1);
	}
	//填充地址
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(atoi(argv[2]));
	servaddr.sin_addr.s_addr=inet_addr(argv[1]);

	sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&servaddr,sizeof(servaddr));

	recvfrom(sockfd,buf,sizeof(buf),0,NULL,NULL);

	printf("recv: %s\n",buf);

	return 0;
}
