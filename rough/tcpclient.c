#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>

void main()
{

	struct sockaddr_in address;
	int sock,conn;
	char message[100],buffer[100];

	sock=socket(AF_INET,SOCK_STREAM,0);

	if(sock<0)
		printf("sock creation error\n");

	address.sin_family=AF_INET;
	address.sin_port=7891;
	address.sin_addr.s_addr=INADDR_ANY;

	conn=connect(sock,(struct sockaddr*)&address,sizeof(address));

	if(conn<0)
		printf("Connection error \n");

	
	printf("Enter message \n");
	scanf("%s",message);

	send(sock,message,sizeof(message),0);
	printf("message send\n");	

	recv(sock,buffer,sizeof(buffer),0);
	printf("Recieved from server :%s",buffer);

	

}

