/*Author: Pratik Kenaudekar
Date Created: 28th March 2018
Date Modified: 28th March 2018
Program: WAP to use raise
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

void sig_handler(int signo)
{
	if(signo==SIGUSR1)
		printf("\nSignal handler function\n i is 5\nExiting\n\n\n");
	exit(0);
}

void main()
{
	int i=0;
	if (signal(SIGUSR1, sig_handler)==SIG_ERR)
		printf("\ncan't catch SIGINT\n");
	
	for(i=0;i<10;i++)
	{
		if(i==5)
		{
			raise(SIGUSR1);
			printf("i=%d\n",i);
		}
	}

}

