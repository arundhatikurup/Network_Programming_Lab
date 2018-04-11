#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main(){

	int id;
	char expr[400];
	int sid;
	char  *shmaddr;
	
	
	//expr="4+3+2";
	

	printf("Client process is executing\n");
	printf("enter:\n");
	scanf("%s",expr);

	
	sid=shmget(25,400, IPC_CREAT | 0666 );
	shmaddr=shmat(sid,NULL,0);
	
	sprintf(shmaddr , "%s" , expr);
	
	shmdt(shmaddr);


	return 0;
	
}

