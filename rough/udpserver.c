#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<sys/socket.h>
#include<netinet/in.h>


void main()
{
	struct sockaddr_in servaddress;
	struct sockaddr_storage servstorage;

	char message[100],buffer[100];

	int udpsock,nbytes;
	socklen_t addr_size;

	udpsock=socket(PF_INET,SOCK_DGRAM,0);
	if(udpsock<0)
		printf("Error\n");
	
	servaddress.sin_family=AF_INET;
	servaddress.sin_port=7891;
	servaddress.sin_addr.s_addr=INADDR_ANY;

	bind(udpsock,(struct sockaddr *)&servaddress,sizeof(servaddress));

	addr_size=sizeof(servstorage);

	nbytes=recvfrom(udpsock,buffer,1024,0,(struct sockaddr *)&servstorage,&addr_size);
	
	printf("Message recieved %s\n",buffer);
	
	strcpy(message,"helloworld");
	sendto(udpsock,message,strlen(message),0,(struct sockaddr *)&servstorage,addr_size);
	printf("serv msg sent \n");


}
