#include<stdio.h>
#include<math.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int n,soc,portno;
	char buffer[1024],fname[20],host[20];
	struct sockaddr_in addr;
	soc=socket(PF_INET,SOCK_STREAM,0);
	addr.sin_family=AF_INET;
	printf("\n************This is client :");
	bzero(host,20);
  	printf("\nEnter \n0 for  local host ( your computer as both client and server ) \n otherwise type ip address of server :\n "); 
  	scanf("%s",host);          
	if(strcmp(host,"0") == 0 )
              strcpy(host,"127.0.0.1"); 
    printf("\nEnter port no  Ex : 5000 ");
  	scanf("%d",&portno); 
	addr.sin_port=htons(portno);
	addr.sin_addr.s_addr=inet_addr(host);
	while(connect(soc,(struct sockaddr*)&addr,sizeof(addr)));
	printf("\n client connected to the server\n");
	printf("enter filename\n");
	scanf("%s",fname);
	send(soc,fname,sizeof(fname),0);
	while((n=recv(soc,buffer,sizeof(buffer),0))>0)
		printf("%s",buffer);
	return 0;
}
	
