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
	int fd, n;
	fd=open("fie.txt",O_RDONLY);
	n=lseek(fd,0,SEEK_END);
	printf("number of bytes before truncation %d\n",n);
	if(truncate("fie.txt", 5)<0)
		perror("error");
	//n=lseek(fd,0,SEEK_SET);
	n=lseek(fd,0,SEEK_END);
	printf("number of bytes after truncation %d\n",n);
    exit(0);
}
