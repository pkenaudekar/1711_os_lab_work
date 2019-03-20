/*Author: Pratik Kenaudekar
Date Created: 19th February 2018
Date Modified: 19th February 2018
Program: WAP to perform following operations
-In Parent Process, display the files in parent folder
-In Child Process print the files in a given folder
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <utime.h>
#include <sys/wait.h>
void main()
{
	int pid;
	int status;
    pid=fork();
	char path[50];
	DIR *d;
	struct dirent *f;
    if(pid<0)
    {
        printf("\n Error ");
        exit(1);
    }
    else if(pid>0)
    {
		wait(&status);
		printf("\n-------------Under Parent Process-------------\n");
       	chdir("..");
		getcwd(path, 50);	
		printf("In Path: %s\n",path);
		d=opendir(path);
		while((f=readdir(d))!=NULL)
		{
			if (f->d_type == DT_DIR)
			{
				printf("Directory file name: %s\n",f->d_name);
			}
			else if (f->d_type == DT_REG)
			{
				printf("Regular file name: %s\n",f->d_name);
			}
		}
		closedir(d);
		printf("\n----------------------------------------------\n");
        exit(1);
	}
    else
    {
		printf("\n-------------Under Child Process-------------\n");
        getcwd(path, 50);
		printf("\nIn Path: %s\n",path);
		d=opendir(path);
		while((f=readdir(d))!=NULL)
		{
			if (f->d_type == DT_DIR)
			{
				printf("Directory file name: %s\n",f->d_name);
			}
			else if (f->d_type == DT_REG)
			{
				printf("Regular file name: %s\n",f->d_name);
			}
		}
		closedir(d);
		printf("\n----------------------------------------------\n");
		exit(1);
    }
   
}

