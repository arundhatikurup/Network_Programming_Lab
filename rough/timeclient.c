#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<time.h>
#include<arpa/inet.h>

int main(int argc , char* argv[])
{
	struct sockaddr_in cliaddr;
	int sock,r,s,slen;
	char buffer[1024];
	slen=sizeof(cliaddr);
	
	sock=socket(AF_INET,SOCK_DGRAM,0);

	cliaddr.sin_family=AF_INET;
	cliaddr.sin_port=7890;
	cliaddr.sin_addr.s_addr=INADDR_ANY;
	
	bind(sock,(struct sockaddr*)&cliaddr,sizeof(cliaddr));

	recvfrom(sock,buffer,sizeof(buffer),0,(struct sockaddr *)&cliaddr,&slen);
	printf("%s\n",buffer);


}
