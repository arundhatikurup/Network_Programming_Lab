#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>


void main()
{

	struct sockaddr_in address;
	int sock ,new_sock ,addrlen;
	char message[100],buffer[100];

	strcpy(message,"Message from server\n");

	addrlen=sizeof(address);

	sock=socket(AF_INET,SOCK_STREAM,0);

	address.sin_family=AF_INET;
	address.sin_port=7891;
	address.sin_addr.s_addr=INADDR_ANY;

	bind(sock,(struct sockaddr *)&address,addrlen);
	if(listen(sock,3) < 0)
		printf("Listening error\n");
	else
		printf("Listening....\n");

	new_sock=accept(sock,(struct sockaddr *)&address,(socklen_t *)&addrlen);

	recv(new_sock,buffer,sizeof(buffer),0);
	printf("Message recieved%s\n",buffer);

	send(new_sock,message,sizeof(message),0);
	

	
}
