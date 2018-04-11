//ATHUK RAJ
//R6-16
//TCP CLIENT

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>//TCP/IP NETWORK LIBRARY
#include<stdlib.h>
#include <string.h>

void main()//MAIN FUNCTION
{
	struct sockaddr_in address;//DEFAULT STRUCTURE WITH OBJECT ADDRESS
	int server_fd,new_socket,recvread,addrlen,opt=1;
	char message[100],buffer[100];

	addrlen = sizeof(address);	

	strcpy(message," message  received ");
	
	server_fd=socket(AF_INET,SOCK_STREAM,0);//creating socket
	if(server_fd<0)
	{
		printf("Socket Error");
	}
	
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port =7891;

	bind(server_fd,(struct sockaddr *)&address,sizeof(address));//BIND SOCKET TO ADDRESS

	if(listen(server_fd, 3) < 0)
		printf("\nServer Error...\n");
	else
		printf("\n Server Listening...\n");

	new_socket = accept(server_fd, (struct sockaddr *)&address,(socklen_t*)&addrlen);//ESTABLISHING CONNECTION

	if(new_socket<0)
	{
		printf("Accept Error");
	}

	recv(new_socket,buffer,sizeof(buffer),0);//RECEIVE DATA ON SOCKET
	printf("\nMessage from Client is :%s\n\n",buffer);

	send(new_socket,message,sizeof(message),0);//SEND DATA
}
