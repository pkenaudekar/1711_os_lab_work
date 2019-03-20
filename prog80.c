/*Author: Pratik Kenaudekar
Date Created: 28th March 2018
Date Modified: 28th March 2018
Program: WAP to use kill
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
#include <sys/times.h>
#include <signal.h>

void signal_handler(int);
int i,pid1,pid2,status;

void main()
{
	int exit_status;
	if(signal(SIGUSR1,signal_handler)==SIG_ERR)
	{
		printf("Parent:Unable to create handler for SIGUSR1\n");
	}
	printf("\nParent pid=%d\n", pid1=getpid());
	if((pid2=fork())==0)
	{
		printf("\nChild pid=%d\n",getpid());
	}
	else
	{
		wait(&status);
		if(WIFEITED(status))
		{
			printf("\nChild return\n");
		}
		else
		{
			if(WIFSIGNALED(status))
			{
				printf("\nChild terminated on signal-%d\n\n", WTERMSIG(status));
			}
		}
		
	}
}

