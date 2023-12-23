//Program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>


void error(const char *msg)
{
	perror(msg);
	exit(1);
}


int main(int argc,char *argv[])
{
	if(argc<2)
	{
		fprintf(stderr ,"Port No not provided. Program terminated\n");
		exit(1);
	}
	int sockid,newsockid,portno,n;
	char buffer[255];

	struct sockaddr_in serv_addr,cli_addr;
	socklen_t clilen;
	
	sockid = socket(AF_INET,SOCK_STREAM,0);
	if(sockid<0)
	{
		error("Error opening socket.");
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);

	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	serv_addr.sin_port=htons(portno);

	if(bind(sockid,(struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		error("Binding Failed.");
	listen(sockid,5);
	clilen=sizeof(cli_addr);
	newsockid=accept(sockid,(struct sockaddr *) &cli_addr, &clilen);

	if(newsockid < 0)
		error("Error on Accept");

	while(1)
	{
		bzero(buffer,255);
		n=read(newsockid,buffer,255);
		if(n<0)
			error("Error on reading.");
		printf("Client:%s\n",buffer);
		bzero(buffer,255);
		fgets(buffer,255,stdin);

		n=write(newsockid,buffer,3);
		if(n<0)
			error("Error on writing.");

		int i=strncmp("Bye",buffer,3);
		if(i==0)
			break;
	}
	close(newsockid);
	close(sockid);
	return 0;
}

