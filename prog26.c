/*Author: Pratik Kenaudekar
Date Created: 22th January 2018
Date Modified: 22th January 2018
Program: WAP to touch and chmod.

*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>

void main(int argc, char *argv[])
{
		if(argc !=3)
		{
			printf("usage: ./prog26.exe touch filename");
			exit(1);
		}
		if(strcmp(argv[1],touch)==0)
		{
			int file1 = open(argv[2], O_RDWR | O_CREAT );
			if (file1 < 0) 
			{
				perror("error");
				exit(1);
			}
			else
			{
				printf("The file exists");
				int access(const char *pathname, int mode);
			}
		}
		exit(0);
}
