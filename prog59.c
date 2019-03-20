/*Author: Pratik Kenaudekar
Date Created: 19th February 2018
Date Modified: 19th February 2018
Program: WAP to that lists files and directories in the currunt working directory
Create a new process to list the files and directory
Your program should also print following from the child process:
-The Process id
-The Parent id
-The Process group id
and for the parent process:
-The Process id
-The Parent id
-The Process group id
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
#include <dirent.h>
#include <sys/types.h>
#include <utime.h>
#include <sys/wait.h>
void main()
{
	int pid;
	int status;
    pid=fork();
    if(pid<0)
    {
        printf("\n Error ");
        exit(1);
    }
    else if(pid==0)
    {
        printf("\nChild Process-id: %d\nChild Process-Parent id: %d\nChild Process-Process Group id: %d\n",getpid(),getppid(),getpgid(pid));
        char path[50];
		DIR *d;
		struct dirent *f;
		getcwd(path, 50);
		printf("\nIn Path: %s\n",path);
		d=opendir(path);
		while((f=readdir(d))!=NULL)
			if (f->d_type == DT_DIR)
			{
				printf("Directory file name: %s\n",f->d_name);
			}
			else if (f->d_type == DT_REG)
			{
				printf("Regular file name: %s\n",f->d_name);
			}
		closedir(d);
		exit(1);
    }
    else
    {
		wait(&status);
        printf("\nParent Process-id: %d\nParent Process-Parent id: %d\nParent Process-Group id: %d\n",getpid(),getppid(),getpgid(pid));
        exit(1);
    }
   
}

