#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include <string.h>

void main()
{
	struct sockaddr_in servaddress;
	struct sockaddr_storage serverstorage;
	int udpsock,nbytes;
	char message[100],buffer[100];
	socklen_t addr_size;
		

	strcpy(message,"The message was recived by the Server");
	
	//create socket
	udpsock=socket(PF_INET,SOCK_DGRAM,0);
	

	if(udpsock<0)
	{
		printf("Socket Error");
	}
	
	//configure the setting in struct
	servaddress.sin_family = AF_INET;
	servaddress.sin_addr.s_addr = INADDR_ANY;
	servaddress.sin_port =7891;

	
	//binding socketv with address struct
	bind(udpsock,(struct sockaddr *)&servaddress,sizeof(servaddress));


	addr_size=sizeof(serverstorage);
	
	nbytes=recvfrom(udpsock,buffer,1024,0,(struct sockaddr *)&serverstorage,&addr_size);
	printf("\nMessage from Client:%s\n\n",buffer);

	sendto(udpsock,buffer,nbytes,0,(struct sockaddr *)&serverstorage,addr_size);
}
