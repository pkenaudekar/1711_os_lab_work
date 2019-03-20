/*Author: Pratik Kenaudekar
Date Created: 22th January 2018
Date Modified: 22th January 2018
Program: WAP to implement chmod command 

*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>

int main()
{
	struct stat statbuf;
	
	if(stat("file.txt", &statbuf) < 0)
		perror("stat error for file.txt");
	if(chmod("file.txt",(statbuf.st_mode | S_IRGRP))<0)
		perror("chmod error for file.txt");
	/*set absolute mode to "rw-r--r--"*/
	if(chmod("newfile.txt",S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)<0)
		perror("chmod error for newfile.txt");
    exit(0);
}
