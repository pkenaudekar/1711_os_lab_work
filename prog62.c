/*Author: Pratik Kenaudekar
Date Created: 20th February 2018
Date Modified: 20th February 2018
Program: WAP to perform vfork
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <utime.h>
#include <sys/wait.h>

int glob =6;
void main()
{
	int var;
	pid_t pid;
	var=88;
	printf("before vfork\n");
	printf("pid= %d, glob= %d, var= %d\n",getpid(),glob,var);
	if((pid=vfork())<0)
	{
		printf("vfork error");
	}
	else if (pid==0)
	{
		//child
		printf("Child process details\n");
		printf("pid= %d, glob= %d, var= %d\n",getpid(),glob,var);
		glob++;/*modify parent's variable*/
		var++;
		exit(0);/*child terminates*/
	}
	//Parent continues here
	printf("Parent process after vfork\n");
	printf("pid= %d, glob= %d, var= %d\n",getpid(),glob,var);
	exit(0);
}

