/*Author: Pratik Kenaudekar
Date Created: 14th February 2018
Date Modified: 14th February 2018
Program: WAP to implement symlink
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
#include <dirent.h>
#define BUFF_SIZE 100

void main()
{
    int fd,n;
	char buf[30];
	creat("file.txt",0777);
	if(symlink("file.txt","symlink")<0)
		perror("error while creating link");
	else
		printf("link created\n");
	n=readlink("symlink",buf,30);
	printf("symlink is pointing to file---> %s\n",buf);
	  
}

