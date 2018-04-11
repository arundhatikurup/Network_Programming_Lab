
//ATHUL RAJ
//R6-16
//MESSAGE QUEUE CLIENT SIDE

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct mesg_buffer{			//STRUCTURE
	long mesg_type;
	char mesg_text[100];
	int encrypt;
}message;
int main()//MAIN FUNCTION
{
	int key,msgid;
	key=9988;
	msgid=msgget(key,0666 | IPC_CREAT);//PROCESS ID
	message.mesg_type=1;
	printf(" Enter message:");
	fgets(message.mesg_text,100,stdin);
	printf("Enter  key: ");
	scanf("%d",&message.encrypt);
	msgsnd(msgid,&message,sizeof(message),0);//MESSAGE SENT
	
	msgrcv(msgid,&message,sizeof(message),2,0);//MESSAGE RECEIVE
	printf(" data received is: %s \n", message.mesg_text);
	return 0;
}
