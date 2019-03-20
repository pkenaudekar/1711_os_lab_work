/*Author: Pratik Kenaudekar
Date Created: 24th January 2018
Date Modified: 24th January 2018
Program: WAP to directory operations.

*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
#include <dirent.h>

void main()
{
	char path[50];
	getcwd(path, 50);
	printf("Path: %s\n", path);
	if(chdir("..")<0)
		perror("error in chdir:");
	else
		printf("directory changed\n");
	getcwd(path, 50);
	printf("Path: %s\n", path);
}
