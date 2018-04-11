/*	NAME:ATHUL RAJ
	ROLL NO:16
	DATE:3rd APRIL 2018
	PROGRAM: TIME SERVER(CLIENT)
*/
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include <string.h>
#include<arpa/inet.h>

int main(int argc,char *argv[])//opening main
{	//declaring variables
	struct sockaddr_in client_addr,serv_addr;
	char buffer[1024],msg[100];
	int sock,r,s,slen=sizeof(client_addr);
	sock=socket(AF_INET, SOCK_DGRAM, 0);	//socket creation
	if(sock<0)
		printf("\nSocket Creation Error\n");
	client_addr.sin_family = AF_INET;
	client_addr.sin_port = 7888;
	client_addr.sin_addr.s_addr = INADDR_ANY;
	bind(sock, (struct sockaddr*)&client_addr, sizeof(client_addr));	//binds socket to address and port no specified
		r=recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &serv_addr , &slen);//receive data
		if(r<0)
			printf("Receiving Error");
		else
			printf("\n%s\n",buffer);
}
