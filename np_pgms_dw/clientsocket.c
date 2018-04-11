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
	int sock,recvread,con;
	char message[100],buffer[100];

	printf("\nEnter message");
	scanf("%s",message);//SCANS MESSAGE

	sock = socket(AF_INET, SOCK_STREAM, 0);//creating socket
	if(sock<0)
	{
		printf("\nError");
	}

	address.sin_family = AF_INET;			//STRUCTURE ELEMENTS
	address.sin_port =7891;				//STRUCTURE ELEMENTS
	address.sin_addr.s_addr = INADDR_ANY;		//STRUCTURE ELEMENTS


	con=connect(sock,(struct sockaddr *)&address, sizeof(address));//ESTABLISHING CONNECTION
	
	if(con<0)//CHECKING CONNECTION
	{
		printf("\n error in connection\n");
	}

	send(sock,message,sizeof(message),0);//COMMUNICATE WITH SERVER

	recvread=recv(sock,buffer,sizeof(buffer),0);//RECEIVE DATA ON SOCKET
	printf("\n%s\n\n",buffer);

}
