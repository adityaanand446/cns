#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>

#define MAXLINE 1024
int main()
{
	int sockfd,portno,n;
	socklen_t len;
	char msg[1024];
	struct sockaddr_in servaddr,cliaddr;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=INADDR_ANY;
	printf("Enter the portno:\t");
	scanf("%d",&portno);
	servaddr.sin_port=htons(portno);
	printf("\n\n Binded");
	bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	printf("\n\n Listening...");
	for(;;)
	{
	      printf("\n ");
	     len=sizeof(cliaddr);
	     n=recvfrom(sockfd,msg,MAXLINE,0,(struct sockaddr*)&cliaddr,&len);
	     printf("\n server :  Client's Message : %s \n  and echo back \n",msg);
	     sendto(sockfd,msg,n,0,(struct sockaddr*)&cliaddr,len);
	    
	}
	return 0;
}
