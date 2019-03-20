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
		printf("\nrecieved SIGINT\n");
	
	if(signo==SIGKILL)
		printf("recieved SIGKILL\n");
	else if(signo==SIGSTOP)
		printf("recieved SIGSTOP\n");
	else if(signo==SIGCONT)
		printf("recieved SIGCONT\n");
	else if(signo==SIGTERM)
		printf("recieved SIGTERM\n");
	
}

void main()
{
	
	if(signal(SIGKILL, sig_handler)==SIG_ERR)
		printf("\ncant catch SIGKILL\n");
	if(signal(SIGSTOP, sig_handler)==SIG_ERR)
		printf("\ncant catch SIGSTOP\n");
	if(signal(SIGCONT, sig_handler)==SIG_ERR)
		printf("\ncant catch SIGCONT\n");
	if(signal(SIGTERM, sig_handler)==SIG_ERR)
		printf("\ncant catch SIGTERM\n");
	if(signal(SIGINT, sig_handler)==SIG_ERR)
		printf("\ncant catch SIGINT\n");
	//A long long wait so that we can easily issue a signal to this process
	sleep(20);
}

