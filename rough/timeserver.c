#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<time.h>
#include<arpa/inet.h>


int main(int argc ,char* argv[])
{
	struct sockaddr_in servaddr;
	int sock,r,s;
	char buffer[1024];
	
	sock=socket(AF_INET,SOCK_DGRAM,0);

	servaddr.sin_family=AF_INET;
	servaddr.sin_port=7890;
	servaddr.sin_addr.s_addr=INADDR_ANY;

	const time_t t=time(NULL);
	snprintf(buffer,sizeof(buffer),"%.24s\r\n",ctime(&t));
	sendto(sock,buffer,sizeof(buffer),0,(struct sockaddr *)&servaddr,sizeof(servaddr));
	printf("Time sent\n");

}
