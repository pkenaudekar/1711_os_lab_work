/*Author: Pratik Kenaudekar
Date Created: 20th February 2018
Date Modified: 20th February 2018
Program: WAP to use wait
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

void main()
{
	pid_t p,p1;
	int status;
	printf("Process id %ld\n", getpid());
	p1=fork();
	if(p1==0)
		printf("Child process\n");
	printf("Parent process enters wait\n");
	p1=wait(&status);
	printf("Completed process %ld\n", p1);
}

