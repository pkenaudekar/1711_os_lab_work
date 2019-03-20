/*Author: Pratik Kenaudekar
Date Created: 24th January 2018
Date Modified: 24th January 2018
Program: WAP to display the regular files in the parent directory
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
	DIR *d;
	struct dirent *f;
	chdir("..");
	getcwd(path, 50);	
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
