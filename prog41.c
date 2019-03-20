/*Author: Pratik Kenaudekar
Date Created: 12th February 2018
Date Modified: 12th February 2018
Program: WAP to implement cd
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
	char cwd[100];
	if (argc != 2) 
	{
		fprintf(stderr, "usage: %s DirectoryName\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd() error");
		exit(EXIT_FAILURE);
	}
    else
	{
		printf("Current working directory is: %s\n", cwd);
	
		if (chdir(argv[1]) != 0)
			printf("chdir() to %s failed",argv[1]);
		else
		{
			printf("chdir() to %s successful",argv[1]);
			if (getcwd(cwd, sizeof(cwd)) == NULL)
			{
				perror("getcwd() error");
				exit(EXIT_FAILURE);
			}
			else
			{
				printf("\nCurrent working directory is: %s\n", cwd);
			}
		}
	}
}

