#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<sys/socket.h>
#include<netinet/in.h>


void main()
{
	struct sockaddr_in servaddress;

	char message[100],buffer[100];

	int udpsock,nbytes;
	socklen_t addrlen;

	udpsock=socket(PF_INET,SOCK_DGRAM,0);
	if(udpsock<0)
		printf("Error\n");
	
	servaddress.sin_family=AF_INET;
	servaddress.sin_port=7891;
	servaddress.sin_addr.s_addr=INADDR_ANY;

	addrlen=sizeof(servaddress);

	printf("Enter message :\n");
	scanf("%s",buffer);
	
	nbytes=strlen(buffer)+1;

	sendto(udpsock,buffer,nbytes,0,(struct sockaddr *)&servaddress,addrlen);
	printf("Message send from client\n");

	recvfrom(udpsock,message,1024,0,NULL,NULL);
	printf("%s\n",message);

}
