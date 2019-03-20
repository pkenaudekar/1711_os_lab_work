/*Author: Pratik Kenaudekar
Date Created: 24th January 2018
Date Modified: 24th January 2018
Program: WAP to display the regular files in given directory
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
#include <dirent.h>

void main(int argc, char *argv[])
{
	if(argc !=2)
	{
		printf("usage: ./prog31.exe directory_name");
		exit(1);
	}
	char path[50];
	DIR *d;
	struct dirent *f;
	strcpy(path,argv[1]);
	printf("Path: %s\n",path);
	printf("\nDirectory files:\n");
	d=opendir(path);
	while((f=readdir(d))!=NULL)
		if (f->d_type == DT_REG)
		{
			printf("file name %s\n",f->d_name);
		}
	closedir(d);
}
