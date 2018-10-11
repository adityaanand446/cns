#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int welcome,new_soc,n,portno;
	char buffer[1024],fname[20];
	struct sockaddr_in addr;
	FILE *fp;
	printf("\nEnter server port number  :  Ex: 5000 ");
	scanf("%d",&portno);
	welcome=socket(PF_INET,SOCK_STREAM,0);
	addr.sin_family=AF_INET;
	addr.sin_port=htons(portno);
	addr.sin_addr.s_addr=INADDR_ANY;
	bind(welcome,(struct sockaddr *)&addr,sizeof(addr));
	printf("\nServer Online\n");
	listen(welcome,5);
	new_soc=accept(welcome,NULL,NULL);
	recv(new_soc,fname,50,0);
	printf("\nRequestingm file name:%s\n",fname);
	fp=fopen(fname,"r");
	if(fp==NULL)
	{
		send(new_soc,"\nFile not found\n",15,0);
	}
	else
	{
		while((fscanf(fp,"%s",buffer))!=EOF)
		{
			send(new_soc,buffer,strlen(buffer),0);
		}
	}
	printf("\nRequest sent\n");
	fclose(fp);
	return 0;
}
