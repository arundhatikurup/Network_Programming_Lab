#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include <string.h>

void main()
{
	struct sockaddr_in serveraddress;
	socklen_t addr_size;

	int clientsock,recvread,nbytes;
	char buffer[100];

	printf("\nEnter message from client:");
	gets(buffer);

	//CREATE SOCKET
	clientsock = socket(PF_INET, SOCK_DGRAM, 0);
	
	if(clientsock<0)
	{
		printf("\nSocket Error");
	}


	//configure settings
	serveraddress.sin_family = AF_INET;
	serveraddress.sin_port =7891;
	serveraddress.sin_addr.s_addr = INADDR_ANY;

	addr_size=sizeof(serveraddress);
	
	nbytes=strlen(buffer)+1;

	sendto(clientsock,buffer,nbytes,0,( struct sockaddr *)&serveraddress,addr_size);
	printf("\nMessage from Client is sent");

	nbytes=recvfrom(clientsock,buffer,1024,0,NULL,NULL);
	printf("\nMessage from Server:%s\n",buffer);

}
