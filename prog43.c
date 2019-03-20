/*Author: Pratik Kenaudekar
Date Created: 14th February 2018
Date Modified: 14th February 2018
Program: WAP to implement link
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
    int fd,fdl;
	//char buf[30];
	//fd=open("file.txt",O_RDONLY);
	if(link("file.txt","link")<0)
		perror("Error in creating link\n");
	else
		printf("Link created\n");
	/*
	if(unlink("link")<0)
		perror("error in unlinking\n");
	else
		printf("link deleted\n");
	*/
	exit(0);   
}

