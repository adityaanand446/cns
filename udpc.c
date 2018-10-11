#include<string.h>
#include<arpa/inet.h>
#include<stdio.h>
#define MAXLINE 1024
int main()
{
int sockfd,portno,host[20];
int n;
socklen_t len;
char sendline[1024],recvline[1024];
struct sockaddr_in servaddr;
strcpy(sendline,"");
bzero(host,20);
printf("Enter \n 0 for local host \n otherwise type ip address of server\n");
scanf("%s",&host);
if(strcmp(host,"0")==0)
	strcpy(host,"127.0.0.1");
printf("\n Enter the port number : \t");
scanf("%d",&portno);
sockfd=socket(AF_INET,SOCK_DGRAM,0);
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr(host);
servaddr.sin_port=htons(portno);
connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
len=sizeof(servaddr);
while(1){
printf("\n Enter the message : ");
scanf("%s",&sendline);
sendto(sockfd,sendline,MAXLINE,0,(struct sockaddr*)&servaddr,len);
n=recvfrom(sockfd,recvline,MAXLINE,0,NULL,NULL);
recvline[n]='\0';
printf("\n clinet : Server's Echo : %s\n\n",recvline);
}
return 0;
}
