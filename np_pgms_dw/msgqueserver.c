
//ATHUL RAJ
//R6-16
//MESSAGE QUEUE SERVER SIDE

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct mesg_buffer {
	long mesg_type;
	char mesg_text[100];
	int encrypt;
}message;
int main()
{
	int key,msgid,i;
	key=9988;
	msgid=msgget(key,0666 | IPC_CREAT);
	msgrcv(msgid,&message,sizeof(message),1,0);
	printf("Data received!");
	
	for(i=0;message.mesg_text[i]!='\0';i++)
	{
		if(message.mesg_text[i]!=' ')
			message.mesg_text[i]+=message.encrypt;
	}
	
	msgid=msgget(key,0666 | IPC_CREAT);
	message.mesg_type=2;
	msgsnd(msgid,&message,sizeof(message),0);
	
	return 0;
}
	
