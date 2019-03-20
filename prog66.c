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
	printf("Real uservid = %ld\n effective user id = %ld",getuid(),getuid());
	setreuid(1001,1001);
	printf("\nreal user id=%ld\n effective user id = %ld", getuid(),getuid());
}

