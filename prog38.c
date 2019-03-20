/*Author: Pratik Kenaudekar
Date Created: 12th February 2018
Date Modified: 12th February 2018
Program: WAP to implement MKdir
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

void main(int argc, char* argv[])
{
	struct stat st;
	unsigned int mode;

	if(argc != 3)
	{
		printf("\nUsage:./prog38.exe Dir_name Dir_mode\n");
		exit(1);
	}
	mode=atoi(argv[2]);
	if (stat(argv[1], &st) == -1) 
	{
		mkdir(argv[1],mode);
		printf("Directory '%s' with permissions '%s' was successfully created",argv[1],argv[2]);
	}
	else
	{
		printf("\nDirectory already exists");
	}
 
}
