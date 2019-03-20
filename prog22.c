/*Author: Pratik Kenaudekar
Date Created: 22th January 2018
Date Modified: 22th January 2018
Program: WAP to display user and group user id for a given file.

*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)
int main()
{
	umask(0420);
	if(creat("file.txt",RWRWRW)<0)
		perror("Creat error for file.txt");
	umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	if(creat("newfile.txt",RWRWRW)<0)
		perror("Creat error for newfile.txt");
    exit(0);
}
