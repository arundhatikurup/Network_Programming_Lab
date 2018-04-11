/*	NAME:ATHUL RAJ
	ROLL NO:16
	DATE:3rd APRIL 2018
	PROGRAM: TIME SERVER(SERVER)
*/
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include <string.h>
#include<arpa/inet.h>
#include <time.h>
int main(int argc,char *argv[])
{	struct sockaddr_in serv_addr,client_addr;
	char buffer[1024],msg[100];
	int sock,r,s,slen=sizeof(client_addr);
	sock=socket(AF_INET, SOCK_DGRAM, 0);	//SOCKET CREATION
	if(sock<0)
		printf("\nSocket Creation Error\n");
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = 7888;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	const time_t t=time(NULL);	//OBTAIN SYSTEM TIME
	snprintf(buffer,sizeof(buffer),"%.24s\r\n",ctime(&t));  //changing time_t type to string
	s=sendto(sock , buffer , sizeof(buffer) , 0 , (struct sockaddr*) &serv_addr, sizeof(serv_addr));  //sending data
	if(s<0)
		printf("Sending Error");
	else
		printf("Sent");
}

