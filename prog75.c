/*Author: Pratik Kenaudekar
Date Created: 28th March 2018
Date Modified: 28th March 2018
Program: WAP to use signals
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
	if(signo==SIGINT)
		printf("\nrecieved SIGINT\nExiting\n\n\n");
	
	exit(0);
}

void main()
{
	if(signal(SIGINT, sig_handler)==SIG_ERR)
		printf("\ncant catch SIGINT\n");
	sleep(20);
}

