/*Author: Pratik Kenaudekar
Date Created: 12th February 2018
Date Modified: 12th February 2018
Program: WAP to implement rmdir
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
	
	if(argc != 2)
	{
		printf("\nUsage:./prog39.exe Dir_name\n");
		exit(1);
	}
	
	if (stat(argv[1], &st) != -1) 
	{
		rmdir(argv[1]);
		printf("Directory '%s' was successfully deleted",argv[1]);
	}
	else
	{
		printf("\nDirectory does not exists");
	}
 
}
