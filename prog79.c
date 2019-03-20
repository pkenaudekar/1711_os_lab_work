/*Author: Pratik Kenaudekar
Date Created: 28th March 2018
Date Modified: 28th March 2018
Program: WAP to use pause
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

void main()
{
	alarm(5);
	printf("alarm set to 5\n");
	printf("system executed paused\n");
	if(pause()==-1)
	{
		perror("error");
	}
}

