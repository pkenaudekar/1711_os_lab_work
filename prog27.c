/*Author: Pratik Kenaudekar
Date Created: 24th January 2018
Date Modified: 24th January 2018
Program: WAP to directory operations.

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
	/*creating directory*/
	if(mkdir("B",0777)<0)
		perror("error in creating directory");
	else
		printf("\ndirectory created");
	/*deleting directory*/
	if(rmdir("C")<0)
		perror("\nerror in deleting directory");
	else
		printf("\ndirectory C is deleted");
	/*reading directory*/
	DIR *d;
	struct dirent *f;
	d=opendir("A");
	if(d==NULL)
		perror("Error:opendir");
	else
	{
		printf("\nDirectory files:\n");
		while((f=readdir(d))!=NULL)
			printf("inode number %ld name %s\n",f->d_ino,f->d_name);
		closedir(d);
	}	
}
