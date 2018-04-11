/*Author:Arundhati Kurup
Date:23/1/18
Title:Dual Pipe*/

#include<stdio.h>
#include<string.h>
#include<sys/types.h>

int fd1[2],fd2[2]; //Initialize file descriptors
pid_t pid;

char s1[20],s2[20];

//main begins
void main()
{
pipe(fd1);
pipe(fd2);

pid=fork(); // fork system call

if(pid==-1)
	printf("Error\n"); // Error
else if(pid>0)//Parent process
{	
	
	printf("Parent:Enter string1\n");
	scanf("%s",s1);
	write(fd1[1],s1,sizeof(s1));
	close(fd1[1]);

	read(fd2[0],s2,sizeof(s2));
	close(fd2[0]);

	strcat(s1,s2);
	printf("In Parent Process:%s\n",s1);

}

else if(pid==0)//Child process
{

	read(fd1[0],s1,sizeof(s1));
	close(fd1[0]);
	printf("Child:Enter string2\n");
	scanf("%s",s2);
	write(fd2[1],s2,sizeof(s2));
	close(fd2[1]);

	

	strcat(s2,s1);
	printf("In Child Process:%s\n",s2);

}

}//main ends
