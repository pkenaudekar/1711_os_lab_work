/*Author: Pratik Kenaudekar
Date Created: 20th February 2018
Date Modified: 20th February 2018
Program: WAP to use execlp
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
	pid_t p;
	p=fork();
	if(p==0)
		execlp("ls","ls",NULL);
}

