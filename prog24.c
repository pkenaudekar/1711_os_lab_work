/*Author: Pratik Kenaudekar
Date Created: 22th January 2018
Date Modified: 22th January 2018
Program: WAP to display user and group user id for a given file.

*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>

int main()
{
	if(chown("a.txt", 1001, -1) < 0)
		perror("error in setting chown");
	else
		printf("success, check ls -l chown.txt");
    exit(0);
}
